#include"constantesEstructuras.h"
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void Menu(struct carpeta **,int *,char [NUMTIPOBORDES],char [NUMTIPOBORDES],char [NUMTIPOBORDES],int *,int [NUMTIPOANCHURA], int [NUMTIPOMIN],struct cadena, struct correo **, struct correo *,struct carpeta *);

int MenuMostrar(struct carpeta *, int, int *,char [TAMVECTOR]);

void menuInicial(struct cadena *, struct correo **, struct carpeta **, int *, int *, int [NUMTIPOANCHURA]);

#endif // MENU_H_INCLUDED
