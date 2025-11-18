#include <stdio.h>
#include <stdlib.h>

// my headers
#include "aux.h"

typedef struct {
    int coord[2];
    int maxSize[2];
    enum elementType typeSelected;
} Cursor;

int checkElement(enum elementType element);

Display generateInitialData(int sizeX, int sizeY);

int insertElement(Display display, int x, int y, enum elementType element);

Cursor* generateCursor(int displayX, int displayY);

int insertElementInCursor(Display display, Cursor* cursor);

int updateCursorElement(Cursor* Cursor, enum elementType newElement);

int updateCursorCoords(Cursor* Cursor, int newCoordX, int newCoordY);

int updateCursorMove(Cursor* Cursor, enum arrowDirection direction);

int updateDisplay(Display display, int sizeX, int sizeY);