// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <mutex>

using namespace std;

int mymain(int argc, char *argv[]) {
    mutex m;
    // m.lock();
    {
        // unique_lock<mutex> l(m, adopt_lock);
        // unique_lock<mutex> l(m, try_to_lock);
        unique_lock<mutex> l(m, defer_lock);
        l.lock();
        std::cout << l.owns_lock() << std::endl;
    }
    m.lock();
    return 0;
}
