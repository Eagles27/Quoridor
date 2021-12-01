#ifndef HEADER_PIERRE_H_INCLUDED
#define HEADER_PIERRE_H_INCLUDED

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct joueur{

    char nomJ[50];
    int scoreP;
    char jetonJ;
    int barrieresR;
    int numeroJ;

}t_joueur;

void deplacement(int dep[3], int matrice[17][17], int nombrejoueur);
void genematrice(int tab[17][17]);
void affiche(int tab[17][17]);
void charger(int tab[17][17]);
void sauver(int tab[17][17]);
void matrice_propre(int tab2[17][17]);

#endif // HEADER_PIERRE_H_INCLUDED
