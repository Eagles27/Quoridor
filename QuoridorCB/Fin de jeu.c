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
}
