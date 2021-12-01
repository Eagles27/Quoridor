#ifndef HEADER_PIERRE_H_INCLUDED
#define HEADER_PIERRE_H_INCLUDED

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

///Structure
typedef struct joueur{

    char nomJ[50];
    int scoreP;
    char jetonJ;
    int barrieresR;
    int numeroJ;

}t_joueur;

///Prototype
void deplacement(int dep[3], int matrice[17][17], int* nombrejoueur);
void genematrice(int tab[17][17]);
void affiche(int tab[17][17]);
void charger(int tab[17][17]);
void sauver(int tab[17][17]);
void matrice_propre(int tab2[17][17]);
int placer_barriere(int tab[17][17], int place1[2], int place2[2]);
void menucote(int lig,int col,int nombreJoueur, t_joueur jugador[4]);
void choixPion(t_joueur jugador[4],int numeroJ);
void main_menu(int* PbarJ1,int* PbarJ2,int* PbarJ3,int* PbarJ4,int* Pnombre_joueur,int mat[17][17]);
int choix_j(int nombre);
void distributio_barriere(int *PbarJ1,int *PbarJ2, int *PbarJ3, int *PbarJ4, int *nombrejoueur);
int nombre_joueur();
void gotoligcol( int lig, int col );
void affiregles();
void menu_game(int mat[17][17],int* Pnombrejoueur,int* PbarJ1,int* PbarJ2,int* PbarJ3,int* PbarJ4);
void saisie_coord(int saisie[2]);
int traduction(char entree);

#endif // HEADER_PIERRE_H_INCLUDED
