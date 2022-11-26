#ifndef JUMPFROG_H_INCLUDED
#define JUMPFROG_H_INCLUDED
#include "PingPong.h"

//CUERPO
#define CUBOGRANDE 	219 == 1
#define CUBOARRIBA 	223 == 2
#define CUBOABAJO   220 == 3
#define CUBOCENTRO 	254 == 4

//POSICION DEL ESCENARIO
#define INI_X	40
#define INI_Y	10
#define FIN_X	97
#define FIN_Y	34

//CARRILES
#define CARRIL_4X   42
#define CARRIL_4Y   14

#define CARRIL_3X   90
#define CARRIL_3Y   18

#define CARRIL_2X   42
#define CARRIL_2Y   22

#define CARRIL_1X   90
#define CARRIL_1Y   26

typedef struct{
    int carriles;
    int velocidad;
}stCarretera;

typedef struct
{
    int color;
    int x;
    int y;
    int lives;
    int matrizX[4][7];
    int matrizY[4][7];
    int lastMove;
    int movimientos;
} stFrog;

typedef struct
{
    int x;
    int y;
    int modelo;
    char sentido;
    int desplazamiento;
    int velocidad;
    int matrizX[4][14];
    int matrizY[4][14];
    int color1;
    int color2;
    int color3;
} stVehiculo;

///Prametros iniciales
stFrog       createFrog     (int color);
stVehiculo   inicVehiculo   ();

void         gotoxyFrog     (int X,int Y);

void         initFrog       (stUsuario* userOn);
stFrog       createFrog     ();
void         moverFrog      (stFrog* frogy, int direccion);
void         actualizarPosF (stFrog* frogy);
void         respawn        (stFrog* frogy);
int          muerte         (stFrog frogy,stVehiculo vehiculo);
int          movimientoLegal(int tecla,stFrog frogy);

void         printSlot      (int x,int y,char text[], int width);
void         printMenu      (int x,int y,int line,int column,char screen[line][column]);
void         printTextMenu  (stFrog frogy,int l, int c,char text[l][c]);
void         printText      (int dato,int c,char text[], int pos);

stVehiculo   initVehiculo   (int x,int y,char sentido,int modelo, int desplazamiento, int c1, int c2, int c3);
void         moverVehiculo  (stVehiculo* vehiculo);
void         actualizarPosV (stVehiculo* vehiculo);
void         printColor     (int color, char c);
int          model          (int modelo);

void         printVX        (int x,int y,int line,int column,char screen[line][column], stVehiculo vehiculo, char color[line][column]);
void         printVY        (int x,int y,char text[], int width, stVehiculo vehiculo, char color[]);

void         printFrogC     (int x,int y,char text[], int width, stFrog frogy);
void         printFrogL     (int x,int y,int line,int column,char screen[line][column], stFrog frogy);

void         marcarFlechas  (int flecha, int last);
void         pressKey       (int flecha,int m,int l,int c, char keys[m][l][c]);

void         showTitle      ();
void         printTitleL    (int x,int y,int line,int column,char title[line][column], int color);
void         printTitleC    (int x,int y,char text[], int width, int color);


#endif // JUMPFROG_H_INCLUDED
