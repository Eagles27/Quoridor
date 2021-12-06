#include "Header_Pierre.h"

void menu_cote(int* Ptour,int* PnombreJoeur, t_joueur player[4])
{
    if(*Ptour == 1)
    {

        gotoligcol(3,60);
        printf("Nombre de Joueur : %d",*PnombreJoeur);

        gotoligcol(5,60);
        printf("Joueur : %s",player[0].nomJ);

        gotoligcol(7,60);
        printf("Score Partie : %d",player[0].scoreP);

        gotoligcol(9,60);
        printf("Jeton : %c",player[0].jetonJ);

        gotoligcol(11,60);
        printf("Barrieres restantes : %d",player[0].barrieresR);

         gotoligcol(20,0);


    }


    else if(*Ptour == 2)
    {

        gotoligcol(3,60);
        printf("Nombre de Joueur : %d",*PnombreJoeur);

        gotoligcol(5,60);
        printf("Joueur : %s",player[1].nomJ);

        gotoligcol(7,60);
        printf("Score Patie : %d",player[1].scoreP);

        gotoligcol(9,60);
        printf("Jeton : %c",player[1].jetonJ);

        gotoligcol(11,60);
        printf("Barrieres restantes : %d",player[1].barrieresR);


         gotoligcol(20,0);

    }

    else if(*Ptour == 3)
    {
        gotoligcol(3,60);
        printf("Nombre de Joueur : %d",*PnombreJoeur);

        gotoligcol(5,60);
        printf("Joueur : %s",player[2].nomJ);

        gotoligcol(7,60);
        printf("Score Patie : %d",player[2].scoreP);

        gotoligcol(9,60);
        printf("Jeton : %c",player[2].jetonJ);

        gotoligcol(11,60);
        printf("Barrieres restantes : %d",player[2].barrieresR);



         gotoligcol(20,0);


    }


    else if(*Ptour == 4)
    {
        gotoligcol(3,60);
        printf("Nombre de Joueur : %d",*PnombreJoeur);

        gotoligcol(5,60);
        printf("Joueur : %s",player[3].nomJ);

        gotoligcol(7,60);
        printf("Score Patie : %d",player[3].scoreP);

        gotoligcol(9,60);
        printf("Jeton : %c",player[3].jetonJ);

        gotoligcol(11,60);
        printf("Barrieres restantes : %d",player[3].barrieresR);




        gotoligcol(20,0);


    }


}
