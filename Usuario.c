#include "Usuario.h"

void gotoxy(int x, int y) {
    printf("%c[%d;%dH", ESC, y, x);
}

stUsuario creacionDeUsuario() {

    int i=0, id = 0;

    id = 1000 + cantidadDeUsuarios(RUTA_USUARIOSGen);

    stUsuario unUsuario;

    validarNombre(unUsuario.nombre);

    gotoxy(57, POSS_Y+3);
    printf("%c[1;%dm", ESC, 32); printf("------ ");printf("%c[0m", ESC);
    printf("Escriba su clave: ");
    fflush(stdin);
    gets(unUsuario.clave);

    unUsuario.idUsuario = id;
    unUsuario.activo    = 1;
    unUsuario.tipo      = i;
    unUsuario.modi      = i;
    unUsuario.coins     = 50;
    unUsuario.maxFrog   = 44;
    unUsuario.maxPong   = 55;
    unUsuario.maxSnake  = 66;
    unUsuario.totalPuntaje = 55;


    unUsuario.compras.colorSnake[i]     = VERDE;
    unUsuario.compras.colorFrog[i]      = VERDE;
    unUsuario.compras.colorPelota[i]    = BLANCO;
    unUsuario.compras.colorTableroSN[i] = BLANCO;
    unUsuario.compras.colorTableroPN[i] = BLANCO;
    unUsuario.compras.validosSnake      = 1;
    unUsuario.compras.validosFrog       = 1;
    unUsuario.compras.validosPelota     = 1;
    unUsuario.compras.validosTableroSN  = 1;
    unUsuario.compras.validosTableroPN  = 1;

    gotoxy(40, POSS_Y+5);
    printf("** Usuario Cargado con exito, recuerde sus datos para ingresar !! \n\n");
    gotoxy(40, POSS_Y+6);
    printf("** Muchas Gracias!! ");
    system("pause");

    return unUsuario;
}



int cantidadDeUsuarios(char ruta[]) {
    int cantidad = 0;
    FILE *archivo;
    archivo = fopen(ruta, "rb");

    if (archivo != NULL) {

        fseek(archivo, 0, SEEK_END);
        cantidad = ftell(archivo)/sizeof(stUsuario);
        fclose(archivo);
    } else {
        printf ("Error de apertura\n");
    }

    return cantidad;
}

int promedioDePuntos (stUsuario ususario) {

    int promedio = (ususario.maxSnake + ususario.maxPong + ususario.maxFrog)/ALLGAMES;

    return promedio;
}

void muestraArreglo(stUsuario ususarios[], int validos){

    int i = 0;
    while(i<validos){
        mostrarUsuario(ususarios[i]);
        i++;
    }
}

void insertarEnOrden (stUsuario U[], int J, stUsuario dato) {


    int i = J;
    while(strcmpi(U[i].nombre, dato.nombre)>0 && i>=0) {

        U[i+1] = U[i];
        i--;
    }
    U[i+1] = dato;
}

void ordenPorInsercionArr (stUsuario U[],int V) {

    int J = 0;
    stUsuario dato;
    while (J < V-1) {

        dato = U[J+1];
        insertarEnOrden(U, J, dato);
        J++;
    }
}

int deArchiToArreglo (stUsuario U[], int dim) {


    FILE * archiUs = fopen(RUTA_USUARIOSGen,"rb");
    stUsuario aux;
    int i = 0;

    if(archiUs) {
        while(i<dim && (fread(&aux,sizeof(stUsuario),1,archiUs)>0)) {
            U[i] = aux;
            i++;
        }
        ordenPorInsercionArr(U, i);
        fclose(archiUs);
    } else {
        printf("Error en apertura :( ");
    }
    return i;
}


void validarNombre(char nombre[]) {
    int coincidencia = 0;
    do {


        system("cls");
        calaberaCreacionUsuario();
        gotoxy(57, POSS_Y-2);printf("%c[1;%dm", ESC, 32);
        printf("------ ");printf("%c[0m", ESC);
        printf(" Crearemos su usuario de juego ");printf("%c[1;%dm", ESC, 32);
        printf("------ ");
        gotoxy(57, POSS_Y-1);printf("____________________________________________");
        printf("%c[0m", ESC);

        gotoxy(57, POSS_Y+1);
        printf("%c[1;%dm", ESC, 32);printf("------");printf("%c[0m", ESC);
        printf(" Ingrese su nombre de usuario:  ");
        fflush(stdin);
        gets(nombre);

        //VALIDACION DE USUARIO EXISTENTE
        coincidencia = existenciaUsuArchi(RUTA_USUARIOSGen,nombre);

        if(coincidencia!=0) {
            gotoxy(56, POSS_Y+3);
            printf("Nombre de usuario en uso, por favor escoja otro\n");
            gotoxy(55, POSS_Y+4);
            system("pause");
            system("cls");
        }

    } while(coincidencia == 1);
}

int existenciaUsuArchi (char ruta[],char unNombre[]) {
    stUsuario aux;
    int flag = 0;
    FILE * archiUs = fopen(ruta,"rb");

    if(archiUs) {
        while(flag == 0 && (fread(&aux,sizeof(stUsuario),1,archiUs)>0)) {
            if (strcmpi(unNombre, aux.nombre)==0) {
                flag = 1;
            }
        }
        fclose(archiUs);
    } else {
        printf("Error en apertura :( ");
    }

    return flag;
}

void guardarUsuArchivo (char ruta[], stUsuario usuario) { //CARGA USUARIO EN ARCHIVO

    FILE *archi = fopen(ruta,"ab");

    if (archi != NULL) {
        fwrite(&usuario, sizeof(stUsuario), 1, archi);
        fclose(archi);
    } else {
        printf("Error en la apertura de archivo");
    }

}

void verArchi (char ruta[]) { //CARGA USUARIO EN ARCHIVO

    FILE * archi = fopen(ruta,"rb");
    stUsuario aux;

    if (archi != NULL) {
        while(fread(&aux, sizeof(stUsuario), 1, archi)>0) {
            mostrarUsuario(aux);
        }
        fclose(archi);
    } else {
        printf("Error en la apertura de archivo");
    }

}

void mostrarUsuario(stUsuario usuarioE) {

    //gotoxy(30,40);
    printf("\n_____________________________________________________________\n\n");
    //gotoxy(44,41);
    printf("ID de usuario:....................%d\n",usuarioE.idUsuario);
    //gotoxy(44,42);
    printf("Nombre de usuario:...........%s\n",usuarioE.nombre);
    //gotoxy(44,43);
    printf("Contrasenia:.................%s\n",usuarioE.clave);
    //gotoxy(44,44);
    printf("Coins:.......................%d\n",usuarioE.coins);
    //gotoxy(44,45);
    printf("Estado:......................%d\n",usuarioE.activo);
    //gotoxy(44,45);
    printf("Maximo puntaje en Snake:.....%d\n",usuarioE.maxSnake);
    //gotoxy(44,46);
    printf("Maximo puntaje en Frog:......%d\n",usuarioE.maxFrog);
    //gotoxy(44,47);
    printf("Maximo puntaje en Pong:......%d\n",usuarioE.maxPong);
    //gotoxy(44,48);
    printf("Puntaje total:...............%d\n",usuarioE.totalPuntaje);
    //gotoxy(30,49);
    printf("_____________________________________________________________\n");
}

void mostrarPuntajeUsu(stUsuario usuarioE) {

    //gotoxy(30,40);
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n||\n");
       //gotoxy(44,42);
    printf("|| Nombre de usuario:...........%s                           \n||\n",usuarioE.nombre);
    //gotoxy(44,45);
    printf("|| Maximo puntaje en SNAKE:.....%d                           \n",usuarioE.maxSnake);
    //gotoxy(44,46);
    printf("|| Maximo puntaje en FROG:......%d                           \n",usuarioE.maxFrog);
    //gotoxy(44,47);
    printf("|| Maximo puntaje en PONG:......%d                           \n||",usuarioE.maxPong);
    //gotoxy(44,48);
    printf("\n|| Puntaje total:.................................%d \n||\n",usuarioE.totalPuntaje);
    //gotoxy(30,49);
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
}

void verPerfil(stUsuario unUsu) {
    gotoxy(25,11);
    printf("----------------------------------------------------------------------------------------");
    gotoxy(25,12);
    printf("|| Nombre de Usuario: %s",unUsu.nombre);
    gotoxy(25,13);printf("||");
    gotoxy(25,14);
    printf("|| Maximo puntaje Snake: [ %d ] ",unUsu.maxSnake);
    gotoxy(25,15);printf("||");
    gotoxy(25,16);
    printf("|| Maximo puntaje Frog:  [ %d ] ",unUsu.maxFrog);
    gotoxy(25,17);printf("||");
    gotoxy(25,18);
    printf("|| Maximo puntaje Pong:  [ %d ] ",unUsu.maxPong);
    gotoxy(25,19);printf("||");
    gotoxy(25,20);
    printf("|| Tus coins:            [$%d ] ",unUsu.coins);
    gotoxy(61,12);
    printf("|| Colores Snake:    ");
    for(int i = 0; i < unUsu.compras.validosSnake; i++) {
        imprimirBloqueDeColor(unUsu.compras.colorSnake[i]);
    }
    gotoxy(111,12);printf("||");
    gotoxy(111,13);printf("||");
    gotoxy(61,14);
    printf("|| Colores TableroSN:");
    for(int i = 0; i < unUsu.compras.validosTableroSN; i++) {
        imprimirBloqueDeColor(unUsu.compras.colorTableroSN[i]);
    }
    gotoxy(111,14);printf("||");
    gotoxy(111,15);printf("||");
    gotoxy(61,16);
    printf("|| Colores Pelota:   ");
    for(int i = 0; i < unUsu.compras.validosPelota; i++) {
        imprimirBloqueDeColor(unUsu.compras.colorPelota[i]);
    }
    gotoxy(111,16);printf("||");
    gotoxy(111,17);printf("||");
    gotoxy(61,18);
    printf("|| Colores TableroPN:");
    for(int i = 0; i < unUsu.compras.validosTableroPN; i++) {
        imprimirBloqueDeColor(unUsu.compras.colorTableroPN[i]);
    }
    gotoxy(111,18);printf("||");
    gotoxy(111,19);printf("||");
    gotoxy(61,20);
    printf("|| Colores Frog:     ");
    for(int i = 0; i < unUsu.compras.validosFrog; i++) {
        imprimirBloqueDeColor(unUsu.compras.colorFrog[i]);
    }
    gotoxy(111,20);printf("||");
    gotoxy(25,21);
    printf("----------------------------------------------------------------------------------------");

}

void imprimirBloqueDeColor(int color){
    switch(color){
        case ROJO:
            printf(" [" RED_T "%c" RESET_COLOR "]"    ,219);
        break;
        case VERDE:
            printf(" [" GREEN_T "%c" RESET_COLOR "]"  ,219);
        break;
        case AMARILLO:
            printf(" [" YELLOW_T "%c" RESET_COLOR "]" ,219);
        break;
        case AZUL:
            printf(" [" BLUE_T "%c" RESET_COLOR "]"   ,219);
        break;
        case VIOLETA:
            printf(" [" MAGENTA_T "%c" RESET_COLOR "]",219);
        break;
        case CIAN:
            printf(" [" CYAN_T "%c" RESET_COLOR "]"   ,219);
        break;
        case BLANCO:
            printf(" [" WHITE_T "%c" RESET_COLOR "]"  ,219);
        break;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void guardarPerfilArchi(stUsuario unUsu) {
    int possUsuario = 0;
    FILE *archi = fopen(RUTA_USUARIOSGen, "r+b");
    if(archi!=NULL) {
        possUsuario = possUsuArchivo(unUsu);
        fseek(archi,sizeof(stUsuario)*(possUsuario-1), SEEK_CUR);
        fwrite(&unUsu,sizeof(stUsuario),1,archi);
        fclose(archi);
    } else {
        printf("Archivo dañado :( ");
    }
}


int possUsuArchivo (stUsuario usuarioActual) {

    stUsuario aux;
    int cont = 0, flag = 0;
    FILE *archivo = fopen(RUTA_USUARIOSGen, "rb");

    if (archivo!=NULL) {

        while(flag == 0 && fread(&aux, sizeof(stUsuario), 1, archivo) > 0) {
            if(strcmpi(aux.nombre,usuarioActual.nombre)==0) {
                flag = 1;
            }
            cont+=1;
        }
        fclose(archivo);
    } else {
        printf("Archivo daniado");
    }

    return cont;
}

void impresionMAME()
{

gotoxy(20,5);printf("  /$$   /$$                           /$$       /$$      /$$ ");
gotoxy(20,6);printf(" | $$$ | $$                          | $/      | $$$    /$$$ ");
gotoxy(20,7);printf(" | $$$$| $$  /$$$$$$         /$$$$$$$|_/       | $$$$  /$$$$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$  ");
gotoxy(20,8);printf(" | $$ $$ $$ /$$__  $$       /$$_____/          | $$ $$/$$ $$ |____  $$| $$_  $$_  $$ /$$__  $$ ");
gotoxy(20,9);printf(" | $$  $$$$| $$  \\ $$      | $$                | $$  $$$| $$  /$$$$$$$| $$ \\ $$ \\ $$| $$$$$$$$ ");
gotoxy(20,10);printf(" | $$\\  $$$| $$  | $$      | $$                | $$\\  $ | $$ /$$__  $$| $$ | $$ | $$| $$_____/ ");
gotoxy(20,11);printf(" | $$ \\  $$|  $$$$$$/      |  $$$$$$$          | $$ \\/  | $$|  $$$$$$$| $$ | $$ | $$|  $$$$$$$ ");
gotoxy(20,12);printf(" |__/  \\__/ \\______/        \\_______/          |__/     |__/ \\_______/|__/ |__/ |__/ \\_______/ ");

gotoxy(20,13);printf("           __ _____ _____ _____ _____ _____    _____ _____    _____ _____ _____ _____ ");
gotoxy(20,14);printf("        __|  |  |  |   __|   __|  |  |   __|  |  |  |   | |  |     |  _  |     |   __|");
gotoxy(20,15);printf("       |  |  |  |  |   __|  |  |  |  |   __|  |  |  | | | |  | | | |     | | | |   __|");
gotoxy(20,16);printf("       |_____|_____|_____|_____|_____|_____|  |_____|_|___|  |_|_|_|__|__|_|_|_|_____|");

}

void calaberaCreacionUsuario (){

gotoxy(20,7);printf("                     ______                                                               ");
gotoxy(20,8);printf("                  .-        -.       ___      ___       __       ___      ___   _______   ");
gotoxy(20,9);printf("                 /            \\     |¨  \\    /¨  |     /¨¨\\     |¨  \\    /¨  | /¨     ¨|  ");
gotoxy(20,10);printf("                |              |     \\   \\  //   |    /    \\     \\   \\  //   |(: ______)  ");
gotoxy(20,11);printf("                |,  .-.  .-.  ,|     /\\\\  \\/.    |   /' /\\  \\    /\\\\  \\/.    | \\/    |    ");
gotoxy(20,12);printf("                | )(_o/  \\o_)( |    |: \\.        |  //  __'  \\  |: \\.        | // ___)_   ");
gotoxy(20,13);printf("                |/     /\\     \\|    |.  \\    /:  | /   /  \\\\  \\ |.  \\    /:  |(:      ¨|  ");
gotoxy(20,14);printf("      (@_       (_     ^^     _)    |___|\\__/|___|(___/    \\___)|___|\\__/|___| \\_______)  ");
gotoxy(20,15);printf("  _    ) \\_______\\__|IIIIII|__/__________________________________________________________ ");
gotoxy(20,16);printf("(_)@8@8{}<________|-\\IIIIII/-|___________________________________________________________>");
gotoxy(20,17);printf("       )_/        \\          /                                                            ");
gotoxy(20,18);printf("      (@           `--------`                                                             ");

}

void calaberaAdmin (int x, int y){

gotoxy(x,y-1); printf("       ssssssss                       ");
gotoxy(x,y);   printf("     ssssssssssss                     ");
gotoxy(x,y+1); printf("   ssssss    ssssss                   ");
gotoxy(x,y+2); printf("  sssss        sssss                  ");
gotoxy(x,y+3); printf("   sss          ssssss                ");
gotoxy(x,y+4); printf("   sssss         ssssss               ");
gotoxy(x,y+5); printf("    ¶¶¶*¶¶        ssssss              ");
gotoxy(x,y+6); printf("    ¶¶¶¶¶¶¶¶¶)     s¶¶¶¶¶¶¶¶¶¶¶¶¶     ");
gotoxy(x,y+7); printf("    ¶¶      //    ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶   ");
gotoxy(x,y+8); printf("     ¶¶          ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶   ");
gotoxy(x,y+9); printf("      ¶ //       ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶  ");
gotoxy(x,y+10);printf("       ¶)        ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ ");
gotoxy(x,y+11);printf("                 s¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶  ");
gotoxy(x,y+12);printf("                sss¶¶  ¶¶¶¶¶¶¶¶   ¶¶  ");
gotoxy(x,y+13);printf("               ssss¶¶    ¶¶¶¶     ¶¶  ");
gotoxy(x,y+14);printf("              sssss¶¶¶¶¶¶¶¶ ¶¶¶¶¶¶¶¶  ");
gotoxy(x,y+15);printf("             ssssss ¶¶¶¶¶¶ ¶ ¶¶¶¶¶¶   ");
gotoxy(x,y+16);printf("             ssssss    ¶¶¶¶¶¶¶¶¶      ");
gotoxy(x,y+17);printf("            ssssss     ¶ ¶ ¶ ¶ ¶      ");
gotoxy(x,y+18);printf("             ssssss      ssssss       ");
gotoxy(x,y+19);printf("              ssssss    ssssss        ");
gotoxy(x,y+20);printf("               ssssss sssssss         ");
gotoxy(x,y+21);printf("                 ssssssssss           ");
gotoxy(x,y+21);printf("                   ssssss             ");

}


void joystick(int x, int y){

gotoxy(x,y);    printf("          ___           ");
gotoxy(x,y+1);  printf("        ,¨---¨.         ");
gotoxy(x,y+2);  printf("        :     ;         ");
gotoxy(x,y+3);  printf("         `-.-'          ");
gotoxy(x,y+4);  printf("          | |           ");
gotoxy(x,y+5);  printf("          | |           ");
gotoxy(x,y+6);  printf("          | |           ");
gotoxy(x,y+7);  printf("       _.-\\_/-._        ");
gotoxy(x,y+8);  printf("    _ / |     | \\ _     ");
gotoxy(x,y+9);  printf("   / /   `---'   \\ \\    ");
gotoxy(x,y+10); printf("  /  `-----------'  \\   ");
gotoxy(x,y+11); printf(" /,-¨¨-.       ,-¨¨-.\\  ");
gotoxy(x,y+12); printf("( i-..-i       i-..-i ) ");
gotoxy(x,y+13); printf("|`|    |-------|    |'| ");
gotoxy(x,y+14); printf("\\ `-..-'  ,=.  `-..-'/  ");
gotoxy(x,y+15); printf(" `--------|=|-------'   ");
gotoxy(x,y+16); printf("          | |           ");
gotoxy(x,y+17); printf("          \\ \\           ");
gotoxy(x,y+18); printf("           ) )          ");
gotoxy(x,y+19); printf("          / /           ");
gotoxy(x,y+20); printf("         ( (            ");
}



void printTienda(int y){

gotoxy(0,y+1); printf("                             _.--.         ");
gotoxy(0,y+2); printf("                        _.-'_:-'||         ");
gotoxy(0,y+3); printf("                    _.-'_.-::::'||         ");
gotoxy(0,y+4); printf("               _.-:'_.-::::::'  ||         ");
gotoxy(0,y+5); printf("             .'`-.-:::::::'     ||         ");
gotoxy(0,y+6); printf("            /.'`;|:::::::'      ||_        ");
gotoxy(0,y+7); printf("           ||   ||::::::'     _.;._'-._    ");
gotoxy(0,y+8); printf("           ||   ||:::::'  _.-!oo @.!-._'-. ");
gotoxy(0,y+9); printf("           '.  ||:::::.-!()oo @!()@.-'_.|| ");
gotoxy(0,y+10);printf("            '.'-;|:.-'.&$@.& ()$%%-'o.'\\U|| ");
gotoxy(0,y+11);printf("              `>'-.!@%%()@'@_%%-'_.-o _.|'|| ");
gotoxy(0,y+12);printf("               ||-._'-.@.-'_.-' _.-o  |'|| ");
gotoxy(0,y+13);printf("               ||=[ '-._.-\\U/.-'    o |'|| ");
gotoxy(0,y+14);printf("               || '-.]=|| |'|      o  |'|| ");
gotoxy(0,y+15);printf("               ||      || |'|        _| '; ");
gotoxy(0,y+16);printf("               ||      || |'|    _.-'_.-'  ");
gotoxy(0,y+17);printf("               |'-._   || |'|_.-'_.-'      ");
gotoxy(0,y+18);printf("                '-._'-.|| |' `_.-'         ");
gotoxy(0,y+19);printf("                    '-.||_/.-'             ");

}





void printTiendaMoneda (int y){

gotoxy(90,y+1);  printf("            $$$$$      ");
gotoxy(90,y+2);  printf("            $:::$      ");
gotoxy(90,y+3);  printf("        $$$$$:::$$$$$$ ");
gotoxy(90,y+4);  printf("      $$::::::::::::::$");
gotoxy(90,y+5);  printf("     $:::::$$$$$$$::::$");
gotoxy(90,y+6);  printf("     $::::$       $$$$$");
gotoxy(90,y+7);  printf("     $::::$            ");
gotoxy(90,y+8);  printf("     $::::$            ");
gotoxy(90,y+9);  printf("     $:::::$$$$$$$$$   ");
gotoxy(90,y+10); printf("      $$::::::::::::$$ ");
gotoxy(90,y+11); printf("        $$$$$$$$$:::::$");
gotoxy(90,y+12); printf("                 $::::$");
gotoxy(90,y+13); printf("                 $::::$");
gotoxy(90,y+14); printf("     $$$$$       $::::$");
gotoxy(90,y+15); printf("     $::::$$$$$$$:::::$");
gotoxy(90,y+16); printf("     $::::::::::::::$$ ");
gotoxy(90,y+17); printf("      $$$$$$:::$$$$$   ");
gotoxy(90,y+18); printf("           $:::$       ");
gotoxy(90,y+19); printf("           $$$$$       ");

}


void printTiendaTitle(){

gotoxy(37,3);  printf("'########:'####:'########:'##::: ##:'########:::::'###::::");
gotoxy(37,4);  printf("... ##..::. ##:: ##.....:: ###:: ##: ##.... ##:::'## ##:::");
gotoxy(37,5);  printf("::: ##::::: ##:: ##::::::: ####: ##: ##:::: ##::'##:. ##::");
gotoxy(37,6);  printf("::: ##::::: ##:: ######::: ## ## ##: ##:::: ##:'##:::. ##:");
gotoxy(37,7);  printf("::: ##::::: ##:: ##...:::: ##. ####: ##:::: ##: #########:");
gotoxy(37,8);  printf("::: ##::::: ##:: ##::::::: ##:. ###: ##:::: ##: ##.... ##:");
gotoxy(37,9);  printf("::: ##::::'####: ########: ##::. ##: ########:: ##:::: ##:");
gotoxy(37,10); printf(":::..:::::....::........::..::::..::........:::..:::::..::");
}

