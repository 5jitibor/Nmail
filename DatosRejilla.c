#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"constantesEstructuras.h"
#include"rejilla.h"

//Funcion que pide los numeros de entrada
int entradaDatosNumericos(int numeroMinimo,char frase[TAMVECTOR]){

    //Incializacion de variables
    int resul, datoCorrecto=1;

    //Limpia de cualquier caracter guardado en el teclado
    fflush(stdin);

    //Buce que compreuba si el dato es correcto
    do{
        //Pide dato numerico
        printf("%s",frase);
        scanf("%d",&resul);

        //Comprueba si es un dato valido
        //Si es correcto termina bucle
        if(numeroMinimo<=resul)datoCorrecto=0;

        //Si no es correcto no termina bucle
         else printf("Numero no valido\n");

    }while(datoCorrecto);

    return resul;
}
void calcularAnchura(int anchura[NUMTIPOANCHURA], struct cadena usuario){
    anchura[ANCHENCABEZADO]=anchura[ANCHCARPETA]+anchura[ANCHCORREO]+anchura[ANCHLEIDO]+TAMSELECTOR;
        if(usuario.longitud>anchura[ANCHENCABEZADO]){
            anchura[ANCHCORREO] += usuario.longitud-anchura[ANCHENCABEZADO];
            anchura[ANCHENCABEZADO] += usuario.longitud-anchura[ANCHENCABEZADO];
        }
        if(((anchura[ANCHENCABEZADO]-usuario.longitud)%2) != 0){
           anchura[ANCHCORREO] ++ ;
           anchura[ANCHENCABEZADO] ++ ;
        }
}

//Funcion que pide los caracteres de entrada
char entradaDatosCaracter(char frase[TAMVECTOR]){

    //Incializacion de variables
    char caracter;

    //Limpia de cualquier caracter guardado en el teclado
    fflush(stdin);

    //Pide dato de un caracter
    printf("%s",frase);
    scanf("%c",&caracter);

        return caracter;
}

void PedirFrase(struct cadena *frase){

            //Variables
            char auxiliar[TAMVECTOR];
            int i;
            gets(auxiliar);
            frase->longitud = strlen(auxiliar);
            frase->contenido = (char *)malloc(sizeof(char)*(frase->longitud));
            for(i=0;i<frase->longitud;i++)frase->contenido[i]=auxiliar[i];

}

void RayasDoblesOSencillas(char bordesActual[NUMTIPOBORDES],char bordesSimples[NUMTIPOBORDES],char bordesDobles[NUMTIPOANCHURA]){

    //Variables
    int i=0, terminarBucle=1;

    //Pedir tipo de bordes, terminara cuando haya elgido correctamente uno de los bordes
        do{
        //Pide que tipo borde quiere
        switch(entradaDatosCaracter("Que tipo de bordes quieres simples(-) o dobles(=): ")){
            //Si ha metido el caracter -
            case '-':
                for(i=0;i<NUMTIPOBORDES;i++)bordesActual[i]=bordesSimples[i];
                terminarBucle=0;
                break;
            //Si ha metido el caracter =
            case '=':
                for(i=0;i<NUMTIPOBORDES;i++)bordesActual[i]=bordesDobles[i];
                terminarBucle=0;
                break;
            //Si no es ninguno de los otros casos
            default:
                printf("Dato no valido\n");
                terminarBucle=1;

        }
        }while(terminarBucle);
}

void crearCorreo(struct correo *mensajes,int posicion,struct carpeta *direccionCarpetas,int anchura[NUMTIPOANCHURA],int celdasCarpeta,struct cadena usuario){
    int terminarBucle=1,i=1;
    fflush(stdin);
    PedirFrase(&mensajes[posicion].titulo);
    if(anchura[ANCHCORREO]< mensajes[posicion].titulo.longitud){
        anchura[ANCHCORREO]=mensajes[posicion].titulo.longitud;
        calcularAnchura(anchura,usuario);
        }


    do{
            printf("En que carpeta lo quieres meter\n");
            for(i=0;i<celdasCarpeta;i++){
                    printf("\t%d-",i);
                    CreacionDePalabras(direccionCarpetas[i].titulo);
                    printf("\n");
                    }

            printf("Respuesta:");
            scanf("%d",&mensajes[posicion].carpeta);
            if(mensajes[posicion].carpeta<celdasCarpeta && mensajes[posicion].carpeta>=0)terminarBucle=0;
            else printf("Numero no valido\n");


            }while(terminarBucle);

            terminarBucle=1;
    do{
        //Comprobar dato correcto
        switch(entradaDatosCaracter("Esta leido si(S,s) o no(N,n): ")){
            //Si ha metido el caracter S o s
            case'S':
            case's':
                terminarBucle=0;
                mensajes[posicion].leido=1;
                break;
            //Si ha metido el caracter N o n
            case'N':
            case'n':
                terminarBucle=0;
                mensajes[posicion].leido=0;
                break;
            //Si no es ninguno de los otros casos
            default:
                printf("Dato incorrecto\n");

        }
        }while(terminarBucle);
    direccionCarpetas[mensajes[posicion].carpeta].NumeroDecorreos ++ ;
    system("cls");

}



void eliminarCarpeta(int *celdasCorreo,int SeleccionarCarpetas,int *celdasCarpeta,struct correo *mensajes, struct carpeta *direccionCarpetas,struct carpeta **direccionCarpetasDestino,struct correo **mensajesDestino){
    struct correo *mensajesAuxiliar=NULL;
    struct carpeta *direccionCarpetasAuxiliar=NULL;
    int contador=0,i=0;

    mensajesAuxiliar=(struct correo*)malloc(sizeof(struct correo)*(*celdasCorreo-direccionCarpetas[SeleccionarCarpetas].NumeroDecorreos));
                    for(i=0;i<*celdasCorreo;i++){
                        if(mensajes[i].carpeta != SeleccionarCarpetas){
                            if(mensajes[i].carpeta > SeleccionarCarpetas){
                                mensajes[i].carpeta --;
                            }
                            mensajesAuxiliar[contador]=mensajes[i];
                            contador++;
                        }
                    }
                    *celdasCorreo-=(direccionCarpetas[SeleccionarCarpetas].NumeroDecorreos);
                    *mensajesDestino=mensajesAuxiliar;

                    direccionCarpetasAuxiliar=(struct carpeta*)malloc(sizeof(struct carpeta)*((*celdasCarpeta)-1));
                    contador=0;
                    for(i=0;i<*celdasCarpeta;i++){
                         if(i != SeleccionarCarpetas){
                        direccionCarpetasAuxiliar[contador]=direccionCarpetas[i];
                        contador++;
                        }
                    }
                    *celdasCarpeta-=1;
                    *direccionCarpetasDestino=direccionCarpetasAuxiliar;
                    system("cls");
                    printf("Carpeta eliminada\n");

}

void crearCarpeta(struct carpeta *direccionCarpetas, int posicion, int anchura[NUMTIPOANCHURA],struct cadena usuario){
    fflush(stdin);
    PedirFrase(&direccionCarpetas[posicion].titulo);
    direccionCarpetas[posicion].NumeroDecorreos=0;
    if(anchura[ANCHCARPETA]-TAMSELECTOR<(direccionCarpetas[posicion].titulo.longitud)){
        anchura[ANCHCARPETA]=(direccionCarpetas[posicion].titulo.longitud);
        anchura[ANCHCARPETA]+=TAMSELECTOR;
        calcularAnchura(anchura,usuario);
    }

}

void datosentrada(int *celdasCarpeta,int *celdasCorreo, struct carpeta **direccionCarpetas, int anchura[NUMTIPOANCHURA],struct cadena *usuario, struct correo **mensajes){
    int i=0;
    printf("Dame el nombre del usuario: ");
    fflush(stdin);
    PedirFrase(usuario);
    system("cls");
    *celdasCarpeta=entradaDatosNumericos(MINRESTO,"Cuantas carpetas quieres(minimo 1): ");
    *direccionCarpetas= (struct carpeta *)malloc(sizeof(struct carpeta)*(*celdasCarpeta));
    for(i=0;i<*celdasCarpeta;i++){
        printf("Dame el nombre de la carpeta %d:",i);
        crearCarpeta(*direccionCarpetas,i,anchura,*usuario);
    }
    system("cls");
    *celdasCorreo=entradaDatosNumericos(MINCORREOS,"Cuantos correos quieres(minimo 0): ");
    *mensajes=(struct correo *)malloc(sizeof(struct correo)*(*celdasCorreo));
    for(i=0;i<*celdasCorreo;i++){
        printf("Dame el nombre del correo %d: ",i);
        crearCorreo(*mensajes,i,*direccionCarpetas,anchura,*celdasCarpeta,*usuario);
    }

}
