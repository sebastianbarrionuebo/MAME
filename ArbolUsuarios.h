#ifndef ARBOLUSUARIOS_H_INCLUDED
#define ARBOLUSUARIOS_H_INCLUDED
#include "ListaHyM.h"

typedef struct _nodoA{

   stUsuario  dato;
   nodoListTicket *historialCompras;
   struct _nodoA *izq;
   struct _nodoA *der;

}nodoArbol;

///---------------PRINCIPALES:
nodoArbol *inicArbol                 ();
nodoArbol *crearNodoArbol            (stUsuario  dato);
nodoArbol *agregarNodoArbolPorNombre (nodoArbol *arbol, nodoArbol *Usuario);
nodoArbol *nodoMasDerecho            (nodoArbol *arbol);
nodoArbol *nodoMasIzquierdo          (nodoArbol *arbol);
nodoArbol *borrarNodoArbolPorUsuario (nodoArbol *arbol, stUsuario dato);
nodoArbol *buscarArbolPorNombre      (nodoArbol *arbol,char nombreUsuario[]);
nodoArbol *buscarPorID               (nodoArbol *arbol, int idBuscado);
void       mostrarNodoArbol          (nodoArbol *nodito, nodoArbol *unUsu);
void       preOrden                  (nodoArbol *arbol);
void       inOrden                   (nodoArbol *arbol);
void       inOrdenPorActv            (nodoArbol *arbol, int activo);
void       postOrden                 (nodoArbol *arbol);

///---------------MODI-USUARIOS:
void       cambioNombreUs            (nodoArbol *arbolUsuarios, nodoArbol  *usuario);
void       cambioDeClave             (nodoArbol *usuario);

///---------------PASAJE:
nodoMaximos *arbolToLista            (nodoArbol *arbolUsuarios, nodoMaximos *listaMaximos);
void         inOrdenArbolToArchi     (nodoArbol *arbol, FILE *archi);
nodoArbol   *arregloToArbol          (stUsuario U[], int base, int tope);

///---------------EXISTENCIA DE USUSARIO:
nodoArbol   *descargarDeArchiAArbol  (nodoArbol *arbol);
nodoArbol   *altaCelda               (nodoArbol *unUsu);
nodoArbol   *validacionDeUsuario     (nodoArbol *arbol);
nodoArbol   *CorroborarUsuario       (nodoArbol *arbol,char nombreUs[],char claveUs[]);

#endif // ARBOLUSUARIOS_H_INCLUDED
