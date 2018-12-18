#include <stdlib.h>
#include <string.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

#include "./polygon.h"
#include "./polygon.inc"

int main(void) {
  polygon_init();
  {
  
    Polygon* polygon = polygon_create();
    Polygon* polygon1 = polygon_create();
    
    polygon1->count=1;
    polygon1->points = malloc(sizeof(Point)*polygon1->count);
    Point pts;
    pts.x=5;
    pts.y=32;
    
    polygon1->points[0]=pts;
    
    polygon = polygon_copy(polygon,polygon1);
    
    printf("%.2f\n",polygon->points[0].x);
    printf("%.2f\n",polygon->points[0].y);
    
    
    Polygon* polygon3 = polygon_clone(polygon1);
    
    printf(" 3 : %.2f\n",polygon3->points[0].x);
    printf(" 3 : %.2f\n",polygon3->points[0].y);
      
    polygon_destroy(polygon);
     polygon_destroy(polygon3);
    polygon_destroy(polygon1);
    
  }
  polygon_finish();
  return EXIT_SUCCESS;
}
