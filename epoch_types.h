/*
    Copyright 2020. Eduardo Programador
    www.eduardoprogramador.com
    consultoria@eduardoprogramador.com
*/

#include <malloc.h>
#define BUF 512
#define ALLOCATION malloc(BUF)

typedef unsigned short int small;
typedef int normal;
typedef long int big;
typedef const char* msg;

typedef struct {

    normal day;
    normal month;
    normal year;
    normal hour;
    normal minute;
    normal second;

} epoch_str;
