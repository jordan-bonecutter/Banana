# Banana
My implementation of the Mersenne Twister for RNG

Banana follows a KISS (Keep it simple, stupid) philosophy. Using an implementation of the Mersenne Twister algorithm it
can generate uniformly distributed integers with an extremely large period. Using banana is simple too. First, you should
create a new random engine by using:

    banana_random_engine* engine = banana_random_engine_create();
 
This function uses a default random seed of 0 (the internal array is initialized using another random engine whose internal array is initialized w/ rand()).
If you would like to provide your own seed, use:

    banana_random_engine* engine = banana_random_engine_create_with_seed(seed);
  
 Or maybe you would like a random engine where it is seeded using the current CPU time, in which case you should use:
 
    banana_random_engine* engine = banana_random_engine_create_with_timed_seed();
  
 In order to get a random 32 bit integer you can use:
    
    banana_random_engine_next_int(engine);
    
For a random number between 0 and 1 use:

    banana_random_engine_next_float(engine);
    
And for a Gaussian Distributed random sample use:

    banana_random_engine_next_gaussian(engine, mean, stddev);
