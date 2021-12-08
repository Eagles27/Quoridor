#include "Header_Pierre.h"

void menu_cote(int* Ptour,int* PnombreJoeur, t_joueur player[4])
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
    if(player[*Ptour-1].A_annule == 0){
        printf("Peut annuler le coup");
    }
    else{
        printf("Ne peut plus annuler");
    }

    gotoligcol(20,0);




}
