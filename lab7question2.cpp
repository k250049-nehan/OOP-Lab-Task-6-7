#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape {
protected:
    int x;
    int y;
    string color;
    float borderThickness;

public:
    Shape(int px, int py, string c, float bt) {
        x = px;
        y = py;
        color = c;
        borderThickness = bt;
    }

    virtual void draw() {
        cout << "Drawing Shape at (" << x << ", " << y << ")" << endl;
    }

    virtual double calculateArea() {
        return 0;
    }

    virtual double calculatePerimeter() {
        return 0;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(int px, int py, string c, float bt, double r)
        : Shape(px, py, c, bt) {
        radius = r;
    }

    void draw() {
        cout << "Drawing Circle with radius " << radius << endl;
    }

    double calculateArea() {
        return 3.1416 * radius * radius;
    }

    double calculatePerimeter() {
        return 2 * 3.1416 * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(int px, int py, string c, float bt, double w, double h)
        : Shape(px, py, c, bt) {
        width = w;
        height = h;
    }

    void draw() {
        cout << "Drawing Rectangle of width " << width << " and height " << height << endl;
    }

    double calculateArea() {
        return width * height;
    }

    double calculatePerimeter() {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    double a;
    double b;
    double c;

public:
    Triangle(int px, int py, string col, float bt, double s1, double s2, double s3)
        : Shape(px, py, col, bt) {
        a = s1;
        b = s2;
        c = s3;
    }

    void draw() {
        cout << "Drawing Triangle with sides " << a << ", " << b << ", " << c << endl;
    }

    double calculatePerimeter() {
        return a + b + c;
    }

    double calculateArea() {
        double s = calculatePerimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

class Polygon : public Shape {
private:
    int sides;
    double sideLength;

public:
    Polygon(int px, int py, string col, float bt, int s, double sl)
        : Shape(px, py, col, bt) {
        sides = s;
        sideLength = sl;
    }

    void draw() {
        cout << "Drawing Polygon with " << sides << " sides" << endl;
    }

    double calculatePerimeter() {
        return sides * sideLength;
    }

    double calculateArea() {
        return (sides * sideLength * sideLength) / (4 * tan(3.1416 / sides));
    }
};

int main() {
    Circle c(0, 0, "Red", 1.5, 5);
    Rectangle r(2, 3, "Blue", 2, 4, 6);
    Triangle t(1, 1, "Green", 1, 3, 4, 5);
    Polygon p(5, 5, "Yellow", 1.2, 6, 3);

    c.draw();
    cout << "Area: " << c.calculateArea() << endl;
    cout << "Perimeter: " << c.calculatePerimeter() << endl;

    r.draw();
    cout << "Area: " << r.calculateArea() << endl;
    cout << "Perimeter: " << r.calculatePerimeter() << endl;

    t.draw();
    cout << "Area: " << t.calculateArea() << endl;
    cout << "Perimeter: " << t.calculatePerimeter() << endl;

    p.draw();
    cout << "Area: " << p.calculateArea() << endl;
    cout << "Perimeter: " << p.calculatePerimeter() << endl;

    return 0;
}
