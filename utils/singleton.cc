// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.26
// Filename:        singleton.h
// Descripton:      实现一个单例模式 
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

///
/// 懒汉模式：第一次调用才创建实例
/// 

#include <iostream>
#include <thread>
#include <mutex>

/// 懒汉模式，第一次调用才会生成一个单例
/// c++11以后，编译器可以保证静态局部变量的线程安全性，利用静态局部变量的线程安全性
/// 可以实现线程安全的Singleton。
/// 存在的问题：局部静态变量先于全局静态变量析构，考虑这样的场景：存在一个全局静态
/// 变量，这个全局静态变量的析构函数使用了这个单例，此时这个单例肯定已经被析构，因
/// 会UAF。
/// 解决方法：规定全局静态变量的析构函数不要使用单例的实例
class Singleton {
public:
    static Singleton& Instance() {
        static Singleton instance_;
        return instance_;
    }
    ~Singleton()=default;

private:
    Singleton()=default;
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
};

void* thread_fun1(void* arg) {
    Singleton& singleton = Singleton::Instance();
    std::cout << &singleton << std::endl;
    (void)arg;
    return nullptr;
}

void* thread_fun2(void* arg) {
    Singleton& singleton = Singleton::Instance();
    std::cout << &singleton << std::endl;
    (void)arg;
    return nullptr;
}

int main() {
    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1, nullptr, thread_fun1, nullptr);
    pthread_create(&t2, nullptr, thread_fun2, nullptr);
    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);
    return 0;
}
