#include <iostream>
#include <vector>
using namespace std;

double add (double x, double y) // <<- signature
{
    return x + y;
}

double absolute (double x) {
    if (x < 0) {

        return x * -1;
    }
    return x;
}

double average (double a, double b)

{
    return (a + b)/2;
}

double square (double x)
{
     return (x*x);
}

double smallest (vector<double> values) {
    double s=values[0];
        for (int i=0; i>values.size(); i++){
            if (values[i]<s) {
           s=values[i];
       }
    }
    return s;
}


    double avevec (vector<double>numbers) {
        double sum=0;
        for (int i=0; i<numbers.size(); i++) {
             sum=sum+numbers[i];

    }
        return sum/numbers.size();
    }

    double addvec(vector<double>values1, vector<double>values2){
        double sum = 0;
        for (int i=0; i<values1.size(); i++) {
            sum=sum+ (values1[i] *values2[i]);
        }
        return sum;
    }
int main()
{

    cout << "add(3,7) returns: " << add (3,7) << endl;
    cout << "the absolute value of negative 176 is " << absolute (-176) << endl;
    cout << "the average of (4,6) is:" << add (4,6)/2 << endl;
    cout << "the square of 3 is: " <<  (3*3) << endl;
    cout << "the smallest value of 1, 54, 2, 77, 12 is: " << smallest({1,54,2,77,12}) << endl;
    cout << "the average of 34, 92, 33, 23, and 19 is:" << avevec ({34,92,33,23,19}) << endl;
    cout << " (3*6) + (7*2)= " << addvec ({3,6},{7,2}) << endl;

    return 0;
}
