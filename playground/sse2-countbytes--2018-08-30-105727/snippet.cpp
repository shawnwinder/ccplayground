// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <emmintrin.h>
#include <iostream>

using namespace std;

int mymain(int argc, char* argv[]) {
    const __m128i zero16 = _mm_setzero_si128();
    uint8_t pos[64] =  {1,1,1,0,0};
    auto cnt = __builtin_popcountll(
        static_cast<uint64_t>(_mm_movemask_epi8(
            _mm_cmpgt_epi8(_mm_loadu_si128(reinterpret_cast<const __m128i*>(pos)), zero16)))
        | (static_cast<uint64_t>(_mm_movemask_epi8(
               _mm_cmpgt_epi8(_mm_loadu_si128(reinterpret_cast<const __m128i*>(pos + 16)), zero16)))
              << 16)
        | (static_cast<uint64_t>(_mm_movemask_epi8(
               _mm_cmpgt_epi8(_mm_loadu_si128(reinterpret_cast<const __m128i*>(pos + 32)), zero16)))
              << 32)
        | (static_cast<uint64_t>(_mm_movemask_epi8(
               _mm_cmpgt_epi8(_mm_loadu_si128(reinterpret_cast<const __m128i*>(pos + 48)), zero16)))
              << 48));
    std::cout << cnt << std::endl;
    return 0;
}
