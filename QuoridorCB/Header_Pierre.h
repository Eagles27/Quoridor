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
    int coordonneX;
    int coordonneY;
    int coordonneX_org;
    int coordonneY_org;


} t_joueur;

///Prototype


///MENU
void menu_game(int mat[17][17],int* Pnombrejoueur,t_joueur player[4],int* Ptour);
void main_menu(int* Pnombre_joueur, int mat[17][17], t_joueur player[4]);
void menu_cote(int* Ptour,int* PnombreJoeur, t_joueur player[4]);

///Actions
void deplacement(int dep[3], int matrice[17][17], int* Pnombre_joueur,int*Ptour,t_joueur player[4]);
void choixPion(t_joueur jugador[4],int numeroPlayer);
int placer_barriere(int tab[17][17], int place[2], char saisie);
int choix_j(int nombre);
void affiregles();
int saisie_dir();
void majuscule(char mot[20]);

///Back
void genematrice(int tab[17][17]);
void affiche(int tab[17][17]);
void matrice_propre(int tab[17][17],t_joueur player[4]);
int traduction(char entree);
void saisie_coord(int saisie[2]);
void gotoligcol( int lig, int col );
void tour_par_tour(int* Pnombre_joueur, int mat[17][17], t_joueur player[4],int* Ptour);
int gagner(t_joueur player[4], int* Pnombrejoueur, int tour);

///SetUp
void distribution_barriere(t_joueur player[4],int *nombrejoueur);
int nombre_joueur();
void setup(int *Pnombrejoueur, int debut, int mat[17][17],t_joueur player[4], int* Ptour);

///Charger & sauvegarde
void charger_plateau(int tab[17][17]);
void sauver_plateau(int tab[17][17]);
void charger_score(char liste_nom[100][50], int liste_score[100]);
void charger_joueur(t_joueur joueur[4], int * Pnombre_joueur);
void sauver_score(t_joueur joueur[4], int *Pnombre_joueur);
void sauver_joueur(t_joueur joueur[4], int *Pnombre_joueur);


///Affichage graphique
void Color(int couleurDuTexte,int couleurDeFond);

#endif // HEADER_PIERRE_H_INCLUDED
