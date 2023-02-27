#include <iostream>

using namespace std;
int main()
{
    cout << "How much does it cost?" << endl;
    double x;
    double y;
    cin >> x;
    cout << "How much did you give?" << endl;
    cin >> y;

    double z = y - x;

    if (z < 0) {
    cout << "I owe you $" << abs (z) << endl;
    }


    int twenties= z/20;
    if (twenties > 0) {
    cout << "I owe you " << twenties << " twenties" << endl;
    }
    z = z - twenties * 20;

    int tens= z/10;
    if (tens > 0) {
    cout  << tens << " tens " << endl;
    }
    z = z - tens * 10;

    int fives= z/5;
    if (fives > 0) {
    cout  << fives << " fives " << endl;
    }
    z = z - fives * 5;

    int ones= z/1;
    if (ones > 0) {
    cout  << ones << " ones " << endl;
    }
    z = z - ones * 1;

    int quarters= z/.25;
    if (quarters > 0) {
    cout  << quarters << " quarters " << endl;
    }
    z = z - quarters * .25;


    int dimes= z/.1;
    if (dimes > 0) {
    cout  << dimes << " dimes " << endl;
    }
    z = z - dimes * .1;

    int nickels= z/.05;
    if (nickels > 0) {
    cout  << nickels << " nickels " << endl;
    }
    z = z - nickels * .05;

    int pennies= z/.01;
    if (pennies > 0) {
    cout  << pennies << " pennies " << endl;
    }
    z = z - pennies * .01;

     cout << "Thank you, have a great day." << endl;

        return 0;
}
