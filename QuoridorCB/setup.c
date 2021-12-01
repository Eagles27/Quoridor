#include "Header_Pierre.h"

void setup(int *nombrejouer, int debut, int mat[17][17])
{
    char cJ1,cJ2,cJ3,cJ4;
    int EcJ1,EcJ2,EcJ3,EcJ4;
    if(*nombrejouer == 2)
    {
        printf("\nJoueur %d:\nPlacer votre Pion sur la premiere ligne\n",debut);
        if (debut == 1)
        {
            do
            {
                printf("Choisir une ligne A --> Q\n");
                fflush(stdin);
                scanf("%c",&cJ1);
            }
            while ((cJ1!='A')&&(cJ1!='C')&&(cJ1!='E')&&(cJ1!='G')&&(cJ1!='I')&&(cJ1!='K')&&(cJ1!='M')&&(cJ1!='O')&&(cJ1!='Q'));

            EcJ1 = traduction(cJ1);;
            mat[0][EcJ1] = 5;
            matrice_propre(mat);


            system("cls");
            matrice_propre(mat);

            printf("\nJoueur 2:\nPlacer votre Pion sur la premiere ligne\n");

            do
            {
                printf("Choisir une ligne A --> Q\n");
                fflush(stdin);
                scanf("%c",&cJ2);
            }
            while ((cJ2!='A')&&(cJ2!='C')&&(cJ2!='E')&&(cJ2!='G')&&(cJ2!='I')&&(cJ2!='K')&&(cJ2!='M')&&(cJ2!='O')&&(cJ2!='Q'));
            EcJ2 = traduction(cJ2);
            mat[16][EcJ2] = 7;
            system("cls");
            matrice_propre(mat);

        }

        else
        {
            do
            {
                printf("Choisir une ligne A --> Q\n");
                fflush(stdin);
                scanf("%c",&cJ2);
            }
            while ((cJ2!='A')&&(cJ2!='C')&&(cJ2!='E')&&(cJ2!='G')&&(cJ2!='I')&&(cJ2!='K')&&(cJ2!='M')&&(cJ2!='O')&&(cJ2!='Q'));

            EcJ2 = traduction(cJ2);
            mat[16][EcJ2] = 7;
            matrice_propre(mat);

            system("cls");
            matrice_propre(mat);
            printf("\nJoueur 1:\nPlacer votre Pion sur la premiere ligne\n");

            do
            {
                printf("Choisir une ligne A --> Q\n");
                fflush(stdin);
                scanf("%c",&cJ1);
            }while ((cJ1!='A')&&(cJ1!='C')&&(cJ1!='E')&&(cJ1!='G')&&(cJ1!='I')&&(cJ1!='K')&&(cJ1!='M')&&(cJ1!='O')&&(cJ1!='Q'));

            EcJ1 = traduction(cJ1);
            mat[0][EcJ1] = 5;
            system("cls");
            matrice_propre(mat);


        }

    }

    else
    {
        printf("Non dispo\n");
    }
}
