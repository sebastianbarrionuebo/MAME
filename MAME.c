#include "MAME.h"



///-------------------------------HERRAMIENTAS------------------------------------------------

void dimencionDeConsola (int ancho,int alto) {

    HANDLE wHnd;
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, ancho, alto};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
}

void imprimirMenusFor (int filas, int columnas, char M[filas][columnas], int possY, int flechita) {

    int j = possY;
    int abanico = 0;

    switch(flechita){
    case 1:
        for(int i = 0; i<filas; i++){
            if (i==0) {
                gotoxy(58,j);
                printf("%c[1;%dm", ESC, 32);
                printf("%s\n", M[i]);
                printf("%c[0m", ESC);
            } else {
                gotoxy(58, j+1+i);
                printf("%s\n", M[i]);
            }
        }
        break;

    case 2:
        for(int i = 0; i<filas; i++) {
            if (i==1) {
                gotoxy(58, j+2);
                printf("%c[1;%dm", ESC, 32);
                printf("%s\n", M[i]);
                printf("%c[0m", ESC);
            } else if(i == 0) {
                gotoxy(58, j);
                printf("%s\n", M[i]);
            } else {
                gotoxy(58, j+4+abanico);
                printf("%s\n", M[i]);
                abanico++;
            }
        }
        break;

    case 3:
        abanico = 0;
        for(int i = 0; i<filas; i++) {
            if (i==2) {
                gotoxy(58,j+3);
                printf("%c[1;%dm", ESC, 32);
                printf("%s\n", M[i]);
                printf("%c[0m", ESC);
            } else if(i<=1) {
                gotoxy(58,j+i);
                printf("%s\n", M[i]);
            } else if(i>2){
                gotoxy(58,j+5+abanico);
                printf("%s\n", M[i]);
                abanico++;
            }
        }
        break;
    case 4:
        abanico = 0;
        for(int i = 0; i<filas; i++) {
            if (i==3) {
                gotoxy(58,j+4);
                printf("%c[1;%dm", ESC, 32);
                printf("%s\n", M[i]);
                printf("%c[0m", ESC);
            } else if(i<=2) {
                gotoxy(58,j+i);
                printf("%s\n", M[i]);
            } else if(i>3){
                gotoxy(58,j+6+abanico);
                printf("%s\n", M[i]);
                abanico++;
            }
        }
        break;
    case 5:
        abanico = 0;
        for(int i = 0; i<filas; i++) {
            if (i==4) {
                gotoxy(58,j+5);
                printf("%c[1;%dm", ESC, 32);
                printf("%s\n", M[i]);
                printf("%c[0m", ESC);
            } else if(i<=3) {
                gotoxy(58,j+i);
                printf("%s\n", M[i]);
            } else if(i>4){
                gotoxy(58,j+7+abanico);
                printf("%s\n", M[i]);
                abanico++;
            }
        }
        break;
    case 6:
        abanico = 0;
        for(int i = 0; i<filas; i++) {
            if (i==5) {
                gotoxy(58,j+6);
                printf("%c[1;%dm", ESC, 32);
                printf("%s\n", M[i]);
                printf("%c[0m", ESC);
            } else if(i<=4) {
                gotoxy(58,j+i);
                printf("%s\n", M[i]);
            } else if(i>5){
                gotoxy(58,j+8+abanico);
                printf("%s\n", M[i]);
                abanico++;
            }
        }
        break;
    case 7:
        abanico = 0;
        for(int i = 0; i<filas; i++) {
            if (i==6) {
                gotoxy(58,j+7);
                printf("%c[1;%dm", ESC, 32);
                printf("%s\n", M[i]);
                printf("%c[0m", ESC);
            } else if(i<=5) {
                gotoxy(58,j+i);
                printf("%s\n", M[i]);
            } else if(i>6){
                gotoxy(58,j+9+abanico);
                printf("%s\n", M[i]);
                abanico++;
            }
        }
        break;
    case 8:
        abanico = 0;
        for(int i = 0; i<filas; i++) {
            if (i==7) {
                gotoxy(58,j+8);
                printf("%c[1;%dm", ESC, 32);
                printf("%s\n", M[i]);
                printf("%c[0m", ESC);
            } else if(i<=6) {
                gotoxy(58,j+i);
                printf("%s\n", M[i]);
            } else if(i>7){
                gotoxy(58,j+10+abanico);
                printf("%s\n", M[i]);
                abanico++;
            }
        }
        break;
        case 9:
        abanico = 0;
        for(int i = 0; i<filas; i++) {
            if (i==8) {
                gotoxy(58,j+9);
                printf("%c[1;%dm", ESC, 32);
                printf("%s\n", M[i]);
                printf("%c[0m", ESC);
            } else if(i<=7) {
                gotoxy(58,j+i);
                printf("%s\n", M[i]);
            } else if(i>8){
                gotoxy(58,j+10+abanico);
                printf("%s\n", M[i]);
                abanico++;
            }
        }
        break;

        case 10:
        abanico = 0;
        for(int i = 0; i<filas; i++) {
            if (i==9) {
                gotoxy(58,j+10);
                printf("%c[1;%dm", ESC, 32);
                printf("%s\n", M[i]);
                printf("%c[0m", ESC);
            } else if(i<=8) {
                gotoxy(58,j+i);
                printf("%s\n", M[i]);
            } else if(i>9){
                gotoxy(58,j+10+abanico);
                printf("%s\n", M[i]);
                abanico++;
            }
        }
        break;

    }

}

int movimientoFlecha (int flecha, int filas, int *menu) {
    int tecla = 0;

    do {
        tecla = getch();
    } while(tecla != ENTER && tecla != ARRIBA && tecla != ABAJO);

    switch(tecla) {
    case ARRIBA:
        flecha--;
        if (flecha < 1) {
            flecha = filas;
        }
        break;

    case ABAJO:
        flecha++;
        if (flecha >  filas) {
            flecha = 1;
        }
        break;

    case ENTER:
        *menu = 1;
        break;
    }
    return flecha;
}

void juegos(int cont, int tecla) {
    char games[9][6][38]= {
        {
            {"  ___   _ _    __ _   | |__   ___     "},
            {" (_-<  | ' `  / _` |  | / /  / -_)    "},
            {" /__/  |_||_| `__,_|  |_`_`  `___|    "},
            {"                                      "},
            {"                                .     "},
            {"                                      "}
        },
        {
            {"        ____                          "},
            {"       / __ .        ____  ____ _     "},
            {"      / /_/ /       / __ `/ __ `/     "},
            {"     / ____/       / / / / /_/ /      "},
            {"    /_/           /_/ /_/`__, /       "},
            {"                        /____/        "}
        },
        {
            {"         /  __)                       "},
            {"         | |__ ____ ___   ____        "},
            {"         |  __) ___) _ ` / _  |       "},
            {"         | | | |  | |_| ( ( | |       "},
            {"         |_| |_|   `___/ `_|| |       "},
            {"                        (_____|       "}
        },
        {
            {"                                      "},
            {"                                      "},
            {"                                      "},
            {" _____  _____  _____  _____  _____    "},
            {"|     ||     ||     ||     ||     |   "},
            {"`-----'`-----'`-----'`-----'`-----'   "}
        },
        {
            {"                                      "},
            {"                                      "},
            {"                                      "},
            {"                                      "},
            {"                                   _, "},
            {"                                    ` "}
        },
        {
            {" | |                                  "},
            {" | |`                                 "},
            {" |_|``                                "},
            {"                                   _  "},
            {"          ```                     | | "},
            {"           `                      | | "}
        },
        {
            {"                                      "},
            {"                                      "},
            {"                                      "},
            {"                                      "},
            {"             --.                      "},
            {"            |__|                      "}
        },
        {
            {"  ___   _ _    __ _   | |__   ___     "},
            {" (_-<  | ' `  / _` |  | / /  / -_)    "},
            {" /__/  |_||_| `__,_|  |_`_`  `___|    "},
            {" _____  _____  _____  _____  _____    "},
            {"|     ||     ||     ||     ||   . |_, "},
            {"`-----'`-----'`-----'`-----'`-----' ` "}
        },
        {
            {" | |    ____                          "},
            {" | |`  / __ .        ____  ____ _     "},
            {" |_|``/ /_/ /       / __ `/ __ `/     "},
            {"     / ____/       / / / / /_/ /   _  "},
            {"    /_/   ```--.  /_/ /_/`__, /   | | "},
            {"           `|__|        /____/    | | "}
        }
    };
    char marco[8][41]= {
        {"36666666666666666666666666666666666666662"},
        {"7                                       7"},
        {"7                                       7"},
        {"7                                       7"},
        {"7                                       7"},
        {"7                                       7"},
        {"7                                       7"},
        {"56666666666666666666666666666666666666664"}
    };
    //refresh
    if((cont == 1 && tecla == ABAJO) || cont==10) {
        printTitleL(45, 15, 8, 41, marco, BLANCO);
        printTitleL(47, 16, 6, 38, games[7], BLANCO);
    } else if(((cont == 0 && tecla == ARRIBA)||(cont == 2 && tecla == ABAJO)) || cont==11) {
        printTitleL(45, 23, 8, 41, marco, BLANCO);
        printTitleL(47, 24, 6, 38, games[8], BLANCO);
    } else if(((cont == 1 && tecla == ARRIBA)|| (cont == 2)) || cont==9) {
        printTitleL(45, 31, 8, 41, marco, BLANCO);
        printTitleL(47, 32, 6, 38, games[2], BLANCO);
    }
    if(cont == 0) {
        printTitleL(45, 15, 8, 41, marco, AMARILLO);
        printTitleL(47, 16, 6, 38, games[0], BLANCO);
        printTitleL(47, 16, 6, 38, games[3], VERDE);
        printTitleL(47, 16, 6, 38, games[4], ROJO);
    } else if(cont == 1) {
        printTitleL(45, 23, 8, 41, marco, CIAN);
        printTitleL(47, 24, 6, 38, games[1], AMARILLO);
        printTitleL(47, 24, 6, 38, games[5], BLANCO);
        printTitleL(47, 24, 6, 38, games[6], ROJO);
    } else if(cont == 2) {
        printTitleL(45, 31, 8, 41, marco, VERDE);
        printTitleL(47, 32, 6, 38, games[2], VERDE);
    }
}

int selectGame() {

    int selectOne=0, cont=0, tecla=0;
    juegos(0, tecla);
    juegos(9, tecla);
    juegos(11, tecla);
    while(selectOne==0) {
        if(kbhit()) {
            tecla = getch();
            if(tecla==ARRIBA  && cont>0) {
                cont--;
                juegos(cont, tecla);
            } else if(tecla==ABAJO && cont<2) {
                cont++;
                juegos(cont, tecla);
            }
            if(tecla == ENTER) {
                selectOne=1;
            }
        }
    }
    return cont;
}

///-------------------------------DECISIONES DE MENU------------------------------------------

void MAME () {
    nodoArbol *arbolUsuarios = inicArbol();
    arbolUsuarios = descargarDeArchiAArbol(arbolUsuarios);
    switchMenuPrincipal(arbolUsuarios);
}

void switchMenuPrincipal (nodoArbol *arbolUsuarios) {

    bool menu  = true;
    int seleccionMP = 0;

    char opcionesMP[3][20] = {"  INICIAR SESION", "GENERAR UN USUARIO", "  SALIR DEL MAME"};
    nodoArbol *unUsuario = inicArbol();

    do {
        system("cls");
        seleccionMP = imprimirMenuPrincipal(3, 20, opcionesMP);
        switch(seleccionMP) {
        //INICIO DE SESION
        case 1:
            arbolUsuarios = altaBajaAdminUsusario(arbolUsuarios, unUsuario);
            break;
        //CREAR USUARIO
        case 2:
            arbolUsuarios = switchCrearNuevoUsuario(arbolUsuarios);
            break;
        //SALIR
        case 3:
            menu = false;
            break;
        }
    } while(menu);
}

nodoArbol *altaBajaAdminUsusario (nodoArbol *arbolUsuarios, nodoArbol *unUsu) {

    unUsu = validacionDeUsuario(arbolUsuarios);

    if(unUsu  && unUsu->dato.tipo == 1) {
        arbolUsuarios = switchInicioSesionAdmin(arbolUsuarios, unUsu);
    } else if(unUsu) {
        if (unUsu->dato.activo == 0) {
            printf("\n Usuario dado de baja, quiere volver a dar de alta ? \n");
            system("pause\n");
            switchAdvertencia(unUsu);
        } else {
            switchInicioSesion(arbolUsuarios, unUsu);
        }
    }
    return arbolUsuarios;
}

nodoArbol *switchCrearNuevoUsuario(nodoArbol *arbolUsuarios) {

    bool menu  = true;
    int seleccion = 0;
    stUsuario unUsu;
    char opcionesCU[2][20] = {"INICIAR EN MAME", "    REGRESAR"};

    do {
        system("cls");
        seleccion = imprimirMenuCrearUsuario(2, 20, opcionesCU);
        switch(seleccion) {
        //INICIAR EN MAME
        case 1:
            unUsu = creacionDeUsuario();
            guardarUsuArchivo(RUTA_USUARIOSGen, unUsu);
            arbolUsuarios = agregarNodoArbolPorNombre(arbolUsuarios, crearNodoArbol(unUsu));
            break;
        //REGRESAR
        case 2:
            menu = false;
            break;
        }
    } while(menu);

    return arbolUsuarios;
}

void switchInicioSesion (nodoArbol *arbolUsuarios, nodoArbol *unUsu) {

    bool ctlmenu_Is = true;
    int  opcionMenuIS = 0, baja = 0;
    char opcionesIS[7][30] = {"JUGAR", "VER PERFIL", "TIENDA", "HISTORIAL DE COMPRAS", "MAXIMOS PUNTAJES", "DAR DE BAJA CUENTA", "GUARDAR Y CERRAR SESION"};
    nodoMaximos *listaMejores = inicListaMejores();

    do {
        opcionMenuIS = imprimirMenuInicioSesion(unUsu, 7, 30, opcionesIS);
        switch(opcionMenuIS) {
        /// JUGAR.
        case 1:
            unUsu = switchInicAJugar(unUsu);
            break;
        /// VER PERFIL.
        case 2:
            switchPerfil(arbolUsuarios,unUsu);
            break;
        /// TIENDA.
        case 3:
            switchTienda(unUsu);
            break;
        ///Historial De Compras
        case 4:
            mostrarListaTickets(unUsu->historialCompras, unUsu->dato);
            system("pause");
            break;
        /// MEJORES PUNTAJES.
        case 5:
            listaMejores = arbolToLista(arbolUsuarios, listaMejores);
            mostrarListaMejores(listaMejores);
            system("pause");
            break;
        /// DAR DE BAJA MI CUENTA.
        case 6:
            baja = switchAdvertencia(unUsu);
            if(baja == 1) {
                ctlmenu_Is = false;
            }
            break;
        ///cerrar sesion
        case 7:
            ctlmenu_Is = false;
            if(unUsu->dato.modi == 1) {
                guardarPerfilArchi(unUsu->dato);
            }
            break;
        }
    } while(ctlmenu_Is);
}

nodoArbol  *switchInicioSesionAdmin (nodoArbol *arbolUsuarios, nodoArbol *unUsuario) {

    bool ctlmenu_Is = true;
    int  opcionMenuIS = 0;
    nodoMaximos *listaMejores = inicListaMejores();
    char opcionesIS[10][30] = {"JUGAR", "VER PERFIL", "MIS TICKETS", "TIENDA","CAMBIAR ESTADO", "ELIMINAR USUARIO", "LISTA DE USUARIOS", "LIQUIDACION DE USUSARIO", "MAXIMOS PUNTAJES", "GUARDAR Y CERRAR SESION"};         ///<=================


    do {
        opcionMenuIS = imprimirMenuInicioSesionAdmin (unUsuario, 10, 30, opcionesIS);
        switch(opcionMenuIS) {
        //JUGAR.
        case 1:
            unUsuario = switchInicAJugar(unUsuario);
            break;
        //VER PERFIL.
        case 2:
            switchPerfil(arbolUsuarios,unUsuario);
            break;
        ///MIS TIKETS
        case 3:
            mostrarListaTickets(arbolUsuarios->historialCompras,unUsuario->dato);
            system("pause");
            break;
        // TIENDA.
        case 4:
            switchTienda(unUsuario);
            break;
        ///CAMBIAR ESTADO DE UN USUARIO
        case 5:
            switchCambioDeEstadoAdmin(arbolUsuarios);
            break;
        ///ELIMINAR USUSARIO
        case 6:
            arbolUsuarios = switchEliminarUsuario(arbolUsuarios);
            FILE *archiUsuGen = fopen(RUTA_USUARIOSGen, "wb");
            inOrdenArbolToArchi(arbolUsuarios, archiUsuGen);
            fclose(archiUsuGen);
            break;
        ///LISTA DE USUARIOS.
        case 7:
            switchVerUsuarios(arbolUsuarios);
            break;
        ///LIQUIDACION.
        case 8:
            switchVerLiquidacion(arbolUsuarios);
            break;
        ///MEJORES PUNTAJES.
        case 9:
            listaMejores = arbolToLista(arbolUsuarios, listaMejores);
            mostrarListaMejores(listaMejores);
            system("pause");
            break;
        ///CERRAR SESION.
        case 10:
            ctlmenu_Is = false;
            if(unUsuario->dato.modi == 1) {
                guardarPerfilArchi(unUsuario->dato);
            }
            break;
        }
    } while(ctlmenu_Is);
    return arbolUsuarios;
}

nodoArbol *switchInicAJugar (nodoArbol *unUsu) {

    system("cls");
    int selected = selectGame();
    switch(selected) {
    case 0:
        inicSnake(unUsu);
        break;
    case 1:
        switchPingPong(unUsu);
        break;
    case 2:
        initFrog(&unUsu->dato);
        break;
    }
    return unUsu;
}

nodoArbol *switchPingPong(nodoArbol *unUsu){

    char P[2][15]= {"1 vs PC","1 vs 1"};
    int selected = imprimirMenuGeneral(2,15,P);
    switch(selected) {
    case 1:
        cicloPongVsIA(&unUsu->dato);
        break;
    case 2:
        cicloPongVS(&unUsu->dato);
        break;
    }
    return unUsu;

}

void switchVerLiquidacion (nodoArbol *arbolUsuarios) {
    bool ctlVerUsus = true;
    int  seleccion = 0;
    int  sumaLiquidacion = 0;
    int  idBuscado = 0;
    char verUsuarios [3][30]= {"Buscar por Nombre","Buscar por ID", "Regresar"};
    nodoArbol *buscado = inicArbol();
    char nameBuscado[30];

    do {
        seleccion = imprimirMenuGeneral(3, 30, verUsuarios);
        switch(seleccion) {
            case 1:
                printf("ingrese un nombre de usuario:\n");
                fflush(stdin);
                gets(nameBuscado);
                buscado = buscarArbolPorNombre(arbolUsuarios,nameBuscado);
                if(buscado!=NULL){
                    mostrarListaTickets(buscado->historialCompras,buscado->dato);
                    sumaLiquidacion = sumarLiquidacion(buscado->historialCompras);
                    printf("\n\nLiquidacion Total: %d\n\n",sumaLiquidacion);
                }else{
                    printf("Error. Usuario Inexistente.\n");
                }
                system("pause");
                break;
            case 2:
                printf("ingrese un ID de usuario:\n");
                fflush(stdin);
                scanf("%d",&idBuscado);
                buscado = buscarPorID(arbolUsuarios,idBuscado);
                if(buscado!=NULL){
                    mostrarListaTickets(buscado->historialCompras,buscado->dato);
                    sumaLiquidacion = sumarLiquidacion(buscado->historialCompras);
                    printf("\n\nLiquidacion Total: %d\n\n",sumaLiquidacion);
                }else{
                    printf("Error. Usuario Inexistente.\n");
                }
                system("pause");
                break;
            case 3:
                ctlVerUsus = false;
                break;
        }
    } while(ctlVerUsus);
}

void switchVerUsuarios (nodoArbol *arbolUsuarios) {
    bool ctlVerUsus = true;
    int  seleccion = 0;
    char verUsuarios [4][30]= {"Ver Usuarios ACTIVOS","Ver Usuarios INACTIVOS", "Ver TODOS", "Regresar"};

    do {
        seleccion = imprimirMenuGeneral(4, 30, verUsuarios);
        switch(seleccion) {
        case 1:
            inOrdenPorActv(arbolUsuarios, 1);
            system("pause");
            break;
        case 2:
            inOrdenPorActv(arbolUsuarios, 0);
            system("pause");
            break;
        case 3:
            inOrden(arbolUsuarios);
            system("pause");
            break;
        case 4:
            ctlVerUsus = false;
            break;
        }
    } while(ctlVerUsus);

}

void switchPerfil (nodoArbol *arbolUsuarios,nodoArbol *unUsu) {

    bool ctlMenuPerfil = true;
    int  opcionMenuPerfil = 0;
    char opcionesPerfil[2][25]= {"AJUSTES", "REGRESAR"};

    do {
        opcionMenuPerfil = imprimirMenuPerfil(unUsu, 2, 25, opcionesPerfil);
        switch(opcionMenuPerfil){
        case 1:
            switchAjustes(arbolUsuarios,unUsu);
            break;
        case 2:
            ctlMenuPerfil = false;
            break;
        }
    } while(ctlMenuPerfil);
}

void switchAjustes (nodoArbol* arbolUsuarios, nodoArbol *unUsu) {
    int  opcionAjustes=0;
    char opcionesAjustes [8][30] = {"Cambiar nombre de Usuario", "Cambiar clave", "Color de serpiente", "Color de tablero SN", "Color de Pelota", "Color de tablero PN", "Color de Frog", "Regresar"};
    bool ctlMenuAjus = true;

    do {
        opcionAjustes = imprimirMenuAjus(8, 30, opcionesAjustes);
        switch(opcionAjustes) {

        case 1:
            cambioNombreUs(arbolUsuarios, unUsu);
            break;
        case 2:
            cambioDeClave(unUsu);
            break;
        ///CAMBIAR COLOR SNAKE
        case 3:
            quieroCambiarColor(unUsu,unUsu->dato.compras.validosSnake, 3);
            break;
        ///AMBIAR COLOR TABLERO SNAKE
        case 4:
            quieroCambiarColor(unUsu,unUsu->dato.compras.validosTableroSN, 4);
            break;
        ///CAMBIAR COLOR PELOTA PONG
        case 5:
            quieroCambiarColor(unUsu,unUsu->dato.compras.validosPelota, 5);
            break;
        ///CAMBIAR COLOR TABLERO PONG
        case 6:
            quieroCambiarColor(unUsu,unUsu->dato.compras.validosTableroPN, 6);
            break;
        ///CAMBIAR COLOR FROG
        case 7:
            quieroCambiarColor(unUsu,unUsu->dato.compras.validosFrog, 7);
            break;
        case 8:
            ctlMenuAjus = false;
            break;
        }
    } while(ctlMenuAjus);
}

void switchTienda (nodoArbol *unUsuario) {

    bool ctlMenuTienda = true;
    int  opcionMenuTienda = 0;

    char opcionesT [6][25] = {"Color Snake", "Color Tablero Snake", "Color Pelota","Color Cancha","Color Frog", "Regresar"};

    do {
        opcionMenuTienda = imprimirMenuTienda(6, 25, opcionesT);
        switch(opcionMenuTienda) {
        ///Color Snake
        case 1:
            switchListaDeColores(opcionMenuTienda, unUsuario);
            break;
        ///Color Tablero Snake
        case 2:
            switchListaDeColores(opcionMenuTienda, unUsuario);
            break;
        ///Color Pelota
        case 3:
            switchListaDeColores(opcionMenuTienda, unUsuario);
            break;
        ///Color Cancha
        case 4:
            switchListaDeColores(opcionMenuTienda, unUsuario);
            break;
        ///Color Frog
        case 5:
            switchListaDeColores(opcionMenuTienda, unUsuario);
            break;
        case 6:
            ctlMenuTienda = false;
            break;

        }

    } while(ctlMenuTienda);
}

void switchListaDeColores (int seleccionTienda, nodoArbol *unUsu) {

    bool menu = true;
    char coloresSnakeYFrog[7][10] = {"Rojo","Amarillo","Azul","Violeta","Cian","Blanco","Regresar"};
    char colores          [7][10] = {"Rojo","Verde","Amarillo","Azul","Violeta","Cian","Regresar"};

    do {

        switch(seleccionTienda) {
        ///SNAKE
        case 1:
            menu = compra(unUsu, 7, 10, coloresSnakeYFrog, P_COLOR_SNAKE, 'S');
            break;
        ///TABLERO SNAKE
        case 2:
            menu = compra(unUsu, 7, 10, colores, P_COLOR_TABLERO_SN, 'T');
            break;
        ///PELOTA
        case 3:
            menu = compra(unUsu, 7, 10, colores, P_COLOR_PELOTA_PN, 'P');
            break;
        ///CANCHA
        case 4:
            menu = compra(unUsu, 7, 10, colores, P_COLOR_TABLERO_PN, 'C');
            break;
        ///FROG
        case 5:
            menu = compra(unUsu, 7, 10, coloresSnakeYFrog, P_COLOR_FROG, 'F');
            break;
        }
    } while(menu);
}

void switchCambioDeEstadoAdmin (nodoArbol *arbolUsuarios) {

    bool ctlMenuAltaBaja = true;
    int  opcionDeBaja = 0;
    char opcionesDeBaja[3][20] = {"Por nombre usuario", "Por ID de usaurio", "Regresar"};

    char nameBuscado[20];
    int  iDBuscado = 0;

    nodoArbol *userBuscado = inicArbol();

    do {
        printf("Buscar por nombre del Usuario o ID\n");
        opcionDeBaja = imprimirMenuGeneral(3,20,opcionesDeBaja);
        switch(opcionDeBaja) {

        case 1:
            printf("ingrese un nombre de usuario:\n");
            fflush(stdin);
            gets(nameBuscado);
            userBuscado = buscarArbolPorNombre(arbolUsuarios,nameBuscado);
            switchcambioDeEstado(userBuscado);
            break;
        case 2:
            printf("ingrese un ID de usuario:\n");
            fflush(stdin);
            scanf("%d",&iDBuscado);
            userBuscado = buscarPorID(arbolUsuarios,iDBuscado);
            switchcambioDeEstado(userBuscado);
            break;
        case 3:
            ctlMenuAltaBaja = false;
            break;
        }


    } while(ctlMenuAltaBaja);
}

int switchAdvertencia (nodoArbol *unUsu) {
    bool ctlAdvertencia = true;
    int  seleccion = 0;
    char advertencia1 [2][5]= {"SI","NO"};

    do {

        seleccion = imprimirMenuGeneral(2, 5, advertencia1);
        switch(seleccion) {
        case 1:
            switchcambioDeEstado(unUsu);
            ctlAdvertencia = false;
            break;
        case 2:
            seleccion = 0;
            ctlAdvertencia = false;
            unUsu->dato.modi=1;
            break;
        }
    } while(ctlAdvertencia);
    return seleccion;
}

void switchcambioDeEstado (nodoArbol *userBuscado) {

    if(userBuscado != NULL && userBuscado->dato.tipo == 0) {
        if(userBuscado->dato.activo == 1) {
            userBuscado->dato.activo = 0;
        } else {
            userBuscado->dato.activo = 1;
        }
        printf("Estado Modificado");
        guardarPerfilArchi(userBuscado->dato);
        system("pause");
    }
    if(userBuscado && userBuscado->dato.tipo == 1) {
        printf("Usuario inexistente o Admin.\n");
        system("pause");
    }
}

nodoArbol* switchEliminarUsuario (nodoArbol *arbolUsuarios) {

    bool ctlMenuEliminacion = true;
    int  opcionMenuEliminar = 0;
    char opcionesEliminar[3][20] = {"Por nombre usuario", "Por ID de usaurio", "Regresar"};

    char nameBuscado[20];
    int iDBuscado = 0;
    nodoArbol *userbuscadoElim = inicArbol();

    do {
        system("cls");
        opcionMenuEliminar = imprimirMenuGeneral(3,20,opcionesEliminar);
        switch(opcionMenuEliminar) {
        case 1:
            printf("ingrese un nombre de usuario:\n");
            fflush(stdin);
            gets(nameBuscado);
            userbuscadoElim = buscarArbolPorNombre(arbolUsuarios,nameBuscado);
            arbolUsuarios = eliminarNodo(arbolUsuarios, userbuscadoElim);
            break;
        case 2:
            printf("ingrese un ID de usuario:\n");
            fflush(stdin);
            scanf("%d",&iDBuscado);
            userbuscadoElim = buscarPorID(arbolUsuarios,iDBuscado);
            arbolUsuarios = eliminarNodo(arbolUsuarios, userbuscadoElim);
            break;
        case 3:
            ctlMenuEliminacion = false;
            break;
        }

    } while(ctlMenuEliminacion);

    return arbolUsuarios;
}

nodoArbol *eliminarNodo (nodoArbol *arbolUsuarios, nodoArbol *aEliminar) {

    if(aEliminar != NULL && aEliminar->dato.tipo == 0) {
        arbolUsuarios = borrarNodoArbolPorUsuario(arbolUsuarios, aEliminar->dato);
        printf("Eliminacion Exitosa");
        system("pause");
    } else {
        printf("Error. El usuario no existe o es Admin.\n");
    }
    return arbolUsuarios;
}



///------------------------------IMPRESION DE MENUS-------------------------------------------
int  imprimirMenuGeneral (int filas, int columnas, char M[filas][columnas]) {
    int flecha = 1, menu = 0;
    do {
        system("cls");


        imprimirMenusFor(filas, columnas, M, POSS_Y, flecha);

        flecha = movimientoFlecha(flecha, filas, &menu);

    } while(menu != 1);
    return flecha;
}

int  imprimirMenuCrearUsuario (int filas, int columnas, char M[filas][columnas]) {
    int flecha = 1, menu = 0;
    do {
        system("cls");

        calaberaCreacionUsuario();
        imprimirMenusFor(filas, columnas, M, POSS_Y, flecha);

        flecha = movimientoFlecha(flecha, filas, &menu);

    } while(menu != 1);
    return flecha;
}

int  imprimirMenuPrincipal (int filas, int columnas, char M[filas][columnas]) {
    int flecha = 1, menu = 0;
    do {
        system("cls");
        impresionMAME();


        imprimirMenusFor(filas, columnas, M, POSS_Y, flecha);

        flecha = movimientoFlecha(flecha, filas, &menu);

    } while(menu != 1);
    return flecha;
}


int imprimirMenuInicioSesion(nodoArbol *unUsuario, int filas, int columnas, char M[filas][columnas]) {

    int flecha = 1, menu = 0;

    do {
        system("cls");
        joystick(14,6);
        joystick(95,25);
        gotoxy(50, 20);
        printf("      Hola  %s!!", unUsuario->dato.nombre);
        gotoxy(50,21);
        printf(" Bienvenido a tu Menu de Juego!!");

        imprimirMenusFor(filas, columnas, M, POSS_Y, flecha);
        flecha = movimientoFlecha(flecha, filas, &menu);

    } while(!menu);

    return flecha;
}

int imprimirMenuInicioSesionAdmin (nodoArbol *unUsuario,int filas, int columnas, char M[filas][columnas]) {

    int flecha = 1, menu = 0;

    do {
        system("cls");
        calaberaAdmin(0, 5);
        calaberaAdmin(90,30);
        gotoxy(50, 20);
        printf(" Hola  %s  ", unUsuario->dato.nombre);
        gotoxy(50,21);
        printf(" Bienvenido a su Menu de Admin!!");
        imprimirMenusFor(filas, columnas, M, POSS_Y, flecha);

        flecha = movimientoFlecha(flecha, filas, &menu);
    } while(!menu);

    return flecha;
}


int imprimirMenuPerfil (nodoArbol *unUsu, int filas, int columnas, char M[filas][columnas]) {
    int flecha = 1, menu = 0;

    do {
        system("cls");

        verPerfil(unUsu->dato);

        imprimirMenusFor(filas, columnas, M, POSS_Y, flecha);
        flecha = movimientoFlecha(flecha, filas, &menu);

    } while(menu != 1);
    return flecha;
}

int imprimirMenuAjus (int filas, int columnas, char M[filas][columnas]) {

    int flecha = 1, menu = 0;

    do {
        system("cls");

        imprimirMenusFor(filas, columnas, M, POSS_Y, flecha);

        flecha = movimientoFlecha(flecha, filas, &menu);
    } while(!menu);

    return flecha;

}

int imprimirMenuTienda (int filas, int columnas, char M[filas][columnas]) {
    int flecha = 1, menu = 0;
    do {
        system("cls");
        printTienda(15);
        printTiendaMoneda(20);
        printTiendaTitle();
        gotoxy(40,15);
        printf("SNAKE..........................................$%d", P_COLOR_SNAKE);
        gotoxy(40,16);
        printf("TABLERO........................................$%d", P_COLOR_TABLERO_SN);
        gotoxy(40,17);
        printf("PELOTA.........................................$%d", P_COLOR_PELOTA_PN);
        gotoxy(40,18);
        printf("TABLERO PONG...................................$%d", P_COLOR_TABLERO_PN);
        gotoxy(40,19);
        printf("FROG...........................................$%d", P_COLOR_FROG);

        imprimirMenusFor(filas, columnas, M, POSS_Y, flecha);
        flecha = movimientoFlecha(flecha, filas, &menu);
    } while(!menu);

    return flecha;
}

int imprimirMenuColores (int filas, int columnas, char M[filas][columnas]) {

    int flecha = 1, menu = 0;
    do {

        system("cls");
        printTienda(15);
        printTiendaMoneda(20);
        printTiendaTitle();
        gotoxy(40,15);
        printf("SNAKE..........................................$%d", P_COLOR_SNAKE);
        gotoxy(40,16);
        printf("TABLERO........................................$%d", P_COLOR_TABLERO_SN);
        gotoxy(40,17);
        printf("PELOTA.........................................$%d", P_COLOR_PELOTA_PN);
        gotoxy(40,18);
        printf("TABLERO PONG...................................$%d", P_COLOR_TABLERO_PN);
        gotoxy(40,19);
        printf("FROG...........................................$%d", P_COLOR_FROG);

        imprimirMenusFor(filas, columnas, M, POSS_Y, flecha);

        flecha = movimientoFlecha(flecha, filas, &menu);

    } while(menu != 1);
    return flecha;

}

int imprimirAdvertencia (int filas, int columnas, char M[filas][columnas]) {

    int flecha = 1, menu = 0;
    do {
        system("cls");
        gotoxy(2,POSS_Y);
        printf("ESTA A PUNTO DE ELIMINAR PERMANENTEMENTE SU USUARIO X_X");

        imprimirMenusFor(filas, columnas, M, POSS_Y, flecha);

        flecha=movimientoFlecha(flecha, filas, &menu);

    } while(menu != 1);
    return flecha;

}


///-----------------------------INTERACCION CON LA TIENDA-------------------------------------
int compraDeColoresSnake (int opcionDeCompra) {
    int codigoDeColor = 0;
    switch(opcionDeCompra) {
    case 1:
        codigoDeColor = ROJO;
        break;
    case 2:
        codigoDeColor = AMARILLO;
        break;
    case 3:
        codigoDeColor = AZUL;
        break;
    case 4:
        codigoDeColor = VIOLETA;
        break;
    case 5:
        codigoDeColor = CIAN;
        break;
    case 6:
        codigoDeColor = BLANCO;
        break;
    }
    return codigoDeColor;
}

int compraDeColores (int opcionDeCompra) {

    int codigoDeColor = 0;

    switch(opcionDeCompra) {

    case 1:
        codigoDeColor = ROJO;
        break;
    case 2:
        codigoDeColor = VERDE;
        break;
    case 3:
        codigoDeColor = AMARILLO;
        break;
    case 4:
        codigoDeColor = AZUL;
        break;
    case 5:
        codigoDeColor = VIOLETA;
        break;
    case 6:
        codigoDeColor = CIAN;
        break;

    }
    return codigoDeColor;
}

bool compra (nodoArbol *unUsu, int filas, int columnas,char M[filas][columnas], int precio, char tipo) {

    int opcion = 0;
    bool  menu = true;
    opcion = imprimirMenuColores(filas, columnas, M);
    if (opcion == 7) {
        menu = false;
    } else {
        switch(tipo) {

        case 'S':
            validacionDeCompra(unUsu, unUsu->dato.compras.colorSnake, &unUsu->dato.compras.validosSnake, tipo, compraDeColoresSnake(opcion), &unUsu->dato.coins, precio);
            break;

        case 'T':
            validacionDeCompra(unUsu, unUsu->dato.compras.colorTableroSN, &unUsu->dato.compras.validosTableroSN, tipo, compraDeColores(opcion), &unUsu->dato.coins, precio);
            break;

        case 'P':
            validacionDeCompra(unUsu, unUsu->dato.compras.colorPelota, &unUsu->dato.compras.validosPelota, tipo, compraDeColores(opcion), &unUsu->dato.coins, precio);
            break;

        case 'C':
            validacionDeCompra(unUsu, unUsu->dato.compras.colorTableroPN, &unUsu->dato.compras.validosTableroPN, tipo, compraDeColores(opcion), &unUsu->dato.coins, precio);
            break;

        case 'F':
            validacionDeCompra(unUsu, unUsu->dato.compras.colorFrog, &unUsu->dato.compras.validosFrog, tipo, compraDeColoresSnake(opcion), &unUsu->dato.coins, precio);
            break;
        }
    }
    return menu;
}

void validacionDeCompra (nodoArbol *unUsu, int arrayColores[], int *validos, char tipo, int codigoDeColor, int *coins, int precio) {

    int i = 0, flag = 0, validosActuales = (*validos);

    while(flag == 0 && i < validosActuales) {

        if(arrayColores[i] == codigoDeColor) {
            flag = 1;
            gotoxy(40,35);
            printf("YA LO TENES REY\n");
            gotoxy(40,36);
            system("pause");
        } else {
            i++;
        }
    }
    if(flag == 0 && (*coins) >= precio) {
        arrayColores[(*validos)] = codigoDeColor;
        (*validos) = (*validos) + 1;
        (*coins) -= precio;
        unUsu->historialCompras = agregarAlPrin(unUsu->historialCompras, guardarTiketArchivo(RUTA_TICKETS, generacionDeTiket(unUsu->dato, codigoDeColor, precio, tipo, unUsu->dato.nombre)));
        unUsu->dato.modi = 1;
    } else if(flag == 0 && (*coins) < precio) {
        printf("No te alcanza, vamo' a juga por mas coins XD \n");
        system("pause");
    }
}

void quieroCambiarColor (nodoArbol *unUsu, int validos, int opcion) {

    if(validos >= 2) {
        decisionDeColor(unUsu, validos, opcion);
    } else {
        printf("Solo cuentas con un color, ve a la tienda por mas ;) \n");
        system("pause");
    }
}

void decisionDeColor (nodoArbol *unUsuario, int validos, int eleccion) {

    switch(eleccion) {
    case 3:
        cambioDePossColor(unUsuario, unUsuario->dato.compras.colorSnake, validos);
        break;
    case 4:
        cambioDePossColor(unUsuario, unUsuario->dato.compras.colorTableroSN, validos);
        break;
    case 5:
        cambioDePossColor(unUsuario, unUsuario->dato.compras.colorPelota, validos);
        break;
    case 6:
        cambioDePossColor(unUsuario, unUsuario->dato.compras.colorTableroPN, validos);
        break;
    case 7:
        cambioDePossColor(unUsuario, unUsuario->dato.compras.colorFrog, validos);
        break;
    }
}

void cambioDePossColor(nodoArbol* unUsuario, int coloresObtenidos[], int validos) {

    int decisionDeColor = 0;
    decisionDeColor = verColoresObtenidos(coloresObtenidos, validos);
    int aux;
    aux = coloresObtenidos[0];
    coloresObtenidos[0] = coloresObtenidos[decisionDeColor];
    coloresObtenidos[decisionDeColor] = aux;
    unUsuario->dato.modi = 1;

}

int verColoresObtenidos (int coloresObtenidos[], int validos) {

    int i=0;
    int menu = 0, flecha = 1;
    do {
        system("cls");
        gotoxy(4, POSS_Y + flecha);
        printf("-->");
        for(i = 0; i < validos; i++) {
            switch(coloresObtenidos[i]) {

            case ROJO:
                gotoxy(10, POSS_Y + i);
                printf("Rojo\n");
                break;
            case VERDE:
                gotoxy(10, POSS_Y + i);
                printf("Verde\n");
                break;
            case AMARILLO:
                gotoxy(10, POSS_Y + i);
                printf("Amarillo\n");
                break;
            case AZUL:
                gotoxy(10, POSS_Y + i);
                printf("Azul\n");
                break;
            case VIOLETA:
                gotoxy(10, POSS_Y + i);
                printf("Violeta\n");
                break;
            case CIAN:
                gotoxy(10, POSS_Y + i);
                printf("Cian\n");
                break;
            case BLANCO:
                gotoxy(10, POSS_Y + i);
                printf("Blanco\n");
                break;
            }
        }
        flecha = movimientoFlecha(flecha, validos-1, &menu);
    } while(menu != 1);
    return flecha;
}




