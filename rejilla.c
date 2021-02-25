#include <stdio.h>
#include <stdlib.h>
//Incluimos el paquete String para que funcione correctamente la parte del strlen
#include <string.h>
#include"rejilla.h"
#include"constantesEstructuras.h"
#include"DatosRejilla.h"


void CreacionCabecera(char bordesActual[NUMTIPOBORDES],int celdasCarpeta,int celdasCorreo,int anchura[NUMTIPOANCHURA],int altura, struct cadena usuario){

    //Generamos variables
    int i,huecos;
    //Creacion del encabezado

        //Creacion de borde inicial
        printf("%c",bordesActual[ESQSUPIZQ]);
        crearRayasHuecos(anchura[ANCHENCABEZADO],bordesActual[HORIZONTAL]);
        printf("%c\n",bordesActual[ESQSUPDER]);

        //Creacion del hueco del encabezado
        for(i=1;i<altura;i++){
        printf("%c",bordesActual[VERTICAL]);
        crearRayasHuecos(anchura[ANCHENCABEZADO],bordesActual[ESPACIOS]);
        printf("%c\n",bordesActual[VERTICAL]);
        }
        huecos=(anchura[ANCHENCABEZADO]-usuario.longitud)/2;
        printf("%c",bordesActual[VERTICAL]);
        crearRayasHuecos(huecos,bordesActual[ESPACIOS]);
        CreacionDePalabras(usuario);
        crearRayasHuecos(huecos,bordesActual[ESPACIOS]);
        printf("%c\n",bordesActual[VERTICAL]);

        //Tipo de raya si hay o no celdas de carpetas
        //Raya normal si hay celdas de carpetas
        if(celdasCarpeta!=0){
        printf("%c",bordesActual[TLATIZQ]);
        crearRayasHuecos(anchura[ANCHCARPETA],bordesActual[HORIZONTAL]);
        }

        //Creacion de ultima raya de carpeta si no hay celda de carpetas
        else finalCarpetas(bordesActual[ESQINFIZQ],bordesActual[HORIZONTAL],anchura[ANCHCARPETA]);



        //Tipo de caracter de union Carpetas-Correos si hay o no celdas
        //Si carpeta o correos tiene celdas
        if(celdasCarpeta!=0 || celdasCorreo!=0)printf("%c",bordesActual[TNORMAL]);

        //Si ninguna de las dos tiene celdas
        else printf("%c",bordesActual[HORIZONTAL]);


        //Tipo de raya si hay o no celdas de carpetas
        //Raya normal si hay celdas de correos
        if(celdasCorreo!=0){
            crearRayasHuecos(anchura[ANCHCORREO],bordesActual[HORIZONTAL]);
            printf("%c",bordesActual[TNORMAL]);
            crearRayasHuecos(anchura[ANCHLEIDO],bordesActual[HORIZONTAL]);
            printf("%c\n",bordesActual[TLATDER]);

        }

        //Creacion de ultima raya de correos y fechas
        else finalCorreos(bordesActual[ESQINFDER],bordesActual[HORIZONTAL],bordesActual[HORIZONTAL],anchura[ANCHCORREO],anchura[ANCHLEIDO]);
}


void CreacionRejilla(char bordesActual[NUMTIPOBORDES],int celdasCarpeta,int celdasCorreo,int anchura[NUMTIPOANCHURA],int altura,struct carpeta *direccionCarpetas,struct correo *mensajes,int tipo){

        //Variables
        int i,j,buscadorDeCorreos=0;

        //Creacion de celdas bucle que repite hasta que termina de hacer celdas
        for(i=1,j=1;i<=celdasCarpeta || j<=celdasCorreo;i++,j++){
        //Bucle que genera el hueco de la altura correspondiente
        rejillaHuecosPalabras(altura,i ,j ,&buscadorDeCorreos ,anchura ,bordesActual,celdasCorreo,celdasCarpeta,direccionCarpetas,mensajes,tipo);
        rejillaRallas(i,j,celdasCorreo,celdasCarpeta,bordesActual,anchura);



        }
}

void rejillaRallas(int i,int j, int celdasCorreo, int celdasCarpeta, char bordesActual[NUMTIPOBORDES], int anchura[NUMTIPOANCHURA]){

            //Caso cuando las celdas de los correos sean mas grandes que las celdas de las carpetas
            if(celdasCarpeta<celdasCorreo){
                //Si hay celdas restantes en ambas
                if(i<=celdasCarpeta)printf("%c",bordesActual[CRUZ]);
                //Si noy celdas restantes de carpeta pero si de correo
                else if(i>celdasCarpeta && j<celdasCorreo)printf("%c",bordesActual[TLATIZQ]);
                //Si no hay niguna celda restante en ambas
                else printf("%c",bordesActual[ESQINFIZQ]);
            }
            //Caso cuando las celdas de las carpetas sean mas grandes que las celdas de correos
            else if(celdasCarpeta>celdasCorreo){
                //Si hay celdas restantes en ambas
                if(j<=celdasCorreo)printf("%c",bordesActual[CRUZ]);
                //Si noy celdas restantes de correo pero si de carpeta
                else if(j>celdasCorreo && i<celdasCarpeta)printf("%c",bordesActual[TLATDER]);
                //Si no hay niguna celda restante en ambas
                else printf("%c",bordesActual[ESQINFDER]);
                }
            //Caso cuando las celdas de los correos son iguales que las celdas de las carpetas
            else {
                //Si hay celdas restantes en ambas
                if(i!=celdasCarpeta){
                    printf("%c",bordesActual[CRUZ]);
                }
                //Si no hay niguna celda restante en ambas
                else printf("%c",bordesActual[TINVERTIDA]);
            }



            //Separacion de celdas de correos y fechas
            if(j<celdasCorreo){
                crearRayasHuecos(anchura[ANCHCORREO],bordesActual[HORIZONTAL]);
                printf("%c",bordesActual[CRUZ]);
                crearRayasHuecos(anchura[ANCHLEIDO],bordesActual[HORIZONTAL]);
                printf("%c\n",bordesActual[TLATDER]);
            }

            //Caso para terminar la zona correos y fechas
            else if (j==celdasCorreo)finalCorreos(bordesActual[ESQINFDER],bordesActual[HORIZONTAL],bordesActual[TINVERTIDA],anchura[ANCHCORREO],anchura[ANCHLEIDO]);

            //Caso cuando no haya mas celdas que crear de correos y fechas
            else printf("\n");

}

void rejillaHuecosPalabras(int altura,int i ,int j ,int *buscadorDeCorreos ,int anchura[NUMTIPOANCHURA],char bordesActual[NUMTIPOBORDES],int celdasCorreo, int celdasCarpeta, struct carpeta *direccionCarpetas, struct correo *mensajes,int tipo){
    int k,flechaSelectora;
    for(k=0;k<altura;k++){
            flechaSelectora=0;
            //Crear hueco celda de carpeta
            if(i<=celdasCarpeta){
            printf("%c",bordesActual[VERTICAL]);
            if(tipo==(i-1)){
                printf("->");
                flechaSelectora=TAMSELECTOR;
            }
            CreacionDePalabras(direccionCarpetas[i-1].titulo);
            crearRayasHuecos(anchura[ANCHCARPETA]-(direccionCarpetas[i-1].titulo.longitud)-flechaSelectora,bordesActual[ESPACIOS]);
            }
            //Caso cuando ya no haya que hacer mas celdas de carpeta
            else crearRayasHuecos(anchura[ANCHCARPETA]+1,bordesActual[ESPACIOS]);

            //Borde entra las celdas de carpeta y correo en la linea de huecos
            printf("%c",bordesActual[VERTICAL]);

            //Crear hueco celda de correos y fechas
            if(j<=celdasCorreo){
            while(tipo != mensajes[*buscadorDeCorreos].carpeta)*buscadorDeCorreos+=1;

            CreacionDePalabras(mensajes[*buscadorDeCorreos].titulo);
            crearRayasHuecos(anchura[ANCHCORREO]-mensajes[*buscadorDeCorreos].titulo.longitud,bordesActual[ESPACIOS]);
            printf("%c",bordesActual[VERTICAL]);
            crearRayasHuecos((anchura[ANCHLEIDO]/2),bordesActual[ESPACIOS]);
            if(mensajes[*buscadorDeCorreos].leido)printf("X");
            else printf(" ");
            crearRayasHuecos((anchura[ANCHLEIDO]/2),bordesActual[ESPACIOS]);
            printf("%c\n",bordesActual[VERTICAL]);
            *buscadorDeCorreos+=1;
            }
            //Caso cuando ya no haya que hacer mas celdas de correos y fechas
            else printf("\n");
            }

            //Separacion de las celdas de carpetas
            if(i<celdasCarpeta){
                printf("%c",bordesActual[TLATIZQ]);
                crearRayasHuecos(anchura[ANCHCARPETA],bordesActual[HORIZONTAL]);
            }
            //Caso para terminar la zona carpetas
            else if(i==celdasCarpeta)finalCarpetas(bordesActual[ESQINFIZQ],bordesActual[HORIZONTAL],anchura[ANCHCARPETA]);

            //Caso cuando no haya mas celdas que crear de carpetas
            else crearRayasHuecos(anchura[ANCHCARPETA]+1,bordesActual[ESPACIOS]);
}



//Funcion que genera los huecos y las rayas
void crearRayasHuecos(int numeroCaracteres, char caracter){

    //Variables
    int i;

    //Genera espacios y rallas
    for(i=0;i<numeroCaracteres;i++)printf("%c",caracter);
}


//Funcion que genera la fila final de carpetas
void finalCarpetas(char esquina,char bordeHorizontal,int anchura){
    printf("%c",esquina);
    crearRayasHuecos(anchura,bordeHorizontal);
}


//Funcion que genera la fila final de correos
void finalCorreos(char esquina,char bordeHorizontal,char unionCorreoFecha,int anchuraCorreo,int anchuraFecha){
    crearRayasHuecos(anchuraCorreo,bordeHorizontal);
    printf("%c",unionCorreoFecha);
    crearRayasHuecos(anchuraFecha,bordeHorizontal);
    printf("%c\n",esquina);
}

void CreacionDePalabras(struct cadena frase){

    int i=0;

    for(i=0;i<frase.longitud;i++){
        printf("%c",frase.contenido[i]);
    }

}

void creacionTablaCompleta(char bordesActual[NUMTIPOBORDES],char bordesSimples[NUMTIPOBORDES],char bordesDobles[NUMTIPOBORDES],int celdasCarpeta, int celdasCorreo, int SeleccionarCarpetas,int anchura[NUMTIPOANCHURA],int altura[NUMTIPOMIN],struct cadena usuario,struct correo *mensajes , struct carpeta *direccionCarpetas){
    RayasDoblesOSencillas(bordesActual,bordesSimples,bordesDobles);
    system("cls");
    CreacionCabecera(bordesActual,celdasCarpeta,direccionCarpetas[SeleccionarCarpetas].NumeroDecorreos,anchura,altura[ALTENCABEZADO],usuario);
    CreacionRejilla(bordesActual,celdasCarpeta,direccionCarpetas[SeleccionarCarpetas].NumeroDecorreos,anchura,altura[ALTRESTO],direccionCarpetas,mensajes,SeleccionarCarpetas);

}
