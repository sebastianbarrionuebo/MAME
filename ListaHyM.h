#ifndef LISTAHYM_H_INCLUDED
#define LISTAHYM_H_INCLUDED
#include "ListaConsumos.h"

///---------------LISTA DE MEJORES JUGADORES E HISTORIAL-----------------///

typedef struct _nodoM {

    stUsuario usuario;
    struct _nodoM *siguiente;

} nodoMaximos;

///------------------PRINCIPALES:
nodoMaximos *inicListaMejores           ();
nodoMaximos *crearNodoMejor             (stUsuario dato);
nodoMaximos *agregarAlPrinMejores       (nodoMaximos *lista, nodoMaximos *nuevo);
nodoMaximos *agregarEnOrdenPorPuntaje   (nodoMaximos *lista, nodoMaximos *aordenar);
void         mostrarListaMejores        (nodoMaximos *mejores);


#endif // LISTAHYM_H_INCLUDED
