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

                // checa elemento abaixo
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
                            // TODO erro colorido de vermelho
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
                            // TODO erro colorido de vermelho
                        }
                    }
                }
                else if (display[i][j+1] == typeWater)
                {
                    display[i][j] = typeAir;
                    display[i][j+1] = typeWater;
                }        

                break;
                case typeWater:

                //checa elemento abaixo
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
                            // TODO erro colorido de vermelho
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
                            // TODO erro colorido de vermelho
                        }
                    }
                }

                break;
                case typeWood:
                // ignora

                break;
            }
        }
    }
}