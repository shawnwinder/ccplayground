// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <emmintrin.h>
#include <sys/mman.h>

using namespace std;

int mymain(int argc, char *argv[]) {
    auto *map =  (char*) mmap(0, 8192, PROT_READ, MAP_ANON | MAP_PRIVATE, 0, 0);
    mprotect(map + 4096, 10, PROT_NONE);
    // std::cout << map[4095] << std::endl;
    auto x = _mm_loadu_si128(reinterpret_cast<const __m128i *>(map + 4181));
    std::cout << ((int*)(&x))[4] << std::endl;
    // _mm_storeu_si128(reinterpret_cast<__m128i *>(dst),
    //     _mm_loadu_si128(reinterpret_cast<const __m128i *>(src)));
    return 0;
}
