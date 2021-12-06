#include "Header_Pierre.h"

void setup(int *Pnombre_joueur, int debut, int mat[17][17],t_joueur player[4], int* Ptour)
{
    char cJ1,cJ2,cJ3,cJ4;


    ///Reset Point de la partie

    for(int i=0; i<4; i++)
    {
        player[i].scoreP = 0;
    }


    if(*Pnombre_joueur == 2)
    {

        if (debut == 1)
        {
            *Ptour = 1;
            do
            {
                system("cls");
                matrice_propre(mat,player);
                menu_cote(Ptour,Pnombre_joueur,player);
                printf("%s:\n\n",player[0].nomJ);
                printf("Choisissez une ligne A --> Q\n");
                fflush(stdin);
                scanf("%c",&cJ1);
                player[0].coordonneX = traduction(cJ1);
                player[0].coordonneY = 0;
            }
            while ((cJ1!='A')&&(cJ1!='C')&&(cJ1!='E')&&(cJ1!='G')&&(cJ1!='I')&&(cJ1!='K')&&(cJ1!='M')&&(cJ1!='O')&&(cJ1!='Q'));

            mat[player[0].coordonneY][player[0].coordonneX] = 5;



            system("cls");
            matrice_propre(mat,player);
            menu_cote(Ptour,Pnombre_joueur,player);



            do
            {
                *Ptour = 2;
                system("cls");
                matrice_propre(mat,player);
                menu_cote(Ptour,Pnombre_joueur,player);
                printf("%s:\n\n",player[1].nomJ);
                printf("Choisissez une ligne A --> Q\n");
                fflush(stdin);
                scanf("%c",&cJ2);
                player[1].coordonneX = traduction(cJ2);
                player[1].coordonneY = 16;
            }
            while ((cJ2!='A')&&(cJ2!='C')&&(cJ2!='E')&&(cJ2!='G')&&(cJ2!='I')&&(cJ2!='K')&&(cJ2!='M')&&(cJ2!='O')&&(cJ2!='Q'));

            mat[player[1].coordonneY][player[1].coordonneX] = 7;



            system("cls");
            matrice_propre(mat,player);
            menu_cote(Ptour,Pnombre_joueur,player);

        }


        else
        {

            do
            {
                *Ptour = 2;
                system("cls");
                matrice_propre(mat,player);
                menu_cote(Ptour,Pnombre_joueur,player);
                printf("%s:\n\n",player[1].nomJ);
                printf("Choisissez une ligne A --> Q\n");
                fflush(stdin);
                scanf("%c",&cJ2);
                player[1].coordonneX = traduction(cJ2);
                player[1].coordonneY = 16;
            }
            while ((cJ2!='A')&&(cJ2!='C')&&(cJ2!='E')&&(cJ2!='G')&&(cJ2!='I')&&(cJ2!='K')&&(cJ2!='M')&&(cJ2!='O')&&(cJ2!='Q'));


            mat[player[1].coordonneY][player[1].coordonneX] = 7;


            system("cls");
            matrice_propre(mat,player);
            menu_cote(Ptour,Pnombre_joueur,player);


            do
            {
                *Ptour = 1;
                system("cls");
                matrice_propre(mat,player);
                menu_cote(Ptour,Pnombre_joueur,player);
                printf("%s:\n\n",player[0].nomJ);
                printf("Choisissez une ligne A --> Q\n");
                fflush(stdin);
                scanf("%c",&cJ1);
                player[0].coordonneX = traduction(cJ1);
                player[0].coordonneY = 0;

            }
            while ((cJ1!='A')&&(cJ1!='C')&&(cJ1!='E')&&(cJ1!='G')&&(cJ1!='I')&&(cJ1!='K')&&(cJ1!='M')&&(cJ1!='O')&&(cJ1!='Q'));



            mat[player[0].coordonneY][player[0].coordonneX] = 5;
            system("cls");
            matrice_propre(mat,player);
            menu_cote(Ptour,Pnombre_joueur,player);


        }

    }

    else
    {
        printf("Non dispo\n");
        system("PAUSE");
    }
}
