#include <iostream>

class Animal {
    public:
    virtual void speak() {
        std::cout << "Animal speaks" << std::endl;
    }
};
class Dog : public Animal {
    public:
    void speak() {
        std::cout << "Dog speaks" << std::endl;
    }
};

static int add (int a, int b) {
    return a + b;
}

static int add (int a, int b, int c, int d) {
    return a + b + c + d;
}

int main() {
    Animal* animal = new Dog();
    animal->speak();
    delete animal;// free memory

    std::cout << "Fuction overloading test: " << std::endl;

    std::cout << "add(2, 3) = " << add(2, 3) << std::endl;
    std::cout << "add(2, 5) = " << add(2, 5) << std::endl;
    std::cout << "add(2, 3, 4, 5) = " << add(2, 3, 4, 5) << std::endl;

    return 0;
}