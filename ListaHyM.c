#include "ListaHyM.h"

nodoMaximos *inicListaMejores() {
    return(NULL);
}

nodoMaximos *crearNodoMejor(stUsuario dato) {
    nodoMaximos *nuevo = (nodoMaximos*)malloc(sizeof(nodoMaximos));
    nuevo->usuario = dato;
    nuevo->siguiente = NULL;
    return(nuevo);
}

nodoMaximos *agregarAlPrinMejores(nodoMaximos *lista,nodoMaximos *agregar) {
    nodoMaximos *nuevo = crearNodoMejor(agregar->usuario);
    nuevo->siguiente=lista;
    return(nuevo);
}

nodoMaximos *agregarEnOrdenPorPuntaje (nodoMaximos *lista, nodoMaximos *aOrdenar) {

    if(!lista) {
        lista  = aOrdenar;
    } else {
        if(aOrdenar->usuario.totalPuntaje <= lista->usuario.totalPuntaje) {
            lista = agregarAlPrinMejores(lista, aOrdenar);
        } else {
            nodoMaximos *anterior = lista;
            nodoMaximos *seg = lista;
            while(seg && (aOrdenar->usuario.totalPuntaje > seg->usuario.totalPuntaje)) {
                anterior = seg;
                seg = seg->siguiente;
            }
            aOrdenar->siguiente = seg;
            anterior->siguiente = aOrdenar;
        }
    }
    return lista;
}

void mostrarListaMejores (nodoMaximos *mejores) {
    if(mejores) {
        mostrarListaMejores(mejores->siguiente);
        mostrarPuntajeUsu(mejores->usuario);
    }
}
