// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

int mymain(int argc, char* argv[]) {
    auto f = [](auto&&... t) {
        auto y = [](auto& z, auto&& h, auto&&... t) {
            std::cout << h << "\n";
            if constexpr (sizeof...(t) > 0) {
                z(z, t...);
            }
        };
        return y(y, t...);
    };
    f(1, 2, 3, 4, 5, 6);
    return 0;
}
