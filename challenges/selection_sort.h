#ifndef __SELECTION_SORT_H__
#define __SELECTION_SORT_H__

#include <stddef.h>           // size_t
#include "elem_select.h"      // elem_select
#include "swap.h"             // swap

void selection_sort(void* first, void* last, size_t elem_size, int (*bin_pred)(void*, void*)) {
  void* elem;
  while (first != last) {
    elem = elem_select(first, last, elem_size, bin_pred);
    if (elem != first)
      swap(elem, first, elem_size);
    first = (char*)first + elem_size;
  }
}

#endif // __SELECTION_SORT_H__