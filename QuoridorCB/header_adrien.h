#ifndef HEADER_ADRIEN_H_INCLUDED
#define HEADER_ADRIEN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>


///////Structures

typedef struct joueur{

    char nomJ[50];
    int scoreP;
    char jetonJ;
    int barrieresR;
    int numeroJ;

}t_joueur;



///////Proto
void affiche(int tab[17][17]);
void genematrice();
//void gotoligcol(int lig,int col,int nombreJoueur,char nomJoueur[50],int scorePartie, char jetonJoueur,int barrieresRestantes);
void menucote(int lig,int col,int nombreJoueur, t_joueur jugador[4],int numeroPlayer);
void choixPion(t_joueur jugador[4],int numeroPlayer);


#endif // HEADER_ADRIEN_H_INCLUDED
