#include<iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Animal is eating" << endl;
    }

    void sleep() {
        cout << "Animal is sleeping" << endl;
    }
};

// Derived class 1
class Bird : public Animal {
public:
    void fly() {
        cout << "Bird is flying" << endl;
    }
};

// Derived class 2
class Mammal : public Animal {
public:
    void run() {
        cout << "Mammal is running" << endl;
    }
};

int main() {
    // Creating objects of derived classes
    Bird sparrow;
    Mammal dog;

    // Accessing base class functions
    cout << "Bird actions:" << endl;
    sparrow.eat();
    sparrow.sleep();
    sparrow.fly();

    cout << "\nMammal actions:" << endl;
    dog.eat();
    dog.sleep();
    dog.run();

    return 0;
}
