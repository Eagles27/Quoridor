#include "Header_Pierre.h"

void affiregles()
{

    int numero_l=0;
    int numero_c=0;
    Color(15,0);
    ///Foncé
    gotoligcol(numero_l,numero_c);
    Color(15,2);
    printf("                                                                                                                             ");
    Color(15,0);
    gotoligcol(numero_l+1,numero_c);
    Color(15,2);
    printf("                                                  BUT DU JEU                                                                 ");
    Color(15,0);
    gotoligcol(numero_l+2,numero_c);
    Color(15,2);
    printf("                                                                                                                             ");
    Color(15,0);
    ///Clair
    gotoligcol(numero_l+3,numero_c);
    Color(15,10);
    printf("                                                                                                                             ");
    Color(15,0);
    gotoligcol(numero_l+4,numero_c);
    Color(15,10);
    printf("                          Il s'agit d'atteindre le premier la ligne opposee a sa ligne de depart.                            ");
    Color(15,0);
    gotoligcol(numero_l+5,numero_c);
    Color(15,10);
    printf("                              En debut de partie, les barrieres sont distribuees aux joueurs.                                ");
    Color(15,0);
    gotoligcol(numero_l+6,numero_c);
    Color(15,10);
    printf("                                          Un tirage au sort determine qui commence.                                          ");
    Color(15,0);
    gotoligcol(numero_l+7,numero_c);
    Color(15,10);
    printf("                                                                                                                             ");
    Color(15,0);
    gotoligcol(numero_l+8,numero_c);
    Color(15,2);
    //system("PAUSE");
    ///Foncé
    printf("                                                                                                                             ");
    Color(15,0);
    gotoligcol(numero_l+9,numero_c);
    Color(15,2);
    printf("                                                  DEPLACEMENTS                                                               ");
    Color(15,0);
    gotoligcol(numero_l+10,numero_c);
    Color(15,2);
    printf("                                                                                                                             ");
    Color(15,0);
    ///Clair
    gotoligcol(numero_l+11,numero_c);
    Color(15,10);
    printf("                                                                                                                             ");
    Color(15,0);
    gotoligcol(numero_l+12,numero_c);
    Color(15,10);
    printf("                                           A tour de role, chaque joueur choisit :                                           ");
    Color(15,0);
    gotoligcol(numero_l+13,numero_c);
    Color(15,10);
    printf("                 -de deplacer son pion d'une case verticalement ou horizontalement, en avant ou en arriere ;                 ");
    Color(15,0);
    gotoligcol(numero_l+14,numero_c);
    Color(15,10);
    printf("             -de poser une de ses barrieres. Une barriere doit etre posee exactement entre deux blocs de 2 cases.            ");
    Color(15,0);
    gotoligcol(numero_l+15,numero_c);
    Color(15,10);
    printf("               Lorsqu'il n'a plus de barrieres, la partie se termine, le.s joueur.s le.s plus avancé.s gagne.nt              ");
    Color(15,0);
    gotoligcol(numero_l+16,numero_c);
    Color(15,10);
    printf("                    La pose des barrieres a pour but de creer son propre chemin ou de ralentir l'adversaire.                 ");
    Color(15,0);
    gotoligcol(numero_l+17,numero_c);
    Color(15,10);
    printf("                              Il est interdit de lui fermer totalement l'acces a sa ligne de but.                            ");
    Color(15,0);
    gotoligcol(numero_l+18,numero_c);
    Color(15,10);
    printf("                  Quand 2 pions se retrouvent en vis-a-vis sur 2 cases voisines non separees par une barriere,               ");
    Color(15,0);
    gotoligcol(numero_l+19,numero_c);
    Color(15,10);
    printf("                le joueur dont c'est le tour peut sauter par-dessus son adversaire et se retrouver derriere lui.             ");
    Color(15,0);
    gotoligcol(numero_l+20,numero_c);
    Color(15,10);
    printf("   Si une barriere se trouve derriere le pion saute, le joueur peut choisir de bifurquer a droite ou a gauche du pion saute. ");
    Color(15,0);
    gotoligcol(numero_l+21,numero_c);
    Color(15,10);
    printf("                                                                                                                             ");
    //system("PAUSE");
    ///Foncé
    Color(15,0);
    gotoligcol(numero_l+22,numero_c);
    Color(15,2);
    printf("                                                                                                                             ");
    Color(15,0);
    gotoligcol(numero_l+23,numero_c);
    Color(15,2);
    printf("                                             REGLES POUR 4 JOUEURS                                                           ");
    Color(15,0);
    gotoligcol(numero_l+24,numero_c);
    Color(15,2);
    printf("                                                                                                                             ");
    ///Clair
    Color(15,0);
    gotoligcol(numero_l+25,numero_c);
    Color(15,10);
    printf("  En debut de partie, les 4 pions sont disposes au centre de chacun des cotes du plateau et chaque joueur a 5 barrieres.     ");
    Color(15,0);
    gotoligcol(numero_l+26,numero_c);
    Color(15,10);
    printf("                  Les regles sont strictement identiques, mais on ne peut sauter plus d'un pion a la fois.                   ");
    Color(15,0);
    gotoligcol(numero_l+27,numero_c);
    Color(15,10);
    printf("                                                                                                                             ");
    Color(15,0);
    gotoligcol(numero_l+28,numero_c);
    system("PAUSE");
    system("cls");
}

