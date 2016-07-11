#pragma once

#include <iostream>
#include <exception>

class Polygon {
protected:
    int width, height;
public:
    void set_values(int a, int b) {
        width = a; height = b;
    }

    int area() {
        std::cout << "Polygon area";
        throw std::exception("ERROR SHOULD NOT BE CALLED");
        return 0;
    }
};

class Rectangle : public Polygon {
public:
    int area() {
        std::cout << "Rectangle area";
        return width * height;
    }
};

class Triangle : public Polygon {
public:
    int area() {
        std::cout << "Triangle area";
        return width * height / 2;
    }
};

int calculateArea(Polygon &polygon) {
    return polygon.area();
}

int test() {
    Polygon polygon;
    Rectangle rectangle;
    Triangle triangle;

    calculateArea(rectangle);
    calculateArea(triangle);
    calculateArea(polygon);
    return 0;
}