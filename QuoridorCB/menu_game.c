#include "jeu.h"

void menu_game(int mat[17][17],int* Pnombrejoueur)
{
    int choix;
    int dep[3];
    char temp;

    do
    {
        gotoligcol(20,0);
        printf("Actions Possibles:\n1-Deplacer son pion\n2-Poser une barriere\n3-Passer son tour\n4-Annuler la derniere action\n\nSaisie de l'action du joueur:\n");
        fflush(stdin);
        scanf("%d",&choix);

        switch(choix)
        {
        case 1:
            {
               ///Mettre programme de pierre

               dep[0] = 0;
               dep[1] = 0;

               deplacement(dep,mat,Pnombrejoueur);
               mat[dep[1]][dep[0]] = 5; // Attention coordonnées inversées
               printf("%d,%d",dep[0],dep[1]);

               system("cls");
               matrice_propre(mat);
               system("PAUSE");

            break;
            }
        case 2:
            {
                ///PPG Barriere
                matrice_propre(mat);
                //ss prg : demande saisit utilisateur
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
        default :
            {
                printf("Saisie Erronée");

            }

        }
    }
    while((choix!=1)&&(choix!=2)&&(choix!=3)&&(choix!=4));




}
