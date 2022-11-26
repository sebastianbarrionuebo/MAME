#include "ArbolUsuarios.h"


///-------------PRINCIPALES:
nodoArbol *inicArbol() {
    return(NULL);
}

nodoArbol *crearNodoArbol(stUsuario dato) {
    nodoArbol *nuevo = (nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->dato = dato;
    nuevo->historialCompras = NULL;
    nuevo->der = NULL;
    nuevo->izq = NULL;
    return nuevo;
}

nodoArbol *agregarNodoArbolPorNombre(nodoArbol *arbol, nodoArbol *nuevoUsuario) {
    if(arbol == NULL) {
        arbol = nuevoUsuario;
    } else {
        if(strcmpi(nuevoUsuario->dato.nombre, arbol->dato.nombre)>0) {
            arbol->der = agregarNodoArbolPorNombre(arbol->der, nuevoUsuario);
        } else if(strcmpi(nuevoUsuario->dato.nombre, arbol->dato.nombre)<0) {
            arbol->izq = agregarNodoArbolPorNombre(arbol->izq, nuevoUsuario);
        }
    }
    return arbol;
}


nodoArbol *nodoMasDerecho(nodoArbol *arbol) {
    nodoArbol *masDerecho = NULL;
    if(arbol->der) {
        masDerecho = nodoMasDerecho(arbol->der);
    } else {
        masDerecho = arbol;
    }
    return masDerecho;
}

nodoArbol *nodoMasIzquierdo(nodoArbol *arbol) {
    nodoArbol *masIzquierdo = NULL;
    if(arbol->izq) {
        masIzquierdo = nodoMasDerecho(arbol->izq);
    } else {
        masIzquierdo = arbol;
    }
    return masIzquierdo;
}

nodoArbol *borrarNodoArbolPorUsuario(nodoArbol *arbol, stUsuario dato) {
    if(arbol) {
        if(strcmpi(dato.nombre, arbol->dato.nombre)==0) {
            if(arbol->izq) {
                nodoArbol *masDerecho = nodoMasDerecho(arbol->izq);
                arbol->dato = masDerecho->dato;
                arbol->izq = borrarNodoArbolPorUsuario(arbol->izq, masDerecho->dato);
            } else if(arbol->der) {
                nodoArbol *masIzquierdo = nodoMasIzquierdo(arbol->der);
                arbol->dato = masIzquierdo->dato;
                arbol->der = borrarNodoArbolPorUsuario(arbol->der, masIzquierdo->dato);
            } else {
                free(arbol);
                arbol=inicArbol();
            }
        } else if(strcmpi(dato.nombre, arbol->dato.nombre)>0) {
            arbol->der = borrarNodoArbolPorUsuario(arbol->der, dato);

        } else if(strcmpi(dato.nombre, arbol->dato.nombre)<0) {
            arbol->izq = borrarNodoArbolPorUsuario(arbol->izq, dato);
        }

    } else {
        printf("El dato buscado no existe en el arbol");
    }
    return arbol;
}

nodoArbol *buscarArbolPorNombre(nodoArbol *arbol,char nombreUsuario[]) {
    nodoArbol *buscado = inicArbol();
    if(arbol!=NULL) {
        if(strcmpi(nombreUsuario,arbol->dato.nombre)==0) {
            buscado = arbol;
        } else {
            if(strcmpi(nombreUsuario,arbol->dato.nombre)>0) {
                buscado = buscarArbolPorNombre(arbol->der,nombreUsuario);
            } else {
                buscado = buscarArbolPorNombre(arbol->izq,nombreUsuario);
            }
        }
    }
    return buscado;
}

nodoArbol *buscarPorID(nodoArbol* arbol, int idBuscado) {
    nodoArbol *buscado = inicArbol();
    if(arbol) {
        if(arbol->dato.idUsuario == idBuscado) {
            buscado = arbol;
        } else {
            buscado = buscarPorID(arbol->izq, idBuscado);
            if(buscado == NULL) {
                buscado = buscarPorID(arbol->der, idBuscado);
            }
        }
    }
    return buscado;
}

int cuentaNodosArbol(nodoArbol* arbol) {
    int cont=0;
    if(arbol) {
        cont=1+cuentaNodosArbol(arbol->izq)+cuentaNodosArbol(arbol->der);
    }
    return cont;
}


void mostrarNodoArbol(nodoArbol *nodito, nodoArbol *unUsu) {
    if(nodito) {
        mostrarUsuario(nodito->dato);
        mostrarListaTickets(nodito->historialCompras,unUsu->dato);
    }
}

void preOrden(nodoArbol *arbol) {
    if(arbol) {
        mostrarUsuario(arbol->dato);
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void inOrden(nodoArbol *arbol) {
    if(arbol) {
        inOrden(arbol->izq);
        mostrarUsuario(arbol->dato);
        inOrden(arbol->der);
    }
}

void inOrdenPorActv(nodoArbol *arbol, int activo) {
    if(arbol) {
        inOrdenPorActv(arbol->izq, activo);
        if(arbol->dato.activo == activo) {
            mostrarUsuario(arbol->dato);
        }
        inOrdenPorActv(arbol->der, activo);
    }
}

void postOrden(nodoArbol *arbol) {
    if(arbol) {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        mostrarUsuario(arbol->dato);
    }
}

nodoArbol *descargarDeArchiAArbol(nodoArbol *arbolUsuarios) {

    int cantidad = cantidadDeUsuarios(RUTA_USUARIOSGen);
    stUsuario *usuarios = (stUsuario *) malloc(sizeof(stUsuario)*cantidad);
    int validosUsu = deArchiToArreglo(usuarios, cantidad);
    arbolUsuarios = arregloToArbol(usuarios, 0, validosUsu-1);

    return arbolUsuarios;
}

nodoArbol *arregloToArbol (stUsuario U[], int base, int tope) {

    int medio;

    nodoArbol *arbolUsuarios = inicArbol();

    if(!(base>tope)) {

        medio = (base+tope)/2;

        arbolUsuarios = crearNodoArbol(U[medio]);
        altaCelda(arbolUsuarios);

        arbolUsuarios->izq = arregloToArbol(U, base, medio-1);
        arbolUsuarios->der = arregloToArbol(U, medio+1, tope);
    }

    return arbolUsuarios;
}

nodoArbol *altaCelda(nodoArbol *unUsu) {

    FILE *archiTicket = fopen(RUTA_TICKETS, "rb");
    stTicketCompra ticketCompra;

    if(archiTicket) {
        while(fread(&ticketCompra, sizeof(stTicketCompra), 1, archiTicket)>0) {
            if(ticketCompra.idTicket == unUsu->dato.idUsuario) {
                unUsu->historialCompras = agregarAlPrin(unUsu->historialCompras, ticketCompra);
            }
        }
    } else {
        printf("error en la apertura de los tickets");
    }
    fclose(archiTicket);
    return unUsu;
}

///----------------------------------NODO-USUSARIO----------------------------///

nodoArbol *validacionDeUsuario(nodoArbol *arbol) {

    nodoArbol *nodoUsuario = inicArbol();
    char nombreUs[30];
    char claveUs[30];
    int  flag = 0, retraccion = 0;


    do {
        system("cls");
        gotoxy(50,POSS_Y-4);printf("%c[1;%dm", ESC, 32);
        printf(" -------");printf("%c[0m", ESC);
        printf(" INICIAR SESION ");printf("%c[1;%dm", ESC, 32);
        printf("--------");
        gotoxy(50,POSS_Y-3);
        printf("---------------------------------");
        gotoxy(51,POSS_Y-2);printf("%c[0m", ESC);
        printf(" INGRESE SU NOMBRE DE USUARIO: ");
        gotoxy(55,POSS_Y);
        gets(nombreUs);
        gotoxy(51,POSS_Y+2);
        printf(" INGRESE SU CLAVE:             ");
        gotoxy(55,POSS_Y+4);
        gets(claveUs);

        nodoUsuario = CorroborarUsuario(arbol,nombreUs,claveUs);

        if(nodoUsuario == NULL) {
            gotoxy(51,POSS_Y+6);
            printf("Usuario y/o clave incorrectas ");
            gotoxy(51,POSS_Y+7);
            printf("Intentelo nuevamente con ENTER \n\n");
            gotoxy(49,POSS_Y+9);
            printf("Para regresar al menu principal ESC");
            retraccion = getch();
            if(retraccion == ESC){
                flag = 1;
            }

        } else {
            flag = 1;
        }

    } while(flag != 1);


    return nodoUsuario;
}

nodoArbol *CorroborarUsuario(nodoArbol *arbol,char nombreUs[],char claveUs[]) {
    nodoArbol *aux = inicArbol();

    if(arbol!=NULL) {
        if(strcmpi(nombreUs,arbol->dato.nombre) == 0 && strcmpi(claveUs,arbol->dato.clave)==0) {
            aux = arbol;
        } else {
            if(strcmpi(nombreUs,arbol->dato.nombre)>0) {
                aux = CorroborarUsuario(arbol->der,nombreUs,claveUs);
            } else {
                aux = CorroborarUsuario(arbol->izq,nombreUs,claveUs);
            }
        }
    }
    return aux;
}

void cambioNombreUs (nodoArbol *arbolUsuarios, nodoArbol  *usuario) {

    int cambioExitoso = 0, retraccion = 0;

    char nombreNuevo[30];
    if(arbolUsuarios) {

        do {
            printf("\nIngrese su nuevo nombre de usuario: ");
            fflush(stdin);
            gets(nombreNuevo);

            nodoArbol *buscado = buscarArbolPorNombre(arbolUsuarios, nombreNuevo);

            if(buscado == NULL) {
                strcpy(usuario->dato.nombre, nombreNuevo);
                cambioExitoso = 1;
            } else {
                printf("\nNombre existente, porfavor ingrese otro: ");
                //preguntar si quiere volverlo a intentar, si no quiere retraccion = 1;
            }
        } while(cambioExitoso == 0 && retraccion == 0);

    }
    printf("Cambio de nombre efectuado correctamente!! :) \n\n");
    usuario->dato.modi=1;
    system("pause");
}

void cambioDeClave(nodoArbol *usuario) {

    int cambioExitoso = 0, retraccion = 0;
    char claveNueva [30];
    char claveActual[30];

    printf("\nIngrese su NUEVA clave: ");
    fflush(stdin);
    gets(claveNueva);

    do {
        printf("\nIngrese su clave ACTUAL :");
        fflush(stdin);
        gets(claveActual);

        if(strcmpi(claveActual,usuario->dato.clave)==0) {
            strcpy(usuario->dato.clave, claveNueva);
            cambioExitoso=1;
        } else {
            printf("\n Clave ACTUAL incorrecta, inténtelo nuevamente ");

        }
    } while(cambioExitoso == 0 && retraccion == 0);

    printf("Cambio de CLAVE efectuado correctamente!! :) \n\n");
    usuario->dato.modi=1;
    system("pause");
}

///--------------PASAJE-----------------------///

nodoMaximos *arbolToLista (nodoArbol *arbolUsuarios, nodoMaximos *listaMaximos) {

    if(arbolUsuarios) {
        arbolUsuarios->dato.totalPuntaje = promedioDePuntos(arbolUsuarios->dato);
        listaMaximos = agregarEnOrdenPorPuntaje(listaMaximos, crearNodoMejor(arbolUsuarios->dato));
        listaMaximos = arbolToLista(arbolUsuarios->izq, listaMaximos);
        listaMaximos = arbolToLista(arbolUsuarios->der, listaMaximos);
    }

    return listaMaximos;
}

void inOrdenArbolToArchi(nodoArbol *arbol, FILE *archi) {

    if(arbol) {
        inOrdenArbolToArchi(arbol->izq,archi);
        fwrite(&arbol->dato, sizeof(stUsuario),1,archi);
        inOrdenArbolToArchi(arbol->der,archi);
    }
}

