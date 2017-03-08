#ifndef FILE_HEADER_RANDOM
#define	FILE_HEADER_RANDOM

#include <stdlib.h>

int* generateRandom(int size, int cache);

void swap(int* tab, int a, int b);

void shuffle(int* tab);

int getRandom();

#endif 
