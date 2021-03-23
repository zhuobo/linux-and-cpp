// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.
// Filename:        algorithm.h
// Descripton:       

#ifndef UTILS_QUICK_SORT_H
#define UTILS_QUICK_SORT_H
#include <vector>

using std::vector;

template<typename T>
void swap(vector<T>& vec, int i, int j) {
    T temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

/// 
/// 将数组划分为两部分，并返回这个割点的索引
/// 
template<typename T>
int partition(vector<T>& vec, int l, int r) {
    T pivot = vec[l];
    int i = l;
    int j = r;
    while ( i < j ) {
        while ( vec[j] >= pivot && j > i ) --j;
        while ( vec[i] <= pivot && i < j ) ++i;
        swap(vec, i, j);
    }
    swap(vec, l, i);
    return i;
}


template<typename T>
void sort(vector<T>& vec, int l, int r) {
    if ( l < r ) {
        int index = partition(vec, l, r);
        sort(vec, l, index - 1);
        sort(vec, index + 1, r);
    }
}


template<typename T>
void quick_sort(vector<T>& vec) {
    sort(vec, 0, vec.size() - 1);
}

#endif



