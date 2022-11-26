#ifndef PINGPONG_H_INCLUDED
#define PINGPONG_H_INCLUDED
#include "SnakeGame.h"

#define FRAMERRATE_P     20
#define VELOCIDADFIJA_P  60

#define POSIB_FALLO_P 8
#define LIMITE_X_P	  93
#define LIMITE_Y_P	  27
#define TAB_X_P	      10
#define TAB_Y_P	      4

#define ESQ_SI_P	201
#define ESQ_SD_P	187
#define ESQ_II_P	200
#define ESQ_ID_P	188
#define BAR_H_P	    205
#define BAR_V_P  	186

typedef struct {

    int x, y, ap, tinte;

} stRaqueta;

typedef struct {

    int x, y, ap, tinte;

} stPelota;

typedef struct _pelota {

    stPelota Pelota;
    struct _pelota *siguiente;

} nodoPelota;


void        asignaPuntajePong        (stUsuario *unUsuario, int puntaje);
void        imprimirEscenarioPong    (stUsuario unUsu);
void        imprimirRaqueta          (int y,stRaqueta r);
stRaqueta   crearRaquetaPlayer1      ();
stRaqueta   crearRaquetaPlayer2      ();
void        movimientoRaquetaCiclico (int y, stRaqueta *r);
void        movRaquetaIA             (stRaqueta *raquetaIA, int direccionPX, nodoPelota *pelota, int direccionPY);
nodoPelota *crearPelota              ();
nodoPelota *crearSombra              ();
void        imprimirPelota           (nodoPelota *pelota, stUsuario unUsu);
void        movimientoPelota         (int x, int y,nodoPelota *pelota);
void        generaRandXY             (int *inicioX, int *inicioY);
void        reboteCampo              (nodoPelota *pelota, int *inicioY);
void        reboteRaqueta            (nodoPelota *pelota, int *inicioX, stRaqueta raqueta1, stRaqueta raqueta2);
int         altoPunto                (nodoPelota *pelota, int *J1, int*J2);
int         centro                   (nodoPelota *pelota,stRaqueta raqueta1, stRaqueta raqueta2);
float       plusUltra                (float velocidad);
float       reboteCertero            (nodoPelota *pelota,stRaqueta raqueta1, stRaqueta raqueta2, float variable);
void        cicloPongVS              (stUsuario *unUsu);
void        cicloPongVsIA            (stUsuario *unUsu);

#endif // PINGPONG_H_INCLUDED
