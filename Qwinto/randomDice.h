#include <iostream>
#include <random>

using namespace std;


//helper structure with only static objects to ensure random numbers are uniform distribution
struct RandomDice
{
	static random_device seed_generator;
	static unsigned seed;
	static mt19937 mersenne_generator;
	static uniform_int_distribution<int> distribution;
};

random_device RandomDice::seed_generator;
unsigned RandomDice::seed = seed_generator();
mt19937 RandomDice::mersenne_generator(RandomDice::seed);
uniform_int_distribution<int> RandomDice::distribution(1,6);
