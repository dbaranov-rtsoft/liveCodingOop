#pragma once

#include <iostream>
#include <set>

struct IObserver {
    virtual void notify() = 0;
};

class Button : public IObserver {
public:
    void notify() override {
        std::cout << "Button" << std::endl;
    }
};

class Label : public IObserver {
public:
    void notify() override {
        std::cout << "Label" << std::endl;
    }
};

class UI {
    std::set<IObserver*> clients;

public:
    void Notify() {
        for (auto& client : clients) {
            client->notify();
        }
    }

    void AddClient(IObserver* observer) {
        clients.insert(observer);
    }

    void RemoveClient(IObserver* observer) {
        clients.erase(observer);
    }
};

void test() {

}
