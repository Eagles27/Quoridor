#include "Header_Pierre.h"

int gagner(t_joueur player, int* Pnombrejoueur)
{
    if(*Pnombrejoueur == 2)
    {
        if(player.barrieresR == 0)
        {
            return 2;
        }
        else if((player.coordonneY_org == 0)&&(player.coordonneY == 16))
        {
            return 1;
        }
        else if((player.coordonneY_org == 16)&&(player.coordonneY_org == 0))
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}
