#include "Header_Pierre.h"

int main()
{
    ///0. DDV
    int depla[3] = {4, 2};
    int tab[17][17];

    ///1. Test
    genematrice(tab);
    tab[2][2]=5;
    tab[1][2]=2;
    tab[2][1]=2;
    tab[depla[1]][depla[0]]=4;
    affiche(tab);
    system("PAUSE");
    tab[depla[1]][depla[0]]=0;
    deplacement(depla, tab, 2);
    //printf("%d, %d\n",depla[0], depla[1]);
    tab[depla[1]][depla[0]]=4;
    affiche(tab);
}
