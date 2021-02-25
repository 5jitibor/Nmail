#include"constantesEstructuras.h"
#ifndef FICHERO_H_INCLUDED
#define FICHERO_H_INCLUDED

void FinalizarPrograma(struct cadena ,struct carpeta *, struct correo *, int, int );

void PedirFraseFichero(struct cadena *,FILE*);

int contadorElementosFichero(char [TAMVECTOR]);

void entradaDatosFicheroCarpeta(int [NUMTIPOANCHURA],struct carpeta *,int , struct cadena *);

void entradaDatosFicheroCorreo(int [NUMTIPOANCHURA],struct carpeta *,int ,struct correo *);

void entradaFicheros(int *,int *, struct carpeta **, int [NUMTIPOANCHURA],struct cadena *, struct correo **);

int ficheroExiste();
#endif // FICHERO_H_INCLUDED
