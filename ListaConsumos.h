#ifndef LISTACONSUMOS_H_INCLUDED
#define LISTACONSUMOS_H_INCLUDED
#include "TicketCompra.h"

typedef struct _nodo {

    stTicketCompra ticket;
    struct _nodo *siguiente;

} nodoListTicket;

///-------------PRINCIPALES------------------///
nodoListTicket *inicLista           ();
nodoListTicket *crearNodo           (stTicketCompra dato);
nodoListTicket *agregarAlPrin       (nodoListTicket *lista,stTicketCompra dato);
nodoListTicket *agregarAlFinal      (nodoListTicket* lista,stTicketCompra dato);
void            mostrarListaTickets (nodoListTicket *lista, stUsuario unUsu);
void            mostrarNodoTicket   (nodoListTicket* nod, stUsuario unUsu);
int             sumarLiquidacion    (nodoListTicket *lista);

#endif // LISTACONSUMOS_H_INCLUDED
