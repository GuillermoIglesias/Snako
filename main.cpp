//Proyecto NCurses Programacion UDP "Snako"
//Integrantes: Guillermo Iglesias & Camilo Iturrieta

#include <curses.h>
#include <windows.h>             //Incluye la funcion Sleep(), para el manejo de los segundos
#include <time.h>                //Incluye la seed time(NULL) para numeros random
#include <stdio.h>

void murallas()
{
    int a, b;

    //Cuadro Nivel 0
    for(a=2; a<=22; a++)
    {
        mvaddch(a,1, ACS_BLOCK);
        mvaddch(a,78, ACS_BLOCK);
        if (a==2||a==22)
        {
            for(b=1; b<=78; b++)
                mvaddch(a,b, ACS_BLOCK);
        }
    }
    //Cuadro Nivel 1
    for(a=6; a<=18; a++)
    {
        mvaddch(a,5, ACS_BLOCK);
        mvaddch(a,74, ACS_BLOCK);
        if (a==6||a==18)
        {
            for(b=5; b<=74; b++)
                mvaddch(a,b, ACS_BLOCK);
        }
    }
    //Cuadro Nivel 2
    for(a=10; a<=14; a++)
    {
        mvaddch(a,9, ACS_BLOCK);
        mvaddch(a,70, ACS_BLOCK);
        if (a==10||a==14)
        {
            for(b=9; b<=70; b++)
                mvaddch(a,b, ACS_BLOCK);
        }
    }

    refresh();
}

void pasadizos(int vec[25][80])
{
    int pasadizo_sup, pasadizo_inf, pasadizo_der, pasadizo_izq;
    int interior_sup, interior_inf;
    int i;

    //Pasadizo Superior
    for (i=1; i<4; i++)
    {
        pasadizo_sup=(rand()%62)+7;
        mvaddch(6,pasadizo_sup++, '1');
        vec[6][pasadizo_sup]=1;
        mvaddch(6,pasadizo_sup++, '2');
        vec[6][pasadizo_sup]=1;
        mvaddch(6,pasadizo_sup++, '3');
        vec[6][pasadizo_sup]=1;
    }
    //Pasadizo Inferior
    for (i=1; i<4; i++)
    {
        pasadizo_inf=(rand()%62)+7;
        mvaddch(18,pasadizo_inf++, '1');
        vec[18][pasadizo_inf]=1;
        mvaddch(18,pasadizo_inf++, '2');
        vec[18][pasadizo_inf]=1;
        mvaddch(18,pasadizo_inf++, '3');
        vec[18][pasadizo_inf]=1;
    }
    //Pasadizo Izquierda
    for (i=1; i<2; i++)
    {
        pasadizo_izq=(rand()%8)+7;
        mvaddch(pasadizo_izq++, 5, '1');
        vec[pasadizo_izq][5]=1;
        mvaddch(pasadizo_izq++, 5, '2');
        vec[pasadizo_izq][5]=1;
        mvaddch(pasadizo_izq++, 5, '3');
        vec[pasadizo_izq][5]=1;
    }
    //Pasadizo Derecha
    for (i=1; i<2; i++)
    {
        pasadizo_der=(rand()%8)+7;
        mvaddch(pasadizo_der++, 74, '1');
        vec[pasadizo_der][74]=1;
        mvaddch(pasadizo_der++, 74, '2');
        vec[pasadizo_der][74]=1;
        mvaddch(pasadizo_der++, 74, '3');
        vec[pasadizo_der][74]=1;
    }
    //Pasadsizo Interior (Superior)
    for(i=1; i<2; i++)
    {
        interior_sup=(rand()%50)+13;
        mvaddch(10, interior_sup++, '1');
        vec[10][interior_sup]=1;
        mvaddch(10, interior_sup++, '2');
        vec[10][interior_sup]=1;
        mvaddch(10, interior_sup++, '3');
        vec[10][interior_sup]=1;
    }
    //Pasadizo Interior (Inferior)
    for(i=1; i<2; i++)
    {
        interior_inf=(rand()%50)+13;
        mvaddch(14, interior_inf++, '1');
        vec[14][interior_inf]=1;
        mvaddch(14, interior_inf++, '2');
        vec[14][interior_inf]=1;
        mvaddch(14, interior_inf++, '3');
        vec[14][interior_inf]=1;
    }
    refresh();
}

void puertas(int vec[25][80])
{
    int i, j, v;
    int puerta_sup1, puerta_inf1, puerta_izq1, puerta_der1;
    int puerta_sup2, puerta_inf2, puerta_izq2, puerta_der2;

    //Puerta Superior Nivel 1
    for (i=1; i<=4; i++)
    {
        puerta_sup1=(rand()%67)+7;
        if (vec[6][puerta_sup1]==0)
        {
            mvaddch(6,puerta_sup1, ACS_DIAMOND);
            mvaddch(5,puerta_sup1, ACS_DIAMOND);
            mvaddch(4,puerta_sup1, ACS_DIAMOND);
            mvaddch(3,puerta_sup1, ACS_DIAMOND);
        }
        else
            i--;
    }
    //Puerta Inferior Nivel 1
    for (i=1; i<=4; i++)
    {
        puerta_inf1=(rand()%67)+7;
        if (vec[18][puerta_inf1]==0)
        {
            mvaddch(18,puerta_inf1, ACS_DIAMOND);
            mvaddch(19,puerta_inf1, ACS_DIAMOND);
            mvaddch(20,puerta_inf1, ACS_DIAMOND);
            mvaddch(21,puerta_inf1, ACS_DIAMOND);
        }
        else
            i--;
    }
    //Puerta Izquierda Nivel 1
    for (i=1; i<=3; i++)
    {
        puerta_izq1=(rand()%8)+7;
        if (vec[puerta_izq1][5]==0)
        {
            mvaddch(puerta_izq1, 5, ACS_DIAMOND);
            mvaddch(puerta_izq1, 4, ACS_DIAMOND);
            mvaddch(puerta_izq1, 3, ACS_DIAMOND);
            mvaddch(puerta_izq1, 2, ACS_DIAMOND);
        }
        else
            i--;
    }
    //Puerta Derecha Nivel 1
    for (i=1; i<=3; i++)
    {
        puerta_der1=(rand()%8)+7;
        if (vec[puerta_der1][74]==0)
        {
            mvaddch(puerta_der1, 74, ACS_DIAMOND);
            mvaddch(puerta_der1, 75, ACS_DIAMOND);
            mvaddch(puerta_der1, 76, ACS_DIAMOND);
            mvaddch(puerta_der1, 77, ACS_DIAMOND);
        }
        else
            i--;
    }
    //Puerta Superior Nivel 2
    for (i=1; i<=2; i++)
    {
        puerta_sup2=(rand()%50)+13;
        if (vec[10][puerta_sup2]==0)
        {
            mvaddch(10,puerta_sup2, ACS_DIAMOND);
            mvaddch(9,puerta_sup2, ACS_DIAMOND);
            mvaddch(8,puerta_sup2, ACS_DIAMOND);
            mvaddch(7,puerta_sup2, ACS_DIAMOND);
        }
        else
            i--;
    }
    //Puerta Inferior Nivel 2
    for (i=1; i<=2; i++)
    {
        puerta_inf2=(rand()%50)+13;
        if (vec[14][puerta_inf2]==0)
        {
            mvaddch(14,puerta_inf2, ACS_DIAMOND);
            mvaddch(15,puerta_inf2, ACS_DIAMOND);
            mvaddch(16,puerta_inf2, ACS_DIAMOND);
            mvaddch(17,puerta_inf2, ACS_DIAMOND);
        }
        else
            i--;
    }
    refresh();
}

void cabeza()
{
    int x=3, y=20;
    int ch;
    const int speed=300;        //Constante de velocidad indirectamente proporcional
    bool movimiento=true;
    bool derecha=true;
    bool izquierda=false;
    bool abajo=false;
    bool arriba=false;

    while (movimiento)
    {
        while(derecha)
        {
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
    int vec [25][80];

    initscr();                      //Inicio NCurses
    keypad(stdscr,1);               //Habilita teclado
    curs_set(0);                    //Esconde puntero
    noecho();                       //Desactiva eco (no aparece lo que se escribe)
    cbreak();                       //Activa el envio inmediato de teclas
    nodelay(stdscr,1);              //Desactiva espera de lectura de teclado
    srand(time(NULL));              //Seed para rand()

    for (int i=0; i<25; i++)      //Generador de Matriz para comprobaciones futuras
        for (int j=0; j<80; j++)
            vec[i][j]=0;


    murallas();
    pasadizos(vec);
    puertas(vec);

    cabeza();                       //Funcion Cabeza

    endwin();                       //Finaliza NCurses
    return 0;
}
