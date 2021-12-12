#include "Header_Pierre.h"

///Programme permettant a l'utilisateur de saisir une case du plateau
void saisie_coord(int saisie[2],int*Ptour,int*PnombreJ,t_joueur player[4],int mat[17][17],t_IA ia)
{
    ///0. DDV
    char saisie_clavier;
    int coord;

    ///1. Saisie abscisse
    do//Blindage
    {
        system("cls");
        matrice_propre(mat,player,ia);//Traduit et affiche la matrice ordi
        menu_cote(Ptour,PnombreJ,player);//Affiche le menu sur le coté (info)
        printf("\nSaisir l'abscisse :\n");
        fflush(stdin);//Liberation du scanf
        scanf("%c", &saisie_clavier);//
        coord = traduction(saisie_clavier);//Passage de lettres de coords à coords reeles (en chiffres)
        saisie[0] = coord;
    }
    while(!((saisie_clavier=='A')||(saisie_clavier=='B')||(saisie_clavier=='C')||(saisie_clavier=='D')||(saisie_clavier=='E')||(saisie_clavier=='F')||(saisie_clavier=='G')||(saisie_clavier=='H')||(saisie_clavier=='I')||(saisie_clavier=='J')||(saisie_clavier=='K')||(saisie_clavier=='L')||(saisie_clavier=='M')||(saisie_clavier=='N')||(saisie_clavier=='O')||(saisie_clavier=='P')||(saisie_clavier=='Q')));


    ///2. Saisie ordonnee
    do//Blindage
    {
        system("cls");
        matrice_propre(mat,player,ia);
        menu_cote(Ptour,PnombreJ,player);
        printf("\nSaisir l'ordonnee :\n");
        fflush(stdin);
        scanf("%c", &saisie_clavier);
        coord = traduction(saisie_clavier);
        saisie[1] = coord;
    }
    while(!((saisie_clavier=='a')||(saisie_clavier=='b')||(saisie_clavier=='c')||(saisie_clavier=='d')||(saisie_clavier=='e')||(saisie_clavier=='f')||(saisie_clavier=='g')||(saisie_clavier=='h')||(saisie_clavier=='i')||(saisie_clavier=='j')||(saisie_clavier=='k')||(saisie_clavier=='l')||(saisie_clavier=='m')||(saisie_clavier=='n')||(saisie_clavier=='o')||(saisie_clavier=='p')||(saisie_clavier=='q')));
}


///Fonction permettant a l'utilisateur de saisir une direction
int saisie_dir(int*Ptour,int*PnombreJ,t_joueur player[4],int mat[17][17],t_IA ia)
{
    ///0. DDV
    char saisie;

    ///1. Saisie
    do//Blindage de saisie
    {
        system("cls");
        matrice_propre(mat,player,ia);
        menu_cote(Ptour,PnombreJ,player);
        printf("\nSaisir direction(h,b,g,d) :\n");
        fflush(stdin);
        scanf("%c", &saisie);
    }
    while(!((saisie=='h')||(saisie=='H')||(saisie=='b')||(saisie=='B')||(saisie=='g')||(saisie=='G')||(saisie=='d')||(saisie=='D')));
    return saisie;//Retourne la direction choisie
}
