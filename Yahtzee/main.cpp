#include <iostream>
#include <vector>
#include <cstdlib>
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
            total = total+1;
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

    cout << "Checking for full house" << endl;
    sort(dice.begin(), dice.end());
    int num1 = dice [0];
    int num2 = dice [4];
    cout << "Num1 = " << num1 <<  "  num2 = " << num2 << endl;

    cout << "Num1 count = " << countDice(dice, num1) << endl;
    cout << "Num2 count = " << countDice(dice, num2) << endl;

    if ((countDice(dice,num1) == 2 && countDice(dice,num2) == 3) || (countDice(dice,num1) == 3 && countDice(dice,num2) == 2)) {
        cout << "Yay!" << endl;
        score = 25;
    }

    cout << "BOOOO" << endl;
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
        return calculateThreeOfAKind(dice);
    case 8:
        return calculateFourOfAKind(dice);
    case 9:
        return calculateFullHouse(dice);
    case 10:
        return calculateSmallStraight(dice);
    case 11:
        return calculateLargeStraight(dice);
    case 12:
        return calculateYahtzee(dice);
    case 13:
        return calculateChance(dice);

    }
    return score;
}


vector<int> roll()
{

    vector<int>dice (5);
    dice[0] = rand()%6 + 1;
    dice[1] = rand()%6 + 1;
    dice[2] = rand()%6 + 1;
    dice[3] = rand()%6 + 1;
    dice[4] = rand()%6 + 1;

    return dice;

}
void displaydice(vector<int>dice) {
    for (int i = 0; i <dice.size(); i++) {
        cout << dice[i] << " ";
    }
    cout << endl;
}

vector<int> reRoll(vector<int>dice) {
    cout << "Would you like to reroll?  " << "y/n" << endl;
    string z;
    cin >> z;
    if (z == "n") {
        return dice;
    }

    else {
        if (z == "y") {
            cout << "How many dice would you like to reroll?" << endl;
            int numToReRoll;
            cin >> numToReRoll;
            for (int i = 0; i < numToReRoll; i++) {
                cout << "Which dice would you like to reroll? ";
                int whichDie;
                cin >> whichDie;
                dice[whichDie-1] = rand()%6 + 1;

            }

//            cout << "Would you like to roll again?  " << "y/n" << endl;
//            string z;
//            cin >> z;
//            if (z == "n") {
//                return dice;
//            }
        }
        else {
            if (z == "y") {
                cout << "How many dice would you like to reroll?" << endl;
                int numToReRoll;
                cin >> numToReRoll;
                for (int i = 0; i < numToReRoll; i++) {
                    cout << "Which dice would you like to reroll? ";
                    int whichDie;
                    cin >> whichDie;
                    dice[whichDie-1] = rand()%6 + 1;

                }
            }
        }
        return dice;


    }
    return dice;
}

void displayScoreSheet(vector<int>scores, vector<bool> scoreUsed) {
    if (scoreUsed[0] == true) {
        cout << "1. Aces = " << scores[1] << endl;
    }
    else {
        cout << "1. Aces = " <<  endl;
    }
    if (scoreUsed[1] == true) {
        cout << "2. Twos = " << scores[2] << endl;
    }
    else {
        cout << "2. Twos = " <<  endl;
    }    if (scoreUsed[2] == true) {
        cout << "3. Threes = " << scores[3] << endl;
    }
    else {
        cout << "3. Threes = " <<  endl;
    }    if (scoreUsed[3] == true) {
        cout << "4. Fours = " << scores[4] << endl;
    }
    else {
        cout << "4. Fours = " <<  endl;
    }    if (scoreUsed[4] == true) {
        cout << "5. Fives = " << scores[5] << endl;
    }
    else {
        cout << "5. Fives = " <<  endl;
    }    if (scoreUsed[5] == true) {
        cout << "6. Sixes = " << scores[6] << endl;
    }
    else {
        cout << "6. Sixes = " <<  endl;
    }
    if (scoreUsed[6] == true) {
        cout << "7. Threes of a Kind = " << scores[7] << endl;
    }
    else {
        cout << "7. Threes of a Kind = " <<  endl;
    }
    if (scoreUsed[7] == true) {
        cout << "8. Four of a Kind = " << scores[8] << endl;
    }
    else {
        cout << "8. Four of a Kind = " <<  endl;
    }
    if (scoreUsed[8] == true) {
        cout << "9. Full House = " << scores[9] << endl;
    }
    else {
        cout << "9. Full House = " <<  endl;
    }
    if (scoreUsed[9] == true) {
        cout << "10. Small Straight = " << scores[10] << endl;
    }
    else {
        cout << "10. Small Straight = " <<  endl;
    }
    if (scoreUsed[10] == true) {
        cout << "11. Large Straight = " << scores[11] << endl;
    }
    else {
        cout << "11. Large Straight = " <<  endl;
    }
    if (scoreUsed[11] == true) {
        cout << "12. Yahtzee = " << scores[12] << endl;
    }
    else {
        cout << "12. Yahtzee = " <<  endl;
    }
    if (scoreUsed[12] == true) {
        cout << "13. Chance = " << scores[13] << endl;
    }
    else {
        cout << "13. Chance = " <<  endl;
    }
}

int toptotal(vector<int>scores) {
    int toptotal = 0;
    for (int i = 0; i<6; i++) {
        toptotal=toptotal + scores[i];
    }
    if (toptotal >= 63) {
        toptotal = toptotal + 35;
    }
    return toptotal;
}

int bottomtotal(vector<int>scores) {
    int bottomtotal = 0;
    for (int i = 7; i<13; i++) {
        bottomtotal=bottomtotal + scores[i];
    }
    return bottomtotal;
}

int main()
{
    int yahtzeeBonus = 0;
    string enter;
    srand(time (0));
    cout << "Welcome to Yahtzee!" << endl;
    cout << "Press ENTER to start.";
    getline (cin, enter);

    vector<int> scores(13);
    vector<bool> scoreUsed(13);

    for (int i = 0; i<13; i++) {
        vector<int>dice = roll();
        displaydice(dice);
        dice = reRoll(dice);
        displaydice(dice);
        dice = reRoll(dice);
        displaydice(dice);

        if((scores[11] ==50) && (calculateScore(dice,12)==50)){
            cout << "You got Yahtzee bonus" << endl;
            yahtzeeBonus=yahtzeeBonus+100;
        }
        while (true){
            displayScoreSheet(scores, scoreUsed);
            cout << "Which rule would you like to use?" << endl;
            int rulenum;
            cin >> rulenum;
            if (scoreUsed[rulenum - 1] == true) {
                cout << "You already used this rule!" << endl;
            }
            if (scoreUsed[rulenum - 1] == false) {
                cout << calculateScore(dice, rulenum) << endl;
                scores[rulenum] = calculateScore(dice, rulenum);
                scoreUsed[rulenum - 1] = true;
                displayScoreSheet(scores, scoreUsed);
                break;
            }
        }
    }
    int topt = toptotal(scores);
    int bott = bottomtotal(scores);
    int finalTot = topt + bott + yahtzeeBonus;
    cout << "Your top total is: " << topt << endl;
    cout << "Your bottom total is: " << bott << endl;
    cout << "Your final total is: " << finalTot << endl;
    cout << "Great job! " << endl;
    return 0;
}

