#ifndef HEADER_ADRIEN_H_INCLUDED
#define HEADER_ADRIEN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

///////Structures

typedef struct joueur{

    char nomJ[50];
    int scoreP;
    char jetonJ;
    int barrieresR;

}t_joueur;

///////Proto
void affiche(int tab[17][17]);
void genematrice();
//void gotoligcol(int lig,int col,int nombreJoueur,char nomJoueur[50],int scorePartie, char jetonJoueur,int barrieresRestantes);
void gotoligcol(int lig,int col,int nombreJoueur, t_joueur jugador[4]);



#endif // HEADER_ADRIEN_H_INCLUDED
