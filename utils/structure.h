#ifndef UTILS_STRUCTRURE_H
#define UTILS_STRUCTRURE_H

///
/// Definition for a binary tree node.
/// 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

///
/// struct ListNode 
/// 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
}; 

///
/// double linked list node
/// 
struct DListNode {
    int         key;
    int         val;
    DListNode*  next;
    DListNode*  prev;
    DListNode() : key(0), val(0), next(nullptr), prev(nullptr) {}
    DListNode(int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) {}
};

/// 
/// Trie Node
///
struct TrieNode {
    bool end;
    TrieNode* next[26];
    TrieNode() : end(false) {
        for ( int i = 0; i < 26; ++i ) {
            next[i] = nullptr;
        }
    }
};


#endif
