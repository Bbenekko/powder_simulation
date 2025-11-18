#include <stdio.h>
#include <stdlib.h>

// my headers
#include "aux.h"

typedef struct {
    int coord[2];
    int maxSize[2];
    enum elementType typeSelected;
} Cursor;