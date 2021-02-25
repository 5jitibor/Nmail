//Programa que diseña un panel de correos introduciendo anchura y celdas de correos y carpetas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"rejilla.h"
#include"constantesEstructuras.h"
#include"fichero.h"
#include"DatosRejilla.h"
#include"Menu.h"


int main()
{
//Incializacion de variables char
    char bordesSimples[NUMTIPOBORDES]={179,196,218,191,192,217,197,195,194,193,180,32}, bordesDobles[NUMTIPOBORDES]={186,205,201,187,200,188,206,204,203,202,185,32}, bordesActual[NUMTIPOBORDES];

    //Incializacion de variables int
    int altura[NUMTIPOMIN]={1,3},anchura[NUMTIPOANCHURA]={3,-1,-1,-1},celdasCorreo=-1, celdasCarpeta=-2;

    struct cadena usuario;
    struct carpeta *direccionCarpetas=NULL;
    struct correo *mensajes=NULL;

    printf("Buenos dias estas en centro de correos electronico personal.\n\n");
    if(ficheroExiste()){
    menuInicial(&usuario,&mensajes,&direccionCarpetas,&celdasCorreo,&celdasCarpeta,anchura);
    }
    else datosentrada(&celdasCarpeta,&celdasCorreo,&direccionCarpetas,anchura,&usuario,&mensajes);
    //Mensaje de bienvenida
    printf("Primera visualizacion de la rejilla:\n");
    creacionTablaCompleta(bordesActual,bordesSimples,bordesDobles,celdasCarpeta,celdasCorreo,0,anchura,altura,usuario,mensajes ,direccionCarpetas);
    Menu(&direccionCarpetas,&celdasCarpeta,bordesActual,bordesSimples,bordesDobles,&celdasCorreo,anchura,altura,usuario,&mensajes,mensajes,direccionCarpetas);
    FinalizarPrograma(usuario,direccionCarpetas,mensajes,celdasCarpeta,celdasCorreo);

}





