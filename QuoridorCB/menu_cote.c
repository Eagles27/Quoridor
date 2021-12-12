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
    printf("   Vous ne pouvez pas annuler le coup    ");
    Color(15,10);
    gotoligcol(numero_ligne_cote+11,numero_colonne_cote);
    Color(15,10);
    printf("                                         ");
    Color(15,0);
    }
    gotoligcol(20,0);
}

void menu_cote_ia(int tour, t_joueur player[4], t_IA ia)
{
    int numero_ligne_cote=3;
    int numero_colonne_cote=60;
    if(tour%2 == 0)//Menu joueur
    {

    ///Menu sombre
    gotoligcol(numero_ligne_cote-2,numero_colonne_cote);
    Color(15,2);
    printf("                                         ");
    Color(15,0);
    gotoligcol(numero_ligne_cote-1,numero_colonne_cote);
    Color(15,2);
    printf("       INFORMATIONS SUR LE JOUEUR        ");
    Color(15,0);
    gotoligcol(numero_ligne_cote,numero_colonne_cote);
    Color(15,2);
    printf("                                         ");
    Color(15,0);


    ///Menu clair
    gotoligcol(numero_ligne_cote+1,numero_colonne_cote);
    Color(15,10);
    printf("                                         ");
    Color(15,0);
    gotoligcol(numero_ligne_cote+2,numero_colonne_cote);
    Color(15,10);
    printf("              Joueur : %s                 ",player[0].nomJ);
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
    printf("          Score Partie : %d               ",player[0].scoreP);
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
    printf("             Jeton : %c                   ",player[0].jetonJ);
    Color(15,0);
    gotoligcol(numero_ligne_cote+7,numero_colonne_cote);
    Color(15,10);
    printf("                                         ");
    Color(15,0);
    gotoligcol(numero_ligne_cote+8,numero_colonne_cote);
    Color(15,10);
    printf("       Barrieres restantes : %d           ",player[0].barrieresR);
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






        /*gotoligcol(5,60);
        printf("Joueur : %s",player[0].nomJ);

        gotoligcol(7,60);
        printf("Score Partie : %d",player[0].scoreP);

        gotoligcol(9,60);
        printf("Jeton : %c",player[0].jetonJ);

        gotoligcol(11,60);
        printf("Barrieres restantes : %d",player[0].barrieresR);*/

        gotoligcol(13,60);
        if(player[0].A_annule == 0)
        {
            printf("           Peut annuler le coup          ");
            Color(15,0);
            gotoligcol(14,60);
            Color(15,10);
            printf("                                         ");
            Color(15,0);
        }
        else
        {
            printf("           Ne peut plus annuler          ");
            Color(15,0);
            gotoligcol(14,60);
            Color(15,10);
            printf("                                         ");
            Color(15,0);
        }
    }
    else//Menu IA
    {
        ///Menu sombre
    gotoligcol(numero_ligne_cote-2,numero_colonne_cote);
    Color(15,2);
    printf("                                         ");
    Color(15,0);
    gotoligcol(numero_ligne_cote-1,numero_colonne_cote);
    Color(15,2);
    printf("       INFORMATIONS SUR LE JOUEUR        ");
    Color(15,0);
    gotoligcol(numero_ligne_cote,numero_colonne_cote);
    Color(15,2);
    printf("                                         ");
    Color(15,0);


    ///Menu clair
    gotoligcol(numero_ligne_cote+1,numero_colonne_cote);
    Color(15,10);
    printf("                                         ");
    Color(15,0);
    gotoligcol(numero_ligne_cote+2,numero_colonne_cote);
    Color(15,10);
    printf("              Joueur : %s                 ",ia.nom);
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
    printf("          Score Partie : %d               ",ia.score);
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
    printf("             Jeton : %c                   ",ia.jeton);
    Color(15,0);
    gotoligcol(numero_ligne_cote+7,numero_colonne_cote);
    Color(15,10);
    printf("                                         ");
    Color(15,0);
    gotoligcol(numero_ligne_cote+8,numero_colonne_cote);
    Color(15,10);
    printf("       Barrieres restantes : %d           ",ia.barrieresR);
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



        /*gotoligcol(5,60);
        printf("Joueur : %s",ia.nom);

        gotoligcol(7,60);
        printf("Score Partie : %d",ia.score);

        gotoligcol(9,60);
        printf("Jeton : %c",ia.jeton);

        gotoligcol(11,60);
        printf("Barrieres restantes : %d",ia.barrieresR);*/

    }



    gotoligcol(20,0);
}
