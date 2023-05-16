#include "graphics.h"
using namespace std;
using namespace mssm;
constexpr Color BPINK(99,27,99);
int score = 0;

void startScreen(Graphics& g)
{
    while (g.draw()) {

        g.text({100,100}, 20, "Press ENTER to start the game", WHITE);

        if (g.onKeyPress(Key::ENTER)) {
            return;
        }
    }
}

void endScreen(Graphics& g, int score)
{
    while (g.draw()) {

        g.text({100,100}, 20, "You lost, your score was: " + to_string(score), WHITE);
        }
    }

int main(int argc, char* argv[])
{
    Graphics g("Hello Graphics!", 1024, 768);

    startScreen(g);

    // 5,5 makes ball go diagonal
    Vec2d velocity {6, 6};
    Vec2d position {100,100};
    Vec2d paddlePos {0, g.height()/2};
    while (g.draw()) {

        //        g.line({400,40}, {100,200}, RED);
        //        g.line({400,40}, {105,195}, ORANGE);
        //        g.line({200,40}, {110,190}, YELLOW);
        //        g.line({200,40}, {115,185}, GREEN);
        //        g.line({0,40}, {120,180}, BLUE);
        //        g.line({0,40}, {125,175}, PURPLE);
        g.text({100,100}, 20, "Score:" + to_string(score));

                Vec2d p1{0,0};
        Vec2d p2{100,100};

        //        g.cout <<"You hit the left wall!" << endl;
        //        g.line(p1, p2, YELLOW);
        paddlePos.y= g.mousePos().y;
        g.rect(paddlePos, 20, 100, ORANGE, YELLOW);

        g.ellipse (position, 50, 50, BPINK, YELLOW);
        // affects size/shape of object ^^

        position = position + velocity;
        //lines below makes shape bounce against wall
        if (position.x>g.width()-25){
            velocity.x=-velocity.x;
        }

        if (position.y>g.height()-25 || position.y<25){
            velocity.y=-velocity.y;
        }

        if (position.x<20 &&
                position.y>g.mousePos().y &&
                position.y<g.mousePos().y+100 &&
                velocity.x < 0) {
            velocity.x=-velocity.x+1;
            score = score + 100;
        }
        if (position.x<-100) {
            endScreen(g, score);
            return 0;
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
