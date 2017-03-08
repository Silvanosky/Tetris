#include <time.h>
#include "random.h"

int* generateRandom() 
{
  int* tab = malloc(sizeof (int) * 70);
  for (int i = 0; i < 70; i++)
    tab[i] = i % 7;
	return tab;
}

void swap(int *tab, int a, int b) 
{
  int save = tab[a];
  tab[a] = tab[b];
  tab[b] = save;
}

void shuffle(int *tab)
{
  srand(time(NULL));
  int random; 
  for (int i = 0; i < 70; i++)
	{
    random = i + (int) (rand() % (70 - i)); 
    swap(tab, i, random);
	}
}
