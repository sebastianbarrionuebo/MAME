#include "JumpFrog.h"

void gotoxyFrog(int X,int Y)
{
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X=X;
      dwPos.Y=Y;
      SetConsoleCursorPosition(hcon,dwPos);
}
void initFrog(stUsuario* userOn)
{
    int  puntaje = 100;
    char ganar[7][111]=
    {
        {" _______  _______  __    _  _______  _______  _______  _______    _______  ______    _______  _______  ___   _ "},
        {"|       ||   _   ||  |  | ||   _   ||       ||       ||       |  |       ||    _ |  |   _   ||       ||   | | |"},
        {"|    ___||  |_|  ||   |_| ||  |_|  ||  _____||_     _||    ___|  |       ||   | ||  |  |_|  ||       ||   |_| |"},
        {"|   | __ |       ||       ||       || |_____   |   |  |   |___   |       ||   |_||_ |       ||       ||      _|"},
        {"|   ||  ||       ||  _    ||       ||_____  |  |   |  |    ___|  |      _||    __  ||       ||      _||     |_ "},
        {"|   |_| ||   _   || | |   ||   _   | _____| |  |   |  |   |___   |     |_ |   |  | ||   _   ||     |_ |    _  |"},
        {"|_______||__| |__||_|  |__||__| |__||_______|  |___|  |_______|  |_______||___|  |_||__| |__||_______||___| |_|"}
    };
    char menu[2][10]=
    {
        {"Saltos "},
        {" Vidas "}
    };
    char map[28][81]=
    {
        {"366666666666666666666666666666666666666666666666666666666666666666666666666666662"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"7                    7                                                          7"},
        {"566666666666666666666666666666666666666666666666666666666666666666666666666666664"}
    };
    int ctl = 0;

    stVehiculo c1 = initVehiculo(CARRIL_1X,CARRIL_1Y,'i', 1, 7, ROJO, AMARILLO, VIOLETA);
    stVehiculo c2 = initVehiculo(CARRIL_2X,CARRIL_2Y,'d', 2, -7, BLANCO, ROJO, VERDE);
    stVehiculo c3 = initVehiculo(CARRIL_3X,CARRIL_3Y,'i', 3, 7, VIOLETA, AMARILLO, AZUL);
    stVehiculo c4 = initVehiculo(CARRIL_4X,CARRIL_4Y,'d', 4, -14, BLANCO, ROJO, VERDE);

    stFrog frogy = createFrog(userOn->compras.colorFrog[0]);
    //setUp
    system("clean");
    system("cls");
    showTitle();
    printTitleL(INI_X-22,INI_Y-2, 28,81,map,BLANCO);
    moverFrog(&frogy, 0);
    marcarFlechas(0,ARRIBA);
    marcarFlechas(0,ABAJO);
    marcarFlechas(0,DERECHA);
    marcarFlechas(0,IZQUIERDA);
    printTextMenu(frogy, 2, 10, menu);

    while(ctl==0)
    {
        int tecla=0;

        moverVehiculo(&c1);
        moverVehiculo(&c2);
        moverVehiculo(&c3);
        moverVehiculo(&c4);

        if(kbhit())
        {
            tecla = getch();
            if(tecla==ARRIBA || tecla==ABAJO || tecla==DERECHA || tecla==IZQUIERDA)
            {
                if(movimientoLegal(tecla,frogy))
                {
                    frogy.movimientos++;
                    moverFrog(&frogy, tecla);
                    marcarFlechas(tecla, frogy.lastMove);
                    frogy.lastMove=tecla;
                    printTextMenu(frogy,3,10,menu);
                }
            }
        }
        if(muerte(frogy, c1) || muerte(frogy, c2) || muerte(frogy, c3) || muerte(frogy, c4))
        {
           frogy.lives -= 1;
           respawn(&frogy);
        }
        if(frogy.lives == 0)
        {
            ctl=1;
            perdisteWey();

        }
        if(frogy.matrizY[0][0] == INI_Y)
        {
            ctl=1;
            printMenu(8,16,7,111,ganar);
        }
        printTextMenu(frogy, 3, 10, menu);
    }

    puntaje -= frogy.movimientos;
    if(puntaje > userOn->maxFrog)
    {
        userOn->maxFrog += puntaje;
    }
    userOn->coins=+puntaje;
    Sleep(3000);
}

void printTextMenu(stFrog frogy,int l, int c,char text[l][c])//falta el user
{
    printText(frogy.movimientos, c, text[0], 1);
    printText(frogy.lives, c, text[1], 4);
}
void printText(int dato,int c,char text[], int pos)
{
    char number[10];
    itoa(dato, number, 10);
    printSlot(INI_X-13, INI_Y+pos, text, c);
    printSlot(INI_X-10, INI_Y+pos+1, number, strlen(number));
}
void respawn(stFrog* frogy)
{
    Sleep(400);
    frogy->x = 25+INI_X;
    frogy->y = 20+INI_Y;
    moverFrog(frogy, 0);
    actualizarPosF(frogy);
}
void printSlot(int x,int y,char text[], int width)
{
    for(int i=0; i < width; i++)
    {
        gotoxyFrog(x,y);
        printf("%c", text[i]);
        x++;
    }
}
void printMenu(int x,int y,int line,int column,char screen[line][column])
{
    int i;
    for(i=0; i<line; i++)
    {
        printSlot(x,y,screen[i], column);
        y++;
    }
}
void printVX(int x,int y,int line,int column,char screen[line][column], stVehiculo vehiculo, char color[line][column])
{
    int i;
    for(i=0; i<line; i++)
    {
        printVY(x,y, screen[i], column, vehiculo, color[i]);
        y++;
    }
}
void printVY(int x,int y,char text[], int width, stVehiculo vehiculo, char color[])
{
    char ascii;
    for(int i=0; i < width; i++)
    {
        gotoxyFrog(x,y);
            if(x > INI_X && x < FIN_X)
            {
                //caracteres
                if(text[i] == '1')
                {
                    ascii = 219;
                }
                else if(text[i] == '2')
                {
                    ascii = 223;
                }
                else if(text[i] == '3')
                {
                    ascii = 220;
                }
                else if(text[i] == '4')
                {
                    ascii = 254;
                }

                if(color[i] == '1')
                {
                    printColor(vehiculo.color1, ascii);
                }
                else if(color[i] == '2')
                {
                    printColor(vehiculo.color2, ascii);
                }
                else if(color[i] == '3')
                {
                    printColor(vehiculo.color3, ascii);
                }
                else
                {
                    printf(" ");
                }
            }
        x++;
    }
}
void printColor(int color, char c)
{
    if(color==ROJO)
    {
        printf(RED_T "%c" RESET_COLOR, c);
    }
    else if(color==AZUL)
    {
        printf(BLUE_T "%c" RESET_COLOR, c);
    }
    else if(color==AMARILLO)
    {
        printf(YELLOW_T "%c" RESET_COLOR, c);
    }
    else if(color==VERDE)
    {
        printf(GREEN_T "%c" RESET_COLOR, c);
    }
    else if(color==CIAN)
    {
        printf(CYAN_T "%c" RESET_COLOR, c);
    }
    else if(color==VIOLETA)
    {
        printf(MAGENTA_T "%c" RESET_COLOR, c);
    }
    else
    {
        printf("%c", c);
    }
}
void moverVehiculo(stVehiculo* vehiculo)
{
        char modelo1[4][7]=
        {
            {"333 111"},
            {"313331 "},
            {"212221 "},
            {"222 111"}
        };
        char c1[4][7]=
        {
            {"111 111"},
            {"222322 "},
            {"222322 "},
            {"111 111"}
        };
        char modelo2[4][7]=
        {
            {"2122 12"},
            {"3111314"},
            {"2111214"},
            {"3133 13"}
        };
        char c2[4][7]=
        {
            {"3131 13"},
            {"1111213"},
            {"1111213"},
            {"3131 13"}
        };
        char modelo3[4][7]=
        {
            {"  3  3 "},
            {"3121114"},
            {"2131114"},
            {"  2  2 "}
        };
        char c3[4][7]=
        {
            {"  3  3 "},
            {"1111112"},
            {"1111112"},
            {"  3  3 "}
        };
        char modelo4[4][14]=
        {
            {" 3  3  3   3  "},
            {"11111111131113"},
            {"11111111121112"},
            {" 2  2  2   2  "}
        };
        char c4[4][14]=
        {
            {" 3  3  3   3  "},
            {"11111111121112"},
            {"11111111121112"},
            {" 3  3  3   3  "}
        };
        Sleep(10);
        if(vehiculo->modelo == 1)
        {
            printVX(vehiculo->x, vehiculo->y, 4, 7, modelo1, *vehiculo, c1);
        }
        else if(vehiculo->modelo == 2)
        {
            printVX(vehiculo->x, vehiculo->y, 4, 7, modelo2, *vehiculo, c2);
        }
        else if(vehiculo->modelo == 3)
        {
            printVX(vehiculo->x, vehiculo->y, 4, 7, modelo3, *vehiculo, c3);
        }
        else
        {
            printVX(vehiculo->x, vehiculo->y, 4, 14, modelo4, *vehiculo, c4);
        }

        //movimiento
        int auxX = vehiculo->x, auxY = vehiculo->y;
        if(vehiculo->sentido == 'i')
        {
            auxX += vehiculo->desplazamiento;
        }
        else
        {
            auxX-=1;
        }
        if(vehiculo->sentido == 'i')
        {
            vehiculo->x -= 1;
        }
        else
        {
            vehiculo->x += 1;
        }
        //limpiar recorrido
        for(int i=0; i<4; i++)
        {
            gotoxyFrog(auxX, auxY);
            auxY++;
            if((vehiculo->sentido == 'd' && auxX<FIN_X) || vehiculo->sentido == 'i')
                printf(" ");
        }
        //limite de pantalla
        if(vehiculo->x == INI_X-7 && vehiculo->sentido == 'i')
        {
            if(vehiculo->modelo == 1)
                vehiculo->x = CARRIL_1X;
            else
                vehiculo->x = CARRIL_3X;
        }
        else if(vehiculo->x == FIN_X+7 && vehiculo->sentido == 'd')
        {
            if(vehiculo->modelo == 2)
                vehiculo->x = CARRIL_2X;
            else
                vehiculo->x = CARRIL_4X;
        }
        actualizarPosV(vehiculo);
}
int model(int modelo)
{
    return modelo<4 ? 7 : 14;
}
void actualizarPosF(stFrog* frogy)
{
    int x = frogy->x, y = frogy->y;
    for(int i=0; i<4; i++)
    {
        for(int c=0; c<7; c++)
        {
            frogy->matrizX[i][c] = x;
            frogy->matrizY[i][c] = y;
            x++;
        }
        x -= 7;
        y++;
    }
}

void actualizarPosV(stVehiculo* vehiculo)
{
    int column = model(vehiculo->modelo);
    int x = vehiculo->x, y = vehiculo->y;
    for(int i=0; i<4; i++)
    {
        for(int c=0; c<column; c++)
        {
            vehiculo->matrizX[i][c] = x;
            vehiculo->matrizY[i][c] = y;
            x++;
        }
        x -= column;
        y++;
    }
}
stVehiculo initVehiculo(int x,int y,char sentido,int modelo, int desplazamiento, int c1, int c2, int c3)
{
    stVehiculo aux;
    aux.x = x;
    aux.y = y;
    actualizarPosV(&aux);
    aux.sentido = sentido;
    aux.modelo = modelo;
    aux.desplazamiento = desplazamiento;
    aux.color1 = c1;
    aux.color2 = c2;
    aux.color3 = c3;
    return aux;
}
stFrog createFrog(int color)
{

    stFrog aux;
    aux.color=color;
    aux.x = 25+INI_X;
    aux.y = 20+INI_Y;
    int xX= aux.y, yY = aux.x;
    for(int i=0; i<4; i++)
    {
        for(int c=0; c<7; c++)
        {
            aux.matrizX[i][c] = xX;
            aux.matrizY[i][c] = yY;
            xX++;
        }
        xX -= 7;
        yY++;
    }
    aux.lives = 4;
    aux.movimientos = 0;
    return aux;
};
void moverFrog(stFrog* frogy, int direccion)
{
    char frog[4][4][7]=
    {
        {//arriba
            {"       "},
            {" 1 3 1 "},
            {" 21112 "},
            {" 12221 "}
        },
        {//abajo
            {" 13331 "},
            {" 31113 "},
            {" 1 2 1 "},
            {"       "}
        },
        {//der
            {"33 333 "},
            {" 1313  "},
            {" 1212  "},
            {"22 222 "}
        },
        {//izq
            {" 333 33"},
            {"  3131 "},
            {"  2121 "},
            {" 222 22"}
        },
    };
    int auxX = frogy->x, auxY = frogy->y;
    switch(direccion)
    {
    case ARRIBA:
        frogy->y-=1;
        printFrogL(frogy->x, frogy->y, 4, 7, frog[0], *frogy);
        for(int l=0; l<2;l++)
        {
            for(int i=0; i<7; i++)
            {
                gotoxyFrog(auxX, auxY+3);
                auxX++;
                printf(" ");
            }
            auxX-=7;
            auxY+=1;
        }
        break;
    case ABAJO:
        frogy->y+=1;
        printFrogL(frogy->x, frogy->y, 4, 7, frog[1], *frogy);
        for(int l=0; l<2;l++)
        {
            for(int i=0; i<7; i++)
            {
                gotoxyFrog(auxX, auxY-1);
                auxX++;
                printf(" ");
            }
            auxX-=7;
            auxY+=1;
        }
        break;
    case DERECHA:
        frogy->x+=2;
        printFrogL(frogy->x, frogy->y, 4, 7, frog[2], *frogy);
        for(int l=0; l<2;l++)
        {
            for(int i=0; i<4; i++)
            {
                gotoxyFrog(auxX, auxY);
                printf(" ");
                auxY++;
            }
            auxX+=1;
            auxY-=4;
        }
        break;
    case IZQUIERDA:
        frogy->x-=2;
        printFrogL(frogy->x, frogy->y, 4, 7, frog[3], *frogy);
        for(int l=0; l<2;l++)
        {
            for(int i=0; i<4; i++)
            {
                gotoxyFrog(auxX+5, auxY);
                printf(" ");
                auxY++;
            }
            auxX+=1;
            auxY-=4;
        }
        break;
    default:
        printFrogL(frogy->x, frogy->y, 4, 7, frog[0], *frogy);
        break;
    }
    actualizarPosF(frogy);
}
void printFrogC(int x,int y,char text[], int width, stFrog frogy)
{
    for(int i=0; i < width; i++)
    {
        gotoxyFrog(x,y);

            if(text[i] == '1')
            {
                printColor(frogy.color, 219);
            }
            else if(text[i] == '2')
            {
                printColor(frogy.color, 223);
            }
            else if(text[i] == '3')
            {
                printColor(frogy.color, 220);
            }
            else
            {
                printf(" ");
            }
        x++;
    }
}
void printFrogL(int x,int y,int line,int column,char screen[line][column], stFrog frogy)
{
    int i;
    for(i=0; i<line; i++)
    {
        printFrogC(x,y,screen[i], column, frogy);
        y++;
    }
}
int muerte(stFrog frogy,stVehiculo vehiculo)
{
    int muerte=0, column=0, flag=1;
    if (vehiculo.modelo < 4)
    {
        column = 7;
    }
    else
    {
        column = 14;
    }
    while(flag == 1)
    {
        for(int fy=0; fy<4; fy++)
        {
            for(int fx=0; fx<7; fx++)
            {
                if(fy!=0 && fx!=0)
                {
                    for(int vy=0; vy<4; vy++)
                    {
                        for(int vx=0; vx<column; vx++)
                        {
                            if((frogy.matrizX[fy][fx] == vehiculo.matrizX[vy][vx]) && (frogy.matrizY[fy][fx] == vehiculo.matrizY[vy][vx]))
                            {
                                muerte=1;
                            }
                        }
                    }
                }
            }
        }
        flag=0;
    }
    return muerte;
}
void marcarFlechas(int flecha, int last)
{
    char keyUp[4][4][6] =
    {
        {
            {" ____ "},
            {"||< ||"},
            {"||__||"},
            {"|/__.|"}
        },
        {
            {" ____ "},
            {"||> ||"},
            {"||__||"},
            {"|/__.|"}
        },
        {
            {" ____ "},
            {"||^ ||"},
            {"||__||"},
            {"|/__.|"}
        },
        {
            {" ____ "},
            {"||v ||"},
            {"||__||"},
            {"|/__.|"}
        }
    };
    char keyDown[4][4][6] =
    {
        {
            {" ____ "},
            {"|.__/|"},
            {"||< ||"},
            {"||__||"}
        },
        {
            {" ____ "},
            {"|.__/|"},
            {"||> ||"},
            {"||__||"}
        },
        {
            {" ____ "},
            {"|.__/|"},
            {"||^ ||"},
            {"||__||"}
        },
        {
            {" ____ "},
            {"|.__/|"},
            {"||v ||"},
            {"||__||"}
        }
    };
    pressKey(last,4,4,6,keyUp);
    pressKey(flecha,4,4,6,keyDown);
}
void pressKey(int flecha,int m,int l,int c, char keys[m][l][c])
{
    if(flecha == ARRIBA)
    {
        printMenu(INI_X-13,INI_Y+11,l,c,keys[2]);
    }
    else if(flecha == ABAJO)
    {
        printMenu(INI_X-13,INI_Y+19,l,c,keys[3]);
    }
    else if(flecha == DERECHA)
    {
        printMenu(INI_X-7,INI_Y+15,l,c,keys[1]);
    }
    else if(flecha == IZQUIERDA)
    {
        printMenu(INI_X-19,INI_Y+15,l,c,keys[0]);
    }
}

void showTitle()
{
    char title[6][34]=
    {
       {"111111121111112  1111112  1111112 "},
       {"113666641136611211366611211366664 "},
       {"111112  11111134117   117117  1112"},
       {"113664  11366112117   117117   117"},
       {"117     117  117511111134511111134"},
       {"564     564  564 5666664  5666664 "}
    };
    printTitleL(52, 3, 6, 34, title, VERDE);
}
void printTitleL(int x,int y,int line,int column,char title[line][column], int color)
{
    for(int i=0; i<line; i++)
    {
        printTitleC(x,y,title[i], column, color);
        y++;
    }
}
void printTitleC(int x,int y,char title[], int width, int color)
{
    for(int i=0; i < width; i++)
    {
        gotoxyFrog(x,y);
        if(title[i] == '1')
        {
            printColor(color, 219);
        }
        else if(title[i] == '2')
        {
            printColor(color, ESQ_SD);
        }
        else if(title[i] == '3')
        {
            printColor(color, ESQ_SI);
        }
        else if(title[i] == '4')
        {
            printColor(color, ESQ_ID);
        }
        else if(title[i] == '5')
        {
            printColor(color, ESQ_II);
        }
        else if(title[i] == '6')
        {
            printColor(color, BAR_H);
        }
        else if(title[i] == '7')
        {
            printColor(color, BAR_V);
        }
        else if(title[i] != ' ')
        {
            printColor(color, title[i]);
        }
        else
        {
            //printf(" ");
        }
        x++;
    }
}


int movimientoLegal(int tecla,stFrog frogy)
{
        int rt=0;
        if(tecla==ABAJO && frogy.matrizY[3][0] < FIN_Y-1)
        {
            rt=1;
        }
        else if(tecla==ARRIBA && frogy.matrizY[0][0] > INI_Y)
        {
            rt=1;
        }
        else if(tecla==DERECHA && frogy.matrizX[0][6] < FIN_X-1)
        {
            rt=1;
        }
        else if(tecla==IZQUIERDA && frogy.matrizX[0][0] > INI_X+1)
        {
            rt=1;
        }
    return rt;
}
