#include <atomic>
#include <thread>

class Spinlock {
    std::atomic_flag flag;
public:
    Spinlock() : flag(ATOMIC_FLAG_INIT) {}

    void lock() {
        while (flag.test_and_set());
    }

    void unlock() {
        flag.clear();
    }
};