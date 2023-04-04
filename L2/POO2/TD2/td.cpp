#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define EMPTY '0'



class Coup{
    private:
        int x;
        int y;
        char p;
    public:
        Coup(int x, int y, char p) {
            this->x=x;
            this->y=y;
            this->p=p;
        }

        int getX(){return x;}
        int getY(){return y;}
        char getP(){return p;}
};




class Morpion{
    private:
        char tab[3][3] = {{EMPTY,EMPTY,EMPTY},{EMPTY,EMPTY,EMPTY},{EMPTY,EMPTY,EMPTY}};
        string name;
        vector<Coup> movePlayed;

    public:
        Morpion(string name){
            this->name = name;
        }

        void display(){
            for(size_t i = 0; i < 3; i++){
                for(size_t j = 0; j < 3; j++){
                    printf("%c ", tab[i][j]);
                }
                printf("\n");
            }
        }

        string getName(){
            return name;
        }

        void jouerCoup(Coup c){

            Coup previous{c.getX(),c.getY(),tab[c.getX()][c.getY()]};
            tab[c.getX()][c.getY()] = c.getP();
            movePlayed.push_back(previous);
        }
        
        void cancelMove(){
            Coup lastmov = movePlayed.back();
            tab[lastmov.getX()][lastmov.getY()] = lastmov.getP();
            movePlayed.pop_back();
        }
        
        vector<Coup> availableMoves(){
            vector<Coup> a_r;
            for(size_t i = 0; i < 3; i++){
                for(size_t j = 0; j < 3; j++){
                    if(tab[i][j] == EMPTY){
                        Coup* add = new Coup(i,j,EMPTY);
                        a_r.push_back(*add);
                    }
                
                }
            }
            return a_r;
        }
};


int main(){
    Morpion* grid = new Morpion("Jeu");
    Coup* c = new Coup(1,1,'X');
    grid->jouerCoup(*c);
    grid->display();

    cout << endl;

    grid->cancelMove();
    grid->display();
    return 0;
}
