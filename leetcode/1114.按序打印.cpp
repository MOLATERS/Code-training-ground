#include <semaphore.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */

// @lc code=start
class Foo {
protected:
    sem_t firstJob;
    sem_t secondJob;

public:
    Foo() {
        sem_init(&firstJob, 0, 0 ) ;
        sem_init(&secondJob, 0, 0 ) ;
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&firstJob);
    }

    void second(function<void()> printSecond) {
        sem_wait(&firstJob);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&secondJob);
    }

    void third(function<void()> printThird) {
        sem_wait(&secondJob);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
// @lc code=end

