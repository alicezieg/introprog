#include <iostream>
#include <vector>
using namespace std;

vector<string>  moreThanFour(vector<string>names)
{
    vector<string> longNames;
int x;
    for (int i = 0; i < names.size(); i++) {
        if (names.size() >= x) {
        longNames.push_back(names[i]);
        }
    }
    return longNames;
}

int main()
{
    vector<string> people{"Bob", "Bobbert", "Bobberson", "Bo", "Bobbie"};

    people.push_back("Bib");
    people.push_back("Blob");
    people.push_back("Bert");

    cout << "How long do you want the names to be?" << endl;
    int minNamesize;
    cin >> minNamesize;

    vector<string> longNamePeople = moreThanFour (people);
    for (int i = 0; i < longNamePeople.size(); i++) {
        cout << longNamePeople[i] << endl;
    }

    return 0;
}

