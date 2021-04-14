// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.14
// Filename:        trie.h
// Descripton:       

#ifndef UTILS_TRIE_H
#define UTILS_TRIE_H

#include "structure.h"

#include <string>

using std::string;


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        head_ = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = head_;
        for ( char c : word ) {
            if ( curr->next[c - 'a'] == nullptr ) {
                curr->next[c - 'a'] = new TrieNode();
            }
            curr = curr->next[c - 'a'];
        }
        curr->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = head_;
        for ( char c : word ) {
            if ( curr->next[c - 'a'] == nullptr ) {
                return false;
            }
            curr = curr->next[c - 'a'];
        }
        return curr->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = head_;
        for ( char c : prefix ) {
            if ( curr->next[c - 'a'] == nullptr ) {
                return false;
            }
            curr = curr->next[c - 'a'];
        }
        return true;
    }
private:
    TrieNode* head_;
};

#endif //  UTILS_TRIE_H
