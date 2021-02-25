#include"constantesEstructuras.h"
#ifndef DATOSREJILLA_H_INCLUDED
#define DATOSREJILLA_H_INCLUDED

//Incializacion de la funcion entrada de datos numericos
int entradaDatosNumericos(int,char frase[TAMVECTOR]);

//Inicializacion de la funcion de la entrada de caracteres
char entradaDatosCaracter(char frase[TAMVECTOR]);

void RayasDoblesOSencillas(char [NUMTIPOBORDES],char [NUMTIPOBORDES],char [NUMTIPOANCHURA]);

void PedirFrase(struct cadena *);

void calcularAnchura(int [NUMTIPOANCHURA], struct cadena );

void crearCorreo(struct correo *,int,struct carpeta *,int [NUMTIPOANCHURA],int,struct cadena);

void crearCarpeta(struct carpeta *, int, int [NUMTIPOANCHURA],struct cadena);

void eliminarCarpeta(int *,int ,int *,struct correo *, struct carpeta *,struct carpeta **,struct correo **);

void datosentrada(int *,int *, struct carpeta **, int [NUMTIPOANCHURA],struct cadena *, struct correo **);
#endif // DATOSREJILLA_H_INCLUDED
