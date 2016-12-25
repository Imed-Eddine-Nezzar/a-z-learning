#ifndef __ELEM_SELECT_H__
#define __ELEM_SELECT_H__

#include <stddef.h>       // size_t

void* elem_select(void* first, void* last, size_t elem_size, int (*bin_pred)(void*, void*)) {
  char* selection = first;
  while (first != last) {
    if (bin_pred(first, selection))
      selection = first;
    first = (char*) first + elem_size;
  }
  return selection;
}

#endif // __ELEM_SELECT_H__
