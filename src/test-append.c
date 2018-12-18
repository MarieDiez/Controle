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
    polygon = polygon_append(polygon,50,50);
    polygon = polygon_insert(polygon,5,10,10);
 

    
    for(int i = 0; i<3 ; i++)
      if (polygon != NULL){
       printf("x : %.2f   y: %.2f\n",polygon->points[i].x,polygon->points[i].y);
      }
     else {
      printf("%d\n",i);
     }
    
   // polygon_destroy(polygon);
   
  }
  
  polygon_finish();
  return EXIT_SUCCESS;
}
