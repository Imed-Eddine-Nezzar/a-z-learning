#include <stdio.h>
#include <string.h>
#include "selection_sort.h"

#define __get_arr_size(arr) sizeof((arr)) / sizeof(*(arr))


// string less than
int strcmp_lt(void* a, void* b) { return strcmp(*(char**)a, *(char**)b) < 0; }

// int less than
int int_lt(void* a, void* b) { return *(int*)a < *(int*)b; }

// custom type
typedef struct {
  int fst;
  int snd;
} pair_t;

// pair fst less than
int pair_flt(void* a, void* b) {
  pair_t* fst = a;
  pair_t* snd = b;
  return fst->fst < snd->fst;
}

// pair snd less than
int pair_slt(void* a, void* b) {
  pair_t* fst = a;
  pair_t* snd = b;
  return fst->snd < snd->snd;
}

int main(void) {
  int ints[] = {5, 1, 8, 9, 2, 3};

  printf("sorting ints:\n");
  selection_sort(ints, ints + __get_arr_size(ints), sizeof(int), int_lt);

  for (int i = 0; i < __get_arr_size(ints); ++i)
    printf("%d, ", ints[i]);
  printf("\n");



  char* strings[] = {"one", "two", "three", "four", "five"};

  printf("sorting strings:\n");
  selection_sort(strings, strings + __get_arr_size(strings), sizeof(char*), strcmp_lt);

  for (int i = 0; i < __get_arr_size(strings); ++i)
    printf("%s, ", strings[i]);
  printf("\n");



  pair_t pairs[] = {{3, 1}, {1, 0}, {-2, 7}, {0, 1}, {2, 10}};

  printf("sorting pairs using the first value:\n");
  selection_sort(pairs, pairs + __get_arr_size(pairs), sizeof(pair_t), pair_flt);

  for (int i = 0; i < __get_arr_size(pairs); ++i)
    printf("{%d, %d}, ", pairs[i].fst, pairs[i].snd);
  printf("\n");

  printf("sorting pairs using the second value:\n");
  selection_sort(pairs, pairs + __get_arr_size(pairs), sizeof(pair_t), pair_slt);

  for (int i = 0; i < __get_arr_size(pairs); ++i)
    printf("{%d, %d}, ", pairs[i].fst, pairs[i].snd);
  printf("\n");
}