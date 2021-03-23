// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.22
// Filename:        function_test.cc
// Descripton:      std::function testing

#include <iostream>
#include <functional>

using namespace std;

std::function<int(int)> functor;

int TestFunc(int a) {
    return a;
}

auto lambda = [](int a)->int{return a;};

class A {
public:
    int operator()(int a) {
        return a;
    }
};

class B {
public:
    int ClassMember(int a) {
        return a;
    }

    static int StaticMember(int a) {
        return a;
    }
};

int main() {
    functor = TestFunc;
    cout << functor(3) << endl;

    functor = lambda;
    cout << functor(4) << endl;

    A a;
    functor = a;
    cout << functor(5) << endl;

    B b;
    functor = std::bind(&B::ClassMember, b, std::placeholders::_1);
    cout << functor(6) << endl;

    functor = B::StaticMember;
    cout << functor(7) << endl;
}

