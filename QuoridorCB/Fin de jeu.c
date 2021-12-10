#include "Header_Pierre.h"

int gagner(t_joueur player[4], int* Pnombrejoueur, int tour)
{
    if(*Pnombrejoueur == 2)
    {
        if(player[tour].barrieresR == 0)
        {
            return 2;
        }
        else if((player[tour].coordonneY_org == 0)&&(player[tour].coordonneY == 16))
        {
            return 1;
        }
        else if((player[tour].coordonneY_org == 16)&&(player[tour].coordonneY == 0))
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else{
        if(player[0].coordonneY == 16){
            return 1;
        }
        else if(player[1].coordonneX == 0){
            return 1;
        }
        else if(player[2].coordonneY == 0){
            return 1;
        }
        else if(player[3].coordonneX == 16){
            return 1;
        }
        else if(player[tour].barrieresR == 0){
            return 2;
        }
        else{
            return -1;
        }
    }
    return -1;
}

int gagner_ia(t_joueur player[4], t_IA ia, int tour){
    if((player[0].barrieresR == 0)||(ia.barrieresR==0)){
        return 2;
    }
    else if(ia.coordonneY == 0){
        return 1;
    }
    else if(player[0].coordonneY == 16){
        return 1;
    }
    else{
        return -1;
    }
    return -1;
}
