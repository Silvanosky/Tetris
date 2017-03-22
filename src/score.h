#ifndef FILE_HEADER_SCORE
#define FILE_HEADER_SCORE

#include <stdlib.h>
#include <err.h>
#include <stdio.h>

void computeScore(int *currentScore, int nbline, int level);

void softDrop(int *currentScore);

void hardDrop(int *currentScore, int nbLine);

struct s_tuple {
	char *name;
	int size;
	int score;
};
typedef struct s_tuple tuple; 

void saveScore (tuple **scoreTab, char *name, int size, int score);

tuple** loadScore();

#endif 
