#ifndef __DETAIL_H__
#define __DETAIL_H__

#include "codeword.h"
#include <memory>

namespace detail {

uint64_t inner_product(uint8_t a, uint8_t b);

size_t hamming_distance(const uint64_t a, const uint64_t b);

size_t hamming_distance(const codeword& a, const codeword& b);

} /* namespace detail */

#endif /* __DETAIL_H__ */
