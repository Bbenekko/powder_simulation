#include "engine.h"

/* ============================ AUXILIARY ==========================================*/
int checkElement(enum elementType element) 
{
    switch (element) 
    {
        case typeAir:
        case typeSand:
        case typeWater:
        case typeWood:
            return SUCESS; // Valid
        default:
            //TODO error message in validating element
            return FAILURE; // Invalid
    }
}

/* ============================ ######## ==========================================*/
Display generateInitialData(int sizeX, int sizeY)
{
    Display display = (Display)malloc(sizeX * sizeof(int*));
    if (display == NULL) return NULL; // TODO add error when return NULL

    for(int i = 0; i < sizeX; i++)
    {
        display[i] = (int*)malloc(sizeY * sizeof(int));
        if (display[i] == NULL) return NULL; // TODO same

        // preenche o display com ar
        for(int j = 0; j < sizeY; j++)
        {
            display[i][j] = typeAir;
        }
    }

    return display;
}

int insertElement(Display display, int x, int y, enum elementType element)
{
    if (checkElement(element))
    {
        display[x][y] = element;
        return SUCESS;
    }
    else
    {
        return FAILURE;
    }
}

/* ============================ CURSOR ==========================================*/
Cursor* generateCursor(int displayX, int displayY)
{
    Cursor* newCursor = (Cursor*)malloc(sizeof(Cursor));

    if (newCursor == NULL)
    {
        // TODO print error
        return NULL;
    }

    newCursor->coord[0] = 0;
    newCursor->coord[1] = 0;
    newCursor->maxSize[0] = displayX;
    newCursor->maxSize[1] = displayY;
    newCursor->typeSelected = typeAir;

    return newCursor;
}

int insertElementInCursor(Display display, Cursor* cursor)
{
    if (checkElement(cursor->typeSelected))
    {
        display[cursor->coord[0]][cursor->coord[1]] = cursor->typeSelected;
        return SUCESS;
    }
    else
    {
        return FAILURE;
    }
}

int updateCursorElement(Cursor* Cursor, enum elementType newElement)
{
    if (checkElement(newElement))
    {
        Cursor->typeSelected = newElement;
        return SUCESS;
    }
    else
    {
        return FAILURE;
    }
}

int updateCursorCoords(Cursor* Cursor, int newCoordX, int newCoordY)
{
    if(newCoordX > Cursor->maxSize[0] || newCoordX < 0 || newCoordY > Cursor->maxSize[1] || newCoordY < 0)
    {
        // TODO print error message
        return FAILURE;
    }
    else
    {
        Cursor->coord[0] = newCoordX;
        Cursor->coord[1] = newCoordY;
        return SUCESS;
    }
}

int updateCursorMove(Cursor* Cursor, enum arrowDirection direction)
{
    switch (direction)
    {
    case arrowUp:
        if(Cursor->coord[1] - 1 >= 0)
        {
            Cursor->coord[1] -= 1;
            return SUCESS;
        }
    case arrowRight:
        if(Cursor->coord[0] + 1 <= Cursor->maxSize[0])
        {
            Cursor->coord[0] += 1;
            return SUCESS;
        }
    case arrowDown:
        if(Cursor->coord[1] + 1 <= Cursor->maxSize[1])
        {
            Cursor->coord[1] += 1;
            return SUCESS;
        }
    case arrowLeft:
        if(Cursor->coord[0] - 1 >= 0)
        {
            Cursor->coord[0] -= 1;
            return SUCESS;
        }

    default:
        // TODO error code
        return FAILURE;
    }
}

/* ============================ UPDATES ==========================================*/
int updateDisplay(Display display, int sizeX, int sizeY)
{
    for(int i = sizeX - 2; i > 0; i--)
    {
        for(int j = sizeY - 2; j > 0; j--)
        {
            switch(display[i][j])
            {
                case typeAir:
                // ignora

                return SUCESS;

                case typeSand:

                // checa element abaixo
                if(display[i][j+1] == typeAir)
                {
                    display[i][j] = typeAir;
                    display[i][j+1] = typeSand;
                } 
                else if (display[i][j+1] == typeSand || display[i][j+1] == typeWood)
                {
                    if (rand() % 2) // esquerda direita
                    {
                        // checa os casos de ar
                        if (i > 0 && display[i-1][j+1] == typeAir)
                        {
                            display[i][j] = typeAir;
                            display[i-1][j+1] == typeSand;
                        }
                        else if (i < (sizeX - 1) && display[i+1][j+1] == typeAir)
                        {
                            display[i][j] = typeAir;
                            display[i+1][j+1] == typeSand;
                        }
                        // checa os casos de água
                        else if (i > 0 && display[i-1][j+1] == typeWater)
                        {
                            display[i][j] = typeWater;
                            display[i-1][j+1] == typeSand;
                        }
                        else if (i < (sizeX - 1) && display[i+1][j+1] == typeWater)
                        {
                            display[i][j] = typeWater;
                            display[i+1][j+1] == typeSand;
                        }
                        else
                        {
                            // TODO erro colorido de vermelho (erro na checagem de typeSand)
                            return FAILURE;
                        }
                    }
                    else // direita esquerda
                    {
                        // caso ar
                        if (i < (sizeX - 1) && display[i+1][j+1] == typeAir)
                        {
                            display[i][j] = typeAir;
                            display[i-1][j+1] == typeSand;
                        }
                        else if (i > 0 && display[i-1][j+1] == typeAir)
                        {
                            display[i][j] = typeAir;
                            display[i+1][j+1] == typeSand;
                        }
                        // caso água
                        else if (i < (sizeX - 1) && display[i+1][j+1] == typeWater)
                        {
                            display[i][j] = typeWater;
                            display[i-1][j+1] == typeSand;
                        }
                        else if (i > 0 && display[i-1][j+1] == typeWater)
                        {
                            display[i][j] = typeWater;
                            display[i+1][j+1] == typeSand;
                        }
                        else
                        {
                            // TODO erro colorido de vermelho (erro na checagem de typeSand)
                            return FAILURE;
                        }
                    }
                }
                else if (display[i][j+1] == typeWater)
                {
                    display[i][j] = typeAir;
                    display[i][j+1] = typeWater;
                }     
                    
                return SUCESS;

                case typeWater:

                //checa element abaixo
                if(display[i][j+1] == typeAir)
                {
                    display[i][j] = typeAir;
                    display[i][j+1] = typeWater;
                } 
                else // type = typeWater || typeWood || typeSand
                {
                    // checa as diaonais primeiro
                    if (rand() % 2) // esquerda direita
                    {
                        // checa os casos de ar
                        if (i > 0 && display[i-1][j+1] == typeAir)
                        {
                            display[i][j] = typeAir;
                            display[i-1][j+1] == typeWater;
                        }
                        else if (i < (sizeX - 1) && display[i+1][j+1] == typeAir)
                        {
                            display[i][j] = typeAir;
                            display[i+1][j+1] == typeWater;
                        }
                        else if (i > 0 && display[i-1][j] == typeAir)
                        {
                            display[i][j] = typeAir;
                            display[i-1][j] = typeWater;
                        }
                        else if (i < (sizeX - 1) && display[i+1][j] == typeAir)
                        {
                            display[i][j] = typeAir;
                            display[i+1][j] = typeWater;
                        }
                        else
                        {
                            // TODO erro colorido de vermelho (erro na checagem de typeWater)
                            return FAILURE;
                        }
                    }
                    else // direita esquerda
                    {
                        // caso ar
                        if (i < (sizeX - 1) && display[i+1][j+1] == typeAir)
                        {
                            display[i][j] = typeAir;
                            display[i-1][j+1] == typeWater;
                        }
                        else if (i > 0 && display[i-1][j+1] == typeAir)
                        {
                            display[i][j] = typeAir;
                            display[i+1][j+1] == typeWater;
                        }
                        else if (i < (sizeX - 1) && display[i+1][j] == typeAir)
                        {
                            display[i][j] = typeAir;
                            display[i+1][j] = typeWater;
                        }
                        else if (i > 0 && display[i-1][j] == typeAir)
                        {
                            display[i][j] = typeAir;
                            display[i-1][j] = typeWater;
                        }
                        else
                        {
                            // TODO erro colorido de vermelho (erro na checagem de typeWater)
                            return FAILURE;
                        }
                    }
                }
                
                return SUCESS;

                case typeWood:
                // ignora

                return SUCESS;

                default:
                // TODO erro colorido de vermelho (element type inválido)
                return FAILURE; 
            }
        }
    }
}