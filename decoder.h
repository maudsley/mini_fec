#ifndef __DECODER_H__
#define __DECODER_H__

#include "codeword.h"

class decoder {
public:
  uint8_t decode(const codeword& x) const;
};

#endif /* __DECODER_H__ */
