#pragma once

#include <iostream>
#include <memory>

struct Drawer {
    virtual void drawPoint(int x, int y) = 0;
};

class OpenGlDrawer : public Drawer {
    virtual void drawPoint(int x, int y) override {
        std::cout << "opengl x=" << x << " y=" << y << std::endl;
    }
};

class DirectX : public Drawer {
    virtual void drawPoint(int x, int y) override {
        std::cout << "directX x=" << x << " y=" << y << std::endl;
    }
};

class Rectangle {
    Drawer &drawer;

public:
    Rectangle(Drawer&& drawer) : drawer(drawer) {
        std::cout << "Rectangle" << std::endl;
    }

    void Draw() {
        std::cout << "draw rectangle" << std::endl;
        drawer.drawPoint(1, 1);
    }
};

void test() {
    OpenGlDrawer drawer;

    Rectangle rectangle(std::move(drawer));
}