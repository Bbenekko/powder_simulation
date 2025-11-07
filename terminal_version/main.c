#include "main.h"

int main(void)
{
    srand(time(NULL));

    initscr(); // Initialize ncurses

    

    // handler de inputs
    while(1)
    {
        if (getch() == 'q')
        {
            finaliza();
        }
        else if (getch() == '1')
        {

        }

    }
}



void finaliza()
{
    endwin();  // End ncurses
    exit(0);
}