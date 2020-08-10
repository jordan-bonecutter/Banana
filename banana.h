/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* banana.h  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* 9 august 2020 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* jordan bonecutter * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef BANANA_INCLUDE_GUARDS
#define BANANA_INCLUDE_GUARDS

typedef void banana_random_engine;

banana_random_engine* banana_random_engine_create(void);
banana_random_engine* banana_random_engine_create_with_seed(int seed);
banana_random_engine* banana_random_engine_create_with_timed_seed();
void banana_random_engine_destroy(banana_random_engine* engine);

int   banana_random_engine_next_int(banana_random_engine* engine);
int   banana_random_engine_next_int_in_range(banana_random_engine* engine, int lo, int hi);
double banana_random_engine_next_float(banana_random_engine* engine);
double banana_random_engine_next_float_in_range(banana_random_engine* engine, float lo, float hi);
double banana_random_engine_next_gaussian(banana_random_engine* engine, float mean, float std_dev);

#endif

