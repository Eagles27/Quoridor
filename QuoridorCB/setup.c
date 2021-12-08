#include "Header_Pierre.h"

void setup(int *Pnombre_joueur, int debut, int mat[17][17],t_joueur player[4], int* Ptour)
{
    char cJ1,cJ2,cJ3,cJ4;


    ///Reset Point de la partie + booléen annulation

    for(int i=0; i<4; i++)
    {
        player[i].scoreP = 0;
        player[i].A_annule = 0;
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

                player[0].coordonneX_org = traduction(cJ1);
                player[0].coordonneY_org = 0;
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

                player[1].coordonneX_org = traduction(cJ2);
                player[1].coordonneY_org = 16;
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

                player[1].coordonneX_org = traduction(cJ2);
                player[1].coordonneY_org = 16;
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

                player[0].coordonneX_org = traduction(cJ1);
                player[0].coordonneY_org = 0;

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

        /// Joueur 1
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
            if(mat[0][traduction(cJ1)]!=0)
            {
                cJ1 = 'b';
            }
            player[0].coordonneX = traduction(cJ1);
            player[0].coordonneY = 0;

            player[0].coordonneX_org = traduction(cJ1);
            player[0].coordonneY_org = 0;
        }
        while ((cJ1!='A')&&(cJ1!='C')&&(cJ1!='E')&&(cJ1!='G')&&(cJ1!='I')&&(cJ1!='K')&&(cJ1!='M')&&(cJ1!='O')&&(cJ1!='Q'));

        mat[player[0].coordonneY][player[0].coordonneX] = 5;



        system("cls");
        matrice_propre(mat,player);
        menu_cote(Ptour,Pnombre_joueur,player);

        /// Joueur 2
        do
        {
            *Ptour = 2;

            system("cls");
            matrice_propre(mat,player);
            menu_cote(Ptour,Pnombre_joueur,player);
            printf("%s:\n\n",player[1].nomJ);
            printf("Choisissez une ligne a --> q\n");
            fflush(stdin);
            scanf("%c",&cJ2);
            if(mat[traduction(cJ2)][16]!=0)
            {
                cJ2 = 'b';
            }
            player[1].coordonneX = 16;
            player[1].coordonneY = traduction(cJ2);

            player[1].coordonneX_org = 16;
            player[1].coordonneY_org = traduction(cJ2);
        }
        while ((cJ2!='a')&&(cJ2!='c')&&(cJ2!='e')&&(cJ2!='g')&&(cJ2!='i')&&(cJ2!='k')&&(cJ2!='m')&&(cJ2!='o')&&(cJ2!='q'));

        mat[player[1].coordonneY][player[1].coordonneX] = 7;



        system("cls");
        matrice_propre(mat,player);
        menu_cote(Ptour,Pnombre_joueur,player);


        /// Joueur 3

        do
        {
            *Ptour = 3;

            system("cls");
            matrice_propre(mat,player);
            menu_cote(Ptour,Pnombre_joueur,player);
            printf("%s:\n\n",player[2].nomJ);
            printf("Choisissez une ligne A --> Q\n");
            fflush(stdin);
            scanf("%c",&cJ3);
            if(mat[16][traduction(cJ3)]!=0)
            {
                cJ3 = 'b';
            }
            player[2].coordonneX = traduction(cJ3);
            player[2].coordonneY = 16;

            player[2].coordonneX_org = traduction(cJ3);
            player[2].coordonneY_org = 16;
        }
        while ((cJ3!='A')&&(cJ3!='C')&&(cJ3!='E')&&(cJ3!='G')&&(cJ3!='I')&&(cJ3!='K')&&(cJ3!='M')&&(cJ3!='O')&&(cJ3!='Q'));

        mat[player[2].coordonneY][player[2].coordonneX] = 9;



        system("cls");
        matrice_propre(mat,player);
        menu_cote(Ptour,Pnombre_joueur,player);


        /// Joueur 4

        do
        {
            *Ptour = 4;

            system("cls");
            matrice_propre(mat,player);
            menu_cote(Ptour,Pnombre_joueur,player);
            printf("%s:\n\n",player[3].nomJ);
            printf("Choisissez une ligne a --> q\n");
            fflush(stdin);
            scanf("%c",&cJ4);
            if(mat[traduction(cJ4)][0]!=0)
            {
                cJ4 = 'b';
            }
            player[3].coordonneX = 0;
            player[3].coordonneY = traduction(cJ4);

            player[3].coordonneX_org = 0;
            player[3].coordonneY_org = traduction(cJ4);
        }
        while ((cJ4!='a')&&(cJ4!='c')&&(cJ4!='e')&&(cJ4!='g')&&(cJ4!='i')&&(cJ4!='k')&&(cJ4!='m')&&(cJ4!='o')&&(cJ4!='q'));

        mat[player[3].coordonneY][player[3].coordonneX] = 11;



        system("cls");
        matrice_propre(mat,player);
        menu_cote(Ptour,Pnombre_joueur,player);


        *Ptour = debut;     ///Attribution du joueur qui commence



    }
}
