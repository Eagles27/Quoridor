#include "Header_Pierre.h"

int main()
{
    ///0. DDV
    int depla[3] = {14, 16};
    int tab[17][17];
    int depla_org[3];
    char lettre = '0';
    int chiffre;

    ///1. Test deplacement
    /*genematrice(tab);
    tab[depla[1]][depla[0]]=4;
    tab[16][16]=5;
    affiche(tab);
    system("PAUSE");
    depla_org[0] = depla[0];
    depla_org[1] = depla[1];
    deplacement(depla, tab, 2);
    tab[depla_org[1]][depla_org[0]]=0;
    tab[depla[1]][depla[0]]=4;
    //printf("%d, %d\n",depla[0], depla[1]);
    //system("cls");
    affiche(tab);*/

    ///2. Test save-DL
    /*genematrice(tab);
    sauver(tab);
    charger(tab);
    affiche(tab);*/

    ///3. Test affiche propre
    genematrice(tab);
    tab[1][0]=3;
    tab[1][1]=3;
    tab[0][1]=3;
    tab[0][0]=5;
    tab[0][2]=7;
    tab[0][4]=9;
    tab[0][6]=11;
    //tab[1][2]=3;
    matrice_propre(tab);
}
