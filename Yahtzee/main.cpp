#include <iostream>
#include <vector>
//#include <algorithm>
//sort(dice.begin(), dice.end());
// reasons i would be a good secretary: attentive, work well with others,organized
// make a function that caluclates change

using namespace std;

int calculateChance(vector<int>dice)
{
    int score = 0;
    for (int i = 0; i < dice.size(); i++) {
        score = score + dice[i];
    }
    return score;
}

int calculateAces(vector<int>dice)
{
    int aces = 0;
    for (int i = 0; i < dice.size(); i++) {
        if (dice[i] == 1) {
            aces++;
        }
    }
    return aces*1;
}

int calculateTwos (vector<int>dice)
{
    int twos = 0;
    for (int i = 0; i < dice.size(); i++) {
        if (dice[i] == 2) {
            twos++;
        }
    }
    return twos*2;
}


int calculateThrees (vector<int>dice)
{
    int threes = 0;
    for (int i = 0; i < dice.size(); i++) {
        if (dice[i] == 3) {
            threes++;
        }
    }
    return threes*3;
}

int calculateFours (vector<int>dice)
{
    int fours = 0;
    for (int i = 0; i < dice.size(); i++) {
        if (dice[i] == 4) {
            fours++;
        }
    }
    return fours*4;
}

int calculateFives (vector<int>dice)
{
    int fives = 0;
    for (int i = 0; i < dice.size(); i++) {
        if (dice[i] == 5) {
            fives++;
        }
    }
    return fives*5;
}

int calculateSixes (vector<int>dice)
{
    int sixes = 0;
    for (int i = 0; i < dice.size(); i++) {
        if (dice[i] == 6) {
            sixes++;
        }
    }
    return sixes*6;
}

int calculateYahtzee (vector<int>dice)
{
    for (int i = 0; i < dice.size(); i++) {
        if (dice[0] != dice[i]) {
            return 0;
        }
    }
    return 50;
}

int howManyDoIHaveFunction (vector<int>dice, int ideal)
{
    int count = 0;
    for (int i = 0; i < dice.size(); i++) {
        if (dice[i] == ideal) {
            count++;
        }
    }
    return count;
}


int calculateThreeOfAKind (vector<int>dice)
{
    int score = 0;
    for (int i=1; i<7; i++) {

        if (howManyDoIHaveFunction(dice,1) > 2) {
            score = calculateChance(dice);
        }
        else if (howManyDoIHaveFunction(dice,2) > 2) {
            score = calculateChance(dice);
        }
        else if (howManyDoIHaveFunction(dice,3) > 2) {
            score = calculateChance(dice);
        }
        else if (howManyDoIHaveFunction(dice,4) > 2) {
            score = calculateChance(dice);
        }
        else if (howManyDoIHaveFunction(dice,5) > 2) {
            score = calculateChance(dice);
        }
        else if (howManyDoIHaveFunction(dice,6) > 2) {
            score = calculateChance(dice);
        }
    }
    return score;
}

int calculateFourOfAKind (vector<int>dice)
{
    int score = 0;
    for (int i=1; i<7; i++) {

        if (howManyDoIHaveFunction(dice,1) > 3) {
            score = calculateChance(dice);
        }
        else if (howManyDoIHaveFunction(dice,2) > 3) {
            score = calculateChance(dice);
        }
        else if (howManyDoIHaveFunction(dice,3) > 3) {
            score = calculateChance(dice);
        }
        else if (howManyDoIHaveFunction(dice,4) > 3) {
            score = calculateChance(dice);
        }
        else if (howManyDoIHaveFunction(dice,5) > 3) {
            score = calculateChance(dice);
        }
        else if (howManyDoIHaveFunction(dice,6) > 3) {
            score = calculateChance(dice);
        }
    }
    return score;
}

int countDice (vector <int> dice, int num) {
    int total = 0;
    for (int i = 0; i <dice.size(); i++) {
        if (dice[i] == num) {
            total = total++;
        }
    }
    return total;
}

int calculateSmallStraight (vector<int>dice) {
    int score = 0;
    sort(dice.begin(), dice.end());
    if ((dice[0] == 1 && dice[1] == 2 && dice[2] == 3 && dice[3] == 4 ||
         dice[0] == 2 && dice[1] == 3 && dice[2] == 4 && dice[3] == 5 ||
         dice[0] == 3 && dice[1] == 4 && dice[2] == 5 && dice[3] == 6)) {
        score = score + 30;
    }
    return score;
}
// add the case where you have a double of a number it still works


int calculateLargeStraight (vector<int>dice) {
    int score = 0;
    sort(dice.begin(), dice.end());
    for (int i =0; i < dice.size(); i++) {
        if (dice [i + 1] == dice[i] + 1) {
            score =40;
        }
    }
    return score;
}


int calculateFullHouse (vector<int>dice) {
    int score = 0;
    sort(dice.begin(), dice.end());
    int num1 = dice [0];
    int num2 = dice [4];
    if (countDice(dice,num1) >= 2 || countDice(dice,num1) >= 3 && countDice(dice,num2) >= 2 || countDice(dice,num2) >= 3) {
        score = 25;
    }
    return score;
}




int calculateScore (vector<int>dice, int rulenum) {
    int score = 0;
    switch (rulenum) {
    case 1:
        return calculateAces(dice);
    case 2:
        return calculateTwos(dice);
    case 3:
        return calculateThrees(dice);
    case 4:
        return calculateFours(dice);
    case 5:
        return calculateFives(dice);
    case 6:
        return calculateSixes(dice);
    case 7:
        return calculateYahtzee(dice);
    case 8:
        return calculateThreeOfAKind(dice);
    case 9:
        return calculateFourOfAKind(dice);
    case 10:
        return calculateSmallStraight(dice);
    case 11:
        return calculateLargeStraight(dice);
    case 12:
        return calculateFullHouse(dice);
    case 13:
        return calculateChance(dice);

    }
    return score;
}




int main()
{
    cout << "Calculate Chance: " << calculateChance ({1, 4, 2, 5, 6}) << endl;
    cout << "Calculate Aces: " << calculateAces ({6, 1, 3, 1, 1}) << endl;
    cout << "Calculate Twos: " << calculateTwos ({4, 2, 2, 3, 6}) << endl;
    cout << "Calculate Threes: " << calculateThrees ({3, 2, 3, 4, 3}) << endl;
    cout << "Calculate Fours: " << calculateFours ({1, 6, 3, 5, 2}) << endl;
    cout << "Calculate Fives: " << calculateFives ({1, 6, 3, 5, 2}) << endl;
    cout << "Calculate Sixes: " << calculateSixes ({5, 6, 6, 3, 2}) << endl;
    cout << "Calculate Yahtzee: " << calculateYahtzee ({4, 1, 2, 5, 3}) << endl;
    cout << "How Many Do I have: " << howManyDoIHaveFunction ({3, 1, 2, 5, 3}, 3) << endl;
    cout << "Three of a Kind: " << calculateThreeOfAKind ({2, 2, 2, 5, 3}) << endl;
    cout << "Four of a Kind: " << calculateFourOfAKind ({3, 1, 2, 5, 3}) << endl;
    cout << "Small Straight: " << calculateSmallStraight ({3, 1, 2, 5, 3}) << endl;
    cout << "Large Straight: " << calculateLargeStraight ({3, 1, 2, 5, 4}) << endl;
    cout << "Full House: " << calculateFullHouse ({3, 5, 2, 5, 6}) << endl;
    return 0;
}
