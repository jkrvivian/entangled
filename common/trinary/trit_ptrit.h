/*
 * Copyright (c) 2018 IOTA Stiftung
 * https://github.com/iotaledger/entangled
 *
 * Refer to the LICENSE file for licensing information
 */

#ifndef __COMMON_TRINARY_TRIT_PTRIT_H_
#define __COMMON_TRINARY_TRIT_PTRIT_H_

#include "common/stdint.h"
#include "common/trinary/ptrit_incr.h"
#include "common/trinary/trits.h"

#ifdef __cplusplus
extern "C" {
#endif

void trits_to_ptrits(trit_t const *const trits, ptrit_t *const ptrits, size_t const index, size_t const length);
void trits_to_ptrits_fill(trit_t const *const trits, ptrit_t *const ptrits, size_t const length);
void ptrits_to_trits(ptrit_t const *const ptrits, trit_t *const trits, size_t const index, size_t const length);

#ifdef __cplusplus
}
#endif

#endif  // __COMMON_TRINARY_TRIT_PTRIT_H_
