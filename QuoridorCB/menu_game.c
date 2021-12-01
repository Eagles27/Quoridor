#include "Header_Pierre.h"

int menu_game(int mat[17][17],int* Pnombrejoueur,int* PbarJ1,int* PbarJ2,int* PbarJ3,int* PbarJ4)
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
            ///Mettre programme de pierre

            dep[0] = 0;
            dep[1] = 0;

            deplacement(dep,mat,Pnombrejoueur);
            mat[dep[1]][dep[0]] = 5; // Attention coordonnées inversées
            printf("%d,%d",dep[0],dep[1]);

            system("cls");
            matrice_propre(mat);
            system("PAUSE");
            return 1;

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
            while(placer_barriere(mat, saisie1, saisie2));
            system("PAUSE");
            system("cls");
            matrice_propre(mat);
            system("PAUSE");

            return 2;
            break;
        }
        case 3 :
        {
            ///PPG passer son tour

            return 3;
            break;
        }
        case 4 :
        {
            ///PPG annuler l'action

            return 4;
            break;
        }
        case 5 :
        {
            main_menu(PbarJ1,PbarJ2,PbarJ3,PbarJ4,Pnombrejoueur,mat);

            return 5;
            break;
        }
        default :
        {
            printf("Saisie Erronée");
            break;
        }
        }
    }
    while((choix!=1)&&(choix!=2)&&(choix!=3)&&(choix!=4));
}
