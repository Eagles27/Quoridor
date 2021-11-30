#include "jeu.h"

void setup(int *nombrejouer, int debut, int mat[17][17])
{
    int cJ1,cJ2,cJ3,cJ4;
    if(*nombrejouer == 2)
    {
        printf("Joueur %d:\nPlacer votre Pion sur la premiere ligne\n",debut);
        if (debut == 1)
        {
            printf("Choisir une ligne A --> I\n");
            scanf("%d",&cJ1);
            mat[0][cJ1] = 5;
            affiche(mat);

            printf("Joueur 2:\nPlacer votre Pion sur la premiere ligne\n");
            printf("Choisir une ligne A --> I\n");
            scanf("%d",&cJ2);
            mat[16][cJ2] = 7;
            affiche(mat);

        }

        else
        {
            printf("Choisir une ligne A --> I\n");
            scanf("%d",&cJ2);
            mat[16][cJ2] = 7;
            affiche(mat);


            printf("Joueur 1:\nPlacer votre Pion sur la premiere ligne\n");
            printf("Choisir une ligne A --> I\n");
            scanf("%d",&cJ1);
            mat[0][cJ1] = 5;
            affiche(mat);


        }

    }

    else
    {
        printf("Non dispo\n");
    }
}
