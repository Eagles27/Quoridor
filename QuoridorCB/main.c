#include "Header_Pierre.h"

int main()
{
    ///0. DDV
    //int depla[3] = {14, 16};
    int tab[17][17];
    //int depla_org[3];
    //char lettre = '0';
    //int chiffre;

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
    /*genematrice(tab);
    tab[1][0]=3;
    tab[1][1]=3;
    tab[0][1]=3;
    tab[0][0]=5;
    tab[0][2]=7;
    tab[0][4]=9;
    tab[0][6]=11;
    //tab[1][2]=3;
    matrice_propre(tab);*/

    ///4. Test barriere
    /*genematrice(tab);
    affiche(tab);
    system("PAUSE");
    system("cls");
    int place1[2] = {1,0};
    int place2[2] = {1,1};
    placer_barriere(tab,place1,place2);
    matrice_propre(tab);*/

    ///5. Main max
    int mat[17][17];
    int nombre_joueur = 0;

    int *Pnombre_joueur = &nombre_joueur;


    ///Barrieres

    int barJ1 = 0;
    int barJ2 = 0;
    int barJ3 = 0;
    int barJ4 = 0;

    int *PbarJ1 = &barJ1;
    int *PbarJ2 = &barJ2;
    int *PbarJ3 = &barJ3;
    int *PbarJ4 = &barJ4;


    genematrice(mat);
    main_menu(PbarJ1,PbarJ2,PbarJ3,PbarJ4,Pnombre_joueur,mat);

    return 0;
}
