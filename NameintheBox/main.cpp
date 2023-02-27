#include <iostream>
using namespace std;

int main() {
string n;
  int namelength;

  cout << "Enter to start" << endl;
  cin. ignore (10000, '\n');
  cout << "Enter a name" << endl;
  getline (cin, n);
  namelength= n. length();

  for (int i=0; i < namelength; i++){
    cout << "*";}
  cout << "****" << endl;

  cout << "* " << n << " *" << endl;

  for (int i=0; i<namelength; i++){
    cout << "*";}
  cout << "****" << endl;
  return 0;
  }
