// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.14
// Filename:        trie.h
// Descripton:       

#ifndef UTILS_TRIE_H
#define UTILS_TRIE_H

#include "structure.h"

#include <string>
#include <vector>

using std::string;
using std::vector;


class Trie {
public:
    Trie() {
        head_ = new TrieNode();
    }
    // 插入一个单词，最后一个节点要统计结尾数量
    void Insert(string& word) {
        TrieNode* curr = head_;
        for ( char c : word ) {
            if ( curr->next[c - 'a'] == nullptr ) {
                curr->next[c - 'a'] = new TrieNode();
            }
            curr = curr->next[c - 'a'];
            ++curr->count;
        }
        ++curr->end_count;
    }
    // 删除一个单词，首先查询是否有这个单词
    // 然后逐一减少节点数量，如果节点数量为0，那么可以直接删除节点
    // 最后一个字符对应的节点，数量记得减一
    void Delete(string& word) {
        if ( !Search(word) ) {
            return;
        }
        vector<TrieNode*> to_delete;
        TrieNode* curr = head_;
        for ( char c : word ) {
            TrieNode* next = curr->next[c - 'a'];
            --next->count;
            if ( next->count == 0 ) {
                to_delete.push_back(next);
                // 这里务必置位nullptr,否则容易导致UAF
                curr->next[c - 'a'] = nullptr;
            }
            curr = next;
        }
        --curr->end_count;
        for ( TrieNode* node : to_delete ) {
            delete node;
        }
    }
    // 很普通的查找
    bool Search(string& word) {
        TrieNode* curr = head_;
        for ( char c : word ) {
            if ( curr->next[c - 'a'] == nullptr ) {
                return false;
            }
            curr = curr->next[c - 'a'];
        }
        return curr->end_count > 0;
    }
    // 很普通的查找
    int PrefixNumber(string& word) {
        TrieNode* curr = head_;
        for ( char c : word ) {
            if ( curr->next[c - 'a'] == nullptr ) {
                return 0;
            } else {
                curr = curr->next[c - 'a'];
            }
        }
        return curr->count;
    }
private:
    TrieNode* head_;
};

#endif //  UTILS_TRIE_H
