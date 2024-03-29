//
// experimental/parallel_group.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2022 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef ASIO_EXPERIMENTAL_PARALLEL_GROUP_HPP
#define ASIO_EXPERIMENTAL_PARALLEL_GROUP_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "asio/detail/config.hpp"
#include "asio/detail/array.hpp"
#include "asio/detail/utility.hpp"
#include "asio/experimental/cancellation_condition.hpp"

#include "asio/detail/push_options.hpp"

namespace asio {
namespace experimental {
namespace detail {

// Helper trait for getting a tuple from a completion signature.

template <typename Signature>
struct parallel_op_signature_as_tuple;

template <typename R, typename... Args>
struct parallel_op_signature_as_tuple<R(Args...)>
{
  typedef std::tuple<typename decay<Args>::type...> type;
};

// Helper trait for concatenating completion signatures.

template <std::size_t N, typename Offsets, typename... Signatures>
struct parallel_group_signature;

template <std::size_t N, typename R0, typename... Args0>
struct parallel_group_signature<N, R0(Args0...)>
{
  typedef asio::detail::array<std::size_t, N> order_type;
  typedef R0 raw_type(Args0...);
  typedef R0 type(order_type, Args0...);
};

template <std::size_t N,
    typename R0, typename... Args0,
    typename R1, typename... Args1>
struct parallel_group_signature<N, R0(Args0...), R1(Args1...)>
{
  typedef asio::detail::array<std::size_t, N> order_type;
  typedef R0 raw_type(Args0..., Args1...);
  typedef R0 type(order_type, Args0..., Args1...);
};

template <std::size_t N, typename Sig0,
    typename Sig1, typename... SigN>
struct parallel_group_signature<N, Sig0, Sig1, SigN...>
{
  typedef asio::detail::array<std::size_t, N> order_type;
  typedef typename parallel_group_signature<N,
    typename parallel_group_signature<N, Sig0, Sig1>::raw_type,
      SigN...>::raw_type raw_type;
  typedef typename parallel_group_signature<N,
    typename parallel_group_signature<N, Sig0, Sig1>::raw_type,
      SigN...>::type type;
};

template <typename Condition, typename Handler,
    typename... Ops, std::size_t... I>
void parallel_group_launch(Condition cancellation_condition, Handler handler,
    std::tuple<Ops...>& ops, asio::detail::index_sequence<I...>);

} // namespace detail

/// A group of asynchronous operations that may be launched in parallel.
/**
 * See the documentation for asio::experimental::make_parallel_group for
 * a usage example.
 */
template <typename... Ops>
class parallel_group
{
private:
  struct initiate_async_wait
  {
    template <typename Handler, typename Condition>
    void operator()(Handler&& h, Condition&& c, std::tuple<Ops...>&& ops) const
    {
      detail::parallel_group_launch(
          std::forward<Condition>(c), std::forward<Handler>(h),
          ops, asio::detail::index_sequence_for<Ops...>());
    }
  };

  std::tuple<Ops...> ops_;

public:
  /// Constructor.
  explicit parallel_group(Ops... ops)
    : ops_(std::move(ops)...)
  {
  }

  /// The completion signature for the group of operations.
  typedef typename detail::parallel_group_signature<sizeof...(Ops),
      typename completion_signature_of<Ops>::type...>::type signature;

  /// Initiate an asynchronous wait for the group of operations.
  /**
   * Launches the group and asynchronously waits for completion.
   *
   * @param cancellation_condition A function object, called on completion of
   * an operation within the group, that is used to determine whether to cancel
   * the remaining operations. The function object is passed the arguments of
   * the completed operation's handler. To trigger cancellation of the remaining
   * operations, it must return a asio::cancellation_type value other
   * than <tt>asio::cancellation_type::none</tt>.
   *
   * @param token A @ref completion_token whose signature is comprised of
   * a @c std::array<std::size_t, N> indicating the completion order of the
   * operations, followed by all operations' completion handler arguments.
   *
   * The library provides the following @c cancellation_condition types:
   *
   * @li asio::experimental::wait_for_all
   * @li asio::experimental::wait_for_one
   * @li asio::experimental::wait_for_one_error
   * @li asio::experimental::wait_for_one_success
   */
  template <typename CancellationCondition,
      ASIO_COMPLETION_TOKEN_FOR(signature) CompletionToken>
  ASIO_INITFN_AUTO_RESULT_TYPE_PREFIX(CompletionToken, signature)
  async_wait(CancellationCondition cancellation_condition,
      CompletionToken&& token)
    ASIO_INITFN_AUTO_RESULT_TYPE_SUFFIX((
      asio::async_initiate<CompletionToken, signature>(
          declval<initiate_async_wait>(), token,
          std::move(cancellation_condition), std::move(ops_))))
  {
    return asio::async_initiate<CompletionToken, signature>(
        initiate_async_wait(), token,
        std::move(cancellation_condition), std::move(ops_));
  }
};

/// Create a group of operations that may be launched in parallel.
/**
 * For example:
 * @code asio::experimental::make_parallel_group(
 *    [&](auto token)
 *    {
 *      return in.async_read_some(asio::buffer(data), token);
 *    },
 *    [&](auto token)
 *    {
 *      return timer.async_wait(token);
 *    }
 *  ).async_wait(
 *    asio::experimental::wait_for_all(),
 *    [](
 *        std::array<std::size_t, 2> completion_order,
 *        std::error_code ec1, std::size_t n1,
 *        std::error_code ec2
 *    )
 *    {
 *      switch (completion_order[0])
 *      {
 *      case 0:
 *        {
 *          std::cout << "descriptor finished: " << ec1 << ", " << n1 << "\n";
 *        }
 *        break;
 *      case 1:
 *        {
 *          std::cout << "timer finished: " << ec2 << "\n";
 *        }
 *        break;
 *      }
 *    }
 *  );
 * @endcode
 */
template <typename... Ops>
ASIO_NODISCARD inline parallel_group<Ops...>
make_parallel_group(Ops... ops)
{
  return parallel_group<Ops...>(std::move(ops)...);
}

} // namespace experimental
} // namespace asio

#include "asio/detail/pop_options.hpp"

#include "asio/experimental/impl/parallel_group.hpp"

#endif // ASIO_EXPERIMENTAL_PARALLEL_GROUP_HPP
