#include "Header_Pierre.h"

int placer_barriere(int tab[17][17], int place1[2], int place2[2])
{
    ///0. DDV
    int x,y;

    if((tab[place1[1]][place1[0]]==1)&&(tab[place2[1]][place2[0]]==1)){
        if(((place1[0]==place2[0])&&(place1[1]==place2[1]+1))||((place1[0]==place2[0])&&(place1[1]==place2[1]-1))||((place1[0]==place2[0]+1)&&(place1[1]==place2[1]))||((place1[0]==place2[0]-1)&&(place1[1]==place2[1])))
        {
            tab[place1[1]][place1[0]]=3;
            tab[place2[1]][place2[0]]=3;
            return 1;
        }
        else
        {
            printf("Les deux parties de la barriere\nDoivent etre cote a cote\n");
            system("PAUSE");
            return -1;
        }
    }
    else{
        printf("Le placement n'est pas valide\n");
        system("PAUSE");
        return -1;
    }
}
