//Proyecto NCurses Programacion UDP "Snako"
//Integrantes: Guillermo Iglesias & Camilo Iturrieta

#include <curses.h>
#include <windows.h>             //Incluye la funcion Sleep(), para el manejo de los segundos
#include <time.h>                //Incluye la seed time(NULL) para numeros random

void menu()
{
    //Creacion del borde
    attron(COLOR_PAIR(1));
    for(int i=0; i<78; i++)
	{
        mvaddch(1,i+1, ACS_BLOCK);
        mvaddch(23,i+1,ACS_BLOCK);
    }

    for(int i=0; i<23; i++)
	{
        mvaddch(i+1,1,ACS_BLOCK);
        mvaddch(i+1,78,ACS_BLOCK);
    }
    attroff(COLOR_PAIR(1));

    //Logo de Snako
    attron(COLOR_PAIR(2));
    mvprintw(2,2,"                          __    __    __    __                              ");
    mvprintw(3,2,"                         /     /     /     /                                ");
    mvprintw(4,2,"________________________/  __ /  __ /  __ /  _______________________________");
    mvprintw(5,2,"_______________________/  /__/  /__/  /__/  /_______________________________");
    mvprintw(6,2,"                       | /     /     /     /    ______                      ");
    mvprintw(7,2,"                       |/    _/    _/    _/         O                       ");
    mvprintw(8,2,"                                               _______/--<                  ");
    mvaddch(3,30,92);
    mvaddch(3,36,92);
    mvaddch(3,42,92);
    mvaddch(3,48,92);
    mvaddch(4,31,92);
    mvaddch(4,37,92);
    mvaddch(4,43,92);
    mvaddch(4,49,92);
    mvaddch(6,29,92);
    mvaddch(6,35,92);
    mvaddch(6,41,92);
    mvaddch(6,47,92);
    mvaddch(6,50,92);
    mvaddch(7,30,92);
    mvaddch(7,36,92);
    mvaddch(7,42,92);
    mvaddch(7,48,92);
    mvaddch(7,56,92);
    mvaddch(8,49,92);
    attroff(COLOR_PAIR(2));

    //Snako

    attron(COLOR_PAIR(4));
    mvprintw(9,2, "                       ___                    _");
    mvprintw(10,2,"                      / __|   _ _     __ _   | |__   ___   ");
    mvprintw(11,2,"                       __    | '     / _' |  | / /  / _      ");
    mvprintw(12,2,"                      |___/  |_||_|   __,_|  |_ _    ___/ ");
    mvaddch(11,24,92);
    mvaddch(11,28,92);
    mvaddch(11,35,92);
    mvaddch(11,58,92);
    mvaddch(12,39,92);
    mvaddch(12,49,92);
    mvaddch(12,51,92);
    mvaddch(12,54,92);
    attroff(COLOR_PAIR(4));

    mvprintw(14,34,"Comenzar Juego");
    mvprintw(15,34,"Instrucciones");
    mvprintw(16,34,"Creditos");
    mvprintw(17,34,"Salir");
    mvprintw(20,28,"(R) 2014 Programacion UDP ");
}

void murallas(int vec[25][80])
{
    int a, b;

    mvaddstr (1,35, "S N A K O" );
    mvaddstr (23,2, "Vidas: ");
    mvaddstr (1,2, "Puntaje: ");
    mvaddstr (1,70, "Nivel ");

    //Cuadro Nivel 0
    for(a=2; a<=22; a++)
    {
        vec[a][1]=1;
        vec[a][78]=1;
    }
    for(b=1; b<=78; b++)
    {
        vec[2][b]=1;
        vec[22][b]=1;
    }

    //Cuadro Nivel 1
    for(a=6; a<=18; a++)
    {
        vec[a][5]=1;
        vec[a][74]=1;
    }
    for(b=5; b<=74; b++)
    {
        vec[6][b]=1;
        vec[18][b]=1;
    }
    //Cuadro Nivel 2
    for(a=10; a<=14; a++)
    {
        vec[a][9]=1;
        vec[a][70]=1;
    }
    for(b=9; b<=70; b++)
    {
        vec[10][b]=1;
        vec[14][b]=1;
    }

    refresh();
}

void imprimir_muralla(int vec[25][80])
{
   for (int i=0; i<=25; i++)
        for (int j=0; j<=80; j++)
            if (vec[i][j]==1)
            {
                attron(COLOR_PAIR(1));
                mvaddch(i,j, ACS_BLOCK);
                attroff(COLOR_PAIR(1));
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
        pasadizo_sup=(rand()%63)+8;

        vec[6][pasadizo_sup]=0;
        mvaddch(6,pasadizo_sup, ' ');

        pasadizo_sup--;

        vec[6][pasadizo_sup]=0;
        mvaddch(6,pasadizo_sup, ' ');

        pasadizo_sup += 2;

        vec[6][pasadizo_sup]=0;
        mvaddch(6,pasadizo_sup, ' ');
    }
    //Pasadizo Inferior
    for (i=1; i<4; i++)
    {
        pasadizo_inf=(rand()%63)+8;

        vec[18][pasadizo_inf]=0;
        mvaddch(18,pasadizo_inf, ' ');

        pasadizo_inf--;

        vec[18][pasadizo_inf]=0;
        mvaddch(18,pasadizo_inf, ' ');

        pasadizo_inf += 2;

        vec[18][pasadizo_inf]=0;
        mvaddch(18,pasadizo_inf, ' ');

    }
    //Pasadizo Izquierda
    for (i=1; i<2; i++)
    {
        pasadizo_izq=(rand()%9)+8;

        vec[pasadizo_izq][5]=0;
        mvaddch(pasadizo_izq, 5, ' ');

        pasadizo_izq--;

        vec[pasadizo_izq][5]=0;
        mvaddch(pasadizo_izq, 5, ' ');

        pasadizo_izq += 2;

        vec[pasadizo_izq][5]=0;
        mvaddch(pasadizo_izq, 5, ' ');
    }
    //Pasadizo Derecha
    for (i=1; i<2; i++)
    {
        pasadizo_der=(rand()%9)+8;

        vec[pasadizo_der][74]=0;
        mvaddch(pasadizo_der, 74, ' ');

        pasadizo_der--;

        vec[pasadizo_der][74]=0;
        mvaddch(pasadizo_der, 74, ' ');

        pasadizo_der += 2;

        vec[pasadizo_der][74]=0;
        mvaddch(pasadizo_der, 74, ' ');
    }
    //Pasadsizo Interior (Superior)
    for(i=1; i<2; i++)
    {
        interior_sup=(rand()%58)+11;

        vec[10][interior_sup]=0;
        mvaddch(10, interior_sup, ' ');

        interior_sup--;

        vec[10][interior_sup]=0;
        mvaddch(10, interior_sup, ' ');

        interior_sup += 2;

        vec[10][interior_sup]=0;
        mvaddch(10, interior_sup, ' ');
    }
    //Pasadizo Interior (Inferior)
    for(i=1; i<2; i++)
    {
        interior_inf=(rand()%58)+11;

        vec[14][interior_inf]=0;
        mvaddch(14, interior_inf, ' ');

        interior_inf--;

        vec[14][interior_inf]=0;
        mvaddch(14, interior_inf, ' ');

        interior_inf += 2;

        vec[14][interior_inf]=0;
        mvaddch(14, interior_inf, ' ');
    }
    refresh();
}

void puertas(int vec[25][80])
{
    int i;
    int puerta_sup1, puerta_inf1, puerta_izq1, puerta_der1;
    int puerta_sup2, puerta_inf2;
    int tipo;

    //Puerta Superior Nivel 1
    for (i=1; i<=4; i++)
    {
        puerta_sup1=(rand()%67)+7;
        tipo = (rand()%3)+2;

        if (vec[6][puerta_sup1]!=0)
        {
            vec[5][puerta_sup1]=tipo;
            vec[4][puerta_sup1]=tipo;
            vec[3][puerta_sup1]=tipo;
        }
        else
            i--;
    }
    //Puerta Inferior Nivel 1
    for (i=1; i<=4; i++)
    {
        puerta_inf1=(rand()%64)+10;
        tipo = (rand()%3)+2;

        if (vec[18][puerta_inf1]!=0)
        {
            vec[19][puerta_inf1]=tipo;
            vec[20][puerta_inf1]=tipo;
            vec[21][puerta_inf1]=tipo;
        }
        else
            i--;
    }
    //Puerta Izquierda Nivel 1
    for (i=1; i<2; i++)
    {
        puerta_izq1=(rand()%6)+6;
        tipo = (rand()%3)+2;

        if (vec[puerta_izq1][5]!=0)
        {
            vec[puerta_izq1][4]=tipo;
            vec[puerta_izq1][3]=tipo;
            vec[puerta_izq1][2]=tipo;
        }
        else
            i--;
    }
    //Puerta Derecha Nivel 1
    for (i=1; i<2; i++)
    {
        puerta_der1=(rand()%8)+7;
        tipo = (rand()%3)+2;

        if (vec[puerta_der1][74]!=0)
        {
            vec[puerta_der1][75]=tipo;
            vec[puerta_der1][76]=tipo;
            vec[puerta_der1][77]=tipo;
        }
        else
            i--;
    }
    //Puerta Superior Nivel 2
    for (i=1; i<=2; i++)
    {
        puerta_sup2=(rand()%50)+13;
        tipo = (rand()%3)+2;

        if (vec[10][puerta_sup2]!=0&&vec[6][puerta_sup2]!=0)
        {
            vec[9][puerta_sup2]=tipo;
            vec[8][puerta_sup2]=tipo;
            vec[7][puerta_sup2]=tipo;
        }
        else
            i--;
    }
    //Puerta Inferior Nivel 2
    for (i=1; i<=2; i++)
    {
        puerta_inf2=(rand()%50)+13;
        tipo = (rand()%3)+2;

        if (vec[14][puerta_inf2]!=0&&vec[18][puerta_inf2]!=0)
        {
            vec[15][puerta_inf2]=tipo;
            vec[16][puerta_inf2]=tipo;
            vec[17][puerta_inf2]=tipo;
        }
        else
            i--;
    }
    refresh();
}

void imprimir_puerta(int vec[25][80], int &puerta)
{
    //Imprime puertas tipo 2
    if (puerta%11==0&&puerta%2!=0)
        for (int i=0; i<=25; i++)
            for (int j=0; j<=80; j++)
                if (vec[i][j]==5)
                {
                    attron(COLOR_PAIR(5));
                    mvaddch(i,j, ACS_BLOCK);
                    attroff(COLOR_PAIR(5));
                    vec[i][j]=2;
                }

    //Elimina puertas tipo 2
    if (puerta%11==0&&puerta%2==0)
        for (int i=0; i<=25; i++)
            for (int j=0; j<=80; j++)
                if (vec[i][j]==2)
                {
                    mvaddch(i,j, ' ');
                    vec[i][j]=5;
                }

    //Imprime puertas tipo 3
    if (puerta%7==0&&puerta%2!=0)
        for (int i=0; i<=25; i++)
            for (int j=0; j<=80; j++)
                if (vec[i][j]==6)
                {
                    attron(COLOR_PAIR(3));
                    mvaddch(i,j, ACS_BLOCK);
                    attroff(COLOR_PAIR(3));
                    vec[i][j]=3;
                }

    //Elimina puertas tipo 3
    if (puerta%14==0)
        for (int i=0; i<=25; i++)
            for (int j=0; j<=80; j++)
                if (vec[i][j]==3)
                {
                    mvaddch(i,j, ' ');
                    vec[i][j]=6;
                }

    //Imprime puertas tipo 4
    if (puerta%5==0&&puerta%2!=0)
        for (int i=0; i<=25; i++)
            for (int j=0; j<=80; j++)
                if (vec[i][j]==7)
                {
                    attron(COLOR_PAIR(4));
                    mvaddch(i,j, ACS_BLOCK);
                    attroff(COLOR_PAIR(4));
                    vec[i][j]=4;
                }

    //Elimina puertas tipo 4
    if (puerta%10==0)
        for (int i=0; i<=25; i++)
            for (int j=0; j<=80; j++)
                if (vec[i][j]==4)
                {
                    mvaddch(i,j, ' ');
                    vec[i][j]=7;
                }

    if (puerta > 9999)
        puerta = 0;

    refresh();
}

void comida(int vec[25][80])
{
    int posX, posY;

    for (int i=0; i<2; i++)
    {
        posX = (rand()%78+1);
        posY = (rand()%21+2);
        if (vec[posY][posX]==0)
        {
            mvaddch(posY, posX, ACS_DIAMOND);
            vec[posY][posX]=9;
            i=2;
        }
        else
            i--;
    }

    refresh();
}

void cola(int camino[25][80], int vec[25][80], int y, int x, int pasos, int &largo, int &contNivel, int &puntaje)
{
    if (vec[y][x]==9)
    {
        largo += 4;
        vec[y][x] = 0;
        comida(vec);
        contNivel++;
        puntaje += 10;
        mvprintw(1,11,"%d", puntaje);
    }

    if (pasos>largo)
    {
        for (int i=0; i<=25; i++)
            for (int j=0; j<=80; j++)
                if (camino[i][j]== pasos - largo)
                {
                    mvaddch(i,j, ' ');
                    /*camino[i][j]=0;*/   //Produce APPCRASH
                }
    }
}

void cabeza(int vec[25][80], int camino[25][80], int &contNivel, int &vidas, int &puntaje)
{
    int x=3, y=20;
    int ch;
    const int speed=2;        //Constante de velocidad indirectamente proporcional
    bool movimiento=true;
    bool derecha=true;
    bool izquierda=false;
    bool abajo=false;
    bool arriba=false;
    int puerta = 0;
    int condicionNivel = 5;

    int pasos = 1;
    int largo = 5;

    while (movimiento)
    {
        while(derecha)
        {
            if (vec[y][x]==0 || vec[y][x]==5 || vec[y][x]==6 || vec[y][x]==7 || vec[y][x]==9)
            {
                halfdelay(speed);
                imprimir_puerta(vec, puerta);
                puerta++;
                attron(COLOR_PAIR(2));
                mvaddch(y,x, '>');
                attroff(COLOR_PAIR(2));

                camino[y][x] = pasos;
                pasos++;
                cola(camino, vec, y, x, pasos, largo, contNivel, puntaje);

                x++;
                refresh();
                ch=getch();

                if (contNivel==condicionNivel)
                {
                    derecha=false;
                    movimiento=false;
                    clear();
                }

                else if (ch==KEY_UP)
                {
                    derecha=false;
                    arriba=true;
                }
                else if (ch==KEY_DOWN)
                {
                    derecha=false;
                    abajo=true;
                }
            }

            else
            {
                derecha=false;
                movimiento=false;
                vidas--;
            }
        }

        while(izquierda)
        {
            if (vec[y][x]==0 || vec[y][x]==5 || vec[y][x]==6 || vec[y][x]==7 || vec[y][x]==9)
            {
                halfdelay(speed);
                imprimir_puerta(vec, puerta);
                puerta++;
                attron(COLOR_PAIR(2));
                mvaddch(y,x, '<');
                attroff(COLOR_PAIR(2));

                camino[y][x] = pasos;
                pasos++;
                cola(camino, vec, y, x, pasos, largo, contNivel, puntaje);

                x--;
                refresh();
                ch=getch();

                if (contNivel==condicionNivel)
                {
                    izquierda=false;
                    movimiento=false;
                    clear();
                }

                else if (ch==KEY_UP)
                {
                    izquierda=false;
                    arriba=true;
                }
                else if (ch==KEY_DOWN)
                {
                    izquierda=false;
                    abajo=true;
                }
            }
            else
            {
                izquierda=false;
                movimiento=false;
                vidas--;
            }
        }

        while(arriba)
        {
            if (vec[y][x]==0 || vec[y][x]==5 || vec[y][x]==6 || vec[y][x]==7 || vec[y][x]==9)
            {
                halfdelay(speed);
                imprimir_puerta(vec, puerta);
                puerta++;
                attron(COLOR_PAIR(2));
                mvaddch(y,x, '^');
                attroff(COLOR_PAIR(2));

                camino[y][x] = pasos;
                pasos++;
                cola(camino, vec, y, x, pasos, largo, contNivel, puntaje);

                y--;
                refresh();
                ch=getch();
                if (contNivel==condicionNivel)
                {
                    arriba=false;
                    movimiento=false;
                    clear();
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
            else
            {
                arriba=false;
                movimiento=false;
                vidas--;
            }
        }

        while(abajo)
        {
            if (vec[y][x]==0 || vec[y][x]==5 || vec[y][x]==6 || vec[y][x]==7 || vec[y][x]==9)
            {
                halfdelay(speed);
                imprimir_puerta(vec, puerta);
                puerta++;
                attron(COLOR_PAIR(2));
                mvaddch(y,x, 'v');
                attroff(COLOR_PAIR(2));

                camino[y][x] = pasos;
                pasos++;
                cola(camino, vec, y, x, pasos, largo, contNivel, puntaje);

                y++;
                refresh();
                ch=getch();
                if (contNivel==condicionNivel)
                {
                    abajo=false;
                    movimiento=false;
                    clear();
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
            else
            {
                abajo=false;
                movimiento=false;
                vidas--;
            }
        }
    }
}

void imp_misc (int vidas, int nivel)
{
    mvprintw(1,77,"%d", nivel);

    if (vidas==3)
    {
        mvaddch (23,9, ACS_DIAMOND);
        mvaddch (23,11, ACS_DIAMOND);
        mvaddch (23,13, ACS_DIAMOND);
    }
    if (vidas==2)
        mvaddch (23,13, ' ');
    if (vidas==1)
        mvaddch (23,11, ' ');
    if (vidas==0)
        mvaddch (23,9, ' ');
}

int main()
{
    initscr();                      //Inicio NCurses
    keypad(stdscr,1);               //Habilita teclado
    curs_set(0);                    //Esconde puntero
    noecho();                       //Desactiva eco (no aparece lo que se escribe)
    cbreak();                       //Activa el envio inmediato de teclas
    nodelay(stdscr,1);              //Desactiva espera de lectura de teclado
    srand(time(NULL));              //Seed para rand()

    start_color();
    init_pair(1,COLOR_CYAN,COLOR_BLACK);
    init_pair(2,COLOR_GREEN,COLOR_BLACK);
    init_pair(3,COLOR_YELLOW,COLOR_BLACK);
    init_pair(4,COLOR_RED,COLOR_BLACK);
    init_pair(5,COLOR_BLUE,COLOR_BLACK);

    int vec [25][80]={0};           //Generador de Matriz para comprobaciones
    int camino [25][80]={0};        //Generador de Matriz para Movimiento Snako

    bool juego=false;
    bool snako=true;

    while (snako)
    {
        menu();
        bool elegir = true;
        int x = 31;
        int y = 14;
        int pressZ;

        while(elegir)
        {
            //Selección en el menú
            mvaddch(y, x, ACS_DIAMOND);
            pressZ = getch();
            if (pressZ == KEY_DOWN && y<17)
            {
                mvprintw(y, x, " ");
                y++;

            }
            else if (pressZ == KEY_UP && y>14)
            {
                mvprintw(y, x, " ");
                y--;
            }
            else if (pressZ == '\n' && y==14)
            {
                elegir = false;
                juego = true;
                clear();
            }

            else if (pressZ == '\n' && y==17)
            {
                elegir = false;
                snako = false;
                clear();
            }
            refresh();
        }

        while (juego)
        {
            int contNivel = 0;          //Contador para diferenciar niveles
            int vidas = 3;              //Contador para las vidas
            int nivel = 1;
            int puntaje = 0;

            murallas(vec);
            imprimir_muralla(vec);
            puertas(vec);
            pasadizos(vec);
            comida(vec);

            while(vidas>0)
            {
                if (contNivel==5)
                {
                    for (int i=0; i<=25; i++)
                        for (int j=0; j<=80; j++)
                            vec[i][j]=0;

                    murallas(vec);
                    imprimir_muralla(vec);
                    puertas(vec);
                    pasadizos(vec);
                    comida(vec);
                    nivel++;
                    contNivel=0;
                }

                imp_misc(vidas, nivel);
                cabeza(vec, camino, contNivel, vidas, puntaje);

                for (int i=0; i<=25; i++)
                    for (int j=0; j<=80; j++)
                        if (camino[i][j]!=0)
                            mvaddch(i,j,' ');

                Sleep(1000);
            }
            juego = false;
            clear();
        }
    }

    endwin();                       //Finaliza NCurses
    return 0;
}
