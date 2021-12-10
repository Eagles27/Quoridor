#include "Header_Pierre.h"

//Fonction qui execute le tour de l'IA

int ia_v0(int dep_ia[2], int mat[17][17], t_joueur player[4], t_IA ia)
{
//Valeur suivant action IA
//-1 si rien / 1 si bouge / 2 si barriere

///Deplacement IA vers le haut
//il n'y a pas de barriere devant
    if(mat[dep_ia[1]-1][dep_ia[0]]==1)
    {
        //La case est libre
        if((mat[dep_ia[1]-2][dep_ia[0]]==0)||(mat[dep_ia[1]-2][dep_ia[0]]==13))
        {
            dep_ia[1] -= 2;
            return 1;
        }
        //La case est occupée par un joueur pas le saut est possible
        else if(mat[dep_ia[1]-3][dep_ia[0]]==1)
        {
            dep_ia[1] -= 4;
            return 1;
        }
        //Le saut n'est pas possible
        else
        {
            //Le decalage a gauche est possible
            if(mat[dep_ia[1]-2][dep_ia[0]-1]==1)
            {
                dep_ia[0] -= 2;
                dep_ia[1] -= 2;
                return 1;
            }
            //Le decalage a droite est possible
            else if(mat[dep_ia[1]-2][dep_ia[0]+1]==1)
            {
                dep_ia[0] += 2;
                dep_ia[1] -= 2;
                return 1;
            }
            //Le decalage n'est pas possible donc on recule
            else if((mat[dep_ia[1]-1][dep_ia[0]]==1)&&(dep_ia[1] != 16))
            {
                dep_ia[1] -= 2;
                return 1;
            }
            //Se deplacer n'est pas possible donc on place une barriere
            else
            {
                //Si il reste des barrieres
                if(ia.barrieresR !=0)
                {
                    //On place une barriere devant le joueur
                    //On place la premiere parte de la barriere
                    mat[player[0].coordonneY+1][player[0].coordonneX] = 2;
                    //Si le joueur est au bord a gauche ou qu'il y a deja une barriere a gauche
                    if((player[0].coordonneX == 0)||(mat[player[0].coordonneY+1][player[0].coordonneX-1]==2))
                    {
                        //Si il ya deja une barriere a droire
                        if(mat[player[0].coordonneY+1][player[0].coordonneX+1==2])
                        {
                            //On supprime la premiere barriere
                            mat[player[0].coordonneY+1][player[0].coordonneX] = 1;
                            //On passe le tour
                        }
                        //On met la barriere a droite
                        else
                        {
                            mat[player[0].coordonneY+1][player[0].coordonneX+1] = 2;
                            mat[player[0].coordonneY+1][player[0].coordonneX+2] = 2;
                            return 2;
                        }
                    }
                    //Si le joueur est au bord a droite ou qu'il y a deja une barriere a droite
                    else if((player[0].coordonneX == 16)||(mat[player[0].coordonneY+1][player[0].coordonneX+1]==2))
                    {
                        //Si il ya deja une barriere a gauche
                        if(mat[player[0].coordonneY+1][player[0].coordonneX-1==2])
                        {
                            //On supprime la premiere barriere
                            mat[player[0].coordonneY+1][player[0].coordonneX] = 1;
                            //On passe le tour
                        }
                        //On met la barriere a gauche
                        else
                        {
                            mat[player[0].coordonneY+1][player[0].coordonneX-2] = 2;
                            mat[player[0].coordonneY+1][player[0].coordonneX-1] = 2;
                            return 2;
                        }
                    }
                    //On met une barriere juste avant la ligne d'arrivée
                    //On test si la premiere place est libre
                    else if((mat[15][0]==1)&&(mat[15][2]==1))
                    {
                        mat[15][0] = 2;
                        mat[15][1] = 2;
                        mat[15][2] = 2;
                        return 2;
                    }
                    //Sinon la suivante...
                    else if((mat[15][2]==1)&&(mat[15][4]==1))
                    {
                        mat[15][2] = 2;
                        mat[15][3] = 2;
                        mat[15][4] = 2;
                        return 2;
                    }
                    else if((mat[15][2]==1)&&(mat[15][4]==1))
                    {
                        mat[15][2] = 2;
                        mat[15][3] = 2;
                        mat[15][4] = 2;
                        return 2;
                    }
                    else if((mat[15][4]==1)&&(mat[15][6]==1))
                    {
                        mat[15][4] = 2;
                        mat[15][5] = 2;
                        mat[15][6] = 2;
                        return 2;
                    }
                    else if((mat[15][6]==1)&&(mat[15][8]==1))
                    {
                        mat[15][6] = 2;
                        mat[15][7] = 2;
                        mat[15][8] = 2;
                        return 2;
                    }
                    else if((mat[15][8]==1)&&(mat[15][10]==1))
                    {
                        mat[15][8] = 2;
                        mat[15][9] = 2;
                        mat[15][10] = 2;
                        return 2;
                    }
                    else if((mat[15][10]==1)&&(mat[15][12]==1))
                    {
                        mat[15][10] = 2;
                        mat[15][11] = 2;
                        mat[15][12] = 2;
                        return 2;
                    }
                    else if((mat[15][12]==1)&&(mat[15][14]==1))
                    {
                        mat[15][12] = 2;
                        mat[15][13] = 2;
                        mat[15][14] = 2;
                        return 2;
                    }
                    else if((mat[15][14]==1)&&(mat[15][16]==1))
                    {
                        mat[15][14] = 2;
                        mat[15][15] = 2;
                        mat[15][16] = 2;
                        return 2;
                    }

                }
                //On a plus de barriere alors on passe le tour
                else
                {
                    //Passe le tour
                    return -1;
                }

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
                return 1;
            }
            //Il n'y a pas de barriere à gauche
            else if((mat[dep_ia[1]][dep_ia[0]-1]!=2)&&(mat[dep_ia[1]][dep_ia[0]-1]!=3))
            {
                dep_ia[0] -= 2;
                return 1;
            }
        }
        //On est pas au bord du plateau à gauche
        else if(dep_ia[1]== 0)
        {
            //Il n'y a pas de barriere à droite
            if((mat[dep_ia[1]][dep_ia[0]-1]!=2)&&(mat[dep_ia[1]][dep_ia[0]-1]!=3))
            {
                dep_ia[0] += 2;
                return 1;
            }
            //Il n'y a pas de barriere à gauche
            else if((mat[dep_ia[1]][dep_ia[0]-1]!=2)&&(mat[dep_ia[1]][dep_ia[0]-1]!=3))
            {
                dep_ia[0] -= 2;
                return 1;
            }
        }
        //On est au bord du plateau a g et a d
        else
        {
            //On est pas en bas du plateau
            if(dep_ia[1] != 0)
            {
                dep_ia[1] -= 2;
                return 1;
            }
            else
            {
                //Si il reste des barrieres
                if(ia.barrieresR !=0)
                {
                    //On place une barriere devant le joueur
                    //On place la premiere parte de la barriere
                    mat[player[0].coordonneY+1][player[0].coordonneX] = 2;
                    //Si le joueur est au bord a gauche ou qu'il y a deja une barriere a gauche
                    if((player[0].coordonneX == 0)||(mat[player[0].coordonneY+1][player[0].coordonneX-1]==2))
                    {
                        //Si il ya deja une barriere a droire
                        if(mat[player[0].coordonneY+1][player[0].coordonneX+1==2])
                        {
                            //On supprime la premiere barriere
                            mat[player[0].coordonneY+1][player[0].coordonneX] = 1;
                            //On passe le tour
                        }
                        //On met la barriere a droite
                        else
                        {
                            mat[player[0].coordonneY+1][player[0].coordonneX+1] = 2;
                            mat[player[0].coordonneY+1][player[0].coordonneX+2] = 2;
                            return 2;
                        }
                    }
                    //Si le joueur est au bord a droite ou qu'il y a deja une barriere a droite
                    else if((player[0].coordonneX == 16)||(mat[player[0].coordonneY+1][player[0].coordonneX+1]==2))
                    {
                        //Si il ya deja une barriere a gauche
                        if(mat[player[0].coordonneY+1][player[0].coordonneX-1==2])
                        {
                            //On supprime la premiere barriere
                            mat[player[0].coordonneY+1][player[0].coordonneX] = 1;
                            //On passe le tour
                        }
                        //On met la barriere a gauche
                        else
                        {
                            mat[player[0].coordonneY+1][player[0].coordonneX-2] = 2;
                            mat[player[0].coordonneY+1][player[0].coordonneX-1] = 2;
                            return 2;
                        }
                    }
                    //On met une barriere juste avant la ligne d'arrivée
                    //On test si la premiere place est libre
                    else if((mat[15][0]==1)&&(mat[15][2]==1))
                    {
                        mat[15][0] = 2;
                        mat[15][1] = 2;
                        mat[15][2] = 2;
                        return 2;
                    }
                    //Sinon la suivante...
                    else if((mat[15][2]==1)&&(mat[15][4]==1))
                    {
                        mat[15][2] = 2;
                        mat[15][3] = 2;
                        mat[15][4] = 2;
                        return 2;
                    }
                    else if((mat[15][2]==1)&&(mat[15][4]==1))
                    {
                        mat[15][2] = 2;
                        mat[15][3] = 2;
                        mat[15][4] = 2;
                        return 2;
                    }
                    else if((mat[15][4]==1)&&(mat[15][6]==1))
                    {
                        mat[15][4] = 2;
                        mat[15][5] = 2;
                        mat[15][6] = 2;
                        return 2;
                    }
                    else if((mat[15][6]==1)&&(mat[15][8]==1))
                    {
                        mat[15][6] = 2;
                        mat[15][7] = 2;
                        mat[15][8] = 2;
                        return 2;
                    }
                    else if((mat[15][8]==1)&&(mat[15][10]==1))
                    {
                        mat[15][8] = 2;
                        mat[15][9] = 2;
                        mat[15][10] = 2;
                        return 2;
                    }
                    else if((mat[15][10]==1)&&(mat[15][12]==1))
                    {
                        mat[15][10] = 2;
                        mat[15][11] = 2;
                        mat[15][12] = 2;
                        return 2;
                    }
                    else if((mat[15][12]==1)&&(mat[15][14]==1))
                    {
                        mat[15][12] = 2;
                        mat[15][13] = 2;
                        mat[15][14] = 2;
                        return 2;
                    }
                    else if((mat[15][14]==1)&&(mat[15][16]==1))
                    {
                        mat[15][14] = 2;
                        mat[15][15] = 2;
                        mat[15][16] = 2;
                        return 2;
                    }

                }
                //On a plus de barriere alors on passe le tour
                else
                {
                    //Passe le tour
                    return -1;
                }

            }
        }

    }
    else
    {
        //Passe son tour
        return -1;
    }

    return -1;
}
