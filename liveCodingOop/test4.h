#pragma once
#pragma once

#include <iostream>
#include <exception>

class Wireless {
public:
    int wave_;

    void virtual switchOn(const int wave) {
        std::cout << "Wireless wave" << wave;
    }
};

class Receiver : public Wireless {
public:
    void virtual switchOn(const int wave) override {
        std::cout << "Receiver wave" << wave;
    }
};

class Transmitter : public Wireless {
public:
    void virtual switchOn(const int wave) override {
        std::cout << "Transmitter wave" << wave;
    }
};

class Radio : public Receiver, public Transmitter {
public:

    void virtual switchOn(const int wave) override {
        std::cout << "Transmitter wave" << wave;
    }
};

void test() {

}