#ifndef POLYGON_H_
#define POLYGON_H_

#include <stdbool.h>
#include <stdio.h>

typedef struct _Polygon Polygon;

extern bool polygon_init(void);
extern bool polygon_finish(void);

extern Polygon* polygon_create(void);
extern void polygon_destroy(Polygon* polygon);

extern Polygon* polygon_clone(const Polygon* polygon);
extern Polygon* polygon_copy(Polygon* dest, const Polygon* src);

extern Polygon* polygon_append(Polygon* polygon, double x, double y);
extern Polygon* polygon_prepend(Polygon* polygon, double x, double y);
extern Polygon* polygon_insert(Polygon* polygon, int position, double x, double y);
extern Polygon* polygon_remove(Polygon* polygon, int position);

extern unsigned int polygon_count(const Polygon* polygon);
extern double polygon_perimeter(const Polygon* polygon);

extern Polygon* polygon_fwrite(const Polygon* polygon, FILE* stream);
extern Polygon* polygon_fread(Polygon* polygon, FILE* stream);

extern const char* polygon_to_string(const Polygon* polygon);

typedef struct _Point Point;

extern Point* polygon_get(const Polygon* polygon, int position);
extern double point_distance(const Point* point_1, const Point* point_2);
extern double point_get_x(const Point* point);
extern double point_get_y(const Point* point);
extern Point* point_set_x(Point* point, const double x);
extern Point* point_set_y(Point* point, const double y);

#endif  // POLYGON_H_
