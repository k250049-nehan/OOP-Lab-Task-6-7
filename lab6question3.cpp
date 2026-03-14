#include <iostream>
using namespace std;

class Position {
protected:
    float x;
    float y;
    float z;

public:
    Position(float xVal, float yVal, float zVal) {
        x = xVal;
        y = yVal;
        z = zVal;
    }

    void displayPosition() {
        cout << "Position: (" << x << ", " << y << ", " << z << ")" << endl;
    }
};

class Health {
protected:
    int health;

public:
    Health(int h) {
        health = h;
    }

    void displayHealth() {
        cout << "Health: " << health << endl;
    }
};

class Character : public Position, public Health {
public:
    Character(float xVal, float yVal, float zVal, int h)
        : Position(xVal, yVal, zVal), Health(h) {}

    void display() {
        displayPosition();
        displayHealth();
    }
};

int main() {
    Character hero(10.5, 20.0, 5.5, 85);
    hero.display();
    return 0;
}
