// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.25
// Filename:        static_assert.cc
// Descripton:       

#include <iostream>

int main() {
    const int num = 2;
    // static_assert failed when compile
    static_assert(num == 1, "num == 1");
    std::cout << "hello world!" << std::endl;
}



