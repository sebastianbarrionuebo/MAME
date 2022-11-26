#include "TicketCompra.h"

stTicketCompra generacionDeTiket(stUsuario unUsu,int compra,int coins,char tipo,char nombreUsu[]) {

    stTicketCompra aux;
    aux.tipo = tipo;
    switch(tipo) {
    case 'S':
        aux.colorSnake     = compra;
        aux.colorTableroSN = 0;
        aux.colorPelota    = 0;
        aux.colorTableroPN = 0;
        aux.colorFrog      = 0;
        break;
    case 'T':
        aux.colorSnake     = 0;
        aux.colorTableroSN = compra;
        aux.colorPelota    = 0;
        aux.colorTableroPN = 0;
        aux.colorFrog      = 0;
        break;
    case 'P':
        aux.colorSnake     = 0;
        aux.colorTableroSN = 0;
        aux.colorPelota    = compra;
        aux.colorTableroPN = 0;
        aux.colorFrog      = 0;
        break;
    case 'C':
        aux.colorSnake     = 0;
        aux.colorTableroSN = 0;
        aux.colorPelota    = 0;
        aux.colorTableroPN = compra;
        aux.colorFrog      = 0;
        break;
    case 'F':
        aux.colorSnake     = 0;
        aux.colorTableroSN = 0;
        aux.colorPelota    = 0;
        aux.colorTableroPN = 0;
        aux.colorFrog      = compra;
        break;
    }
    strcpy(aux.nombreUser, nombreUsu);
    aux.coinsGastados = coins;
    aux.ticket = unUsu.idUsuario + rand()%1001;
    aux.idTicket = unUsu.idUsuario;

    time_t t = time(NULL);
    struct tm tiempoLocal = *localtime(&t);
    char fechaHora[70];
    char *formato = "%Y-%m-%d %H:%M:%S";
    int bytesEscritos = strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);
    if(bytesEscritos != 0) {
        strcpy(aux.fecha,fechaHora);
    }
    return aux;
}

stTicketCompra guardarTiketArchivo(char ruta[], stTicketCompra ticket) {

    FILE *archivo = fopen(ruta,"ab");
    if(archivo!=NULL) {
        fwrite(&ticket,sizeof(stTicketCompra),1,archivo);
        fclose(archivo);
    } else {
        printf("Error. No se pudo abrir el archivo.\n");
    }
    return ticket;
}


void verArchiTickets (char ruta[], stUsuario unUsu) {

    FILE * archi = fopen(ruta,"rb");
    stTicketCompra aux;

    if(archi) {
        while(fread(&aux, sizeof(stTicketCompra), 1, archi)>0) {
            mostrarTiket(aux, unUsu);
        }
        fclose(archi);
    } else {
        printf("Error en la apertura de archivo");
    }
}

void mostrarTiket(stTicketCompra ticket, stUsuario unUsu) {

    printf("         Tiket codigo %d     \n", ticket.ticket);
    printf("Nombre de Usuario:....[ %s ] \n", unUsu.nombre);
    printf("Fecha:................[ %s ] \n", ticket.fecha);
    switch(ticket.tipo) {
    case 'S':
        printf("Color Snake: ");
        imprimirBloqueDeColor(ticket.colorSnake);
        break;
    case 'T':
        printf("Color Tablero: ");
        imprimirBloqueDeColor(ticket.colorTableroSN);
        break;
    case 'P':
        printf("Color Pelota: ");
        imprimirBloqueDeColor(ticket.colorPelota);
        break;
    case 'C':
        printf("Color Cancha: ");
        imprimirBloqueDeColor(ticket.colorTableroPN);
        break;
    case 'F':
        printf("Color Frog:  ");
        imprimirBloqueDeColor(ticket.colorFrog);
        break;
    }
    printf("\nCoins gastados:....[ %d ]",ticket.coinsGastados);
}
