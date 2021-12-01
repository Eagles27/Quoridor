#include "Header_Pierre.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
////////////////    /!\ Ne marche que pour les barrières    /////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

void saisie_coord(int saisie[2])
{
    ///0. DDV
    char saisie_clavier;
    int coord;

    ///1. Saisi abscisse
    do
    {
        printf("Saisir l'abscisse :\n");
        fflush(stdin);
        scanf("%c", &saisie_clavier);
        coord = traduction(saisie_clavier);
        saisie[0] = coord;
    }
    while(!((saisie_clavier=='B')||(saisie_clavier=='D')||(saisie_clavier=='F')||(saisie_clavier=='H')||(saisie_clavier=='J')||(saisie_clavier=='L')||(saisie_clavier=='N')||(saisie_clavier=='P')));



    ///2. Saisi ordonnee
    do
    {
        printf("Saisir l'ordonnee :\n");
        fflush(stdin);
        scanf("%c", &saisie_clavier);
        coord = traduction(saisie_clavier);
        saisie[1] = coord;
    }
    while(!((saisie_clavier=='b')||(saisie_clavier=='d')||(saisie_clavier=='f')||(saisie_clavier=='h')||(saisie_clavier=='j')||(saisie_clavier=='l')||(saisie_clavier=='n')||(saisie_clavier=='p')));
}
