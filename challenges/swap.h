#ifndef __SWAP_H__
#define __SWAP_H__

#include <stddef.h>       // size_t
#include <string.h>       // memcpy

void swap(void* a, void* b, size_t n) {
  char tmp[n];
  memcpy(tmp, a, n);
  memcpy(a, b, n);
  memcpy(b, tmp, n);
}

#endif // __SWAP_H__