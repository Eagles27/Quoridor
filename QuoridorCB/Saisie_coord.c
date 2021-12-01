#include "Header_Pierre.h"

void saisie_coord(int saisie[2])
{
    ///0. DDV
    char saisie_clavier;
    int coord;

    ///1. Saisi abscisse
    printf("Saisir l'abscisse :\n");
    scanf("%c", &saisie_clavier);
    coord = traduction(saisie_clavier);
    saisie[0] = coord;

    ///2. Saisi ordonnee
    printf("Saisir l'ordonnee :\n");
    scanf("%c", &saisie_clavier);
    coord = traduction(saisie_clavier);
    saisie[1] = coord;
}
