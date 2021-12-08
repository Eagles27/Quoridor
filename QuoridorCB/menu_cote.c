#include "Header_Pierre.h"

void menu_cote(int* Ptour,int* PnombreJoeur, t_joueur player[4])
{
    int numero_ligne_cote=3;
    int numero_colonne_cote=60;

    ///Menu sombre
    gotoligcol(numero_ligne_cote-3,numero_colonne_cote);
    Color(15,2);
    printf("                                         ");
    Color(15,0);
    gotoligcol(numero_ligne_cote-2,numero_colonne_cote);
    Color(15,2);
    printf("       INFORMATIONS SUR LE JOUEUR        ");
    Color(15,0);
    gotoligcol(numero_ligne_cote-1,numero_colonne_cote);
    Color(15,2);
    printf("                                         ");
    Color(15,0);

    ///Menu clair
    gotoligcol(numero_ligne_cote,numero_colonne_cote);
    Color(15,10);
    printf("                                         ");
    Color(15,0);
    gotoligcol(numero_ligne_cote+1,numero_colonne_cote);
    Color(15,10);
    printf("        Nombre de Joueur : %d             ",*PnombreJoeur);
    Color(15,0);
    gotoligcol(numero_ligne_cote+2,numero_colonne_cote);
    Color(15,10);
    printf("              Joueur : %s                 ",player[*Ptour-1].nomJ);
    Color(15,0);

    //Cacher ce qui dépasse du nom
    gotoligcol(numero_ligne_cote+2,numero_colonne_cote+41);
    Color(15,0);
    printf("                ");
    Color(15,0);

    gotoligcol(numero_ligne_cote+3,numero_colonne_cote);
    Color(15,10);
    printf("                                         ");
    Color(15,0);
    gotoligcol(numero_ligne_cote+4,numero_colonne_cote);
    Color(15,10);
    printf("          Score Partie : %d               ",player[*Ptour-1].scoreP);
    Color(15,0);

    //Cacher ce qui dépasse du score
    gotoligcol(numero_ligne_cote+4,numero_colonne_cote+41);
    Color(15,0);
    printf("                ");
    Color(15,0);

    gotoligcol(numero_ligne_cote+5,numero_colonne_cote);
    Color(15,10);
    printf("                                         ");
    Color(15,0);
    gotoligcol(numero_ligne_cote+6,numero_colonne_cote);
    Color(15,10);
    printf("             Jeton : %c                   ",player[*Ptour-1].jetonJ);
    Color(15,0);
    gotoligcol(numero_ligne_cote+7,numero_colonne_cote);
    Color(15,10);
    printf("                                         ");
    Color(15,0);
    gotoligcol(numero_ligne_cote+8,numero_colonne_cote);
    Color(15,10);
    printf("       Barrieres restantes : %d           ",player[*Ptour-1].barrieresR);
    Color(15,0);

    //Cacher ce qui dépasse de barrières
    gotoligcol(numero_ligne_cote+8,numero_colonne_cote+41);
    Color(15,0);
    printf("                ");
    Color(15,0);

    gotoligcol(numero_ligne_cote+9,numero_colonne_cote);
    Color(15,10);
    printf("                                         ");
    Color(15,0);

    gotoligcol(numero_ligne_cote+10,numero_colonne_cote);
    Color(15,10);
    if(player[*Ptour-1].A_annule == 0){
    printf("      Vous pouvez annuler le coup        ");
    Color(15,0);
    gotoligcol(numero_ligne_cote+11,numero_colonne_cote);
    Color(15,10);
    printf("                                         ");
    Color(15,0);
    }
    else{
    printf("   Vous ne pouvez pas annuler le coup  ");
    Color(15,10);
    gotoligcol(numero_ligne_cote+11,numero_colonne_cote);
    Color(15,10);
    printf("                                         ");
    Color(15,0);
    }

    gotoligcol(20,0);




}
