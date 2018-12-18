#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./polygon.h"
#include "./polygon.inc"

static int counter = 0;

bool polygon_init(void){
	
	if (!counter++){
		assert(printf("Polygon initialised\n"));
	}
	return true;
}

bool polygon_finish(void){

	if (counter){
		if (!--counter){
			assert(printf("Polygon finished\n"));
		}
		return true;
	}
	else {
		return false;
	}
}


Polygon* polygon_create(void){
	Polygon * poly = malloc(sizeof(Polygon));
	poly->count=0;
	poly->points=NULL;
	
	return poly;
}

void polygon_destroy(Polygon* polygon){
	free(polygon->points);
	free(polygon);
}

Polygon* polygon_clone(const Polygon* polygon){

	Polygon * dest = malloc(sizeof(Polygon));
	dest= polygon_copy(dest,polygon);
	
	return dest;

}

Polygon* polygon_copy(Polygon* dest, const Polygon* src){
	dest->count=src->count;
	dest->points = malloc(sizeof(Point)*dest->count);
	
	for (int i=0;i<dest->count;i++){
		(dest->points[i]).x=(src->points[i]).x;
		(dest->points[i]).y=(src->points[i]).y;
	}
	
	return dest;
}









