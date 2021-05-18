# Template Array

A small header only C file to generate arrays of a given type.

To generate a template array for your type create your header file and include in `array_template.h`.

The following examples will be based on generating a template array for an `int` array with the name `int`.

Example:
```c
#ifndef INT_ARRAY_H
#define INT_ARRAY_H

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

#endif
```

A struct is generated with the format:
```c
typedef struct int_array {
    size_t len;
    size_t cap;
    int *int_data;
} int_array;
```

The functions generated are (all functions are `static inline void`):
- `init_int_array(int_array *arr, size_t N)` for initializing the array.
- `free_int_array(int_array *arr)` for freeing the array.
- `insert_int_array(int_array *arr, int obj)` for inserting values into the array, this handles reallocating.
- `get_int_array(const int_array *arr, size_t index, int *obj)` for getting a value at the given index.


