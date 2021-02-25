#ifndef CONSTANTESESTRUCTURAS_H_INCLUDED
#define CONSTANTESESTRUCTURAS_H_INCLUDED

#define VERTICAL 0
#define HORIZONTAL 1
#define ESQSUPIZQ 2
#define ESQSUPDER 3
#define ESQINFIZQ 4
#define ESQINFDER 5
#define CRUZ 6
#define TLATIZQ 7
#define TNORMAL 8
#define TINVERTIDA 9
#define TLATDER 10
#define ESPACIOS 11

#define ANCHLEIDO 0
#define ANCHCORREO 1
#define ANCHCARPETA 2
#define ANCHENCABEZADO 3

#define MINCORREOS 0
#define MINRESTO 1

#define ALTENCABEZADO 1
#define ALTRESTO 0

#define NUMTIPOBORDES 12
#define NUMTIPOANCHURA 4
#define NUMTIPOMIN 2

#define TAMVECTOR 200
#define TAMSELECTOR 2

#define NUMEROOPCIONES 2

struct cadena{
    char * contenido;
    int longitud;
};

struct carpeta{
    struct cadena titulo;
    int NumeroDecorreos;
};

struct correo{
    struct cadena titulo;
    int leido;
    int carpeta;
};

#endif // CONSTANTESESTRUCTURAS_H_INCLUDED
