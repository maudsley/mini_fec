#include "decoder.h"
#include "encoder.h"
#include "detail.h"

uint8_t decoder::decode(const codeword& x) const {
  uint8_t y;
  size_t y_dist = ~size_t(0);
  encoder enc;
  for (size_t i = 0; i < 256; ++i) {
    size_t dist = detail::hamming_distance(enc.encode(i), x);
    if (dist < y_dist) {
      y = uint8_t(i);
      y_dist = dist;
    }
  }
  return y;
}
