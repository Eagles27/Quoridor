#include "Header_Pierre.h"

void case_bonus(int mat[17][17])
{

    int case_b[2];
    int nb_bonus;
    int i = 0;

    srand(time(NULL));


    nb_bonus = rand()%7;

    while(i<=nb_bonus)
    {
        case_b[0] = rand()%16;
        case_b[1] = rand()%16;
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
