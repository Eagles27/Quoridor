#include "Header_Pierre.h"

void menu_game(int mat[17][17],int* Pnombrejoueur,t_joueur player[4],int* Ptour)
{
    int choix;
    int dep[3];
    int org[3];
    char temp;
    int saisie1[2];
    int saisie2[2];
    int bool_barriere = -1;



    gotoligcol(20,0);
    printf("Actions Possibles:\n1-Deplacer son pion\n2-Poser une barriere\n3-Passer son tour\n4-Annuler la derniere action\n5-Revenir au menu precedent\n\nSaisie de l'action du joueur:\n");
    fflush(stdin);
    scanf("%d",&choix);





    switch(choix)
    {
    case 1:
    {
        ///Mettre programme de pierre




        dep[0] =  player[*Ptour-1].coordonneX;
        dep[1] = player[*Ptour-1].coordonneY;
        org[0] =  player[*Ptour-1].coordonneX;
        org[1] = player[*Ptour-1].coordonneY;



        deplacement(dep,mat,Pnombrejoueur);

        player[*Ptour-1].coordonneX = dep[0];
        player[*Ptour-1].coordonneY = dep[1];
        mat[org[1]][org[0]]=0;

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

        while(bool_barriere==-1)
        {
            system("cls");
            matrice_propre(mat);
            saisie_coord(saisie1);

            //bool_barriere = placer_barriere(mat, saisie1, saisie_dir());
        }

        system("cls");
        matrice_propre(mat);
        system("PAUSE");

        break;
    }
    case 3 :
    {
        ///PPG passer son tour

        //tour_par_tour(Pnombrejoueur,mat,player,Ptour);

        *Ptour ++;


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
