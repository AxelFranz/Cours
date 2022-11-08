#ifndef FILE_INT2
#define FILE_INT2

#include "base.h"

typedef struct strfile{
        Nat v;
        struct strfile *s;
}StrFile;

typedef struct sfile{
        Strfile *h;
        Strfile *q;
}File;
