#include "libs.h"

void mysort(void *first, size_t len, size_t size, int (*comparator_int)(const void *, const void *));
int comparator_int(const void *elem1, const void *elem2);
