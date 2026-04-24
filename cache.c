#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csapp.h"
#include "cache.h'

#define MAX_CACHE_SIZE 1049000

void cache_init(CacheList *list) {
  list->size = 0;
  list->first = NULL;
  list->last = NULL;
}

void cache_URL(char *URL, void *item, size_t size, CacheList *list){

}
