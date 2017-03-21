#include "game.h"
#include "score.h"

void computeScore(int *currentScore, int nbLine, int level) {
	switch (nbLine) {
		case 1: 
			*currentScore += 40 * (level + 1);
			break;
		case 2:
			*currentScore += 100 * (level + 1);
			break;
		case 3:
			*currentScore += 300 * (level + 1);
			break;
		case 4:
			*currentScore += 1200 * (level + 1);
			break;
		default:
			break;
	}	
}

void softDrop(int *currentScore) {
	*currentScore += 1;
}

void hardDrop(int* currentScore, int nbLine) {
	*currentScore += nbLine * 2;
}
