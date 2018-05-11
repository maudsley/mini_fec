#ifndef __ENCODER_H__
#define __ENCODER_H__

#include "codeword.h"

class encoder {
public:
  codeword encode(const uint8_t x) const;
};

#endif /* __ENCODER_H__ */
