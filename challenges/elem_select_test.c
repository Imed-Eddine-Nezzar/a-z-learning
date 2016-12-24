#include <stdio.h>
#include "elem_select.h"

static int int_greater(void* a, void* b) {
  return *(int*)a > *(int*)b;
}

static int int_lesser(void* a, void* b) {
  return *(int*)a < *(int*)b;
}

int main(void) {
  int arr[] = {2, 9, 10, -2, 0, 1, 29, 3};

  int* max = elem_select(arr, 8, sizeof(int), int_greater);
  int* min = elem_select(arr, 8, sizeof(int), int_lesser);

  printf("max: %d\n", *max);
  printf("min: %d\n", *min);
}