// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.23
// Filename:        timer.cc
// Descripton:      usage of linux timer


#include <sys/timerfd.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <stdint.h>
#include <iostream>

using namespace std;

constexpr int EPOLL_SIZE = 10;

int main(int argc, char* argv[]) {
    int tfd;
    int epfd;
    int ndfs;

    struct epoll_event event;
    struct epoll_event events[EPOLL_SIZE];

    // 创建timerfd， 非阻塞，绝对时间
    tfd = timerfd_create(CLOCK_REALTIME, TFD_NONBLOCK);
    if ( tfd < 0 ) {
        cerr << "timerfd_create error!" << endl;
        return -1;
    }

    struct timespec start_time;
    struct timespec interval_time;

    start_time.tv_sec = 0;
    start_time.tv_nsec = 1;
    interval_time.tv_sec = 3; // 每3s超时一次
    interval_time.tv_nsec = 0;

    struct itimerspec new_value;
    new_value.it_value = start_time;
    new_value.it_interval = interval_time;

    if ( timerfd_settime(tfd, 0, &new_value, NULL) < 0 ) {
        cerr << "timerfd_settime error" << endl;
        return -1;
    }
    epfd = epoll_create(EPOLL_SIZE);
    if ( epfd < 0 ) {
        cerr << "epoll_create error" << endl;
        return -1;
    }

    event.data.fd = tfd;
    event.events = EPOLLIN;
    if ( epoll_ctl(epfd, EPOLL_CTL_ADD, tfd, &event) < 0 ) {
        cerr << "epoll_ctl error!" << endl;
        return -1;
    }

    uint64_t count = 0;
    while ( 1 ) {
        ndfs = epoll_wait(epfd, events, EPOLL_SIZE, 0);
        if ( ndfs == 0 ) continue;
        for ( int i = 0; i < ndfs; ++i ) {
            if ( events[i].events & EPOLLIN ) {
                uint64_t data;
                read(events[i].data.fd, &data, sizeof(uint64_t));
                count += data;
                cout << "read: " << data << ", timer count: " << count << endl;
            }
        }
    }
    (void)argc;(void)argv;
    return 0;
}
