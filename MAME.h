#ifndef MAME_H_INCLUDED
#define MAME_H_INCLUDED
#include "JumpFrog.h"


///----------------A JUGAR--------------------------///
void      MAME     ();

///-------------------------------HERRAMIENTAS------------------------------------------------
void      dimencionDeConsola             (int ancho, int alto);
void      imprimirMenusFor               (int filas, int columnas, char M[filas][columnas], int poss, int flechita);
int       movimientoFlecha               (int tecla, int filas, int *menu);
void      juegos                         (int cont,  int tecla);
int       selectGame                     ();

///-------------------------------MENUS------------------------------------------
nodoArbol *switchInicAJugar              (nodoArbol *unUsu);
nodoArbol *switchPingPong                (nodoArbol *unUsu);
void       switchMenuPrincipal           (nodoArbol *arbolUsuarios);
nodoArbol *switchCrearNuevoUsuario       (nodoArbol *arbolUsuarios);
nodoArbol *altaBajaAdminUsusario         (nodoArbol *arbolUsuarios, nodoArbol *unUsu);
void       switchInicioSesion            (nodoArbol *arbolUsuarios, nodoArbol *unUsu);
nodoArbol *switchInicioSesionAdmin       (nodoArbol *arbolUsuarios, nodoArbol *unUsu);
void       switchVerLiquidacion          (nodoArbol *arbolUsuarios);
void       switchVerUsuarios             (nodoArbol *arbolUsuarios);
void       switchPerfil                  (nodoArbol *arbolUsuarios, nodoArbol *unUsu);
void       switchAjustes                 (nodoArbol *arbolUsuarios, nodoArbol *unUsu);
void       switchTienda                  (nodoArbol *unUsu);
void       switchListaDeColores          (int seleccionTienda, nodoArbol *unUsu);
void       switchCambioDeEstadoAdmin     (nodoArbol *arbolUsuarios);
int        switchAdvertencia             (nodoArbol *unUsu);
void       switchcambioDeEstado          (nodoArbol *userbuscado);
nodoArbol *switchEliminarUsuario         (nodoArbol *arbolUsuarios);
nodoArbol *eliminarNodo                  (nodoArbol *arbolUsuarios, nodoArbol *aEliminar);

///------------------------------IMPRESION DE MENUS-------------------------------------------
int       imprimirMenuGeneral            (int filas, int columnas, char M[filas][columnas]);
int       imprimirMenuPrincipal          (int filas, int columnas, char M[filas][columnas]);
int       imprimirMenuCrearUsuario       (int filas, int columnas, char M[filas][columnas]);
int       imprimirMenuInicioSesionAdmin  (nodoArbol *unUsuario,int filas, int columnas, char M[filas][columnas]);
int       imprimirMenuInicioSesion       (nodoArbol *unUsua,int filas, int columnas, char M[filas][columnas]);
int       imprimirMenuTienda             (int filas, int columnas, char M[filas][columnas]);
int       imprimirMenuPerfil             (nodoArbol *unUsu, int filas, int columnas, char M[filas][columnas]);
int       imprimirMenuAjus               (int filas, int columnas, char M[filas][columnas]);
int       imprimirMenuColores            (int filas, int columnas, char M[filas][columnas]);
int       imprimirAdvertencia            (int filas, int columnas, char M[filas][columnas]);

///-----------------------------INTERACCION CON LA TIENDA-------------------------------------
int       compraDeColoresSnake           (int opcionDeCompra);
int       compraDeColores                (int opcionDeCompra);
bool      compra                         (nodoArbol *unUsu, int filas, int columnas,char M[filas][columnas], int precio, char tipo);
void      validacionDeCompra             (nodoArbol *unUsu, int arrayColores[], int *validos, char tipo, int codigoDeColor, int *coins, int precio);
void      quieroCambiarColor             (nodoArbol *unUsu,int validos, int opcion);
void      decisionDeColor                (nodoArbol *unUsuario, int validos, int eleccion);
void      cambioDePossColor              (nodoArbol *unUsuario, int coloresObtenidos[], int validos);
int       verColoresObtenidos            (int coloresObtenidos[], int validos);

#endif // MAME_H_INCLUDED
