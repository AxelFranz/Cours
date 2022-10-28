#include "pile_char2.h"

bool parentheses(char* str){
	Pile p;
	p->=0;
	int i = 0;
	while(str[i]!='\0'){
		char y=str[i];
		if(y == '(' || y== '{' || y == '['){
			p = empiler(p,y);
		}
		switch(y){
			case ')':
				if(sommet(p)=='('){
					p=depiler(p);
				}
				break;
			case '}':
				if(sommet(p)=='}'){
					p=depiler(p);
					break;
				}
			case ']':
				if(sommet(p)=='}'){
					p=depiler(p);
				}
				break;
			default:
				break;
		}
		i++;
	}
	if(p->h==0)
		return 1;
	return 0;
}

int main(int argc, char** argv){
	fprintf(stdout,"%d\n",parentheses("({"));
	return 0;
}