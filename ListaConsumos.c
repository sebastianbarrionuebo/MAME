#include "ListaConsumos.h"


///-------------------------Principales:
nodoListTicket *inicLista() {
    return(NULL);
}

nodoListTicket *crearNodo(stTicketCompra dato) {
    nodoListTicket *nuevo = (nodoListTicket*)malloc(sizeof(nodoListTicket));
    nuevo->ticket = dato;
    nuevo->siguiente = NULL;
    return(nuevo);
}

nodoListTicket *agregarAlPrin(nodoListTicket *lista,stTicketCompra dato) {
    nodoListTicket *nuevo = crearNodo(dato);
    nuevo->siguiente=lista;
    return(nuevo);
}


nodoListTicket * agregarAlFinal(nodoListTicket* lista,stTicketCompra dato) {
    nodoListTicket *nuevo = crearNodo(dato);
    nodoListTicket *seg = lista;
    if(seg==NULL) {
        lista = nuevo;
    } else {
        while(seg->siguiente!=NULL) {
            seg=seg->siguiente;
        }
        seg->siguiente=nuevo;
    }
    return(lista);
}

void mostrarListaTickets(nodoListTicket *lista, stUsuario unUsu) {
    nodoListTicket *seg = lista;
    while(seg!=NULL) {
        mostrarNodoTicket(seg, unUsu);
        seg = seg->siguiente;
    }
}

void mostrarNodoTicket(nodoListTicket* nod, stUsuario unUsu) {

    printf("\n._____________________________________.\n");
    mostrarTiket(nod->ticket, unUsu);
    printf("\n|_____________________________________|\n");
}

int sumarLiquidacion(nodoListTicket *lista){
    nodoListTicket *seg = lista;
    int suma=0;
    while(seg!=NULL){
        suma = suma + seg->ticket.coinsGastados;
        seg=seg->siguiente;
    }
    return(suma);
};







