// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.
// Filename:        
// Descripton:       
#ifndef UTILS_QUEUE_USING_STACK_H
#define UTILS_QUEUE_USING_STACK_H

#include <stack>
#include <iostream>

using std::stack;

template <typename T>
class QueueUsingStack {
public:
    QueueUsingStack() = default;

    bool Empty() {
        return stk1_.empty() && stk2_.empty();
    }

    int Size() {
        return stk1_.size() + stk2_.size();
    }

    void Push(T t) {
        stk1_.push(t);
    }

    void Pop() {
        if ( Empty() ) {
            return;
        }
        if ( stk2_.empty() ) {
            Move(stk1_, stk2_);
        }
        T ret = stk2_.top();
        stk2_.pop();
    }

    T Front() {
        try {
            if ( Empty() ) {
                throw "Front with an empty queue";
            }
        } catch ( const char* msg ) {
            std::cout << msg << std::endl;
        }
        if ( stk2_.empty() ) {
            Move(stk1_, stk2_);
        }
        return stk2_.top();
    }

private:
    void Move(stack<T>& stk1, stack<T>& stk2) {
        while ( !stk1.empty() ) {
            T t = stk1.top();
            stk1.pop();
            stk2.push(std::move(t));
        }
    }

    stack<T> stk1_;
    stack<T> stk2_;
};
#endif //  UTILS_QUEUE_USING_STACK_H 
