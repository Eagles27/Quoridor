#include "Header_Pierre.h"

void menu_game(int mat[17][17],int* Pnombrejoueur,t_joueur player[4],int* Ptour)
{
    int choix;
    int dep[3];
    char temp;
    int saisie1[2];
    int saisie2[2];
    int bool_barriere;



    gotoligcol(20,0);
    printf("Actions Possibles:\n1-Deplacer son pion\n2-Poser une barriere\n3-Passer son tour\n4-Annuler la derniere action\n5-Revenir au menu precedent\n\nSaisie de l'action du joueur:\n");
    fflush(stdin);
    scanf("%d",&choix);



    switch(choix)
    {
    case 1:
    {
        ///Mettre programme de pierre

        printf("%d",*Ptour);
         system("PAUSE");


        dep[0] =  player[*Ptour-1].coordonneX;
        dep[1] = player[*Ptour-1].coordonneY;


        printf("%d,%d",dep[0],dep[1]);
        system("PAUSE");

        deplacement(dep,mat,Pnombrejoueur);
        player[*Ptour-1].coordonneX = dep[0];
        player[*Ptour-1].coordonneY = dep[1];

        if(*Pnombrejoueur == 2)
        {
            if(*Ptour == 2)
            {
                mat[dep[1]][dep[0]] = 7;
            }

            else
            {
                mat[dep[1]][dep[0]] = 5;

            }


        }

        system("cls");
        matrice_propre(mat);
        menu_cote(Ptour,Pnombrejoueur,player);
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
        while(placer_barriere(mat, saisie1, saisie2));
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
