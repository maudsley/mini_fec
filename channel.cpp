#include "channel.h"

channel::channel(const double noise) : noise_(noise), error_count_(0) {
  srand(0x12345678);
}

size_t channel::get_error_count() const {
  return error_count_;
}

void channel::send(const codeword& cw) {
  codeword tx = cw;
  codeword noise = get_noise_vector();
  for (size_t i = 0; i < 4; ++i) {
    tx.bits[i] ^= noise.bits[i]; /* simulate channel errors */
  }
  buffer_.push_back(tx);
}

bool channel::receive(codeword* cw) {
  if (!buffer_.empty() && cw) {
    *cw = buffer_.front();
    buffer_.pop_front();
    return true;
  }
  return false;
}

codeword channel::get_noise_vector() {
  /* introduce a bit flip based on a biased coin toss */
  codeword noise;
  for (size_t i = 0; i < 4; ++i) {
    for (size_t j = 0; j < 64; ++j) {
      double urand = rand() / double(RAND_MAX);
      if (urand < noise_) {
        noise.bits[i] |= uint64_t(1) << j;
        error_count_++;
      }
    }
  }
  return noise;
}
