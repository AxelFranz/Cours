 #include "/home/axel/library/base.h"
typedef struct str_file{
	Nat val;
	struct str_file* next;
}StrFile,*File;

typedef struct str_pile{
	Nat val;
	struct strpile* sommet;
} StrPileLst, *PileLst;

typedef struct{
	int h;
	PileLst sommet;
}StrPile,*Pile;

File new_File(){
	return NULL;
}
File enfiler(File f, Nat x){
	File f1 = MALLOC(StrFile);
	if(f1==NULL){
		fprintf(stderr,"Erreur malloc");
		exit(1);
	}
	f1->val=x;
	if(f==NULL){
		f1->next=f1;
	} else {
		f1->next=f->next;
		f->next=f1;
	}
	return f1;
}

File defiler(File f){
	if(f==NULL)
			return NULL;
	if(f->next==f){
		FREE(f);
		return NULL;
	}
	File f1 = f->next;
	FREE(f1);
	return f;
}
Nat tete(File f){
	return f->next->val;
}
int longueur(File f){
	if(f==NULL)
		return 0;
	File f1=f;
	int l=0;
	do{
		f1=f->next;
		l++;
	}while(f1!=f);
	return l;
}

Pile new_Pile(){
	Pile p = MALLOC(StrPileLst);
	if(p==NULL){
		fprintf(stderr,"Erreur malloc")
		exit(1);
	}
	p->sommet=NULL;
	p->val=0;
	return p; 
}

Pile empiler(Pile p, Nat x){
	PileLst p2=MALLOC(StrPileLst);
	if(p2==NULL){
		fprintf(stderr,"Erreur malloc");
		exit(1);
	}
	p2->vol=x;
	p2->next=p->sommet;
	p->sommet=p2;
	p->h++;
	return p;

}

Pile depiler(Pile p){
	if(p->sommet==NULL)
		return p;
	PileLst p2=p->sommet->next;
	FREE(p->sommet);
	P->sommet=p2;
	p->h--;
	return p;
}

Nat sommet(Pile p){
	return p->sommet->val;
}
int longueur(Pile p){
	return p->h;
}

int main(){
	return 0;
}