//Proyecto NCurses Programacion UDP "Snako"
//Integrantes: Guillermo Iglesias & Camilo Iturrieta

#include <curses.h>
#include <windows.h>             //Incluye la funcion Sleep(), para el manejo de los segundos

void cabeza()
{
    int x=0, y=10;
    int ch;
    const int speed=100;        //Constante de velocidad indirectamente proporcional
    bool movimiento=true;
    bool derecha=true;
    bool izquierda=false;
    bool abajo=false;
    bool arriba=false;

    while (movimiento)
    {
        while(derecha)
        {
            clear();
            mvaddch(y,x,'>');
            Sleep(speed);
            x++;
            refresh();
            ch=getch();
            if (ch==KEY_UP)
            {
                derecha=false;
                arriba=true;
            }
            else if (ch==KEY_DOWN)
            {
                derecha=false;
                abajo=true;
            }
            else if (ch==KEY_LEFT)
            {
                derecha=false;
                izquierda=true;
            }
        }

        while(izquierda)
        {
            clear();
            mvaddch(y,x,'<');
            Sleep(speed);
            x--;
            refresh();
            ch=getch();
            if (ch==KEY_UP)
            {
                izquierda=false;
                arriba=true;
            }
            else if (ch==KEY_DOWN)
            {
                izquierda=false;
                abajo=true;
            }
            else if (ch==KEY_RIGHT)
            {
                izquierda=false;
                derecha=true;
            }
        }

        while(arriba)
        {
            clear();
            mvaddch(y,x,'^');
            Sleep(speed);
            y--;
            refresh();
            ch=getch();
            if (ch==KEY_DOWN)
            {
                arriba=false;
                abajo=true;
            }
            else if (ch==KEY_RIGHT)
            {
                arriba=false;
                derecha=true;
            }
            else if (ch==KEY_LEFT)
            {
                arriba=false;
                izquierda=true;
            }
        }

        while(abajo)
        {
            clear();
            mvaddch(y,x,'v');
            Sleep(speed);
            y++;
            refresh();
            ch=getch();
            if (ch==KEY_UP)
            {
                abajo=false;
                arriba=true;
            }
            else if (ch==KEY_RIGHT)
            {
                abajo=false;
                derecha=true;
            }
            else if (ch==KEY_LEFT)
            {
                abajo=false;
                izquierda=true;
            }
        }
    }
}

int main()
{
    initscr();                      //Inicio NCurses
    keypad(stdscr,1);               //Habilita teclado
    curs_set(0);                    //Esconde puntero
    noecho();                       //Desactiva eco (no aparece lo que se escribe)
    cbreak();                       //Activa el envio inmediato de teclas
    nodelay(stdscr,1);              //Desactiva espera de lectura de teclado

    cabeza();                       //Funcion Cabeza

    endwin();                       //Finaliza NCurses
    return 0;
}
