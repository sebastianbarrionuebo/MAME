#ifndef SNAKEGAME_H_INCLUDED
#define SNAKEGAME_H_INCLUDED
#include "ArbolUsuarios.h"


//VELOCIDAD DE EJECUCION
#define FRAMERATE 	80
#define VELOCIDAD   250

//POSICION DEL ESCENARIO.
#define LIMITE_X	65
#define LIMITE_Y	35
#define TAB_X	    35
#define TAB_Y	    10

//TABLA ASCII PARA DIBUJAR ESCENARIO.
#define ESQ_SI	201
#define ESQ_SD	187
#define ESQ_II	200
#define ESQ_ID	188
#define BAR_H	205
#define BAR_V	186

//FORMA DE LA SERPIENTE.
#define LENGUA_ARRIBA 	 118
#define LENGUA_ABAJO 	 94
#define LENGUA_IZQUIERDA 62
#define LENGUA_DERECHA 	 60
#define CUERPO 			 'O'

//Manzana
#define PMANZANADORADA	5
#define PMANZANA	    1
#define PROB_MD	        25
#define AP_MANZANA      208



///-----------ESTRUCTURAS-----------
typedef struct {
    int X, Y, AP, COLOR;
} stSnake;

typedef struct {
    int X, Y, AP, COLOR, PUNTOS;
} stManzana;


///----------------------------FUNCIONES DE SNAKE------------------------------------------
void      inicSnake               (nodoArbol *unUsu);
int       preCicloDeJuego         (stSnake snake[],stManzana Manzana, stUsuario *unUsuario);
int       cicloDeJuego            (stSnake snake[],int validosSnake, stManzana Manzana, stUsuario *unusuario);
stSnake   crearCabeza             ();
stSnake   crearCuerpo             (stUsuario *unUsuario);
stSnake   crearVacio              ();
stManzana crearManzana            ();
void      imprimirEscenario       (stUsuario *unusuario);
void      imprimirSerpiente       (stSnake snake[], int validos);
void      imprimirManzana         (stManzana manzana);
void      movimientoCabeza        (int x, int y, stSnake cabeza[], int validos);
int       comerManzana            (stManzana manzana, stSnake snake[]);
void      sumaDeLosPuntos         (stManzana manzana, int *PUNTOS);
void      asignaPuntaje           (stUsuario *unUsuario, int puntaje);
int       crecimientoSnake        (stSnake snake[], int validos, int dim, stManzana tipo, stUsuario *unUsuario);
int       colicionSnakeSnake      (stSnake snake[], int validos);
int       colicionTablero         (stSnake snake[]);
int       muerteSnake             (stSnake snake[], int validos);
void      perdisteWey             ();
#endif // SNAKEGAME_H_INCLUDED
