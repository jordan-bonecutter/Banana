/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* banana_radnom_engine.c  * * * * * * * * * * * * * * * * * * * * * * * * */
/* 9 august 2020 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* jordan bonecutter * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "banana_internal.h"
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>

/* initialize state array */
banana_random_engine* banana_random_engine_create_with_seed(int seed){
  banana_random_engine* ret = malloc(sizeof *ret);
  uint32_t* j;
  
  srand(seed);
  for(j = (uint32_t*)ret->x; j != (((uint32_t*)ret->x) + N); ++j){
    *j = rand();
  }
  ret->i = 0;

  return ret;
}

banana_random_engine* banana_random_engine_create(){
  return banana_random_engine_create_with_seed(0);
}

/* use clock() to get a time based seed */
banana_random_engine* banana_random_engine_create_with_timed_seed(){
  return banana_random_engine_create_with_seed((int)clock());
}

/* since bre's don't allocate any data, you only need to free them */
void banana_random_engine_destroy(banana_random_engine* engine){
  free(engine);
}

/* do 1 iteration of mersenne twister algorithm */
int banana_random_engine_next_int(banana_random_engine* engine){
  int i = engine->i;
  uint32_t *x = (uint32_t*)engine->x + i;
  uint32_t y = ((*x)&U) | ((*x)&LL);

  *x = ((x - i)[(i+M)%N]) ^ (y>>1) ^ ((y & 1)? a : 0);
  y = *x;
  y ^= y>>u;
  y ^= (y<<s)&b;
  y ^= (y<<t)&c;
  y ^= y>>l;

  i = (i+1)%N;

  return y; 
}

/* genereate a 32 bit int using MT and normalize it */
double banana_random_engine_next_float(banana_random_engine* engine){
  unsigned int nextint = banana_random_engine_next_int(engine);
  double val = nextint / (double)(0xFFFFFFFF);
  return val;
}

/* de normalize result from float */
double banana_random_engine_next_float_in_range(banana_random_engine* engine, float lo, float hi){
  return (double)(banana_random_engine_next_float(engine)*(hi-lo) + lo);
}

// TODO: Don't use Box–Muller transform cause apparently it sucks :(
/* use Box-Muller algorithm to transform a uniform rv to a gaussian rv */
double banana_random_engine_next_gaussian(banana_random_engine* engine, float mean, float std_dev){
  double u1, u2;
  u1 = DBL_EPSILON;

  while(u1 == DBL_EPSILON){
    u1 = banana_random_engine_next_float(engine);
    u2 = banana_random_engine_next_float(engine);
  }

  double normal_gaussian = sqrt(-2. * log(u1)) * cos(2. * M_PI * u2);
  return normal_gaussian*std_dev + mean;
}

#ifdef BANANA_RANDOM_ENGINE_UNIT_TEST

#define TESTITERS 1000000
#include <stdio.h>

int main(){
  banana_random_engine* engine = banana_random_engine_create_with_timed_seed();
  int array[100] = {0};
  int i;
  double result;

  for(i = 0; i < TESTITERS; ++i){
    result = banana_random_engine_next_gaussian(engine, 0.5, 0.2);
    if(result < 0 || result > 1){
      continue;
    }
    ++array[(int)(result*100)];
  }

  for(i = 0; i < 100; ++i){
    printf("%d\n", array[i]);
  }

  banana_random_engine_destroy(engine);
}

#endif

