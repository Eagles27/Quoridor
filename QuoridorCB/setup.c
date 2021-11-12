#include "jeu.h"

void setup(int nbrj,int tab[17][17])
{
    int j_commence;
    int c_j1,l_j1;
    int c_j2,l_j2;
    int c_j3,l_j3;
    int c_j4,l_j4;
    int nbjoueur = nbrj;

    srand(time(NULL));  // Reset de l'horloge intenr

    j_commence = rand()%(nbrj-1+1)+1;
    printf("C'est au joueur %d\n",j_commence);

    //Placement des pions en début de partie

    while(nbjoueur!=0)
    {

    }
}


