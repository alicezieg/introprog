#include "graphics.h"

using namespace std;
using namespace mssm;




int main(int argc, char *argv[])
{
    Graphics g("Asteroids!", 1024, 768);
    int score = 100;
    while(g.draw()) {
        g.text({300,300}, 40, to_string(score), BLUE, HAlign::center);
        g.ellipse({300,300}, 3, 3, GREEN);
        g.cout << "Hello" << endl << "my name is Alice my score is: " << score << endl;

        g.line({100,100}, g.mousePos(), RED);
        g.cout << g.mousePos() << endl;
        g.rect({100,100}, 17, 37, BLUE, GREEN);

        if (g.isMousePressed(MouseButton::Left)) {
            int sign = 0;
            g.cout<< to_string(sign);
        }

    }
}

//        if (g.onKeyPress(Key::Up)) {
//            g.cout<<"Hey my name is alice"<< endl;
//        }
//    }
//}
//        if (g.isMousePressed(MouseButton::Left)) {
//            score = score + 1;
//        }
//    }
//}

//        if (g.isMousePressed(MouseButton::Left)) {
//            Vec2d pos = g.mousePos();
//            double x = pos.x;
//            double y = pos.y;

//            stringstream ss;
//            ss << "Left Mouse: " << x << " " << y;

//            g.text(pos, 20, ss.str());
//        }
//    }
//}



//// class - user defined type (type tells us, values and operations)

//class Ship {
//public:
//    Vec2d position;  // variables: fields
//    Vec2d velocity;  // this is a field
//    Color color;     // this is a field
//    double angularVelocity;
//    double angle;
//};


//void drawShip(Graphics&g, Ship player, double scale)
//{
//    vector<Vec2d> points { {-20, 0}, {0, 30},{20, 0}, {0, -40}};

//    for (int i = 0; i < points.size(); i++) {
//        points[i].rotate(player.angle);
//        points[i] = points[i]*scale + player.position;
//    }

//    g.polygon(points, player.color, player.color);
//}

//void updateShip(Graphics&g, Ship& player)
//{
//    player.position = player.position + player.velocity; // PHYSICS!!!
//    player.angle = player.angle + player.angularVelocity;

//    if (player.position.x > g.width()-20) {
//        player.velocity.x *= -1;
//        player.position.x = g.width()-21;
//    }
//    if (player.position.x < 0) {
//        player.velocity.x *= -1;
//        player.position.x = 1;
//    }
//    if (player.position.y > g.height()-20) {
//        player.velocity.y *= -1;
//        player.position.y = g.height()-21;
//    }
//    if (player.position.y < 0) {
//        player.velocity.y *= -1;
//        player.position.y = 1;
//    }
//}



//int main(int argc, char *argv[])
//{
//    Graphics g("Asteroids!", 1024, 768);


//    //Ship player;

//    vector<Ship> ships;

//    for (int i = 0; i < 1000; i++) {
//        Ship player;
//        player.position = {g.randomDouble(0,500),g.randomDouble(0,500)};
//        player.velocity = {g.randomDouble(-10,10), g.randomDouble(-10,10)};
//        player.color = Color(g.randomInt(0,255), g.randomInt(0,255), g.randomInt(0,255));
//        player.angularVelocity = g.randomDouble(-0.1, 0.1);
//        ships.push_back(player);
//    }


//    while(g.draw()) {
//        for (int i = 0; i < ships.size(); i++) {
//            drawShip(g, ships[i], 1);
//            updateShip(g, ships[i]);
//        }
//    }

//}






























//    Graphics g("Hello Graphics!", 1024, 768);

//    Vec2d position{500,500};

//    Image skull(g, "skull.png"); //load image

//    Sound pew(g, "sounds/ShortLaser.wav"); //load a sound clip
//    g.music("sounds/goldn-116392.mp3"); //play music, don't need to load



//    while(g.draw()){
//        if(g.onKeyPress(Key::Space)){
//            g.play(pew);
//        }

//    }




//Vec2d is a 2 dimensial vector, package of doubles


//        Vec2d p1{50, 50};
//        Vec2d p2;
//        p2.x = 150;
//        p2.y = 300;

//        Color c;
//        c.r = 13;
//        c.g = 120;
//        c.b = 200;
//        c.a = 250;

//        g.line(p1, {300,200}, GREEN);
//        g.line({50,70}, g.mousePos(), PURPLE);

//r is red, g is green, b is blue, a is alpha or transparentcy/opcaity
//0-258

//        g.line({20, 20}, Vec2d{100, 100}, BLUE);

//        g.rect({50, 50}, 300, 400, c, c);


//        c.g = c.g + 1;

//        if(position.x >= 1024){
//            position.x = 0;

//        }
//        if(position.y >= 768){
//            position.y = 0;
//        }




//        g.cout << "Press H to say Hi" << endl;
//        if (g.onKeyPress('H')) {
//            g.cerr << "Hello!!" << endl;
//        }

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
//         }
//    }


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

