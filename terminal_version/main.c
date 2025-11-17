#include "main.h"


int main(void)
{
    srand(time(NULL));

    initscr();              // Initialize ncurses
    noecho();               // tira o eco na tela ao digitar
    cbreak();               // Para entrada imediata (sem esperar por Enter)
    keypad(stdscr, TRUE);   // Para arrow keys

    int pressed_key;

    // handler de inputs
    while(1)
    {
        pressed_key = getch();
        if (pressed_key == 'q')
        {
            finaliza();
        }
        else if (pressed_key == KEY_UP)
        {
            mvprintw(0, 0, "Teste!");
            refresh();
        }

    }
    return 0;
}



void finaliza()
{
    endwin();  // End ncurses
    exit(0);
}