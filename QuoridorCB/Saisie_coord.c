#include "Header_Pierre.h"

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
    while(!((saisie_clavier=='A')||(saisie_clavier=='B')||(saisie_clavier=='C')||(saisie_clavier=='D')||(saisie_clavier=='E')||(saisie_clavier=='F')||(saisie_clavier=='G')||(saisie_clavier=='H')||(saisie_clavier=='I')||(saisie_clavier=='J')||(saisie_clavier=='K')||(saisie_clavier=='L')||(saisie_clavier=='M')||(saisie_clavier=='N')||(saisie_clavier=='O')||(saisie_clavier=='P')||(saisie_clavier=='Q')));


    ///2. Saisi ordonnee
    do
    {
        printf("Saisir l'ordonnee :\n");
        fflush(stdin);
        scanf("%c", &saisie_clavier);
        coord = traduction(saisie_clavier);
        saisie[1] = coord;
    }
    while(!((saisie_clavier=='a')||(saisie_clavier=='b')||(saisie_clavier=='c')||(saisie_clavier=='d')||(saisie_clavier=='e')||(saisie_clavier=='f')||(saisie_clavier=='g')||(saisie_clavier=='h')||(saisie_clavier=='i')||(saisie_clavier=='j')||(saisie_clavier=='k')||(saisie_clavier=='l')||(saisie_clavier=='m')||(saisie_clavier=='n')||(saisie_clavier=='o')||(saisie_clavier=='p')||(saisie_clavier=='q')));
}



int saisie_dir(){
    ///0. DDV
    char saisie;


    do{
        printf("Saisir direction :\n");
        fflush(stdin);
        scanf("%c", &saisie);
    }while(!((saisie!='h')||(saisie!='H')||(saisie!='b')||(saisie!='B')||(saisie!='g')||(saisie!='G')||(saisie!='d')||(saisie!='D')));
    return saisie;
}
