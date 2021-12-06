#include "Header_Pierre.h"

int placer_barriere(int tab[17][17], int place[2], char saisie)
{
    if(!((place[0]%2==1)&&(place[1]%2==1)))
    {
        if((saisie == 'h')||(saisie == 'H'))
        {
            if(place[1]==0)
            {
                printf("Placement invalide\n");
                system("PAUSE");
                return -1;
            }
            else
            {
                if((tab[place[1]][place[0]]==1)&&(tab[place[1]-1][place[0]]==1)&&(tab[place[1]-2][place[0]]==1))
                {
                    tab[place[1]][place[0]]=3;
                    tab[place[1]-1][place[0]]=3;
                    tab[place[1]-2][place[0]]=3;
                    return 1;
                }
                else
                {
                    printf("Placement invalide\n");
                    system("PAUSE");
                    return -1;
                }
            }
        }

        else if((saisie == 'b')||(saisie == 'B'))
        {
            if(place[1]==16)
            {
                printf("Placement invalide\n");
                system("PAUSE");
                return -1;
            }
            else
            {
                if((tab[place[1]][place[0]]==1)&&(tab[place[1]+1][place[0]]==1)&&(tab[place[1]+2][place[0]]==1))
                {
                    tab[place[1]][place[0]]=3;
                    tab[place[1]+1][place[0]]=3;
                    tab[place[1]+2][place[0]]=3;
                    return 1;
                }
                else
                {
                    printf("Placement invalide\n");
                    system("PAUSE");
                    return -1;
                }
            }
        }

        else if((saisie == 'g')||(saisie == 'G'))
        {
            if(place[0]==0)
            {
                printf("Placement invalide\n");
                system("PAUSE");
                return -1;
            }
            else
            {
                if((tab[place[1]][place[0]]==1)&&(tab[place[1]][place[0]-1]==1)&&(tab[place[1]][place[0]-2]==1))
                {
                    tab[place[1]][place[0]]=3;
                    tab[place[1]][place[0]-1]=3;
                    tab[place[1]][place[0]-2]=3;
                    return 1;
                }
                else
                {
                    printf("Placement invalide\n");
                    system("PAUSE");
                    return -1;
                }
            }
        }

        else if((saisie == 'd')||(saisie == 'D'))
        {
            if(place[0]==16)
            {
                printf("Placement invalide\n");
                system("PAUSE");
                return -1;
            }
            else
            {
                if((tab[place[1]][place[0]]==1)&&(tab[place[1]][place[0]+1]==1)&&(tab[place[1]][place[0]+2]==1))
                {
                    tab[place[1]][place[0]]=3;
                    tab[place[1]][place[0]+1]=3;
                    tab[place[1]][place[0]+2]=3;
                    return 1;
                }
                else
                {
                    printf("Placement invalide\n");
                    system("PAUSE");
                    return -1;
                }
            }
        }
    }
    else
    {
        printf("Placement invalide\n");
        system("PAUSE");
        return -1;
    }
    return -1;
}
