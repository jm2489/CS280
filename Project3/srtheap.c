#include <stddef.h>
#include <string.h>
#include "srt.h"

void srtheap(void *base, size_t nelem, size_t size, int (*compar)(const void *, const void *)) {
    char *qb = (char *)base;

    // Max heap
    for (size_t i = nelem / 2; i-- > 0;) {
        size_t root = i;

        while (2 * root + 1 < nelem) {
            size_t child = 2 * root + 1;
            if (child + 1 < nelem && compar(qb + child * size, qb + (child + 1) * size) < 0) {
                child++;
            }

            if (compar(qb + root * size, qb + child * size) < 0) {
                swap(qb + root * size, qb + child * size, size);
                root = child;
            } else {
                break;
            }
        }
    }

    // Heap sort
    for (size_t i = nelem - 1; i > 0; --i) {
        swap(qb, qb + i * size, size);

        size_t root = 0;
        while (2 * root + 1 < i) {
            size_t child = 2 * root + 1;
            if (child + 1 < i && compar(qb + child * size, qb + (child + 1) * size) < 0) {
                child++;
            }

            if (compar(qb + root * size, qb + child * size) < 0) {
                swap(qb + root * size, qb + child * size, size);
                root = child; 
            } else {
                break;
            }
        }
    }
}
