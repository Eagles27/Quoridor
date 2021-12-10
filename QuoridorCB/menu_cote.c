#include "Header_Pierre.h"

void menu_cote(int* Ptour,int* PnombreJoeur, t_joueur player[4], t_IA ia)
{

    gotoligcol(3,60);
    printf("Nombre de Joueur : %d",*PnombreJoeur);

    gotoligcol(5,60);
    printf("Joueur : %s",player[*Ptour-1].nomJ);

    gotoligcol(7,60);
    printf("Score Partie : %d",player[*Ptour-1].scoreP);

    gotoligcol(9,60);
    printf("Jeton : %c",player[*Ptour-1].jetonJ);

    gotoligcol(11,60);
    printf("Barrieres restantes : %d",player[*Ptour-1].barrieresR);

    gotoligcol(13,60);
    if(player[*Ptour-1].A_annule == 0)
    {
        printf("Peut annuler le coup");
    }
    else
    {
        printf("Ne peut plus annuler");
    }

    gotoligcol(20,0);
}

void menu_cote_ia(int tour, t_joueur player[4], t_IA ia)
{
    if(tour%2 == 0)//Menu joueur
    {
        gotoligcol(5,60);
        printf("Joueur : %s",player[0].nomJ);

        gotoligcol(7,60);
        printf("Score Partie : %d",player[0].scoreP);

        gotoligcol(9,60);
        printf("Jeton : %c",player[0].jetonJ);

        gotoligcol(11,60);
        printf("Barrieres restantes : %d",player[0].barrieresR);

        gotoligcol(13,60);
        if(player[0].A_annule == 0)
        {
            printf("Peut annuler le coup");
        }
        else
        {
            printf("Ne peut plus annuler");
        }
    }
    else//Menu IA
    {
        gotoligcol(5,60);
        printf("Joueur : %s",ia.nom);

        gotoligcol(7,60);
        printf("Score Partie : %d",ia.score);

        gotoligcol(9,60);
        printf("Jeton : %c",ia.jeton);

        gotoligcol(11,60);
        printf("Barrieres restantes : %d",ia.barrieresR);
    }



    gotoligcol(20,0);
}
