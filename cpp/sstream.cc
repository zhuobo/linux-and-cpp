// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.
// Filename:        
// Descripton:       
#include <sstream>
#include <iostream>
#include <string>


int main() {
    std::string str;
    std::getline(std::cin, str);
    std::istringstream iss(str);
    std::cout << iss.str() << std::endl;

    int ival;
    double dval;
    std::string sval;
    iss >> ival >> dval >> sval;
    std::cout << ival << std::endl;
    std::cout << dval << std::endl;
    std::cout << sval << std::endl;

    std::ostringstream oss;
    oss << 1 << 2.23 << "string" << '\n';
    std::cout << oss.str() << '\n';
}
