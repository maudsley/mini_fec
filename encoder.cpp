#include "encoder.h"
#include "detail.h"

codeword encoder::encode(const uint8_t x) const {
  codeword y;
  for (size_t i = 0; i < 4; ++i) {
    for (size_t j = 0; j < 64; ++j) {
      uint64_t bit = detail::inner_product(i * 64 + j, x);
      y.bits[i] |= bit << j;
    }
  }
  return y;
}
