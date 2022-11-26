#ifndef TIKETCOMPRA_H_INCLUDED
#define TIKETCOMPRA_H_INCLUDED
#include "Usuario.h"

#define RUTA_TICKETS "TicketsTienda.dat"

///-----------PRECIOS----------------///

#define P_COLOR_SNAKE       30
#define P_COLOR_TABLERO_SN  20
#define P_COLOR_PELOTA_PN   25
#define P_COLOR_TABLERO_PN  20
#define P_COLOR_FROG        50

//-----------ESTRUCTURAS-----------
typedef struct {

    int  ticket; /// campo único y autoincremental
    int  idTicket;
    char tipo;
    char nombreUser[20];
    char fecha[70];
    int  coinsGastados;
    int  colorTableroSN;
    int  colorSnake;
    int  colorTableroPN;
    int  colorPelota;
    int  colorFrog;

} stTicketCompra;

///----------------------PRINCIPALES:
stTicketCompra generacionDeTiket       (stUsuario unUsu, int compra, int coins, char tipo, char nombreUsu[]);
int            buscarUltimoNumeroTiket ();
stTicketCompra guardarTiketArchivo     (char ruta[], stTicketCompra ticket);
void           mostrarTiket            (stTicketCompra tiket, stUsuario unUsu);
void           verArchiTickets         (char ruta[], stUsuario unUsu);



#endif // TIKETCOMPRA_H_INCLUDED
