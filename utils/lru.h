// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.04.
// Filename:        
// Descripton:       

#ifndef UTILS_LRU_H
#define UTILS_LRU_H

#include "structure.h"

#include <unordered_map>

using std::unordered_map;

class LRUCache {
public:
    LRUCache(int capacity) : size_(0), capacity_(capacity) {
        head_ = new DListNode();
        tail_ = new DListNode();
        head_->next = tail_;
        tail_->prev = head_;
    }

    int Get(int key);

    void Put(int key, int val);

private:
    void AddToHead(DListNode* node);

    void RemoveNode(DListNode* node);

    void MoveToHead(DListNode* node);

    DListNode* RemoveTail();

    unordered_map<int, DListNode*> cache_;
    DListNode*                     head_;
    DListNode*                     tail_;
    int                            size_;
    int                            capacity_;
};

int LRUCache::Get(int key) {
    if ( cache_.find(key) == cache_.end() ) {
        return -1;
    }
    DListNode* node = cache_[key];
    MoveToHead(node);
    return node->val;
}

void LRUCache::Put(int key, int val) {
    if ( cache_.find(key) == cache_.end() ) {
        // 不存在，创建一个节点
        DListNode* node = new DListNode(key, val);
        cache_[key] = node;
        AddToHead(node);
        ++size_;
        if ( size_ > capacity_ ) {
            DListNode* removed_node = RemoveTail();
            cache_.erase(removed_node->key);
            delete removed_node;
            --size_;
        }
    } else {
        DListNode* node = cache_[key];
        node->val = val;
        MoveToHead(node);
    }
}

void LRUCache::AddToHead(DListNode* node) {
    node->prev = head_;
    node->next =head_->next;
    head_->next->prev = node;
    head_->next = node;
}

void LRUCache::RemoveNode(DListNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void LRUCache::MoveToHead(DListNode* node) {
    RemoveNode(node);
    AddToHead(node);
}

DListNode* LRUCache::RemoveTail() {
    DListNode* node = tail_->prev;
    RemoveNode(node);
    return node;
}

#endif //  UTILS_LRU_H
