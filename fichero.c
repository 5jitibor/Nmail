#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"constantesEstructuras.h"
#include "DatosRejilla.h"

void FinalizarPrograma(struct cadena nombre,struct carpeta *direccionCarpetas, struct correo *mensajes, int celdasCarpeta, int celdasCorreo){

        int i,j,guardar=2;
        do{
            switch(entradaDatosCaracter("Quieres guardar los cambios si(S,s)o(N,n): ")){
                case 'S':
                case 's':
                    guardar=1;
                    break;
                case 'N':
                case 'n':
                    guardar=0;
                    break;
                default:
                    printf("Dato no valido\n");

            }

        }while(guardar>1);
        system("cls");
        if(guardar){
            FILE* Fichero =fopen("Ficheros/CarpetasUsuario.txt","w+");
            for(i=0;i<nombre.longitud;i++){
                fputc(nombre.contenido[i],Fichero);
                }
            fputc('\n',Fichero);
            for(i=0;i<celdasCarpeta;i++){
                for(j=0;j<direccionCarpetas[i].titulo.longitud;j++){
                    fputc(direccionCarpetas[i].titulo.contenido[j],Fichero);
                }
                fputc('\n',Fichero);
            }
            fclose(Fichero);
            Fichero =fopen("Ficheros/Correos.txt","w+");

            for(i=0;i<celdasCorreo;i++){
                for(j=0;j<mensajes[i].titulo.longitud;j++){
                fputc(mensajes[i].titulo.contenido[j],Fichero);
                }
                fputc('\n',Fichero);
                fprintf(Fichero,"%d\n",mensajes[i].carpeta);
                fprintf(Fichero,"%d\n",mensajes[i].leido);


            }
            fclose(Fichero);
            printf("Se ha guardado correctamente.\n");
            }
            else{
            printf("No se han guardado los datos.\n");
            }

        //Mensaje de despedida
        printf("Adios.\nGracias por utilizar mi programa.\n");

        //Pausa para cuando le de terminarloCarpetas
        system("pause");


}
void PedirFraseFichero(struct cadena *frase,FILE* Fichero){

            //Variables
            char auxiliar[TAMVECTOR];
            int i;

            fgets(auxiliar,200,Fichero);
            frase->longitud = strlen(auxiliar)-1;
            frase->contenido = (char *)malloc(sizeof(char)*(frase->longitud));
            for(i=0;i<frase->longitud;i++)frase->contenido[i]=auxiliar[i];

}

int contadorElementosFichero(char origen[TAMVECTOR]){
    int contador=0;
    char auxiliar[TAMVECTOR];
    FILE* ficheroAbierto=fopen(origen,"r");
    while(!feof(ficheroAbierto))
        {
            fgets(auxiliar,TAMVECTOR,ficheroAbierto);
            contador++;
        }
    fclose(ficheroAbierto);
    return contador;

}

void entradaDatosFicheroCarpeta(int anchura[NUMTIPOANCHURA],struct carpeta *direccionCarpetas, int celdasCarpeta,struct cadena *usuario){

    int i;
    FILE* Carpetas = fopen("Ficheros/CarpetasUsuario.txt","r");
    PedirFraseFichero(usuario,Carpetas);
    for(i=0;i<celdasCarpeta;i++){
            fflush(stdin);
            PedirFraseFichero(&direccionCarpetas[i].titulo,Carpetas);
            if(anchura[ANCHCARPETA]<(direccionCarpetas[i].titulo.longitud))anchura[ANCHCARPETA]=(direccionCarpetas[i].titulo.longitud);
            direccionCarpetas[i].NumeroDecorreos = 0;
        }
        fclose(Carpetas);
        anchura[ANCHCARPETA]+=TAMSELECTOR;

}

void entradaDatosFicheroCorreo(int anchura[NUMTIPOANCHURA],struct carpeta *direccionCarpetas, int celdasCorreo,struct correo *mensajes){

    int i;
    FILE* Correos = fopen("Ficheros/Correos.txt","r");
        for(i=0;i<celdasCorreo;i++){
            PedirFraseFichero(&mensajes[i].titulo,Correos);
            if(anchura[ANCHCORREO]< mensajes[i].titulo.longitud) anchura[ANCHCORREO]=mensajes[i].titulo.longitud;
            fscanf(Correos,"%d",&mensajes[i].carpeta);
            fscanf(Correos,"%d\n",&mensajes[i].leido);
            direccionCarpetas[mensajes[i].carpeta].NumeroDecorreos ++ ;
        }
        fclose(Correos);

}

void entradaFicheros(int *celdasCarpeta,int *celdasCorreo, struct carpeta **direccionCarpetas, int anchura[NUMTIPOANCHURA],struct cadena *usuario, struct correo **mensajes){

    *celdasCarpeta += contadorElementosFichero("Ficheros/CarpetasUsuario.txt");
    *direccionCarpetas = (struct carpeta *)malloc(sizeof(struct carpeta)*(*celdasCarpeta));
    entradaDatosFicheroCarpeta(anchura,*direccionCarpetas,*celdasCarpeta,usuario);
    *celdasCorreo += contadorElementosFichero("Ficheros/Correos.txt");
    *mensajes = (struct correo *)malloc(sizeof(struct correo)*(*celdasCorreo));
    *celdasCorreo/=3;
    entradaDatosFicheroCorreo(anchura,*direccionCarpetas,*celdasCorreo,*mensajes);
    calcularAnchura(anchura,*usuario);
    printf("Se han cargado los datos correctamente\n\n");
}

int ficheroExiste(){
    int comprobacion;
    FILE* FicheroCarpetasUsuario=fopen("Ficheros/CarpetasUsuario.txt","r");
    FILE* FicheroCorreos=fopen("Ficheros/Correos.txt","r");

    if(FicheroCarpetasUsuario==NULL || FicheroCorreos==NULL ){
        comprobacion=0;
        printf("Error: No se ha podido encontrar uno de los dos ficheros tienes que meter los datos por teclado\n");
    }
    else{
        comprobacion=1;
    }
    return comprobacion;
    fclose(FicheroCorreos);


}
