#include"constantesEstructuras.h"
#ifndef REJILLA_H_INCLUDED
#define REJILLA_H_INCLUDED

//Incializacion de la funcion de crear rayas y huecos
void crearRayasHuecos(int,char);

//Inicializacion del final de las carpetas
void finalCarpetas(char,char,int);

//Inicializacion del final de los correos y fechas
void finalCorreos(char,char,char,int,int);

//Inicializacion de la creacion del encabezado
void CreacionCabecera(char [NUMTIPOBORDES],int,int,int [NUMTIPOANCHURA],int,  struct cadena usuario);

//Inicializacion de la creacion de la rejilla
void CreacionRejilla(char [NUMTIPOBORDES],int,int,int [NUMTIPOANCHURA],int,struct carpeta *,struct correo *,int);

//Inicializacion de mostrar las palabras
void CreacionDePalabras(struct cadena);

void creacionTablaCompleta(char [NUMTIPOBORDES],char [NUMTIPOBORDES],char [NUMTIPOBORDES],int , int , int ,int [NUMTIPOANCHURA],int [NUMTIPOMIN],struct cadena ,struct correo *, struct carpeta *);

void rejillaHuecosPalabras(int ,int ,int ,int *,int [NUMTIPOANCHURA],char [NUMTIPOBORDES], int, int, struct carpeta *, struct correo *,int);

void rejillaRallas(int ,int , int , int , char [NUMTIPOBORDES], int [NUMTIPOANCHURA]);


#endif // REJILLA_H_INCLUDED
