#include "detail.h"

namespace detail {

uint64_t inner_product(uint8_t a, uint8_t b) {
  uint8_t y = a & b;
  y ^= (y >> 4);
  y ^= (y >> 2);
  y ^= (y >> 1);
  return y & 1;
}

size_t hamming_distance(const uint64_t a, const uint64_t b) {
  size_t dist = 0;
  uint64_t sum = a ^ b;
  for (size_t j = 0; j < 64; ++j) {
    dist += (sum >> j) & 1;
  }
  return dist;
}

size_t hamming_distance(const codeword& a, const codeword& b) {
  size_t dist = 0;
  for (size_t i = 0; i < 4; ++i) {
    dist += hamming_distance(a.bits[i], b.bits[i]);
  }
  return dist;
}

} /* namespace detail */
