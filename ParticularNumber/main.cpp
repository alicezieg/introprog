#include <iostream>
#include <vector>

using namespace std;

int CountNumbers(vector<int>numbers, int n)
{
    int x = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (n == numbers[i]) {
            x++;
        }
    }
    return x;
}

int main()
{
    vector<int> values {3,4,7,10, 17, 77, 79, 137, 794, 7, 7, 7 ,7, 4, 4, 14};
    cout << CountNumbers(values,4) << endl;

    return 0;
}
