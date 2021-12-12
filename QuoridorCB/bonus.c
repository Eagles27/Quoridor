#include "Header_Pierre.h"

///Place un nombre aleatoire (<7) de case bonus sur le plateau
void case_bonus(int mat[17][17])
{
    ///0. DDV
    int case_b[2];
    int nb_bonus;
    int i = 0;

    ///0.1. Initialisation clock
    srand(time(NULL));

    ///1. Generation aleatoire du nombre de case bonus
    nb_bonus = rand()%7;

    ///2. Placement des cases bonus
    while(i<=nb_bonus)
    {
        ///2.1. Generation aleatoire des coordonnees de la case
        case_b[0] = rand()%16;
        case_b[1] = rand()%16;

        ///2.2. Si les coordonnees sont bien celle d'une case et qu'elle est vide alors on ajoute le bonus
        if((case_b[0]!=1)&&(case_b[0]!=3)&&(case_b[0]!=5)&&(case_b[0]!=7)&&(case_b[0]!=9)&&(case_b[0]!=11)&&(case_b[0]!=15)&&(case_b[0]!=15)&&(case_b[1]!=1)&&(case_b[1]!=3)&&(case_b[1]!=5)&&(case_b[1]!=7)&&(case_b[1]!=9)&&(case_b[1]!=11)&&(case_b[1]!=13)&&(case_b[1]!=15))
        {
            if(mat[case_b[1]][case_b[0]] == 0)
            {
                mat[case_b[1]][case_b[0]] = 4;
                i++;
            }
        }
    }


}
