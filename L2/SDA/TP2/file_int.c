#include "file_int.h"

File filenouv(){
        File a_r;
        a_r.h=0;
        a_r.l=0;
        return a_r;
}

File adjq(File f, Nat n){
        if(f.h+f.l >= MAX_P) exit(1);
        f.tab[f.h+f.l]=n;
        f.l++;
        return f;
}

File supt(File f){
        f.h++;       
        if(f.h+f.l >= MAX_P) exit(1);
}

Nat tete(File f){
        return f.tab[f.h];
}

Bool vide(File f){
        return f.l==0;
}

Nat longueur(File f){
        return f.l;
}

int main(){
        File f = filenouv();
        f = adjq(f,4);
        printf("%d\n",f.tab[f.h]);
        return 0;
}

