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
    int coordonneX_av;
    int coordonneY_av;
    int coordonneX_org;
    int coordonneY_org;
    int A_annule;


} t_joueur;

typedef struct IA
{
    char nom[3];
    int score;
    char jeton;
    int barrieresR;
    int numero;
    int coordonneX;
    int coordonneY;
    int coordonneX_av;
    int coordonneY_av;
    int coordonneX_org;
    int coordonneY_org;

} t_IA;

                                                 ///Prototype

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////MENU//////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu_game(int mat[17][17],int* Pnombrejoueur,t_joueur player[4],int* Ptour, int mat_avant[17][17], int *Action, t_IA ia, int tour);
void main_menu(int* Pnombre_joueur, int mat[17][17], t_joueur player[4], t_IA ia);
void menu_cote(int* Ptour,int* PnombreJoeur, t_joueur player[4]);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////Actions/////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deplacement(int dep[3], int matrice[17][17], int* Pnombre_joueur,int*Ptour,t_joueur player[4], t_IA ia);
int placer_barriere(int tab[17][17], int place[2], char saisie);
void affiregles();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////Fin de partie/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int gagner_barriere(t_joueur player[4], int *Pnombre_joueur);
int gagner(t_joueur player[4], int* Pnombrejoueur, int tour);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////Back/////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///Matrice
void genematrice(int tab[17][17]);
void matrice_propre(int tab[17][17],t_joueur player[4], t_IA);

///Gestion entr�es
int traduction(char entree);
void saisie_coord(int saisie[2],int*Ptour,int*PnombreJ,t_joueur player[4],int mat[17][17],t_IA ia);
int saisie_dir(int*Ptour,int*PnombreJ,t_joueur player[4],int mat[17][17],t_IA ia);
void majuscule(char mot[20]);

///Gestion joueur
void tour_par_tour(int* Pnombre_joueur, int mat[17][17], t_joueur player[4],int* Ptour, int mat_avant[17][17]);
int choix_j(int nombre);

///Habillage
void gotoligcol( int lig, int col );
void Color(int couleurDuTexte,int couleurDeFond);
void Affichage_Du_Titre(int numero_ligne, int numero_colonne);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////SetUp/////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void distribution_barriere(t_joueur player[4],int *nombrejoueur);
int nombre_joueur();
void setup(int *Pnombrejoueur, int debut, int mat[17][17],t_joueur player[4], int* Ptour,t_IA ia);
void choixPion(t_joueur jugador[4], int *PnbJ);
void case_bonus(int mat[17][17]);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////Charger & sauvegarde/////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void charger_plateau(int tab[17][17]);
void sauver_plateau(int tab[17][17]);
void sauver_joueur(t_joueur joueur[4], int *Pnombre_joueur);


void save_score(t_joueur player[4],int i);
void actualisation_score(t_joueur player[4],int tour_test);

void tableau_score(t_joueur player[150]);
void saisietaille(int*Ptaille);
void trierB(t_joueur player[150],int*Ptaille);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// IA //////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ia_v0(int dep_ia[2], int mat[17][17], t_joueur player[4], t_IA ia);
void deplacement_ia(int dep[3], t_joueur player[4], int mat[17][17], int tour, t_IA ia);
void choix_pion_ia(t_joueur jugador[4], t_IA ia);
void menu_cote_ia(int tour, t_joueur player[4], t_IA ia);
int gagner_ia(t_joueur player[4], t_IA ia, int tour);


////////////////////////////////////////////////////////////

#endif // HEADER_PIERRE_H_INCLUDED
