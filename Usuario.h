#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

//--------------LIBRERIAS-CB--------------//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#include <direct.h>

//----------------RUTAS-ARCHIVOS----------------//
#define RUTA_USUARIOSGen "UsuariosGenerales.dat"

//-----------ESC----------------//
#define ESC      27
#define ENTER    13
#define ALLGAMES 3

//--------POSICION EN Y DE MENUS.
#define POSS_Y 23

//----------------COLORES----------------------//
#define ROJO     31
#define VERDE    32
#define AMARILLO 33
#define AZUL     34
#define VIOLETA  35
#define CIAN     36
#define BLANCO   37

#define RESET_COLOR     "\x1b[0m"
#define RED_T           "\x1b[31m"
#define GREEN_T         "\x1b[32m"
#define YELLOW_T        "\x1b[33m"
#define BLUE_T          "\x1b[34m"
#define MAGENTA_T       "\x1b[35m"
#define CYAN_T          "\x1b[36m"
#define WHITE_T         "\x1b[37m"


//FLECHAS DE MOVIMIENTO.
#define ARRIBA 		72
#define IZQUIERDA 	75
#define DERECHA 	77
#define ABAJO 		80


//-----------ESTRUCTURAS-----------
typedef struct {

    int colorTableroSN[10];
    int validosTableroSN;
    int colorSnake[10];
    int validosSnake;
    int colorTableroPN[10];
    int validosTableroPN;
    int colorPelota[10];
    int validosPelota;
    int colorFrog[10];
    int validosFrog;

} stTienda;

typedef struct {

    int  idUsuario;
    int  tipo;          /// 1 admin y 0 usuario
    int  activo;        /// 1 ativo y 0 de baja
    int  modi;          /// 0 sin modificar / 1 modificado
    char nombre[20];
    char clave[20];
    int  coins;
    int  maxFrog;       /// Maxima puntuacion en Frog
    int  maxSnake;      /// Maxima puntuacion en Snake
    int  maxPong;       /// Maxima puntuacion (partidos ganados) en Pong
    int  totalPuntaje;  /// Total de puntos(Promedio)

    stTienda compras;

} stUsuario;

///-------------------PRINCIPALES:
stUsuario creacionDeUsuario      ();
int       promedioDePuntos       (stUsuario ususario);
void      validarNombre          (char nombre[]);
int       existenciaUsuArchi     (char ruta[], char unNombre[]);
void      guardarUsuArchivo      (char ruta[], stUsuario usuario);
void      verArchi               (char ruta[]);
int       cantidadDeUsuarios     (char ruta[]);
void      mostrarUsuario         (stUsuario usuarioE);
void      mostrarPuntajeUsu      (stUsuario usuarioE);
void      verPerfil              (stUsuario unUsu);
void      guardarPerfilArchi     (stUsuario unUsu);
int       possUsuArchivo         (stUsuario usuarioActual);
void      insertarEnOrden        (stUsuario U[], int J, stUsuario dato);
void      ordenPorInsercionArr   (stUsuario U[], int V);
int       deArchiToArreglo       (stUsuario U[], int dim);
void      muestraArreglo         (stUsuario ususarios[], int validos);
void      impresionMAME          ();
void      calaberaCreacionUsuario();
void      calaberaAdmin          (int x, int y);
void      joystick               (int x, int y);
void      printTienda            (int y);
void      printTiendaMoneda      (int y);
void      printTiendaTitle       ();
void      imprimirBloqueDeColor  (int color);

///--------REQUERIDA EN TODO EL PROGRAMA---------///
void      gotoxy               (int x, int y);

#endif // USUARIO_H_INCLUDED
