#include "Header_Pierre.h"

void setup(int *nombrejouer, int debut, int mat[17][17],t_joueur player[4], int tour)
{
    char cJ1,cJ2,cJ3,cJ4;
    int EcJ1,EcJ2,EcJ3,EcJ4;

    ///Reset Point de la partie

    for(int i=0;i<4;i++)
    {
        player[i].scoreP = 0;
    }


    if(*nombrejouer == 2)
    {

        if (debut == 1)
        { tour = 1;
            do
            {   printf("%s:\n\n",player[0].nomJ);
                printf("Choisissez une ligne A --> Q\n");
                fflush(stdin);
                scanf("%c",&cJ1);
            }
            while ((cJ1!='A')&&(cJ1!='C')&&(cJ1!='E')&&(cJ1!='G')&&(cJ1!='I')&&(cJ1!='K')&&(cJ1!='M')&&(cJ1!='O')&&(cJ1!='Q'));

            EcJ1 = traduction(cJ1);;
            mat[0][EcJ1] = 5;

            tour = 2;


            system("cls");
            matrice_propre(mat);
            menu_cote(tour,nombrejouer,player);





            do
            {
                printf("%s:\n\n",player[1].nomJ);
                printf("Choisissez une ligne A --> Q\n");
                fflush(stdin);
                scanf("%c",&cJ2);
            }
            while ((cJ2!='A')&&(cJ2!='C')&&(cJ2!='E')&&(cJ2!='G')&&(cJ2!='I')&&(cJ2!='K')&&(cJ2!='M')&&(cJ2!='O')&&(cJ2!='Q'));
            EcJ2 = traduction(cJ2);
            mat[16][EcJ2] = 7;

            system("cls");
            matrice_propre(mat);
            menu_cote(tour,nombrejouer,player);

        }


        else
        {
            tour = 2;
            do
            {
                printf("%s:\n\n",player[1].nomJ);
                printf("Choisissez une ligne A --> Q\n");
                fflush(stdin);
                scanf("%c",&cJ2);
            }
            while ((cJ2!='A')&&(cJ2!='C')&&(cJ2!='E')&&(cJ2!='G')&&(cJ2!='I')&&(cJ2!='K')&&(cJ2!='M')&&(cJ2!='O')&&(cJ2!='Q'));

            EcJ2 = traduction(cJ2);
            mat[16][EcJ2] = 7;


            system("cls");
            matrice_propre(mat);
            menu_cote(tour,nombrejouer,player);


            do
            {
                printf("%s:\n\n",player[0].nomJ);

                printf("Choisissez une ligne A --> Q\n");
                fflush(stdin);
                scanf("%c",&cJ1);
            }
            while ((cJ1!='A')&&(cJ1!='C')&&(cJ1!='E')&&(cJ1!='G')&&(cJ1!='I')&&(cJ1!='K')&&(cJ1!='M')&&(cJ1!='O')&&(cJ1!='Q'));

            tour = 1;
            EcJ1 = traduction(cJ1);
            mat[0][EcJ1] = 5;
            system("cls");
            matrice_propre(mat);
            menu_cote(tour,nombrejouer,player);


        }

    }

    else
    {
        printf("Non dispo\n");
        system("PAUSE");
    }
}
