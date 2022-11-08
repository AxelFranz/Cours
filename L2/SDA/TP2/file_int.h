#ifndef FILE_INT
#define FILE_INT
#include "base.h"
#define MAX_P 5000
typedef struct{
	Nat tab[MAX_P];
	Nat h;
	Nat l;
}File;

File filenouv(); // Fait

File adjq(File f, Nat n); // Fait

File supt(File f); // Fait

Nat tete(File f); // Fait

Bool vide(File f); // Fait

Nat longueur(File f); // Fait
#endif


