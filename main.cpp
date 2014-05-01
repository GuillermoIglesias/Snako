//Proyecto NCurses Programacion UDP "Snako"
//Integrantes: Guillermo Iglesias & Camilo Iturrieta

#include <curses.h>
#include <windows.h>             //Incluye la funcion Sleep(), para el manejo de los segundos
#include <time.h>                //Incluye la seed time(NULL) para numeros random

void murallas(int vec[25][80])
{
    int a, b;

    //Cuadro Nivel 0
    for(a=2; a<=22; a++)
    {
        mvaddch(a,1, ACS_BLOCK);
        mvaddch(a,78, ACS_BLOCK);
        vec[a][1]=1;
        vec[a][78]=1;
    }
    for(b=1; b<=78; b++)
    {
        mvaddch(2,b, ACS_BLOCK);
        mvaddch(22,b, ACS_BLOCK);
        vec[2][b]=1;
        vec[22][b]=1;
    }

    //Cuadro Nivel 1
    for(a=6; a<=18; a++)
    {
        mvaddch(a,5, ACS_BLOCK);
        mvaddch(a,74, ACS_BLOCK);
        vec[a][5]=1;
        vec[a][74]=1;
    }
    for(b=5; b<=74; b++)
    {
        mvaddch(6,b, ACS_BLOCK);
        mvaddch(18,b, ACS_BLOCK);
        vec[6][b]=1;
        vec[18][b]=1;
    }
    //Cuadro Nivel 2
    for(a=10; a<=14; a++)
    {
        mvaddch(a,9, ACS_BLOCK);
        mvaddch(a,70, ACS_BLOCK);
        vec[a][9]=1;
        vec[a][70]=1;
    }
    for(b=9; b<=70; b++)
    {
        mvaddch(10,b, ACS_BLOCK);
        mvaddch(14,b, ACS_BLOCK);
        vec[10][b]=1;
        vec[14][b]=1;
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
        vec[6][pasadizo_sup]=0;
        mvaddch(6,pasadizo_sup++, ' ');
        vec[6][pasadizo_sup]=0;
        mvaddch(6,pasadizo_sup++, ' ');
        vec[6][pasadizo_sup]=0;
        mvaddch(6,pasadizo_sup++, ' ');
    }
    //Pasadizo Inferior
    for (i=1; i<4; i++)
    {
        pasadizo_inf=(rand()%62)+7;
        vec[18][pasadizo_inf]=0;
        mvaddch(18,pasadizo_inf++, ' ');
        vec[18][pasadizo_inf]=0;
        mvaddch(18,pasadizo_inf++, ' ');
        vec[18][pasadizo_inf]=0;
        mvaddch(18,pasadizo_inf++, ' ');

    }
    //Pasadizo Izquierda
    for (i=1; i<2; i++)
    {
        pasadizo_izq=(rand()%8)+7;
        vec[pasadizo_izq][5]=0;
        mvaddch(pasadizo_izq++, 5, ' ');
        vec[pasadizo_izq][5]=0;
        mvaddch(pasadizo_izq++, 5, ' ');
        vec[pasadizo_izq][5]=0;
        mvaddch(pasadizo_izq++, 5, ' ');
    }
    //Pasadizo Derecha
    for (i=1; i<2; i++)
    {
        pasadizo_der=(rand()%8)+7;
        vec[pasadizo_der][74]=0;
        mvaddch(pasadizo_der++, 74, ' ');
        vec[pasadizo_der][74]=0;
        mvaddch(pasadizo_der++, 74, ' ');
        vec[pasadizo_der][74]=0;
        mvaddch(pasadizo_der++, 74, ' ');
    }
    //Pasadsizo Interior (Superior)
    for(i=1; i<2; i++)
    {
        interior_sup=(rand()%50)+13;
        vec[10][interior_sup]=0;
        mvaddch(10, interior_sup++, ' ');
        vec[10][interior_sup]=0;
        mvaddch(10, interior_sup++, ' ');
        vec[10][interior_sup]=0;
        mvaddch(10, interior_sup++, ' ');
    }
    //Pasadizo Interior (Inferior)
    for(i=1; i<2; i++)
    {
        interior_inf=(rand()%50)+13;
        vec[14][interior_inf]=0;
        mvaddch(14, interior_inf++, ' ');
        vec[14][interior_inf]=0;
        mvaddch(14, interior_inf++, ' ');
        vec[14][interior_inf]=0;
        mvaddch(14, interior_inf++, ' ');
    }
    refresh();
}

void puertas(int vec[25][80])
{
    int i;
    int puerta_sup1, puerta_inf1, puerta_izq1, puerta_der1;
    int puerta_sup2, puerta_inf2;

    //Puerta Superior Nivel 1
    for (i=1; i<=4; i++)
    {
        puerta_sup1=(rand()%67)+7;
        if (vec[6][puerta_sup1]!=0)
        {
            mvaddch(6,puerta_sup1, ACS_BLOCK);
            mvaddch(5,puerta_sup1, ACS_BLOCK);
            vec[5][puerta_sup1]=1;
            mvaddch(4,puerta_sup1, ACS_BLOCK);
            vec[4][puerta_sup1]=1;
            mvaddch(3,puerta_sup1, ACS_BLOCK);
            vec[3][puerta_sup1]=1;
        }
        else
            i--;
    }
    //Puerta Inferior Nivel 1
    for (i=1; i<=4; i++)
    {
        puerta_inf1=(rand()%67)+7;
        if (vec[18][puerta_inf1]!=0)
        {
            mvaddch(18,puerta_inf1, ACS_BLOCK);
            mvaddch(19,puerta_inf1, ACS_BLOCK);
            vec[19][puerta_inf1]=1;
            mvaddch(20,puerta_inf1, ACS_BLOCK);
            vec[20][puerta_inf1]=1;
            mvaddch(21,puerta_inf1, ACS_BLOCK);
            vec[21][puerta_inf1]=1;
        }
        else
            i--;
    }
    //Puerta Izquierda Nivel 1
    for (i=1; i<=3; i++)
    {
        puerta_izq1=(rand()%8)+7;
        if (vec[puerta_izq1][5]!=0)
        {
            mvaddch(puerta_izq1, 5, ACS_BLOCK);
            mvaddch(puerta_izq1, 4, ACS_BLOCK);
            vec[puerta_izq1][4]=1;
            mvaddch(puerta_izq1, 3, ACS_BLOCK);
            vec[puerta_izq1][3]=1;
            mvaddch(puerta_izq1, 2, ACS_BLOCK);
            vec[puerta_izq1][2]=1;
        }
        else
            i--;
    }
    //Puerta Derecha Nivel 1
    for (i=1; i<=3; i++)
    {
        puerta_der1=(rand()%8)+7;
        if (vec[puerta_der1][74]!=0)
        {
            mvaddch(puerta_der1, 74, ACS_BLOCK);
            mvaddch(puerta_der1, 75, ACS_BLOCK);
            vec[puerta_der1][75]=1;
            mvaddch(puerta_der1, 76, ACS_BLOCK);
            vec[puerta_der1][76]=1;
            mvaddch(puerta_der1, 77, ACS_BLOCK);
            vec[puerta_der1][77]=1;
        }
        else
            i--;
    }
    //Puerta Superior Nivel 2
    for (i=1; i<=2; i++)
    {
        puerta_sup2=(rand()%50)+13;
        if (vec[10][puerta_sup2]!=0&&vec[6][puerta_sup2]!=0)
        {
            mvaddch(10,puerta_sup2, ACS_BLOCK);
            mvaddch(9,puerta_sup2, ACS_BLOCK);
            vec[9][puerta_sup2]=1;
            mvaddch(8,puerta_sup2, ACS_BLOCK);
            vec[8][puerta_sup2]=1;
            mvaddch(7,puerta_sup2, ACS_BLOCK);
            vec[7][puerta_sup2]=1;
        }
        else
            i--;
    }
    //Puerta Inferior Nivel 2
    for (i=1; i<=2; i++)
    {
        puerta_inf2=(rand()%50)+13;
        if (vec[14][puerta_inf2]!=0&&vec[18][puerta_inf2]!=0)
        {
            mvaddch(14,puerta_inf2, ACS_BLOCK);
            mvaddch(15,puerta_inf2, ACS_BLOCK);
            vec[15][puerta_inf2]=1;
            mvaddch(16,puerta_inf2, ACS_BLOCK);
            vec[16][puerta_inf2]=1;
            mvaddch(17,puerta_inf2, ACS_BLOCK);
            vec[17][puerta_inf2]=1;
        }
        else
            i--;
    }
    refresh();
}

void victoria(int vec[25][80])
{
    mvaddch(4,76, ACS_DIAMOND);
    vec[4][76]=1;
    refresh();
}

void cabeza(int vec[25][80])
{
    int x=3, y=20;
    int ch;
    const int speed=200;        //Constante de velocidad indirectamente proporcional
    bool movimiento=true;
    bool derecha=true;
    bool izquierda=false;
    bool abajo=false;
    bool arriba=false;

    while (movimiento)
    {
        while(derecha)
        {
            if (vec[y][x]==0)
            {
                Sleep(speed);
                mvaddch(y,x, '>');
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
        }

        while(izquierda)
        {
            if (vec[y][x]==0)
            {
                Sleep(speed);
                mvaddch(y,x, '<');
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
        }

        while(arriba)
        {
            if (vec[y][x]==0)
            {
                Sleep(speed);
                mvaddch(y,x, '^');
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
        }

        while(abajo)
        {
            if (vec[y][x]==0)
            {
                Sleep(speed);
                mvaddch(y,x, 'v');
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

    for (int i=0; i<25; i++)        //Generador de Matriz para comprobaciones futuras
        for (int j=0; j<80; j++)
            vec[i][j]=0;


    murallas(vec);
    pasadizos(vec);
    puertas(vec);
    victoria(vec);
    cabeza(vec);

    endwin();                          //Finaliza NCurses
    return 0;
}
