#ifndef FILE_HEADER_SCORE
#define FILE_HEADER_SCORE

#include <stdlib.h>

void computeScore(int *currentScore, int nbline, int level);

void softDrop(int *currentScore);

void hardDrop(int *currentScore, int nbLine);

#endif 
