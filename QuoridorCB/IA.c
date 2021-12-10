#include "Header_Pierre.h"

//Fonction qui execute le tour de l'IA

void setup_IA()
{

}

void ia_v0(int dep_ia[2], int mat[17][17])
{
    ///Deplacement vers le haut
    //il n'y a pas de barriere devant
    if(mat[dep_ia[1]-1][dep_ia[0]]==1)
    {
        //La case est libre
        if((mat[dep_ia[1]-2][dep_ia[0]]==0)||(mat[dep_ia[1]-2][dep_ia[0]]==13))
        {
            dep_ia[1] -= 2;
        }
        //La case est occupée par un joueur pas le saut est possible
        else if(mat[dep_ia[1]-3][dep_ia[0]]==1)
        {
            dep_ia[1] -= 4;
        }
        //Le saut n'est pas possible
        else
        {
            //Le decalage a gauche est possible
            if(mat[dep_ia[1]-2][dep_ia[0]-1]==1)
            {
                dep_ia[0] -= 2;
                dep_ia[1] -= 2;
            }
            //Le decalage a droite est possible
            else if(mat[dep_ia[1]-2][dep_ia[0]+1]==1)
            {
                dep_ia[0] += 2;
                dep_ia[1] -= 2;
            }
            //Le decalage n'est pas possible donc on recule
            else if((mat[dep_ia[1]-1][dep_ia[0]]==1)&&(dep_ia[1] != 16))
            {
                dep_ia[1] -= 2;
            }
            else
            {
                //Passe le tour
                system("cls");
                printf("L'IA est bloquée\n");
                system("PAUSE");
            }
        }
    }
    //Il y a une barriere devant
    else if((mat[dep_ia[1]-1][dep_ia[0]]==2)||(mat[dep_ia[1]-1][dep_ia[0]]==3))
    {
        //On est pas au bord du plateau à droite
        if(dep_ia[0]==16)
        {
            //Il n'y a pas de barriere à droite
            if((mat[dep_ia[1]][dep_ia[0]-1]!=2)&&(mat[dep_ia[1]][dep_ia[0]-1]!=3))
            {
                dep_ia[0] += 2;
            }
            //Il n'y a pas de barriere à gauche
            else if((mat[dep_ia[1]][dep_ia[0]-1]!=2)&&(mat[dep_ia[1]][dep_ia[0]-1]!=3))
            {
                dep_ia[0] -= 2;
            }
        }
        //On est pas au bord du plateau à gauche
        else if(dep_ia[1]== 0)
        {
            //Il n'y a pas de barriere à droite
            if((mat[dep_ia[1]][dep_ia[0]-1]!=2)&&(mat[dep_ia[1]][dep_ia[0]-1]!=3))
            {
                dep_ia[0] += 2;
            }
            //Il n'y a pas de barriere à gauche
            else if((mat[dep_ia[1]][dep_ia[0]-1]!=2)&&(mat[dep_ia[1]][dep_ia[0]-1]!=3))
            {
                dep_ia[0] -= 2;
            }
        }
        //On est au bord du plateau a g et a d
        else
        {
            //On est pas en bas du plateau
            if(dep_ia[1] != 0)
            {
                dep_ia[1] -= 2;
            }
            else
            {
                //Passe le tour
            }
        }

    }
    else
    {
        //Passe son tour
    }
}
