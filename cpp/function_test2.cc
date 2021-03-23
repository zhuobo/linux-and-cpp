// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.22
// Filename:        function_test2.cc
// Descripton:       

#include <functional>
#include <iostream>

typedef std::function<void()> Functor;

class B {
public:
    void setCallback(const Functor& cb) {
        functor = cb;
    }

    void printFunctor() {
        functor();
    }

private:
    Functor functor;
};

class A {
public:
    A(int x_) : x(x_) {
        b.setCallback(std::bind(&addStatic, x, 2));

        b.setCallback(std::bind(&A::add, this, x, 22));
    }

    void print() {
        b.printFunctor();
    }
private:
    void add(int a, int b) {
        std::cout << a + b << std::endl;
    }

    static void addStatic(int a, int b) {
        std::cout << a + b << std::endl;
    }
    B b;
    int x;
};


int main() {
    A a(4);
    a.print();
    return 0;
}

