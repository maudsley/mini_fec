#ifndef __CHANNEL_H__
#define __CHANNEL_H__

#include "codeword.h"
#include <deque>
#include <memory>

class channel {
public:
  channel(const double noise);
  size_t get_error_count() const;
  void send(const codeword& cw);
  bool receive(codeword* cw);
private:
  codeword get_noise_vector();
  std::deque<codeword> buffer_;
  double noise_;
  size_t error_count_;
};

#endif /* __CHANNEL_H__ */
