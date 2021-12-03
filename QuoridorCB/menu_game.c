#include "Header_Pierre.h"

void menu_game(int mat[17][17],int* Pnombrejoueur,t_joueur player[4],int tour)
{
    int choix;
    int dep[3];
    char temp;
    int saisie1[2];
    int saisie2[2];
    int bool_barriere;

    do
    {
        gotoligcol(20,0);
        printf("Actions Possibles:\n1-Deplacer son pion\n2-Poser une barriere\n3-Passer son tour\n4-Annuler la derniere action\n5-Revenir au menu precedent\n\nSaisie de l'action du joueur:\n");
        fflush(stdin);
        scanf("%d",&choix);

        switch(choix)
        {
        case 1:
        {
            fflush(stdin);
            ///Mettre programme de pierre
            deplacement(dep,mat,Pnombrejoueur);
            mat[dep[1]][dep[0]] = 5; // Attention coordonnées inversées
            //printf("%d,%d",dep[0],dep[1]);

            system("cls");
            matrice_propre(mat);
            menu_cote(tour,Pnombrejoueur,player);
            system("PAUSE");

            break;
        }
        case 2:
        {
            ///PPG Barriere

            do
            {
                system("cls");
                matrice_propre(mat);
                saisie_coord(saisie1);
                system("PAUSE");
                saisie_coord(saisie2);
                bool_barriere = placer_barriere(mat, saisie1, saisie2);
            }
            while(bool_barriere == -1);
            system("PAUSE");
            system("cls");
            matrice_propre(mat);
            system("PAUSE");

            break;
        }
        case 3 :
        {
            ///PPG passer son tour

            break;
        }
        case 4 :
        {
            ///PPG annuler l'action

            break;
        }
        case 5 :
        {
            main_menu(Pnombrejoueur,mat,player);
            break;
        }
        default :
        {
            printf("Saisie Erronee\n\n");
            system("PAUSE");
            system("cls");
            matrice_propre(mat);
            break;
        }
        }
    }
    while(choix!=5);
}
