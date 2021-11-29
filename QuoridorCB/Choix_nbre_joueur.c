#include "header_adrien.h"

int nbre_joueurs()
{
    int nbr;

    printf("CHOISIR LE NOMBRE DE JOUEUR (2 ou 4)\n");
    scanf("%d",&nbr);
    if((nbr!=2)&&(nbr!=4))
    {
        printf("Saisie erronee\n");
    }
    else
    {
        printf("Vous jouez a ");
        printf("%d ",nbr);
        printf("joueurs\n");
        return nbr;
    }
}
