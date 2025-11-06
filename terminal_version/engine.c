#include "engine.h"

int validaElemento(enum elementType elemento) 
{
    switch (elemento) 
    {
        case typeAir:
        case typeSand:
        case typeWater:
        case typeWood:
            return SUCESS; // Valid
        default:
            return FAILURE; // Invalid
    }
}

int** generateInitialData(int sizeX, int sizeY)
{
    int display[sizeX][sizeY];

    // preenche o display com ar
    for(int i = 0; i < sizeX; i++)
    {
        for(int j = 0; j < sizeY; j++)
        {
            display[i][j] = typeAir;
        }
    }

    return display;
}

int insereElemento(int** display, int coluna, enum elementType elemento)
{
    if (validaElemento)
    {
        display[coluna][0] = elemento;
        return SUCESS;
    }
    else
    {
        return FAILURE;
    }
}

int atualizaDisplay(int** display, int sizeX, int sizeY)
{
    for(int i = sizeX - 2; i > 0; i--)
    {
        for(int j = sizeY - 2; j > 0; j--)
        {
            switch(display[i][j])
            {
                case typeAir:
                // ignora

                break;
                case typeSand:
                if(display[i][j+1] != typeAir)
                {
                    display[i][j] = typeAir;
                    display[i][j+1] = typeSand;
                } 
                
                break;
                case typeWater:
                if (j < sizeY - 1) // checa borda Y
                {

                }

                break;
                case typeWood:
                // ignora

                break;
            }
        }
    }
}