// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.28
// Filename:        bubble_sort.h
// Descripton:       

#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

void bubble_sort(vector<int>& ivec) {
    int len = ivec.size();
    for ( int i = 0; i < len - 1; ++i ) {
        for ( int j = i + 1;  j < len; ++j ) {
            if ( ivec[j] < ivec[i] ) {
                swap(ivec[i], ivec[j]);
            }
        }
    }
}


