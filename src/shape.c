#include "shape.h"

void createShape(shape* shape, size_t w, size_t h, int data[])
{
	shape->w = w;
	shape->h = h;
	shape->form = malloc(w*h * sizeof(int));
	for(size_t i = 0; i < w*h; i++)
	{
		shape->form[i] = data[i];
	}
}

shape** getShape(size_t id)
{
	static shape*** data = NULL;
	if(!data)
	{
		data = malloc(2 * sizeof(shape**));
		int i = 1, j = 0;
		data[i] = malloc(2 * sizeof(shape*));
		int a[] = {1, 1, 1, 1};
		createShape(data[i][j++], 1, 4, a);
		createShape(data[i++][j++], 4, 1, a);
	}

	return data[id];
}
