#include "Header_Pierre.h"

void choixPion(t_joueur jugador[4], int *PnbJ)
{
    //Ancien : 8 pions : 0@ 1* 2# 3& 4% 5? 6£ 7$
    //Mi-Nouveau : 8 pions : 0,0x0E 1,0x0F 2,0x02 3,0x04 4,0x05 5,0x06 6,0x9C 7,0x09
    //Nouveau : 11 pions dont 3 de secours : 0,0X40 1,0x2A 2,0x23 3,0x26 4,0x25 5,0x3F 6,0x9C 7,0x24

    srand(time(NULL));

    char list_car[8] = {0X40, 0x2A, 0x23, 0x26, 0x25, 0x3F, 0x9C, 0x24};
    char list_car1[7];
    char list_car2[6];
    char list_car3[5];
    int index;

    ///1. Choix pion pour 2 joueurs
    if(*PnbJ == 2)
    {
        ///1.1. Attribution alearoire premier jeton
        index = rand()%8;
        jugador[0].jetonJ = list_car[index];

        ///1.1.2. Creation liste sans le premier jeton
        for(int j = 0; j<8; j++)
        {
            if(j < index)
            {
                list_car1[j] = list_car[j];
            }
            else if(j>index)
            {
                list_car1[j-1] = list_car[j];
            }
        }

        ///1.1.3. Choix jeton aleatoire parmis ceux restant
        index = rand()%7;
        jugador[1].jetonJ = list_car1[index];
    }

    ///2. Choix pion pour 4 joueurs
    else
    {
        ///2.1. Attribution alearoire premier jeton
        index = rand()%8;
        jugador[0].jetonJ = list_car[index];

        ///2.1.2. Creation liste sans le premier jeton
        for(int j = 0; j<8; j++)
        {
            if(j < index)
            {
                list_car1[j] = list_car[j];
            }
            else if(j>index)
            {
                list_car1[j-1] = list_car[j];
            }
        }

        ///2.2. Choix jeton aleatoire parmis ceux restant
        index = rand()%7;
        jugador[1].jetonJ = list_car1[index];

        ///2.2.1. Creation liste sans le premier et le deuxieme jeton
        for(int j = 0; j<7; j++)
        {
            if(j < index)
            {
                list_car2[j] = list_car1[j];
            }
            else if(j>index)
            {
                list_car2[j-1] = list_car1[j];
            }
        }

        ///2.3. Choix jeton aleatoire parmis ceux restant
        index = rand()%6;
        jugador[2].jetonJ = list_car2[index];

        ///2.3.1. Creation liste sans le premier, le deuxieme et le troisieme jeton
        for(int j = 0; j<6; j++)
        {
            if(j < index)
            {
                list_car3[j] = list_car2[j];
            }
            else if(j>index)
            {
                list_car3[j-1] = list_car2[j];
            }
        }

        ///2.4. Choix jeton aleatoire parmis ceux restant
        index = rand()%5;
        jugador[3].jetonJ = list_car3[index];
    }
}

///Choix Pion IA

void choix_pion_ia(t_joueur jugador[4], t_IA ia)
{
    ///0. DDV
    int index;
    char list_car[8] = {0X40, 0x2A, 0x23, 0x26, 0x25, 0x3F, 0x9C, 0x24};
    char list_car1[7];

    ///0.1. Initialisation clock
    srand(time(NULL));

    ///1.1. Generation aleatoire du premier jeton
    index = rand()%8;

    ///1.2. Attribution du jeton
    jugador[0].jetonJ = list_car[index];

    ///1.3. Creation liste sans le premier jeton
    for(int j = 0; j<8; j++)
    {
        if(j < index)
        {
            list_car1[j] = list_car[j];
        }
        else if(j>index)
        {
            list_car1[j-1] = list_car[j];
        }
    }

    ///2. Choix jeton aleatoire parmis ceux restant
    index = rand()%7;
    ia.jeton = list_car1[index];
}
