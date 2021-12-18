#include "Header_Pierre.h"

void setup(int *Pnombre_joueur, int debut, int mat[17][17],t_joueur player[4], int* Ptour, t_IA ia)
{
///0 Déclaration des variables locales

    char cJ1,cJ2,cJ3,cJ4;
    int numero_lig=20;
    int numero_col=3;

///1 Cas pour 2 joueurs

    if(*Pnombre_joueur == 2)
    {

///1.1 J1 commence a jouer

        if (debut == 1)     // Variable qui détermine qui commence de maniere aleatoire
        {
            *Ptour = 1;     //Ptour = debut pour acceder a la bonne structure
            do
            {
                system("cls");
                matrice_propre(mat,player,ia);
                menu_cote(Ptour,Pnombre_joueur,player);


                Color(15,0);
                gotoligcol(numero_lig,numero_col);
                Color(15,2);
                printf("                                      ");
                Color(15,0);
                gotoligcol(numero_lig+1,numero_col);
                Color(15,2);
                printf("                %s                     ",player[0].nomJ);
                Color(15,0);
                ///Effacage de ce qui dépasse
                gotoligcol(numero_lig+1,numero_col+38);
                printf("             ");
                gotoligcol(numero_lig+2,numero_col);
                Color(15,10);
                printf("                                      ");
                Color(15,0);
                gotoligcol(numero_lig+3,numero_col);
                Color(15,10);
                printf("    Choisissez une colonne A --> Q    ");
                Color(15,0);
                gotoligcol(numero_lig+4,numero_col);
                Color(15,10);
                printf("                                      ");
                Color(15,0);
                gotoligcol(numero_lig+5,numero_col);

                fflush(stdin);
                scanf("%c",&cJ1);
                player[0].coordonneX = traduction(cJ1); //traduction permet de transformer les lettres en entiers
                player[0].coordonneY = 0;

                player[0].coordonneX_org = traduction(cJ1); //les (x,y) sont stockes pour savoir la position d'origine du joueur
                player[0].coordonneY_org = 0;
            }
            while ((cJ1!='A')&&(cJ1!='C')&&(cJ1!='E')&&(cJ1!='G')&&(cJ1!='I')&&(cJ1!='K')&&(cJ1!='M')&&(cJ1!='O')&&(cJ1!='Q'));

            mat[player[0].coordonneY][player[0].coordonneX] = 5;    // 5 est la valeur dans la matrice ordinateur qui represente J1



            system("cls");
            matrice_propre(mat,player,ia);
            menu_cote(Ptour,Pnombre_joueur,player);



            do
            {
                *Ptour = 2; //Ptour prend la deuxieme valeur possible
                system("cls");
                matrice_propre(mat,player,ia);
                menu_cote(Ptour,Pnombre_joueur,player);


                Color(15,0);
                gotoligcol(numero_lig,numero_col);
                Color(15,2);
                printf("                                      ");
                Color(15,0);
                gotoligcol(numero_lig+1,numero_col);
                Color(15,2);
                printf("                %s                     ",player[1].nomJ);
                Color(15,0);
                ///Effacage de ce qui dépasse
                gotoligcol(numero_lig+1,numero_col+38);
                printf("             ");
                gotoligcol(numero_lig+2,numero_col);
                Color(15,10);
                printf("                                      ");
                Color(15,0);
                gotoligcol(numero_lig+3,numero_col);
                Color(15,10);
                printf("    Choisissez une colonne A --> Q    ");
                Color(15,0);
                gotoligcol(numero_lig+4,numero_col);
                Color(15,10);
                printf("                                      ");
                Color(15,0);
                gotoligcol(numero_lig+5,numero_col);

                fflush(stdin);
                scanf("%c",&cJ2);
                player[1].coordonneX = traduction(cJ2);
                player[1].coordonneY = 16;

                player[1].coordonneX_org = traduction(cJ2);
                player[1].coordonneY_org = 16;
            }
            while ((cJ2!='A')&&(cJ2!='C')&&(cJ2!='E')&&(cJ2!='G')&&(cJ2!='I')&&(cJ2!='K')&&(cJ2!='M')&&(cJ2!='O')&&(cJ2!='Q'));

            mat[player[1].coordonneY][player[1].coordonneX] = 7; //7 est la valeur dans la matrice ordinateur qui represente J2



            system("cls");
            matrice_propre(mat,player,ia);
            menu_cote(Ptour,Pnombre_joueur,player);

        }

///1.2 J2 commence a jouer

        else
        {

            do
            {
                *Ptour = 2;
                system("cls");
                matrice_propre(mat,player,ia);
                menu_cote(Ptour,Pnombre_joueur,player);


                Color(15,0);
                gotoligcol(numero_lig,numero_col);
                Color(15,2);
                printf("                                      ");
                Color(15,0);
                gotoligcol(numero_lig+1,numero_col);
                Color(15,2);
                printf("                %s                     ",player[1].nomJ);
                Color(15,0);
                ///Effacage de ce qui dépasse
                gotoligcol(numero_lig+1,numero_col+38);
                printf("             ");
                gotoligcol(numero_lig+2,numero_col);
                Color(15,10);
                printf("                                      ");
                Color(15,0);
                gotoligcol(numero_lig+3,numero_col);
                Color(15,10);
                printf("    Choisissez une colonne A --> Q    ");
                Color(15,0);
                gotoligcol(numero_lig+4,numero_col);
                Color(15,10);
                printf("                                      ");
                Color(15,0);
                gotoligcol(numero_lig+5,numero_col);

                fflush(stdin);
                scanf("%c",&cJ2);
                player[1].coordonneX = traduction(cJ2);
                player[1].coordonneY = 16;

                player[1].coordonneX_org = traduction(cJ2);
                player[1].coordonneY_org = 16;
            }
            while ((cJ2!='A')&&(cJ2!='C')&&(cJ2!='E')&&(cJ2!='G')&&(cJ2!='I')&&(cJ2!='K')&&(cJ2!='M')&&(cJ2!='O')&&(cJ2!='Q'));


            mat[player[1].coordonneY][player[1].coordonneX] = 7; //7 est la valeur dans la matrice ordinateur qui represente J2


            system("cls");
            matrice_propre(mat,player,ia);
            menu_cote(Ptour,Pnombre_joueur,player);


            do
            {
                *Ptour = 1;
                system("cls");
                matrice_propre(mat,player,ia);
                menu_cote(Ptour,Pnombre_joueur,player);


                Color(15,0);
                gotoligcol(numero_lig,numero_col);
                Color(15,2);
                printf("                                      ");
                Color(15,0);
                gotoligcol(numero_lig+1,numero_col);
                Color(15,2);
                printf("                %s                     ",player[0].nomJ);
                Color(15,0);
                ///Effacage de ce qui dépasse
                gotoligcol(numero_lig+1,numero_col+38);
                printf("             ");
                gotoligcol(numero_lig+2,numero_col);
                Color(15,10);
                printf("                                      ");
                Color(15,0);
                gotoligcol(numero_lig+3,numero_col);
                Color(15,10);
                printf("    Choisissez une colonne A --> Q    ");
                Color(15,0);
                gotoligcol(numero_lig+4,numero_col);
                Color(15,10);
                printf("                                      ");
                Color(15,0);
                gotoligcol(numero_lig+5,numero_col);

                fflush(stdin);
                scanf("%c",&cJ1);
                player[0].coordonneX = traduction(cJ1);
                player[0].coordonneY = 0;

                player[0].coordonneX_org = traduction(cJ1);
                player[0].coordonneY_org = 0;

            }
            while ((cJ1!='A')&&(cJ1!='C')&&(cJ1!='E')&&(cJ1!='G')&&(cJ1!='I')&&(cJ1!='K')&&(cJ1!='M')&&(cJ1!='O')&&(cJ1!='Q'));



            mat[player[0].coordonneY][player[0].coordonneX] = 5;    //5 est la valeur dans la matrice ordinateur qui represente J1
            system("cls");
            matrice_propre(mat,player,ia);
            menu_cote(Ptour,Pnombre_joueur,player);


        }

    }

///2 Cas pour 4 joueurs

    else
    {

        /// Joueur 1
        cJ1 = 'I';  //Position imposee pour 4J, milieu de la ligne

        player[0].coordonneX = traduction(cJ1);
        player[0].coordonneY = 0;

        player[0].coordonneX_org = traduction(cJ1);
        player[0].coordonneY_org = 0;

        mat[player[0].coordonneY][player[0].coordonneX] = 5;



        /// Joueur 2
        cJ2 = 'i';  //Position imposee pour 4J, milieu de la ligne

        player[1].coordonneX = 16;
        player[1].coordonneY = traduction(cJ2);

        player[1].coordonneX_org = 16;
        player[1].coordonneY_org = traduction(cJ2);

        mat[player[1].coordonneY][player[1].coordonneX] = 7;




        /// Joueur 3

        cJ3 = 'I';  //Position imposee pour 4J, milieu de la ligne

        player[2].coordonneX = traduction(cJ3);
        player[2].coordonneY = 16;

        player[2].coordonneX_org = traduction(cJ3);
        player[2].coordonneY_org = 16;

        mat[player[2].coordonneY][player[2].coordonneX] = 8;




        /// Joueur 4

        cJ4 = 'i';  //Position imposee pour 4J, milieu de la ligne

        player[3].coordonneX = 0;
        player[3].coordonneY = traduction(cJ4);

        player[3].coordonneX_org = 0;
        player[3].coordonneY_org = traduction(cJ4);

        mat[player[3].coordonneY][player[3].coordonneX] = 9;


        *Ptour = debut;     ///Attribution du joueur qui commence



    }
}
