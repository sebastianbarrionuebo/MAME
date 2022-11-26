#include "PingPong.h"


void asignaPuntajePong (stUsuario *unUsuario, int puntaje) {
    unUsuario->coins += puntaje;
    unUsuario->maxPong += puntaje;
}

void cicloPongVS (stUsuario *unUsu) {
    int golesJugador1 = 0, golesJugador2 = 0;
    do {
        float velocidadVariable = 60;
        srand(time(NULL));
        imprimirEscenarioPong(*unUsu);
        stRaqueta raqueta1;
        stRaqueta raqueta2;
        raqueta1 = crearRaquetaPlayer1();
        raqueta2 = crearRaquetaPlayer2();
        char tecla;

        nodoPelota *Pelota = crearPelota();


        imprimirRaqueta(raqueta1.y,raqueta1);
        imprimirRaqueta(raqueta2.y,raqueta2);
        imprimirPelota(Pelota, *unUsu);
        int inicioY,inicioX;
        generaRandXY(&inicioX,&inicioY);
        int timig = 0;

        gotoxy(10,3);
        printf("Jugador1: %d", golesJugador1);
        gotoxy(94,3);
        printf("Jugador2: %d", golesJugador2);
        int gol = 0;

        do {

            if(kbhit()) {
                tecla = getch();

                switch(tecla) {

                case 'w':
                    if(raqueta1.y > TAB_Y_P+3)
                        movimientoRaquetaCiclico(-1, &raqueta1);
                    break;

                case 's':
                    if(raqueta1.y < LIMITE_Y_P+2)
                        movimientoRaquetaCiclico(1, &raqueta1);
                    break;

                case ARRIBA:
                    if(raqueta2.y > TAB_Y_P+3)
                        movimientoRaquetaCiclico(-1, &raqueta2);
                    break;

                case ABAJO:
                    if(raqueta2.y < LIMITE_Y_P+2)
                        movimientoRaquetaCiclico(1, &raqueta2);
                    break;
                }
            }
            Sleep(FRAMERRATE_P);
            timig+=FRAMERRATE_P;
            if(timig>=velocidadVariable) {
                movimientoPelota(Pelota->Pelota.x+inicioX,Pelota->Pelota.y+inicioY,Pelota);
                imprimirPelota(Pelota, *unUsu);
                reboteCampo(Pelota, &inicioY);
                reboteRaqueta(Pelota, &inicioX, raqueta1, raqueta2);
                velocidadVariable = reboteCertero(Pelota, raqueta1, raqueta2, velocidadVariable);
                timig=0;
            }
            gol = altoPunto(Pelota, &golesJugador1, &golesJugador2);
            gotoxy(0,0);
            printf("%2.f", velocidadVariable);

        } while(gol == 0);

    } while(golesJugador1 < 3 && golesJugador2 < 3);
    if (golesJugador1 == 3){
        asignaPuntajePong(unUsu, 20);
    }
}

void cicloPongVsIA (stUsuario *unUsu) {
    int golesJugador1 = 0, golesIA = 0;
    do {
        float velocidadVariable = 60;
        srand(time(NULL));
        imprimirEscenarioPong(*unUsu);
        stRaqueta raqueta1;
        stRaqueta raquetaIA;
        raqueta1 = crearRaquetaPlayer1();
        raquetaIA = crearRaquetaPlayer2();
        char tecla;

        nodoPelota *Pelota = crearPelota();


        imprimirRaqueta(raqueta1.y,raqueta1);
        imprimirRaqueta(raquetaIA.y,raquetaIA);
        imprimirPelota(Pelota, *unUsu);
        int inicioY,inicioX;
        generaRandXY(&inicioX,&inicioY);
        int timing = 0;

        gotoxy(10,3);
        printf("Jugador1: %d", golesJugador1);
        gotoxy(94,3);
        printf("Jugador2: %d", golesIA);
        int gol = 0;
        gotoxy(30,34);
        system("pause");
        do {

            if(kbhit()) {
                tecla = getch();

                switch(tecla) {

                case 'w':
                    if(raqueta1.y > TAB_Y_P+3)
                        movimientoRaquetaCiclico(-1, &raqueta1);
                    break;

                case 's':
                    if(raqueta1.y < LIMITE_Y_P+2)
                        movimientoRaquetaCiclico(1, &raqueta1);
                    break;
                }
            }
            Sleep(FRAMERRATE_P);
            timing+=FRAMERRATE_P;
            if(timing>=velocidadVariable) {
                movimientoPelota(Pelota->Pelota.x+inicioX,Pelota->Pelota.y+inicioY,Pelota);
                imprimirPelota(Pelota, *unUsu);
                movRaquetaIA(&raquetaIA, inicioX, Pelota, inicioY);
                reboteCampo(Pelota, &inicioY);
                reboteRaqueta(Pelota, &inicioX, raqueta1, raquetaIA);
                velocidadVariable = reboteCertero(Pelota, raqueta1, raquetaIA, velocidadVariable);
                timing=0;
            }
            gol = altoPunto(Pelota, &golesJugador1, &golesIA);
        } while(gol == 0);
    } while(golesJugador1 < 3 && golesIA < 3);
    if (golesJugador1 == 3){
        asignaPuntajePong(unUsu, 50);
    }
}


void generaRandXY (int *inicioX, int *inicioY) {

    *inicioX = rand()%3;
    *inicioY = rand()%2;

    if(*inicioX == 0 || *inicioX == 1) {
        *inicioX = -2;
    }
    if(*inicioY == 0) {
        *inicioY = -1;
    }
}

stRaqueta crearRaquetaPlayer1() {

    stRaqueta raqueta;

    raqueta.x = TAB_X_P+3;
    raqueta.y =LIMITE_Y_P /2 + TAB_Y_P;
    raqueta.ap  = 219;
    raqueta.tinte = 37;

    return raqueta;
}

stRaqueta crearRaquetaPlayer2() {

    stRaqueta raqueta;

    raqueta.x = (LIMITE_X_P + TAB_X_P)-2;
    raqueta.y =LIMITE_Y_P /2 + TAB_Y_P;
    raqueta.ap  = 219;
    raqueta.tinte = 37;

    return raqueta;
}

nodoPelota *crearPelota() {

    nodoPelota *pelotita = (nodoPelota *)malloc(sizeof(nodoPelota));
    pelotita->Pelota.x  = LIMITE_X_P /2 + TAB_X_P;
    pelotita->Pelota.y  = LIMITE_Y_P /2 + TAB_Y_P;
    pelotita->Pelota.ap = 79;
    pelotita->Pelota.tinte = 37;
    pelotita->siguiente = crearSombra();

    return pelotita;
}

nodoPelota *crearSombra() {

    nodoPelota *sombraP = (nodoPelota *)malloc(sizeof(nodoPelota));
    sombraP->Pelota.x  = LIMITE_X_P /2 + TAB_X_P;
    sombraP->Pelota.y  = LIMITE_Y_P /2 + TAB_Y_P + 1;
    sombraP->Pelota.ap = 255;
    sombraP->Pelota.tinte = 30;
    sombraP->siguiente = NULL;

    return sombraP;
}

void imprimirPelota(nodoPelota *pelota, stUsuario unUsu) {
    while(pelota != NULL) {
        printf("%c[1;%dm", ESC, unUsu.compras.colorPelota[0]);
        gotoxy(pelota->Pelota.x, pelota->Pelota.y);
        printf("%c", pelota->Pelota.ap);
        printf("%c[0m", ESC);
        pelota = pelota->siguiente;
    }
}

void movimientoPelota (int x, int y, nodoPelota *pelota) {

    int possProx, possProy, possActualx, possActualy;
    possProx = x;
    possProy = y;

    while(pelota != NULL) {

        possActualx = pelota->Pelota.x;
        possActualy = pelota->Pelota.y;
        pelota->Pelota.x = possProx;
        pelota->Pelota.y = possProy;
        possProx = possActualx;
        possProy = possActualy;
        pelota = pelota->siguiente;
    }
}

void reboteCampo (nodoPelota *pelota, int *inicioY) {

    if(pelota->Pelota.y <= TAB_Y_P+1 || pelota->Pelota.y == (LIMITE_Y_P + TAB_Y_P)) {
        *inicioY *= (-1);
    }
}
void reboteRaqueta (nodoPelota *pelota, int *inicioX, stRaqueta raqueta1, stRaqueta raqueta2) {

    if(pelota->Pelota.x <= raqueta1.x+1 && pelota->Pelota.y >= raqueta1.y-2 && pelota->Pelota.y <= raqueta1.y+2) {
        *inicioX *= (-1);
    }
    if(pelota->Pelota.x >= raqueta2.x-1 && pelota->Pelota.y >= raqueta2.y-2 && pelota->Pelota.y <= raqueta2.y+2) {
        *inicioX *= (-1);
    }

}
//COLOR AL REBOTAR EN EL CENTRO
float reboteCertero (nodoPelota *pelota,stRaqueta raqueta1, stRaqueta raqueta2, float variable) {

    if(pelota->Pelota.x == raqueta1.x+1 || pelota->Pelota.x == raqueta2.x-1) {
        int validCentro = 0;
        validCentro = centro(pelota, raqueta1, raqueta2);
        if (validCentro == 1) {
            variable = plusUltra(variable);
        } else {
            variable = VELOCIDADFIJA_P;
        }
    }
    return variable;
}

int centro (nodoPelota *pelota,stRaqueta raqueta1, stRaqueta raqueta2) {

    int centro = 0;
    if(pelota->Pelota.x == raqueta1.x+1 && pelota->Pelota.y == raqueta1.y) {
        centro = 1;
    }
    if(pelota->Pelota.x == raqueta2.x-1 && pelota->Pelota.y == raqueta2.y) {
        centro = 1;
    }
    return centro;
}

float plusUltra (float velocidad) {

    velocidad -= (velocidad*50)/100;
    return velocidad;
}


int altoPunto (nodoPelota *pelota, int *golesJugador1, int *golesJugador2) {

    int gol = 0;
    if (pelota->Pelota.x <= TAB_X_P) {
        gol = 1;
        *golesJugador2 += 1;
    } else if(pelota->Pelota.x >= LIMITE_X_P+TAB_X_P) {
        gol = 1;
        *golesJugador1 += 1;
    }
    return gol;
}

void imprimirRaqueta(int y, stRaqueta r) {

    int i = 0, j = -2;
    printf("%c[1;%dm", ESC, r.tinte);
    if(y > 0) {
        for(i=0; i<5; i++) {
            gotoxy(r.x,r.y+(-3));
            printf("%c", 255);
            gotoxy(r.x,r.y+j);
            printf("%c", r.ap);
            j++;
        }
    }
    if(y < 0) {
        for(i=0; i<5; i++) {
            gotoxy(r.x,r.y+3);
            printf("%c", 255);
            gotoxy(r.x,r.y+j);
            printf("%c", r.ap);
            j++;
        }
    }
    printf("%c[0m", ESC);
}

void movimientoRaquetaCiclico(int y, stRaqueta *r) {
    r->y += y;
    imprimirRaqueta(y,*r);
}
// posibilidad de que se mueva pal otro lado
void movRaquetaIA (stRaqueta *raquetaIA, int direccionPX, nodoPelota *pelota, int direccionPY) {

    int posibilidad = rand()%101;

    if(direccionPX == 2 && raquetaIA->y > TAB_Y_P+3 && pelota->Pelota.y < raquetaIA->y && direccionPY == -1) {
        if(posibilidad <= POSIB_FALLO_P) {
            raquetaIA->y += 0;
        } else {
            raquetaIA->y += direccionPY;
            imprimirRaqueta(direccionPY, *raquetaIA);
        }


    } else if (direccionPX == 2 && raquetaIA->y < LIMITE_Y_P+2 && pelota->Pelota.y > raquetaIA->y && direccionPY == 1) {
        if(posibilidad <= POSIB_FALLO_P) {
            raquetaIA->y -= 0;
        } else {
            raquetaIA->y += direccionPY;
            imprimirRaqueta(direccionPY, *raquetaIA);
        }

    }
}

void imprimirEscenarioPong(stUsuario unUsu) {
    system("cls");
    int i, j;
    char c;
    printf("%c[1;%dm", ESC, unUsu.compras.colorTableroPN[0]);
    gotoxy(TAB_X_P, TAB_Y_P);
    for(j=0; j<LIMITE_Y_P+2; j++) { //LARGO
        for(i=0; i<LIMITE_X_P+2; i++) { //ANCHO
            //COLUMNAS:
            if(i==0 || i==LIMITE_X_P+1) {
                switch(j) {
                case 0:
                    if(i==0) {
                        c = ESQ_SI_P;
                    } else if(i==LIMITE_X_P+1) {
                        c = ESQ_SD_P;
                    }
                    break;
                case LIMITE_Y_P+1:
                    if(i==0) {
                        c = ESQ_II_P;
                    } else if(i==LIMITE_X_P+1) {
                        c = ESQ_ID_P;
                    }
                    break;
                default:
                    c = BAR_V_P;
                    break;
                }
            }//ENTRE MEDIO:
            else {//FILAS
                if(j==0 || j==LIMITE_Y_P+1) {
                    c = BAR_H_P;
                } else {
                    c = ' ';
                }
            }
            printf("%c",c);
            if(i==LIMITE_X_P+1) {
                gotoxy(TAB_X_P, TAB_Y_P+j+1);
            }
        }
        Sleep(5);
    }
    printf("%c[0m", ESC);
}
