// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.
// Filename:        
// Descripton:       
#ifndef SMART_PTR
#define SMART_PTR

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

template<typename T>
class smart_ptr {
public:
    smart_ptr(T* ptr = nullptr)
        : ptr_(ptr),
          ref_count_(new int(1)),
          mutex_(new mutex) {

          }

    ~smart_ptr() {
        Release();
    }

    smart_ptr(const smart_ptr<T>& other)
        : ptr_(other.ptr_),
          ref_count_(other.ref_count_),
          mutex_(other.mutex_) {
        AddRefCount();     
    }

    smart_ptr<T>& operator=(const smart_ptr<T>& other) {
        if ( ptr_ == other.ptr_ ) {
            return *this;
        }
        Release();
        ptr_ = other.ptr_;
        ref_count_ = other.ref_count_;
        mutex_ = other.mutex_;
        AddRefCount();
        return *this;
    }


    T& operator*() const {
        return *ptr_;
    }

    T* operator->() const {
        return ptr_;
    }

    int RefCount() const {
        return *ref_count_;
    }

    T* Get() const {
        return ptr_;
    }

    void AddRefCount() {
        mutex_->lock();
        ++(*ref_count_);
        mutex_->unlock();
    }

private:
    void Release() {
        bool delete_flag = false;
        mutex_->lock();
        if ( --(*ref_count_) == 0 ) {
            delete ref_count_;
            delete ptr_;
            delete_flag = true;
        }
        mutex_->unlock();
        if ( delete_flag ) {
            delete mutex_;
        }
    }

    int*    ref_count_;
    T*      ptr_;
    mutex*  mutex_;
};
#endif
