#include <stdlib.h>
#include <stdio.h>
#include <utils/vector.h>

/*
Usage of vector:

typedef struct {
    int num1;
    int num2;
} object_t;

//allocate chunk of memory for object
int amt_obj = 1;
object_t *ptr_to_obj = (object_t *)malloc(sizeof(object_t)*amt_obj);

//make vector and add our object
vector_t vector = vector();
vector_add(&vector, ptr_to_obj);
//this will also free our object. see note in vector_free() for more info.
vector_free(&vector, 1);

---------------------------------------

*/

void vector_init(vector_t *vec) {
    vec->sz = VEC_START_SZ;
    vec->used = 0;
    vec->items = malloc(sizeof(void *)*vec->sz);
    vec->freed = 0;
}

unsigned char vector_freed(vector_t *vec) {
    if (vec->freed == 1) {
        printf("vector with size %d does not exist!\n", vec->sz);
        return 1;
    }
    return 0;
}

void vector_resize(vector_t *vec, int sz) {
    //printf("resizing from %d to %d\n", vec->sz, sz);
    void **items = realloc(vec->items, sizeof(void *)*sz);
    if (items) {
        vec->items = items;
        vec->sz = sz;
    }
}

void vector_add(vector_t *vec, void *item) {
    if (vector_freed(vec)) return;

    if (vec->sz == vec->used) {
        vector_resize(vec, vec->sz*2);
    }
    vec->items[vec->used++] = item;
}

void vector_set(vector_t *vec, int index, void *item) {
    if (vector_freed(vec)) return;
    
    if (index >= 0 && index < vec->used) {
        vec->items[index] = item;
    }
}

void *vector_get(vector_t *vec, int index) {
    if (vector_freed(vec)) return NULL;
    
    if (index >= 0 && index < vec->used) {
        return vec->items[index];
    }
    return NULL;
}

unsigned char vector_cat(vector_t *dest, vector_t *vec) {
    int vec_len = vec->used;
    int i;
    void *vec_info;
    for (i = 0; i < vec_len; i++) {
        vec_info = vector_get(vec, i);
        if (vec_info == NULL) return VECTOR_FAIL;
        vector_add(dest, vec_info);
    }
    return VECTOR_OK;
}

void vector_remove(vector_t *vec, int index) {
    if (vector_freed(vec)) return;
    
    if (index < 0 || index >= vec->used) {
        return;
    }
    vec->items[index] = NULL;
    int i;
    for (i = index; i < vec->used-1; i++) {
        vec->items[i] = vec->items[i+1];
        vec->items[i+1] = NULL;
    }
    vec->used--;
    if (vec->used > 0 && vec->used == vec->sz/4) {
        vector_resize(vec, vec->sz/2);
    }
}

void vector_free_items(vector_t *vec) {
    int i;
    for (i = 0; i < vec->used; i++) {
        free(vector_get(vec, i));
    }
}

void vector_free(vector_t *vec, unsigned char free_data) {
    /*---WARNING---
      DO NOT use free_data if there are multiple
      allocations in one vector_add(). e.x

      typedef struct {
        char *str;
        int num;
      } data_t;

      ...

      vector_add(&your_vector, data);

      ---DO NOT---
      vector_free(&your_vector, 1);

      ---DO---
      int i;
      void *temp_data;
      for (i = 0; i < your_vector->used; i++) {
        //free any allocated objects first
        temp_data = vector_get(&your_vector, i);
        free(temp_data->str);
        //free the actual memory containing object
        free(temp_data);
      }
      //finally, free the vector.
      vector_free(&your_vector, 0);

      freeing the object with vector_free() shall only be used for structures such as:

      typedef struct {
        int num1;
        int num2;
      } data;
    */


    if (vec->freed == 1)  {
        printf("vector of size %d has already been freed!\n", vec->sz);    
        return;
    }
    if (free_data) {
        vector_free_items(vec);
    }

    free(vec->items);
    vec->freed = 1;
}