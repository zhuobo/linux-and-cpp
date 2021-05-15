// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.
// Filename:        
// Descripton:       
#include <iostream>
using namespace std;

template<int N>
struct Fib{
    enum { result = Fib<N - 1>::result + Fib<N - 2>::result };
};

template<>
struct Fib<0> {
    enum { result = 0 };
};

template<>
struct Fib<1> {
    enum { result = 1 };
};

int main() {
    int i = Fib<3>::result;
    cout << i << endl;
}

