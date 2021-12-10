#include "Header_Pierre.h"

void setup(int *Pnombre_joueur, int debut, int mat[17][17],t_joueur player[4], int* Ptour, t_IA ia)
{
    char cJ1,cJ2,cJ3,cJ4;


    if(*Pnombre_joueur == 2)
    {

        if (debut == 1)
        {
            *Ptour = 1;
            do
            {
                system("cls");
                matrice_propre(mat,player,ia);
                menu_cote(Ptour,Pnombre_joueur,player,ia);
                printf("%s:\n\n",player[0].nomJ);
                printf("Choisissez une ligne A --> Q\n");
                fflush(stdin);
                scanf("%c",&cJ1);
                player[0].coordonneX = traduction(cJ1);
                player[0].coordonneY = 0;

                player[0].coordonneX_org = traduction(cJ1);
                player[0].coordonneY_org = 0;
            }
            while ((cJ1!='A')&&(cJ1!='C')&&(cJ1!='E')&&(cJ1!='G')&&(cJ1!='I')&&(cJ1!='K')&&(cJ1!='M')&&(cJ1!='O')&&(cJ1!='Q'));

            mat[player[0].coordonneY][player[0].coordonneX] = 5;



            system("cls");
            matrice_propre(mat,player,ia);
            menu_cote(Ptour,Pnombre_joueur,player,ia);



            do
            {
                *Ptour = 2;
                system("cls");
                matrice_propre(mat,player,ia);
                menu_cote(Ptour,Pnombre_joueur,player,ia);
                printf("%s:\n\n",player[1].nomJ);
                printf("Choisissez une ligne A --> Q\n");
                fflush(stdin);
                scanf("%c",&cJ2);
                player[1].coordonneX = traduction(cJ2);
                player[1].coordonneY = 16;

                player[1].coordonneX_org = traduction(cJ2);
                player[1].coordonneY_org = 16;
            }
            while ((cJ2!='A')&&(cJ2!='C')&&(cJ2!='E')&&(cJ2!='G')&&(cJ2!='I')&&(cJ2!='K')&&(cJ2!='M')&&(cJ2!='O')&&(cJ2!='Q'));

            mat[player[1].coordonneY][player[1].coordonneX] = 7;



            system("cls");
            matrice_propre(mat,player,ia);
            menu_cote(Ptour,Pnombre_joueur,player,ia);

        }


        else
        {

            do
            {
                *Ptour = 2;
                system("cls");
                matrice_propre(mat,player,ia);
                menu_cote(Ptour,Pnombre_joueur,player,ia);
                printf("%s:\n\n",player[1].nomJ);
                printf("Choisissez une ligne A --> Q\n");
                fflush(stdin);
                scanf("%c",&cJ2);
                player[1].coordonneX = traduction(cJ2);
                player[1].coordonneY = 16;

                player[1].coordonneX_org = traduction(cJ2);
                player[1].coordonneY_org = 16;
            }
            while ((cJ2!='A')&&(cJ2!='C')&&(cJ2!='E')&&(cJ2!='G')&&(cJ2!='I')&&(cJ2!='K')&&(cJ2!='M')&&(cJ2!='O')&&(cJ2!='Q'));


            mat[player[1].coordonneY][player[1].coordonneX] = 7;


            system("cls");
            matrice_propre(mat,player,ia);
            menu_cote(Ptour,Pnombre_joueur,player,ia);


            do
            {
                *Ptour = 1;
                system("cls");
                matrice_propre(mat,player,ia);
                menu_cote(Ptour,Pnombre_joueur,player,ia);
                printf("%s:\n\n",player[0].nomJ);
                printf("Choisissez une ligne A --> Q\n");
                fflush(stdin);
                scanf("%c",&cJ1);
                player[0].coordonneX = traduction(cJ1);
                player[0].coordonneY = 0;

                player[0].coordonneX_org = traduction(cJ1);
                player[0].coordonneY_org = 0;

            }
            while ((cJ1!='A')&&(cJ1!='C')&&(cJ1!='E')&&(cJ1!='G')&&(cJ1!='I')&&(cJ1!='K')&&(cJ1!='M')&&(cJ1!='O')&&(cJ1!='Q'));



            mat[player[0].coordonneY][player[0].coordonneX] = 5;
            system("cls");
            matrice_propre(mat,player,ia);
            menu_cote(Ptour,Pnombre_joueur,player,ia);


        }

    }

    else
    {

        /// Joueur 1



        cJ1 = 'I';

        player[0].coordonneX = traduction(cJ1);
        player[0].coordonneY = 0;

        player[0].coordonneX_org = traduction(cJ1);
        player[0].coordonneY_org = 0;

        mat[player[0].coordonneY][player[0].coordonneX] = 5;



        /// Joueur 2



        cJ2 = 'i';

        player[1].coordonneX = 16;
        player[1].coordonneY = traduction(cJ2);

        player[1].coordonneX_org = 16;
        player[1].coordonneY_org = traduction(cJ2);

        mat[player[1].coordonneY][player[1].coordonneX] = 7;




        /// Joueur 3

        cJ3 = 'I';

        player[2].coordonneX = traduction(cJ3);
        player[2].coordonneY = 16;

        player[2].coordonneX_org = traduction(cJ3);
        player[2].coordonneY_org = 16;

        mat[player[2].coordonneY][player[2].coordonneX] = 8;




        /// Joueur 4



        cJ4 = 'i';

        player[3].coordonneX = 0;
        player[3].coordonneY = traduction(cJ4);

        player[3].coordonneX_org = 0;
        player[3].coordonneY_org = traduction(cJ4);

        mat[player[3].coordonneY][player[3].coordonneX] = 9;






        *Ptour = debut;     ///Attribution du joueur qui commence



    }
}
