/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* banana_internal.h * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* 9 august 2020 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* jordan bonecutter * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef BANANA_INTERNAL_INCLUDE_GUARDS
#define BANANA_INTERNAL_INCLUDE_GUARDS

#include <stdint.h>

/* Constants from orginal MT paper table II 
 * with generator variant MT19937 */

const uint32_t U  = 0x80000000;
const uint32_t LL = 0x7FFFFFFF;
const int      N  = 624;
const int      M  = 397;
const uint32_t a  = 0x9908B0DF;
const int      u  = 11;
const int      s  = 7;
const int      b  = 0x9D2C5680;
const int      t  = 15;
const int      c  = 0xEFC60000;
const int      l  = 18;

typedef struct{
  uint32_t x[N];
  int i;
}banana_random_engine;

#endif

