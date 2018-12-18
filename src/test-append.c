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
    
    assert(polygon->points == NULL);
    
    polygon = polygon_append(polygon,5,5);
    polygon = polygon_insert(polygon,-101,10,10);
    polygon = polygon_insert(polygon,100,15,15);
    polygon = polygon_append(polygon,20,20);
     polygon = polygon_insert(polygon,1,0,0);
    
    for(int i = 0; i<5 ; i++)
      printf("x : %.2f   y: %.2f\n",polygon->points[i].x,polygon->points[i].y);
    
    polygon_destroy(polygon);
   
  }
  
  polygon_finish();
  return EXIT_SUCCESS;
}
