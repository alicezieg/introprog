#include "graphics.h"

using namespace std;
using namespace mssm;

//issues:breaks up asteroids when hit with laser, score, lives

// classes are user-defined types
//   what is a type?    Tells us values that can stored and operations that can be performed

class Ship {
public:
    Vec2d position;  // instance variables AKA fields AKA members
    Vec2d velocity;
    Color border;
    Color fill;
    double angle = 0;
    Vec2d acceleration;

    // declare the methods
    void draw(Graphics& g, double scale);  // method (a function that is part of
    // the class.  a function that is a member)
    void update(Graphics& g);
};

class Asteroid {
public:
    Vec2d position;
    Vec2d velocity;
    Color border=GREY;
    Color fill=GREY;
    double angle = 0;
    double angularVelocity = 0;
    double scale = 5;

    void draw(Graphics& g);
    void update(Graphics& g);

};

class Bullet {
public:
    Vec2d position;
    Vec2d velocity;
    double angle= 0;
    double lifetime=500;

    void draw(Graphics& g);
    void update(Graphics& g);
};

class Star {
public:
    Vec2d position;
    Vec2d velocity;

    void draw(Graphics& g);
};

void Star::draw(Graphics& g) {
    position = position;
    g.ellipse ({position.x,position.y}, 2, 2, WHITE, WHITE);
}

void Bullet::draw(Graphics& g) {
    g.ellipse(position, 15, 15, RED, RED);
}

void Bullet::update(Graphics& g) {
    lifetime=lifetime-g.elapsedMs();

    position = position + velocity;
    position = velocity+position;
    if (position.x > g.width()-20) {
        position.x=position.x-g.width();
    }
    if (position.x < 0) {
        position.x=position.x+g.width();
    }
    if (position.y > g.height()-20) {
        position.y=position.y-g.height();
    }
    if (position.y < 0) {
        position.y=position.y+g.height();
    }
}

void Ship::draw(Graphics& g, double scale)
{
    vector<Vec2d> points{ {0, -18.75}, {-18.75, 18.75}, {0, 5}, {18.75,18.75}};

    for (int i = 0; i < points.size(); i++) {
        points[i] = points[i] * scale;
        points[i].rotate(angle);
        points[i] = points[i] + position;
    }

    g.polygon(points, border, fill);
}

void Asteroid::draw(Graphics& g)
{
    vector<Vec2d> points {{6, -5}, {10, -3}, {8,3}, {7.5,7}, {4,12}, {-3,9}, {-9,12}, {-10,3}, {-4,-4}};
    for (int i = 0; i < points.size(); i++) {
        points[i] = points[i] * scale;
        points[i].rotate(angle-.5);
        points[i] = points[i] + position;
    }

    g.polygon(points, border, fill);
}

void Ship::update(Graphics& g )
{
    position = position + velocity; // PHYSICS!!!
    if (g.isKeyPressed(Key::Up)) {
        acceleration.x= .1*cos(angle-1.57);
        acceleration.y= .1*sin(angle-1.57);
    }
    else {
        acceleration = {0,0};
    }
    velocity = velocity+acceleration;
    if (position.x > g.width()-20) {
        position.x=position.x-g.width();
    }
    if (position.x < 0) {
        position.x=position.x+g.width();
    }
    if (position.y > g.height()-20) {
        position.y=position.y-g.height();
    }
    if (position.y < 0) {
        position.y=position.y+g.height();
    }
    if (g.isKeyPressed(Key::Left)) {
        angle= angle-.1;
    }
    if(g.isKeyPressed(Key::Right)) {
        angle= angle+.1;
    }
}

void Asteroid::update(Graphics& g )
{
    position = velocity+position;
    if (position.x > g.width()-20) {
        position.x=position.x-g.width();
    }
    if (position.x < 0) {
        position.x=position.x+g.width();
    }
    if (position.y > g.height()-20) {
        position.y=position.y-g.height();
    }
    if (position.y < 0) {
        position.y=position.y+g.height();
    }
}

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

int main(int argc, char *argv[])
{
    Graphics g("Asteroids!", 1024, 768);
    Sound PEWPEW(g,"untitled.wav");

    int lives = 3;
    int score = 0;
    int moreRocks;

    //    cout << a.position.x << endl;   // .  is the member access operator

    Ship rocket;


    // set up the ship

    rocket.position = {g.randomDouble(30, g.width()-30),g.randomDouble(30, g.height()-30)};
    //    rocket.velocity = {g.randomDouble(-4,4),g.randomDouble(-4,4)};
    rocket.border = Color(g.randomInt(0,255), g.randomInt(0,255),g.randomInt(0,255));
    rocket.fill = Color(g.randomInt(0,255), g.randomInt(0,255),g.randomInt(0,255));

    double scale = 2;

    vector<Bullet> bullets;
    double bulletSpeed = 10;

    vector<Asteroid>rocks;
    for (int i = 0; i < 6; i++) {
        Asteroid rock;
        rock.position = {g.randomDouble(0,500),g.randomDouble(0,500)};
        rock.velocity = {g.randomDouble(-6,6), g.randomDouble(-6,6)};
        rock.border = GREY;
        rock.fill = GREY;
        rock.angularVelocity = g.randomDouble(-0.1, 0.1);
        rocks.push_back(rock);
    }

    vector<Star> stars;

    for (int i = 0; i < 50; i++) {
        Star star;
        star.position = {g.randomInt(0,1024), g.randomInt(0,728)};
        stars.push_back(star);
    }

    startScreen(g);
            while(g.draw()) {

        for (int i = 0; i < stars.size(); i++) {
            stars[i].draw(g);
        }

        g.cout << "Lives: " << lives << endl;
        g.cout << "Score: " << score << endl;
        rocket.draw(g, scale);
        rocket.update(g);

        for (int i = 0; i < rocks.size(); i++) {
            rocks[i].draw(g);
            rocks[i].update(g);

        }

        if (g.onKeyPress (' ')) {
            g.play(PEWPEW);
            Bullet z;
            z.position={rocket.position};
            z.angle = rocket.angle;
            z.velocity = {bulletSpeed*cos(z.angle-1.57), bulletSpeed*sin(z.angle-1.57)};
            bullets.push_back(z);
        }

        for (int i =0; i< bullets.size(); i++) {
            bullets[i].draw(g);
            bullets[i].update(g);
            if (bullets[i].lifetime <= 0) {
                bullets.erase(bullets.begin() +i);
                i--;
            }
        }

        for (int i =0; i< bullets.size(); i++) {
            for (int x= 0; x< rocks.size(); x++) {
                if ((bullets[i].position-rocks[x].position).magnitude()<60) {
                    bullets.erase(bullets.begin() +i);
                    i--;
                    if (rocks[x].scale == 5) {
                        rocks[x].scale = 3;
                        rocks.push_back(rocks[x]);
                        rocks[x].velocity= rocks[x].velocity*-1;
                    }
                    else if (rocks[x].scale ==2) {
                        rocks.erase(rocks.begin()+x);
                        x--;
                    }
                    else if (rocks[x].scale == 3) {
                        rocks[x].scale = 2;
                        rocks.push_back(rocks[x]);
                        rocks[x].velocity= rocks[x].velocity*-1;
                    }
                    score++;
                    break;
                }
            }
        }
        for (int i = 0; i < rocks.size(); i++) {
            if ((rocket.position - rocks[i].position).magnitude() < (12+(rocks[i].scale*8))) {
                rocket.position = {500, 400};
                lives = lives - 1;
                rocks.erase(rocks.begin()+i);
                i--;
            }
        }
        if (lives == 0) {
            endScreen(g,score);
            break;
        }
        if (rocks.empty()) {
            for (int i = 0; i < moreRocks; i++) {
                Asteroid rock;
                rock.position = {g.randomDouble(0,500),g.randomDouble(0,500)};
                rock.velocity = {g.randomDouble(-6,6), g.randomDouble(-6,6)};
                rock.border = GREY;
                rock.fill = GREY;
                rock.angularVelocity = g.randomDouble(-0.1, 0.1);
                rocks.push_back(rock);
            }
            moreRocks = moreRocks + 5;
        }
    }

}

//// class - user defined type (type tells us, values and operations)

//class Ship {
//public:
//    Vec2d position;  // variables: fields
//    Vec2d velocity;  // this is a field
//    Color color;     // this is a field
//    double angularVelocity;
//    double angle;
//};


//void drawShip(Graphics&g, Ship , double scale)
//{
//    vector<Vec2d> points { {-20, 0}, {0, 30},{20, 0}, {0, -40}};

//    for (int i = 0; i < points.size(); i++) {
//        points[i].rotate(angle);
//        points[i] = points[i]*scale + position;
//    }
//    g.polygon(points, color, color);
//}

//void updateShip(Graphics&g)
//}



//int main(int argc, char *argv[])
//{
//    Graphics g("Asteroids!", 1024, 768);
//}


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

