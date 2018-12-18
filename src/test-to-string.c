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

    assert(strcmp(polygon_to_string(polygon), "[]") == 0);
    
    polygon_append(polygon, 0, 0);
    polygon_append(polygon, 0, 3);
    polygon_append(polygon, 4, 0);

	printf("p = %s\n", polygon_to_string(polygon));
    assert(strcmp(polygon_to_string(polygon), "[(0;0),(0;3),(4;0)]") == 0);

    polygon_destroy(polygon);
  }
  polygon_finish();
  return EXIT_SUCCESS;
}
