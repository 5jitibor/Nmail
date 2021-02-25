#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantesEstructuras.h"
#include "rejilla.h"
#include "DatosRejilla.h"
#include "fichero.h"

int MenuMostrar(struct carpeta *direccionCarpetas, int celdasCarpeta, int *SeleccionarCarpetas,char frase[TAMVECTOR]){
    int i=0,terminarBucle=1,volver=0;
    do{
            printf("Que carpeta quieres %s:",frase);
            for(i=0;i<celdasCarpeta;i++){
            printf("\n\t%d-",i);
            CreacionDePalabras(direccionCarpetas[i].titulo);

            }
            printf("\nOtras Opciones:\n\t%d-Volver\nRespuesta: ",i);
            scanf("%d",SeleccionarCarpetas);
            if(*SeleccionarCarpetas<celdasCarpeta+NUMEROOPCIONES && *SeleccionarCarpetas>=0)terminarBucle=0;
            else printf("Numero no valido\n");
            }while(terminarBucle);
            if(*SeleccionarCarpetas==i)volver=1;

            return volver;
}


void Menu(struct carpeta **direccionCarpetas,int *celdasCarpeta,char bordesActual[NUMTIPOBORDES],char bordesSimples[NUMTIPOBORDES],char bordesDobles[NUMTIPOBORDES],int *celdasCorreo,int anchura[NUMTIPOANCHURA], int altura[NUMTIPOMIN],struct cadena usuario, struct correo **mensajes, struct correo *mensajesValor,struct carpeta *carpetasValor){
    //Variables
        int terminarBucle=1,SeleccionarCarpetas=0,volver=0;
        char caracterTipo;



do{
            fflush(stdin);
            printf("Que quieres hacer:\n\tA-Anyadir carpeta\n\tR-Eliminar Carpeta\n\ta-Anyadir correo\n\tV-Visualizar rejilla\n\tF-Terminar programa\nRespuesta:");
            scanf("%c",&caracterTipo);
            system("cls");
            switch(caracterTipo){
                case 'A':
                    *celdasCarpeta+= 1;
                    *direccionCarpetas = realloc(*direccionCarpetas,sizeof(struct carpeta)*(*celdasCarpeta));
                    printf("Dame el nombre de la carpeta nueva: ");
                    crearCarpeta(*direccionCarpetas,*celdasCarpeta-1,anchura,usuario);
                    system("cls");
                    printf("Carpeta creada\n");
                    break;
                case 'a':
                    *celdasCorreo+= 1;
                    *mensajes = realloc(*mensajes,sizeof(struct correo)*(*celdasCorreo));
                    printf("Dame el nombre del correo nuevo: ");
                    crearCorreo(*mensajes,((*celdasCorreo)-1),*direccionCarpetas,anchura,*celdasCarpeta,usuario);
                    printf("Correo creado\n");
                    break;
                case 'R':
                    volver=MenuMostrar(*direccionCarpetas,*celdasCarpeta,&SeleccionarCarpetas,"eliminar");
                    eliminarCarpeta(celdasCorreo,SeleccionarCarpetas,celdasCarpeta,mensajesValor,carpetasValor,direccionCarpetas,mensajes);
                    carpetasValor= (*direccionCarpetas);
                    mensajesValor= (*mensajes);
                    break;
                case 'V':
                    volver=MenuMostrar(*direccionCarpetas,*celdasCarpeta,&SeleccionarCarpetas,"mostrar");
                    system("cls");
                    if(!volver){
                    creacionTablaCompleta(bordesActual,bordesSimples,bordesDobles,*celdasCarpeta,*celdasCorreo,SeleccionarCarpetas,anchura,altura,usuario,*mensajes ,*direccionCarpetas);
                    }
                    break;
                case 'F':
                    terminarBucle=0;
                    break;
                default:
                    printf("Dato no valido\n\n");
            }


            }while(terminarBucle);
}

void menuInicial(struct cadena *usuario, struct correo **mensajes, struct carpeta **direccionCarpetas, int *celdasCorreo, int *celdasCarpeta, int anchura[NUMTIPOANCHURA]){
    char caracter;
    int terminarbucle=1;
    do{
    printf("Como quieres introducir los datos:\n\tA-Por fichero\n\tM-Por teclado\nOpcion:");
    fflush(stdin);
    scanf("%c",&caracter);
    system("cls");
    switch(caracter){
        case'A':
        entradaFicheros(celdasCarpeta,celdasCorreo, direccionCarpetas,anchura,usuario,mensajes);
        terminarbucle--;
        break;
        case 'M':
        datosentrada(celdasCarpeta,celdasCorreo,direccionCarpetas,anchura,usuario,mensajes);
        terminarbucle--;
        break;
        default:
        printf("Dato no valido\n");
    }
    }while(terminarbucle);
}


