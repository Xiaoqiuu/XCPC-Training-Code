#include <iostream>
#include <mutex>

using std::cin;
using std::cout;

#define akitama return 0

class Singleton {
    static Singleton* instance_;
    static std::mutex mutex_;
    Singleton(){};
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    public:
    static Singleton* getInstance() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (instance_ == nullptr) {
            instance_ = new Singleton();
        }
        return instance_;
    }
};


signed main() {
    akitama;
}