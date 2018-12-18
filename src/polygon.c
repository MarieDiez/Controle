#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
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

Polygon* polygon_prepend(Polygon* polygon, double x, double y){
	Point pts;
	pts.x = x;
	pts.y = y;
	Point *tabPoints = polygon->points;
	polygon->count += 1;
	polygon->points = malloc(sizeof(Point)*(polygon->count));
	if (polygon->points){
		polygon->points[0] = pts;
		for(int i = 1; i < polygon->count; i++){
			polygon->points[i] = tabPoints[i-1];
		}
		free(tabPoints);
	}
	return polygon;
}

Polygon* polygon_insert(Polygon* polygon, int position, double x, double y){
	if (position < 0){	
		position = (int)polygon->count - position +1 ;		
	}
	if (abs(position) > (int)polygon->count){
		return NULL;
	}

	Point pts;
	pts.x = x;
	pts.y = y;
	Point *tabPoints = polygon->points;
	polygon->count += 1;
	polygon->points = malloc(sizeof(Point)*(polygon->count));
	if (polygon->points){

		for(int i = 0; i < position; i++){
			polygon->points[i] = tabPoints[i];
		}

		polygon->points[position] = pts;

		for(int i = position+1; i < polygon->count; i++){
			polygon->points[i] = tabPoints[i-1];
		}

		free(tabPoints);
	}
	return polygon;

}

Polygon* polygon_append(Polygon* polygon, double x, double y){
	return polygon_insert(polygon,polygon->count,x,y);
}



Polygon* polygon_remove(Polygon* polygon, int position){
	if (position <0 ){
		position = ((int)polygon->count)+position;
	}
	if (abs(position) > (int)polygon->count){
		return NULL;
	}

	Point * tabPoints = malloc(sizeof(Point)*polygon->count-1);
	for (int i=0;i<position;i++){
		tabPoints[i]=polygon->points[i];
	}
	for (int i=position;i<polygon->count;i++){
		tabPoints[i]=polygon->points[i+1];
	}
	free(polygon->points);
	polygon->points=tabPoints;
	return polygon;
}

unsigned int polygon_count(const Polygon* polygon){
	return polygon->count;
}
/*
Point* polygon_get(const Polygon* polygon, int position){
	if (position <0 ){
		position = ((int)polygon->count)+position;
	}

	return &polygon->points[position];
}

double point_get_x(const Point* point){
	return point->x;
}
double point_get_y(const Point* point){
	return point->y;
}
Point* point_set_x(Point* point, const double x){
	point->x=x;
}
Point* point_set_y(Point* point, const double y){
	point->y=y;
}

double point_distance(const Point* point_1, const Point* point_2){
	double sum = abs(point_1->x-point_1->y) +  abs(point_2->x-point_2->y);
	return sqrt(sum);	
}*/
/*

double polygon_perimeter(const Polygon* polygon){
	double somme=0;
	for (int i =0 ; i<polygon->count-1;i++){
		somme+=point_distance(polygon->points[i],polygon->points[i+1]);
	}
	somme+=point_distance(polygon->points[polygon->count],polygon->points[0]);

	return somme;
}
*/
Polygon* polygon_fwrite(const Polygon* polygon, FILE* stream){

	if (fwrite(&polygon->count,sizeof(unsigned int),1,stream)==1 && fwrite(polygon->points,sizeof(Point),polygon->count,stream)==polygon->count){
		return (Polygon*)polygon;
	}
	else {
		return NULL;
	}
}

Polygon* polygon_fread(Polygon* polygon, FILE* stream){
	int count;
	if(fread(&count,sizeof(unsigned int),1,stream) == 1 ){
		Point * points = malloc(count * sizeof(Point));
		if (points){
			if(fread(points,sizeof(Point),count,stream) != count){
				return NULL;
			}
			free(polygon->points);
			polygon->count = count;
			polygon->points = points;
			return (Polygon*)polygon;
		}else{
			return NULL;
		}
	}else{
		return NULL;
	}

}

const char* polygon_to_string(const Polygon* polygon){
	static char ch[100];
	sprintf(ch,"%s","[");
	for(int i = 0 ; i < polygon->count ; i++){
		if(i < polygon->count-1){
			sprintf(ch,"%s(%g;%g)",ch,polygon->points[i].x,polygon->points[i].y);
		}
		if(i == polygon->count-1){
			sprintf(ch,"%s,",ch);
		}
	}
	sprintf(ch,"%s]",ch);
	return ch;	
}









