#include "jeu.h"

void setup(int *nombrejouer, int debut, int mat[17][17])
{
    char cJ1,cJ2,cJ3,cJ4;
    int EcJ1,EcJ2,EcJ3,EcJ4;
    if(*nombrejouer == 2)
    {
        printf("\nJoueur %d:\nPlacer votre Pion sur la premiere ligne\n",debut);
        if (debut == 1)
        {
            printf("Choisir une ligne A --> I\n");
            fflush(stdin);
            scanf("%c",&cJ1);
            EcJ1 = traduction(cJ1);
            mat[0][EcJ1] = 5;
            affiche(mat);


            system("cls");
            affiche(mat);

            printf("\nJoueur 2:\nPlacer votre Pion sur la premiere ligne\n");
            printf("Choisir une ligne A --> I\n");
            fflush(stdin);
            scanf("%c",&cJ2);
            EcJ2 = traduction(cJ2);
            mat[16][EcJ2] = 7;
            system("cls");
            affiche(mat);

        }

        else
        {

            printf("Choisir une ligne A --> I\n");
            fflush(stdin);
            scanf("%c",&cJ2);
            EcJ2 = traduction(cJ2);
            mat[16][EcJ2] = 7;
            affiche(mat);


            system("cls");
            affiche(mat);

            printf("\nJoueur 1:\nPlacer votre Pion sur la premiere ligne\n");
            printf("Choisir une ligne A --> I\n");
            fflush(stdin);
            scanf("%c",&cJ1);
            EcJ1 = traduction(cJ1);
            mat[0][EcJ1] = 5;
            system("cls");
            affiche(mat);


        }

    }

    else
    {
        printf("Non dispo\n");
    }
}
