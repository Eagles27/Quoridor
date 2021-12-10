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
        if((mat[dep_ia[1]-2][dep_ia[0]]==0)||(mat[dep_ia[1]-2][dep_ia[0]]==4))
        {
            dep_ia[1] -= 2;
            return 1;
        }
        //La case est occup�e par un joueur pas le saut est possible
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
            /*else if((mat[dep_ia[1]-1][dep_ia[0]]==1)&&(dep_ia[1] != 16))
            {
                dep_ia[1] -= 2;
                return 1;
            }*/
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
                    //On met une barriere juste avant la ligne d'arriv�e
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
                        mat[15][4] = 2;
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
        //On est pas au bord du plateau � droite et a gauche
        if((dep_ia[0]!=16)&&(dep_ia[0]!= 0))
        {
            //Il n'y a pas de barriere � droite
            if((mat[dep_ia[1]][dep_ia[0]+1]!=2)&&(mat[dep_ia[1]][dep_ia[0]+1]!=3))
            {
                //Il n'a y pas un joueur a droite
                if((mat[dep_ia[1]][dep_ia[0]+2]==0)||(mat[dep_ia[1]][dep_ia[0]+2]==4))
                {
                    dep_ia[0] += 2;
                    return 1;
                }
                //Il y a un joueur a droite
                //Il n'y a pas de barriere qui empeche le saut
                else if(mat[dep_ia[1]][dep_ia[0]+3]==1)
                {
                    dep_ia[0] += 4;
                    return 1;
                }
                //Une barriere gene le passage
                else
                {
                    //On peut faire un decalage en haut
                    if(((mat[dep_ia[1]+2][dep_ia[0]+2]==0)||(mat[dep_ia[1]+2][dep_ia[0]+2]==4))&&(mat[dep_ia[1]+1][dep_ia[0]+2]==1))
                    {
                        dep_ia[0] += 2;
                        dep_ia[1] -= 2;
                        return 1;
                    }
                    //On peut faire un saut en bas
                    else if(((mat[dep_ia[1]+2][dep_ia[0]+2]==0)||(mat[dep_ia[1]+2][dep_ia[0]+2]==4))&&(mat[dep_ia[1]-1][dep_ia[0]+2]==1)&&(dep_ia[1]!=14))
                    {
                        dep_ia[0] += 2;
                        dep_ia[1] += 2;
                        return 1;
                    }
                    //On met une barriere
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
                            //On met une barriere juste avant la ligne d'arriv�e
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
                                mat[15][4] = 2;
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
            //Il y a une barriere a droite
            //Il n'y a pas de barriere a gauche
            else if((mat[dep_ia[1]][dep_ia[0]-1]!=2)&&(mat[dep_ia[1]][dep_ia[0]-1]!=3))
            {
                //Il n'y a pas de joueur a gauche
                if((mat[dep_ia[1]][dep_ia[0]-2]==0)||(mat[dep_ia[1]][dep_ia[0]-2]==4))
                {
                    dep_ia[0] -= 2;
                    return 1;
                }
                //Il y a un joueur a gauche mais pas de barriere
                else if(mat[dep_ia[1]][dep_ia[0]-3]==1)
                {
                    dep_ia[0] -= 4;
                    return 1;
                }
                else
                {
                    //Le decalage en haut est possible
                    if(mat[dep_ia[1]-1][dep_ia[0]-2]==1)
                    {
                        dep_ia[0] -= 2;
                        dep_ia[1] -= 2;
                        return 1;
                    }
                    //Le decalage en bas est possible
                    else if((mat[dep_ia[1]+1][dep_ia[0]-2]==1)&&(dep_ia[1]!=16))
                    {
                        dep_ia[0] -= 2;
                        dep_ia[1] += 2;
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
                            //On met une barriere juste avant la ligne d'arriv�e
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
                                mat[15][4] = 2;
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
            ///Attention j'exclu le cas ou un joueur se trouve derriere l'ia
            //On ne peut pas se decaler alors on recule
            else if((dep_ia[1]!=16)&&((mat[dep_ia[1]+2][dep_ia[0]]==0)||(mat[dep_ia[1]+2][dep_ia[0]]==4)))
            {
                dep_ia[1] += 2;
                return 1;
            }
        }
        //On est  au bord du plateau � gauche
        else if(dep_ia[0]==0)
        {
            //Il n'y a pas de barriere � droite
            if((mat[dep_ia[1]][dep_ia[0]-1]!=2)&&(mat[dep_ia[1]][dep_ia[0]-1]!=3))
            {
                dep_ia[0] += 2;
                return 1;
            }
            //Il y a une barriere a droite mais on peut reculer
            /*else if((mat[dep_ia[1]-2][dep_ia[0]]==0)&&(mat[dep_ia[1]-2][dep_ia[0]]==4)&&(mat[dep_ia[1]-1][dep_ia[0]]==1))
            {
                dep_ia[0] -= 2;
                return 1;
            }*/
            //Sinon on place une barriere
            else
            {

                //Si il reste des barrieres
                if(ia.barrieresR !=0)
                {
                    //On place une barriere devant le joueur
                    //Si le joueur est au bord a gauche et qu'il n'y a pas deja une barriere devant
                    if((player[0].coordonneX == 0)&&(mat[player[0].coordonneY+1][player[0].coordonneX]==1)&&(mat[player[0].coordonneY+1][player[0].coordonneX+2]==1))
                    {
                        mat[player[0].coordonneY+1][player[0].coordonneX] = 2;
                        mat[player[0].coordonneY+1][player[0].coordonneX+1] = 3;
                        mat[player[0].coordonneY+1][player[0].coordonneX+2] = 2;
                        return 2;

                    }
                    //Si le joueur est au bord a droite et qu'il n'y a pas deja une barriere devant
                    else if((player[0].coordonneX == 16)&&(mat[player[0].coordonneY+1][player[0].coordonneX]==1)&&(mat[player[0].coordonneY+1][player[0].coordonneX-2]==1))
                    {
                        mat[player[0].coordonneY+1][player[0].coordonneX] = 2;
                        mat[player[0].coordonneY+1][player[0].coordonneX-1] = 3;
                        mat[player[0].coordonneY+1][player[0].coordonneX-2] = 2;
                        return 2;
                    }
                    //Si le joueur n'a pas de barriere devant lui et en bas a gauche
                    else if((mat[player[0].coordonneY+1][player[0].coordonneX]==1)&&(mat[player[0].coordonneY+1][player[0].coordonneX-2]==1))
                    {
                        mat[player[0].coordonneY+1][player[0].coordonneX] = 2;
                        mat[player[0].coordonneY+1][player[0].coordonneX-1] = 3;
                        mat[player[0].coordonneY+1][player[0].coordonneX-2] = 2;
                        return 2;
                    }
                    //Si le joueur n'a pas de barriere devant lui et en bas a droite
                    else if((mat[player[0].coordonneY+1][player[0].coordonneX]==1)&&(mat[player[0].coordonneY+1][player[0].coordonneX+2]==1))
                    {
                        mat[player[0].coordonneY+1][player[0].coordonneX] = 2;
                        mat[player[0].coordonneY+1][player[0].coordonneX+1] = 3;
                        mat[player[0].coordonneY+1][player[0].coordonneX+2] = 2;
                        return 2;
                    }
                    //On met une barriere juste avant la ligne d'arriv�e
                    //On test si la premiere place est libre
                    else if((mat[15][0]==1)&&(mat[15][2]==1))
                    {
                        mat[15][0] = 2;
                        mat[15][1] = 3;
                        mat[15][2] = 2;
                        return 2;
                    }
                    //Sinon la suivante...
                    else if((mat[15][2]==1)&&(mat[15][4]==1))
                    {
                        mat[15][2] = 2;
                        mat[15][3] = 3;
                        mat[15][4] = 2;
                        return 2;
                    }
                    else if((mat[15][2]==1)&&(mat[15][4]==1))
                    {
                        mat[15][2] = 2;
                        mat[15][3] = 3;
                        mat[15][4] = 2;
                        return 2;
                    }
                    else if((mat[15][4]==1)&&(mat[15][6]==1))
                    {
                        mat[15][4] = 2;
                        mat[15][5] = 3;
                        mat[15][6] = 2;
                        return 2;
                    }
                    else if((mat[15][6]==1)&&(mat[15][8]==1))
                    {
                        mat[15][6] = 2;
                        mat[15][7] = 3;
                        mat[15][8] = 2;
                        return 2;
                    }
                    else if((mat[15][8]==1)&&(mat[15][10]==1))
                    {
                        mat[15][8] = 2;
                        mat[15][9] = 3;
                        mat[15][10] = 2;
                        return 2;
                    }
                    else if((mat[15][10]==1)&&(mat[15][12]==1))
                    {
                        mat[15][10] = 2;
                        mat[15][11] = 3;
                        mat[15][12] = 2;
                        return 2;
                    }
                    else if((mat[15][12]==1)&&(mat[15][14]==1))
                    {
                        mat[15][12] = 2;
                        mat[15][4] = 3;
                        mat[15][14] = 2;
                        return 2;
                    }
                    //On place pas de derniere barriere sinon plus possible de gagner
                    /*else if((mat[15][14]==1)&&(mat[15][16]==1))
                    {
                        mat[15][14] = 2;
                        mat[15][15] = 3;
                        mat[15][16] = 2;
                        return 2;
                    }*/

                }
                //On a plus de barriere alors on passe le tour
                else
                {
                    //Passe le tour
                    return -1;
                }
            }
        }
        //On est au bord du plateau a droite
        else if(dep_ia[0]==16)
        {
            //On peut se decaler a gauche (il n'y a pas de barriere)
            if(((mat[dep_ia[1]][dep_ia[0]-2]==0)||(mat[dep_ia[1]][dep_ia[0]-2]==4))&&(mat[dep_ia[1]][dep_ia[0]-1]==1))
            {
                dep_ia[0] -= 2;
                return 1;
            }
            //Il y a un joueur a gauche mais de pas barriere
            else if((mat[dep_ia[1]][dep_ia[0]-3]==1)&&(mat[dep_ia[1]][dep_ia[0]-1]==2))
            {
                dep_ia[0] -= 4;
                return 1;
            }
            //On ne peut pas sauter mais decalage en haut
            else if(((mat[dep_ia[1]-2][dep_ia[0]-2]==0)||(mat[dep_ia[1]-2][dep_ia[0]-2]==4))&&(mat[dep_ia[1]-1][dep_ia[0]-2]==1)&&(mat[dep_ia[1]][dep_ia[0]-1]==2))
            {
                dep_ia[0] -= 2;
                dep_ia[1] -= 2;
                return 1;
            }
            //Decalage en bas
            else if(((mat[dep_ia[1]+2][dep_ia[0]-2]==0)||(mat[dep_ia[1]+2][dep_ia[0]-2]==4))&&(mat[dep_ia[1]+1][dep_ia[0]-2]==1)&&(dep_ia[1]!=16)&&(mat[dep_ia[1]][dep_ia[0]-1]==2))
            {
                dep_ia[0] -= 2;
                dep_ia[1] += 2;
                return 1;
            }
            //On ne peut pas se decaler alors on recule
            ///Je ne traite pas le cas ou il y a un pion derriere l'ia
            /*else if(((mat[dep_ia[1]-2][dep_ia[0]]==0)||(mat[dep_ia[1]-2][dep_ia[0]]==4))&&(mat[dep_ia[1]-1][dep_ia[0]]==1))
            {
                dep_ia[1] += 2;
                return 1;
            }*/
            //On place une nbarriere
            else
            {
                //Si il reste des barrieres
                if(ia.barrieresR !=0)
                {
                    //On place une barriere devant le joueur
                    //Si le joueur est au bord a gauche et qu'il n'y a pas deja une barriere devant
                    if((player[0].coordonneX == 0)&&(mat[player[0].coordonneY+1][player[0].coordonneX]==1)&&(mat[player[0].coordonneY+1][player[0].coordonneX+2]==1))
                    {
                        mat[player[0].coordonneY+1][player[0].coordonneX] = 2;
                        mat[player[0].coordonneY+1][player[0].coordonneX+1] = 3;
                        mat[player[0].coordonneY+1][player[0].coordonneX+2] = 2;
                        return 2;

                    }
                    //Si le joueur est au bord a droite et qu'il n'y a pas deja une barriere devant
                    else if((player[0].coordonneX == 16)&&(mat[player[0].coordonneY+1][player[0].coordonneX]==1)&&(mat[player[0].coordonneY+1][player[0].coordonneX-2]==1))
                    {
                        mat[player[0].coordonneY+1][player[0].coordonneX] = 2;
                        mat[player[0].coordonneY+1][player[0].coordonneX-1] = 3;
                        mat[player[0].coordonneY+1][player[0].coordonneX-2] = 2;
                        return 2;
                    }
                    //Si le joueur n'a pas de barriere devant lui et en bas a gauche
                    else if((mat[player[0].coordonneY+1][player[0].coordonneX]==1)&&(mat[player[0].coordonneY+1][player[0].coordonneX-2]==1))
                    {
                        mat[player[0].coordonneY+1][player[0].coordonneX] = 2;
                        mat[player[0].coordonneY+1][player[0].coordonneX-1] = 3;
                        mat[player[0].coordonneY+1][player[0].coordonneX-2] = 2;
                        return 2;
                    }
                    //Si le joueur n'a pas de barriere devant lui et en bas a droite
                    else if((mat[player[0].coordonneY+1][player[0].coordonneX]==1)&&(mat[player[0].coordonneY+1][player[0].coordonneX+2]==1))
                    {
                        mat[player[0].coordonneY+1][player[0].coordonneX] = 2;
                        mat[player[0].coordonneY+1][player[0].coordonneX+1] = 3;
                        mat[player[0].coordonneY+1][player[0].coordonneX+2] = 2;
                        return 2;
                    }
                    //On met une barriere juste avant la ligne d'arriv�e
                    //On test si la premiere place est libre
                    else if((mat[15][0]==1)&&(mat[15][2]==1))
                    {
                        mat[15][0] = 2;
                        mat[15][1] = 3;
                        mat[15][2] = 2;
                        return 2;
                    }
                    //Sinon la suivante...
                    else if((mat[15][2]==1)&&(mat[15][4]==1))
                    {
                        mat[15][2] = 2;
                        mat[15][3] = 3;
                        mat[15][4] = 2;
                        return 2;
                    }
                    else if((mat[15][2]==1)&&(mat[15][4]==1))
                    {
                        mat[15][2] = 2;
                        mat[15][3] = 3;
                        mat[15][4] = 2;
                        return 2;
                    }
                    else if((mat[15][4]==1)&&(mat[15][6]==1))
                    {
                        mat[15][4] = 2;
                        mat[15][5] = 3;
                        mat[15][6] = 2;
                        return 2;
                    }
                    else if((mat[15][6]==1)&&(mat[15][8]==1))
                    {
                        mat[15][6] = 2;
                        mat[15][7] = 3;
                        mat[15][8] = 2;
                        return 2;
                    }
                    else if((mat[15][8]==1)&&(mat[15][10]==1))
                    {
                        mat[15][8] = 2;
                        mat[15][9] = 3;
                        mat[15][10] = 2;
                        return 2;
                    }
                    else if((mat[15][10]==1)&&(mat[15][12]==1))
                    {
                        mat[15][10] = 2;
                        mat[15][11] = 3;
                        mat[15][12] = 2;
                        return 2;
                    }
                    else if((mat[15][12]==1)&&(mat[15][14]==1))
                    {
                        mat[15][12] = 2;
                        mat[15][4] = 3;
                        mat[15][14] = 2;
                        return 2;
                    }
                    //On place pas de derniere barriere sinon plus possible de gagner
                    /*else if((mat[15][14]==1)&&(mat[15][16]==1))
                    {
                        mat[15][14] = 2;
                        mat[15][15] = 3;
                        mat[15][16] = 2;
                        return 2;
                    }*/

                }
                //On a plus de barriere alors on passe le tour
                else
                {
                    //Passe le tour
                    return -1;
                }
            }
        }
        //Si on a pas pu se deplacer on place une barriere
        else
        {
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            //Si il reste des barrieres
            if(ia.barrieresR !=0)
            {
                //On place une barriere devant le joueur
                //Si le joueur est au bord a gauche et qu'il n'y a pas deja une barriere devant
                if((player[0].coordonneX == 0)&&(mat[player[0].coordonneY+1][player[0].coordonneX]==1)&&(mat[player[0].coordonneY+1][player[0].coordonneX+2]==1))
                {
                    mat[player[0].coordonneY+1][player[0].coordonneX] = 2;
                    mat[player[0].coordonneY+1][player[0].coordonneX+1] = 3;
                    mat[player[0].coordonneY+1][player[0].coordonneX+2] = 2;
                    return 2;

                }
                //Si le joueur est au bord a droite et qu'il n'y a pas deja une barriere devant
                else if((player[0].coordonneX == 16)&&(mat[player[0].coordonneY+1][player[0].coordonneX]==1)&&(mat[player[0].coordonneY+1][player[0].coordonneX-2]==1))
                {
                    mat[player[0].coordonneY+1][player[0].coordonneX] = 2;
                    mat[player[0].coordonneY+1][player[0].coordonneX-1] = 3;
                    mat[player[0].coordonneY+1][player[0].coordonneX-2] = 2;
                    return 2;
                }
                //Si le joueur n'a pas de barriere devant lui et en bas a gauche
                else if((mat[player[0].coordonneY+1][player[0].coordonneX]==1)&&(mat[player[0].coordonneY+1][player[0].coordonneX-2]==1))
                {
                    mat[player[0].coordonneY+1][player[0].coordonneX] = 2;
                    mat[player[0].coordonneY+1][player[0].coordonneX-1] = 3;
                    mat[player[0].coordonneY+1][player[0].coordonneX-2] = 2;
                    return 2;
                }
                //Si le joueur n'a pas de barriere devant lui et en bas a droite
                else if((mat[player[0].coordonneY+1][player[0].coordonneX]==1)&&(mat[player[0].coordonneY+1][player[0].coordonneX+2]==1))
                {
                    mat[player[0].coordonneY+1][player[0].coordonneX] = 2;
                    mat[player[0].coordonneY+1][player[0].coordonneX+1] = 3;
                    mat[player[0].coordonneY+1][player[0].coordonneX+2] = 2;
                    return 2;
                }
                //On met une barriere juste avant la ligne d'arriv�e
                //On test si la premiere place est libre
                else if((mat[15][0]==1)&&(mat[15][2]==1))
                {
                    mat[15][0] = 2;
                    mat[15][1] = 3;
                    mat[15][2] = 2;
                    return 2;
                }
                //Sinon la suivante...
                else if((mat[15][2]==1)&&(mat[15][4]==1))
                {
                    mat[15][2] = 2;
                    mat[15][3] = 3;
                    mat[15][4] = 2;
                    return 2;
                }
                else if((mat[15][2]==1)&&(mat[15][4]==1))
                {
                    mat[15][2] = 2;
                    mat[15][3] = 3;
                    mat[15][4] = 2;
                    return 2;
                }
                else if((mat[15][4]==1)&&(mat[15][6]==1))
                {
                    mat[15][4] = 2;
                    mat[15][5] = 3;
                    mat[15][6] = 2;
                    return 2;
                }
                else if((mat[15][6]==1)&&(mat[15][8]==1))
                {
                    mat[15][6] = 2;
                    mat[15][7] = 3;
                    mat[15][8] = 2;
                    return 2;
                }
                else if((mat[15][8]==1)&&(mat[15][10]==1))
                {
                    mat[15][8] = 2;
                    mat[15][9] = 3;
                    mat[15][10] = 2;
                    return 2;
                }
                else if((mat[15][10]==1)&&(mat[15][12]==1))
                {
                    mat[15][10] = 2;
                    mat[15][11] = 3;
                    mat[15][12] = 2;
                    return 2;
                }
                else if((mat[15][12]==1)&&(mat[15][14]==1))
                {
                    mat[15][12] = 2;
                    mat[15][4] = 3;
                    mat[15][14] = 2;
                    return 2;
                }
                //On place pas de derniere barriere sinon plus possible de gagner
                /*else if((mat[15][14]==1)&&(mat[15][16]==1))
                {
                    mat[15][14] = 2;
                    mat[15][15] = 3;
                    mat[15][16] = 2;
                    return 2;
                }*/

            }
            //On a plus de barriere alors on passe le tour
            else
            {
                //Passe le tour
                return -1;
            }
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    }


    else
    {
        //Passe son tour
        return -1;
    }

    return -1;
}
