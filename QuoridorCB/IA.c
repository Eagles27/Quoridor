#include "Header_Pierre.h"

//Fonction qui execute le tour de l'IA

void setup_IA()
{

}

void ia_v0(int dep_ia[2], int mat[17][17])
{
    int action = 0; //Booleen qui verfie que l'IA a fait quelque chose (meme passe son tour)

    ///L'IA commence en bas
    if(mat[dep_ia[1]-1][dep_ia[0]]==1)
    {
        dep_ia[1] -= 2;
        action = 1;
    }
    else if((mat[dep_ia[1]-1][dep_ia[0]]==2)||(mat[dep_ia[1]-1][dep_ia[0]]==3))
    {
        if((mat[dep_ia[1]][dep_ia[0]-1]!=2)&&(mat[dep_ia[1]][dep_ia[0]-1]!=3))
        {
            dep_ia[0] += 2;
            action = 1;
        }
        else if((mat[dep_ia[1]][dep_ia[0]+1]!=2)&&(mat[dep_ia[1]][dep_ia[0]+1]!=3))
        {
            dep_ia[0] -= 2;
            action = 1;
        }
        else
        {
            //Passe son tour
            action = 1;
        }
    }
    else
    {
        //Passe son tour
        action = 1;
    }
}
