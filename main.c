#include <stdio.h>

#include "array_template.h"

/**
 * This function generates all of the template array functions and types.
 *
 * The first parameter is the name you want to give it. This will expand to
 * int_array.
 *
 * The second parameter is the type. So the internal array in the template
 * array struct will be `int *int_data`
 */
generate_array_template(int, int)

    /**
     * forcing a typedef to the template array type
     * I don't need to do this but it ensures my type will always point to however the array template type generates to. (if I change it)
     */
    typedef array_template_type(int) int_array;

/**
 * Simple example file.
 *
 * TODO have formal unit tests
 */

int main(int argc, const char *argv[]) {
  // instantiate template array
  int_array arr;
  // initatialize it
  init_int_array(&arr, 0);
  printf("cap: %ld\n", arr.cap);
  for (int i = 0; i < 10; ++i) {
    // insert values into the template array
    insert_int_array(&arr, i * 2);
    printf("cap: %ld\n", arr.cap);
  }
  printf("cap: %ld\n", arr.cap);

  for (int i = 0; i < arr.len; ++i) {
    int out = -1;
    // get value from template array
    get_int_array(&arr, i, &out);
    if (out == -1)
      printf("error getting value at index: %d\n", i);
    printf("index: %d, value: %d\n", i, out);
  }

  // free template array
  free_int_array(&arr);
  return 0;
}
