#include "graphics.h"
using namespace std;
using namespace mssm;

void drawBoard(Graphics& g, vector <vector<int>>board) {
    for (int i=0; i <= 6 ; i++) {
        g.line({0,i*100+100},{700,i*100+100}, WHITE);
    }
    for (int i=0; i <= 6; i++) {
        g.line({i*100+100,0},{i*100+100,600}, WHITE);
    }
    for (int r=0; r <= 5; r++) {
        for (int c=0; c <= 6; c++) {
            Color color = BLACK;
            if (board[r][c] == 1){
                color = RED;
            }
            if (board[r][c] == 2){
                color = YELLOW;
            }
            g.ellipse({c*100+50, r*100+50}, 80, 80, WHITE, color);
        }
    }
}

int whichColumn(int x) {
    int column;
    column=x/100;
    return column;
}

int whichRow(vector<vector<int>>board, int column) {
    for (int r = 5; r >= 0; r--) {
        if (board[r][column] == 0) { // if spot is empty
            return r;
        }
    }
    return -1;
}

int checkForWinHorizontal(vector<vector<int>>board) {
    for (int r = 0; r < 6; r++) {
        if ((board[r][0] == 1 && board[r][1]== 1 && board[r][2]== 1 && board[r][3]== 1)||
                (board[r][1] == 1 && board[r][2]== 1 && board[r][3]== 1 && board[r][4]== 1)||
                (board[r][2] == 1 && board[r][3]== 1 && board[r][4]== 1 && board[r][5]== 1)||
                (board[r][3] == 1 && board[r][4]== 1 && board[r][5]== 1 && board[r][6]== 1)){
            return 1;
        }
    }
    for (int r = 0; r < 6; r++) {
        if ((board[r][0] == 2 && board[r][1]== 2 && board[r][2]== 2 && board[r][3]== 2)||
                (board[r][1] == 2 && board[r][2]== 2 && board[r][3]== 2 && board[r][4]== 2)||
                (board[r][2] == 2 && board[r][3]== 2 && board[r][4]== 2 && board[r][5]== 2)||
                (board[r][3] == 2 && board[r][4]== 2 && board[r][5]== 2 && board[r][6]== 2)){
            return 2;
        }
    }
    return 0;
}

int checkForVerticalWin(vector<vector<int>>board) {
    for (int c = 0; c < 7; c++) {
        if ((board[0][c] == 1 && board[1][c]==1 && board[2][c] == 1 && board[3][c]==1)||
                (board[1][c] == 1 && board[2][c]==1 && board[3][c] == 1 && board[4][c]==1)||
                (board[2][c] == 1 && board[3][c]==1 && board[4][c] == 1 && board[5][c]==1))
            return 1;
    }
    for (int c = 0; c < 7; c++) {
        if ((board[0][c] == 2 && board[1][c]==2 && board[2][c] == 2 && board[3][c]==2)||
                (board[1][c] == 2 && board[2][c]==2 && board[3][c] == 2 && board[4][c]==2)||
                (board[2][c] == 2 && board[3][c]==2 && board[4][c] == 2 && board[5][c]==2))
            return 2;
    }
}

int checkForDiagonolWin(vector<vector<int>>board) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 4; c++) {
            if((board[r][c]) * (board[r+1][c+1]) * (board[r+2][c+2]) * (board[r+3][c+3])==1){
                return 1;
            }
            if((board[r][c]) * (board[r+1][c+1]) * (board[r+2][c+2]) * (board[r+3][c+3])==16){
                return 2;
            }
        }
    }

    for (int r = 0; r < 3; r++) {
        for (int c = 4; c < 7; c++) {
            if((board[r][c]) * (board[r+1][c-1]) * (board[r+2][c-2]) * (board[r+3][c-3])==1){
                return 1;
            }
            if((board[r][c]) * (board[r+1][c-1]) * (board[r+2][c-2]) * (board[r+3][c-3])==16){
                return 2;
            }
        }
    }
}

bool checkEveryoneLost(vector<vector<int>>board) {
    for (int c = 0; c < 7; c++) {
        if((board[0][c] == 0)) {
            return false;
        }
    }
    return true;
}


void gameOverOneWins(Graphics& g)
{
    while (g.draw()) {

        g.text({100,100}, 20, "Player 1 Wins! ");
    }
}

void gameOverTwoWins(Graphics& g)
{
    while (g.draw()) {

        g.text({100,100}, 20, "Player 2 Wins! ");
    }
}

void gameOverEVERYONELOOSES(Graphics& g)
{
    while (g.draw()) {

        g.text({100,100}, 20, "EVERYONE LOSSES! DUN DUN DUN!");
    }
}

int main(int argc, char* argv[])
{
    int player=1;
    int turn = 1;
    Graphics g("Hello Graphics!", 1024, 768);

    vector<vector<int>> board(6, vector<int>(7));

    while (g.draw()) {
        drawBoard(g, board);
        if (g.onMousePress(MouseButton::Left)) {
            Vec2d pos = g.mousePos();
            double x = pos.x;
            double y = pos.y;
            //            board[whichRow(board, whichColumn(g.mousePos().x))][whichColumn(g.mousePos().x)] = player;

            if (turn==-1) {
                board[whichRow(board, whichColumn(g.mousePos().x))][whichColumn(g.mousePos().x)] = 2;
            }
            else if (turn==1) {
                board[whichRow(board, whichColumn(g.mousePos().x))][whichColumn(g.mousePos().x)] = 1;
            }
            turn*=-1;
        }
        int winner = checkForWinHorizontal(board);
        if (winner == 1) {
            gameOverOneWins(g);

        }
        else if (winner == 2) {
            gameOverTwoWins(g);
        }

        winner = checkForVerticalWin(board);
        if (winner == 1) {
            gameOverOneWins(g);
        }
        else if (winner == 2) {
            gameOverTwoWins;
        }
        winner = checkForDiagonolWin(board);
        if (winner == 1) {
            gameOverOneWins(g);
        }
        else if (winner == 2) {
            gameOverTwoWins;
        }
        else if (checkEveryoneLost(board)) {
            gameOverEVERYONELOOSES(g);
        }
    }
}


//                g.cout << "Press H to say Hi" << endl;
//                if (g.onKeyPress('H')) {
//                    g.cerr << "Hello!!" << endl;
//                }

//        auto key = g.getKeyPressed();
//        if (key != Key::None) {
//            g.cerr << key << endl;
//        }

//        if (g.onKeyPress(Key::ESC)) {
//            break;
//        }

//        if (g.isKeyPressed(' ')) {
//            g.cout << "Space bar is pressed" << endl;
//        }

//        if (g.isMousePressed(MouseButton::Left)) {
//            Vec2d pos = g.mousePos();
//            double x = pos.x;
//            double y = pos.y;

//            stringstream ss;
//            ss << "Left Mouse: " << x << " " << y;

//            g.text(pos, 20, ss.str());
//        }

