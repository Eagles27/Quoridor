#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

///Library

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>


///Proto

void main_menu(int* PbarJ1,int* PbarJ2,int* PbarJ3,int* PbarJ4,int* Pnombre_joueur,int mat[17][17]);
int choix_j(int nombre);
void affiche(int tab[17][17]);
void genematrice(int tab[17][17]);
void distributio_barriere(int *PbarJ1,int *PbarJ2, int *PbarJ3, int *PbarJ4, int *nombrejoueur);
int nombre_joueur();
void gotoligcol( int lig, int col );
void affiche(int tab[17][17]);
void affiregles();
void menu_game();







#endif // JEU_H_INCLUDED
