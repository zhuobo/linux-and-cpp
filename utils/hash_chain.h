// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.28
// Filename:        hash_chain.h
// Descripton:      

#ifndef UTILS_HASH_CHAIN_H
#define UTILS_HASH_CHAIN_H

#include "structure.h"
#include <vector>
#include <iostream>

namespace utils {

class HashChain {
public:
    HashChain() : hash_table_(0), table_len_(0){}

    explicit HashChain(int table_len) 
        : hash_table_(table_len, nullptr),
          table_len_(table_len) {}

    void Insert(ListNode* node) {
        int hash_key = node->val % table_len_;
        node->next = hash_table_[hash_key];
        hash_table_[hash_key] = node;
    }

    bool Search(int val) {
        int hash_key = val % table_len_;
        ListNode* curr = hash_table_[hash_key];
        while ( curr != nullptr ) {
            if ( curr->val == val ) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    ///
    /// 如果有多个，只会移除一个
    /// 
    void Remove(int val) {
        int hash_key = val % table_len_;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        curr->next = hash_table_[hash_key];
        
        while ( curr->next != nullptr ) {
            if ( curr->next->val == val ) {
                ListNode* next = curr->next->next;
                delete curr->next;
                curr->next = next;
                break;
            }
            curr = curr->next;
        }
        hash_table_[hash_key] = dummy->next;
    }

    void Show() {
        for ( int i = 0; i < table_len_; ++i ) {
            ListNode* head = hash_table_[i];
            std::cout << "slot[" << i << "] ";
            while ( head != nullptr ) {
                std::cout << head->val << ' ';
                head = head->next;
            }
            std::cout  << std::endl;
        }
    }

private:
    std::vector<ListNode*> hash_table_;
    int                    table_len_;
};
}

#endif
