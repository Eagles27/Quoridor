#include "Header_Pierre.h"

///Transforme chaque entree sous forme de caractere en chiffre
int traduction(char entree)
{
    ///On test pour savoir de qu'elle lettre il s'agit puis on renvoie le chiffre correspondant
    if (entree == 'A')
    {
        return 0;
    }

    else if (entree == 'B')
    {
        return 1;
    }

    else if(entree == 'C')
    {
        return 2;
    }

    else if (entree == 'D')
    {
        return 3;
    }

    else if(entree == 'E')
    {
        return 4;
    }

    else if (entree == 'F')
    {
        return 5;
    }

    else if(entree == 'G')
    {
        return 6;
    }

    else if (entree == 'H')
    {
        return 7;
    }

    else if(entree == 'I')
    {
        return 8;
    }

    else if (entree == 'J')
    {
        return 9;
    }

    else if(entree == 'K')
    {
        return 10;
    }

    else if (entree == 'L')
    {
        return 11;
    }

    else if(entree == 'M')
    {
        return 12;
    }

    else if (entree == 'N')
    {
        return 13;
    }

    else if(entree == 'O')
    {
        return 14;
    }

    else if (entree == 'P')
    {
        return 15;
    }

    else if(entree == 'Q')
    {
        return 16;
    }

    else if (entree == 'a')
    {
        return 0;
    }

    else if (entree == 'b')
    {
        return 1;
    }

    else if(entree == 'c')
    {
        return 2;
    }

    else if (entree == 'd')
    {
        return 3;
    }

    else if(entree == 'e')
    {
        return 4;
    }

    else if (entree == 'f')
    {
        return 5;
    }

    else if(entree == 'g')
    {
        return 6;
    }

    else if (entree == 'h')
    {
        return 7;
    }

    else if(entree == 'i')
    {
        return 8;
    }

    else if (entree == 'j')
    {
        return 9;
    }

    else if(entree == 'k')
    {
        return 10;
    }

    else if (entree == 'l')
    {
        return 11;
    }

    else if(entree == 'm')
    {
        return 12;
    }

    else if (entree == 'n')
    {
        return 13;
    }

    else if(entree == 'o')
    {
        return 14;
    }

    else if (entree == 'p')
    {
        return 15;
    }

    else if(entree == 'q')
    {
        return 16;
    }

    return -1;
}

///Transforme chaque mot entr? en majuscule
void majuscule(char mot[50]){
    ///0. DDV
    int i = 0;

    ///1.Transformation
    while(mot[i] != '\0'){
        ///1.1. Test si deja en Maj
        if((mot[i] >= 'a')&&(mot[i] <= 'z')){
            mot[i] = mot[i] - 32;
        }
        i ++;
    }
}
