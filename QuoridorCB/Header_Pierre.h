#ifndef HEADER_PIERRE_H_INCLUDED
#define HEADER_PIERRE_H_INCLUDED

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

///Structure
typedef struct joueur
{

    char nomJ[50];
    int scoreP;
    char jetonJ;
    int barrieresR;
    int numeroJ;

} t_joueur;

///Prototype


///MENU
void menu_game(int mat[17][17],int* Pnombrejoueur,t_joueur player[4],int tour); /// Variable tour pour Test non fonctionnel
void main_menu(int* Pnombre_joueur, int mat[17][17], t_joueur player[4]);
void menu_cote(int tour,int* PnombreJoeur, t_joueur player[4]);

///Actions
void deplacement(int dep[3], int matrice[17][17], int* nombrejoueur);
void charger(int tab[17][17]);
void sauver(int tab[17][17]);
void choixPion(t_joueur jugador[4],int numeroJ);
int placer_barriere(int tab[17][17], int place1[2], int place2[2]);
int choix_j(int nombre);
void affiregles();

///Back
void genematrice(int tab[17][17]);
void affiche(int tab[17][17]);
void matrice_propre(int tab2[17][17]);
int traduction(char entree);
void saisie_coord(int saisie[2]);
void gotoligcol( int lig, int col );
void tour_par_tour(int* Pnombre_joueur, int mat[17][17], t_joueur player[4],int tour);

///SetUp
void distribution_barriere(t_joueur player[4],int *nombrejoueur);
int nombre_joueur();
void setup(int *nombrejouer, int debut, int mat[17][17],t_joueur player[4], int tour);





#endif // HEADER_PIERRE_H_INCLUDED
