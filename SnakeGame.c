#include "SnakeGame.h"

void inicSnake(nodoArbol *unUsu) {
    stManzana Manzana = crearManzana();
    stSnake Snake[2000];
    int validosSnake;
    int puntaje;

    system("cls");
    validosSnake = preCicloDeJuego(Snake, Manzana, &unUsu->dato);
    puntaje = cicloDeJuego(Snake, validosSnake, Manzana, &unUsu->dato);
    asignaPuntaje(&unUsu->dato, puntaje);
    perdisteWey();
    Sleep(2000);
}

int preCicloDeJuego (stSnake snake[],stManzana Manzana, stUsuario *unUsuario) {
    stSnake   cabeza;
    stSnake   cuerpo;
    stSnake   vacio;
    cabeza  = crearCabeza();
    cuerpo  = crearCuerpo(unUsuario);
    vacio   = crearVacio();
    snake[0] = cabeza;
    snake[1] = cuerpo;
    snake[2] = vacio;

    imprimirEscenario(unUsuario);
    imprimirManzana(Manzana);

    return 3;
}

int cicloDeJuego (stSnake snake[],int validosSnake, stManzana Manzana, stUsuario *unusuario) {


    int gameOver = 0, timing = 0, tecla = 0, colision = 0, PUNTAJE = 0;

    imprimirSerpiente(snake, validosSnake);

    while(!gameOver) {

        if(kbhit()) {
            tecla = getch();
            switch(tecla) {
            case ARRIBA:
                snake[0].AP = LENGUA_ARRIBA;
                break;
            case ABAJO:
                snake[0].AP = LENGUA_ABAJO;
                break;
            case DERECHA:
                snake[0].AP = LENGUA_DERECHA;
                break;
            case IZQUIERDA:
                snake[0].AP = LENGUA_IZQUIERDA;
                break;
            default:
                break;
            }
        }

        Sleep(FRAMERATE);
        timing+=FRAMERATE;
        if(timing>=VELOCIDAD) {
            switch(tecla) {
            case ARRIBA:
                movimientoCabeza(snake[0].X,snake[0].Y-1, snake, validosSnake);
                break;
            case ABAJO:
                movimientoCabeza(snake[0].X,snake[0].Y+1, snake, validosSnake);
                break;
            case DERECHA:
                movimientoCabeza(snake[0].X+1,snake[0].Y, snake, validosSnake);
                break;
            case IZQUIERDA:
                movimientoCabeza(snake[0].X-1,snake[0].Y, snake, validosSnake);
                break;
            }
            imprimirSerpiente(snake, validosSnake);
            colision = comerManzana(Manzana, snake);
            if(colision != 0) {
                sumaDeLosPuntos(Manzana, &PUNTAJE);
                gotoxy(30,4);
                printf("\tPuntos: %d", PUNTAJE);
                validosSnake = crecimientoSnake(snake, validosSnake, 2000, Manzana, unusuario);
                Manzana = crearManzana();
                imprimirManzana(Manzana);
            }
        }
        gameOver = muerteSnake(snake, validosSnake);
    }
    return PUNTAJE;
}

void imprimirEscenario(stUsuario *unusuario) {
    int i, j;
    char c;
    gotoxy(TAB_X, TAB_Y);

    for(j=0; j<LIMITE_Y+2; j++) { //LARGO
        for(i=0; i<LIMITE_X+2; i++) { //ANCHO
            //COLUMNAS:
            if(i==0 || i==LIMITE_X+1) {
                switch(j) {
                case 0:
                    if(i==0) {
                        c = ESQ_SI;
                    } else if(i==LIMITE_X+1) {
                        c = ESQ_SD;
                    }
                    break;
                case LIMITE_Y+1:
                    if(i==0) {
                        c = ESQ_II;
                    } else if(i==LIMITE_X+1) {
                        c = ESQ_ID;
                    }
                    break;
                default:
                    c = BAR_V;
                    break;
                }
            }
            //ENTRE MEDIO:
            else {
                //FILAS
                if(j==0 || j==LIMITE_Y+1) {
                    c = BAR_H;
                } else {
                    c = ' ';
                }
            }
            printf("%c[1;%dm", ESC, unusuario->compras.colorTableroPN[0]);
            printf("%c",c);
            //printf("%c[0m", ESC);
            if(i==LIMITE_X+1) {
                gotoxy(TAB_X, TAB_Y+j+1);
            }
        }
        Sleep(5);
    }
}

stSnake crearCabeza () {
    stSnake cabeza;
    cabeza.X = LIMITE_X / 2 + TAB_X;
    cabeza.Y = LIMITE_Y / 2 + TAB_Y;
    cabeza.AP = LENGUA_ARRIBA;
    cabeza.COLOR = 31;
    return cabeza;
}

stSnake crearCuerpo (stUsuario *unUsuario) {
    stSnake cuerpo;
    cuerpo.X  = LIMITE_X / 2 + TAB_X;
    cuerpo.Y  = (LIMITE_Y / 2 + TAB_Y)+1;
    cuerpo.AP = CUERPO;
    cuerpo.COLOR = unUsuario->compras.colorSnake[0];
    return cuerpo;
}

stSnake crearVacio () {
    stSnake vacio;
    vacio.X = LIMITE_X / 2 + TAB_X;
    vacio.Y = (LIMITE_Y / 2 + TAB_Y)+2;
    vacio.AP = 255;
    vacio.COLOR = 30;
    return vacio;
}

stManzana crearManzana () {
    int probabilidad = rand()%101;
    stManzana Manzana;
    Manzana.X = rand()%(LIMITE_X)+ TAB_X+1;
    Manzana.Y = rand()%(LIMITE_Y)+ TAB_Y+1;
    Manzana.AP = AP_MANZANA;

    if(probabilidad <= PROB_MD) {
        Manzana.COLOR  = 33;
        Manzana.PUNTOS = PMANZANADORADA;
    } else {
        Manzana.COLOR  = 31;
        Manzana.PUNTOS = PMANZANA;
    }
    return Manzana;
}

void imprimirSerpiente (stSnake snake[], int validos) {
    int i = 0;
    for(i = 0; i< validos; i++) {
        printf("%c[1;%dm", ESC, snake[i].COLOR);
        gotoxy(snake[i].X, snake[i].Y);
        printf("%c", snake[i].AP);
        printf("%c[0m", ESC);
    }
}

void imprimirManzana(stManzana manzana) {
    printf("%c[1;%dm", ESC, manzana.COLOR);
    gotoxy(manzana.X, manzana.Y);
    printf("%c", manzana.AP);
    printf("%c[0m", ESC);
}

void movimientoCabeza (int x, int y, stSnake snake[], int validos) {
    int i = 0;
    int posActualX, posActualY, posProxX, posProxY;
    posProxX = x;
    posProxY = y;

    while(i < validos) {
        posActualX = snake[i].X;
        posActualY = snake[i].Y;
        snake[i].X = posProxX;
        snake[i].Y = posProxY;
        posProxX = posActualX;
        posProxY = posActualY;
        i++;
    }
}

int comerManzana (stManzana manzana, stSnake snake[]) {
    int colision = 0;

    if(snake[0].X == manzana.X && snake[0].Y == manzana.Y) {
        colision = 1;
    }
    return colision;
}

void sumaDeLosPuntos (stManzana manzana, int *PUNTOS) {

    if(manzana.PUNTOS == PMANZANA) {
        *PUNTOS = *PUNTOS + PMANZANA;
    } else if(manzana.PUNTOS == PMANZANADORADA) {
        *PUNTOS = *PUNTOS + PMANZANADORADA;
    }
}

void asignaPuntaje (stUsuario *unUsuario, int puntaje) {
    int coins = 0;
    coins = puntaje;
    unUsuario->coins += coins;
    if(puntaje > unUsuario->maxSnake) {
        unUsuario->maxSnake = puntaje;
    }
}

int crecimientoSnake (stSnake snake[], int validos, int dim, stManzana tipo, stUsuario *unUsuario) {
    stSnake cuerpoAgregado;
    cuerpoAgregado = crearCuerpo(unUsuario);
    stSnake auxVacio;
    int i = validos-1;
    int j = 0;

    if(tipo.PUNTOS == PMANZANA && validos < dim) {
        auxVacio = snake[i];
        snake[i] = cuerpoAgregado;
        snake[i+1] = auxVacio;
        validos++;
    }
    while(tipo.PUNTOS == PMANZANADORADA && validos<dim && j < 3) {
        auxVacio = snake[i];
        snake[i] = cuerpoAgregado;
        snake[i+1] = auxVacio;
        i++;
        j++;
        validos++;
    }
    return validos;
}

int colicionSnakeSnake (stSnake snake[], int validos) {
    int i = 1, muerte = 0;
    while(i<validos && muerte != 1) {
        if (snake[0].X == snake[i].X && snake[0].Y == snake[i].Y) {
            muerte = 1;
        } else {
            i++;
        }
    }
    return muerte;
}

int colicionTablero (stSnake snake[]) {

    int muerte = 0;

    if (snake[0].X <= TAB_X || snake[0].Y <= TAB_Y || snake[0].X >= (TAB_X + LIMITE_X)+1 || snake[0].Y >= (TAB_Y + LIMITE_Y)+1) {
        muerte = 1;
    }

    return muerte;
}

int muerteSnake (stSnake snake[], int validos) {


    int muerte = 0;

    if (colicionTablero(snake) != 0 || colicionSnakeSnake(snake, validos) != 0) {
        muerte = 1;
    }
    return muerte;
}

void perdisteWey () {
    gotoxy(32,20);
    printf(" _______  _______  __   __  _______    _______  __   __  _______  ______  \n");
    gotoxy(32,21);
    printf("|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ | \n");
    gotoxy(32,22);
    printf("|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | || \n");
    gotoxy(32,23);
    printf("|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_\n");
    gotoxy(32,24);
    printf("|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  | \n");
    gotoxy(32,25);
    printf("|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | | \n");
    gotoxy(32,26);
    printf("|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_| \n");
}
