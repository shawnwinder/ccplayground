// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <ccutils/microbench.hpp>
#include <emmintrin.h>
#include <iostream>
#include <vector>

using namespace std;

inline uint32_t _mm_sum_epu8(const __m128i v) {
    __m128i vsum = _mm_sad_epu8(v, _mm_setzero_si128());
    return _mm_extract_epi16(vsum, 0) + _mm_extract_epi16(vsum, 4);
}

int mymain(int argc, char* argv[]) {
    size_t len = 1 << 25;
    std::vector<uint8_t> data (len, 1);
    uint8_t * array = data.data();
    auto f1 = [&]() {
        size_t cnt = 0;
        const __m128i zero16 = _mm_setzero_si128();
            __m128i count = _mm_setzero_si128();
        for (auto pos = array; pos < array + (len); pos += 64) {
            // for (auto j = 0u; j < 192; ++j) {
            count = _mm_sub_epi8(count, _mm_cmpgt_epi8(_mm_loadu_si128(reinterpret_cast<const __m128i*>(pos)), zero16));
            count = _mm_sub_epi8(count, _mm_cmpgt_epi8(_mm_loadu_si128(reinterpret_cast<const __m128i*>(pos + 16)), zero16));
            count = _mm_sub_epi8(count, _mm_cmpgt_epi8(_mm_loadu_si128(reinterpret_cast<const __m128i*>(pos + 32)), zero16));
            count = _mm_sub_epi8(count, _mm_cmpgt_epi8(_mm_loadu_si128(reinterpret_cast<const __m128i*>(pos + 48)), zero16));
            // }
            // cnt += _mm_sum_epu8(count);
        }
        return cnt;
    };

    auto f2 = [&]() {
        size_t count = 0;
        const __m128i zero16 = _mm_setzero_si128();
        for (auto pos = array; pos < array + (len); pos += 64)
            count += __builtin_popcountll(
                static_cast<uint64_t>(_mm_movemask_epi8(
                    _mm_cmpgt_epi8(_mm_loadu_si128(reinterpret_cast<const __m128i*>(pos)), zero16)))
                | (static_cast<uint64_t>(_mm_movemask_epi8(_mm_cmpgt_epi8(
                       _mm_loadu_si128(reinterpret_cast<const __m128i*>(pos + 16)), zero16)))
                      << 16)
                | (static_cast<uint64_t>(_mm_movemask_epi8(_mm_cmpgt_epi8(
                       _mm_loadu_si128(reinterpret_cast<const __m128i*>(pos + 32)), zero16)))
                      << 32)
                | (static_cast<uint64_t>(_mm_movemask_epi8(_mm_cmpgt_epi8(
                       _mm_loadu_si128(reinterpret_cast<const __m128i*>(pos + 48)), zero16)))
                      << 48));
        return count;
    };

    std::cout << ccutils::microbench<std::chrono::microseconds, 1, 1>([&]() { f1(); }) << endl;
    std::cout << ccutils::microbench<std::chrono::microseconds, 1, 1>([&]() { f2(); }) << endl;
    return 0;
}
