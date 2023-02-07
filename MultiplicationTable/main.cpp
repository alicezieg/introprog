#include <iostream>
using namespace std;
#include<iomanip>
//for loop over multiple columns
//mutiplication table
// due thursday February 9th

int main() {
    int a;
    int b;
    cout << "how many rows would you like?" << endl;
    cin >> a;
    cout << "how many columns would you like?" << endl;
    cin >> b;

    cout << "  ";
    for (int i=1; i <= b; i++) {
        cout << setw(4);
        cout << i;


    }

    cout << endl;

    for (int i=1; i <= a; i++) {
        cout << i << "|";

        for (int j = 1; j <= b; j++) {

         cout << setw(4) << j*i;

        }

        cout << "\n";
    }




}
