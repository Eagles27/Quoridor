#include "jeu.h"

void menu_game()
{
    int choix;

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
            break;
            }
        case 2:
            {
                ///PPG Barriere
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
