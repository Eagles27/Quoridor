#include "header_adrien.h"

void choixPion(t_joueur jugador[4],int numeroPlayer)
{
    //8 pions : 0@ 1* 2# 3& 4% 5? 6£ 7$

    srand(time(NULL));

    int aleaCorresp;

    jugador[numeroPlayer].jetonJ='1';

    if (jugador[numeroPlayer].jetonJ=='1'){

        aleaCorresp=rand()%8;

        if(aleaCorresp==0){
            jugador[numeroPlayer].jetonJ='@';
        }

        if(aleaCorresp==1){
            jugador[numeroPlayer].jetonJ='*';
        }

        if(aleaCorresp==2){
            jugador[numeroPlayer].jetonJ='#';
        }

        if(aleaCorresp==3){
            jugador[numeroPlayer].jetonJ='@';
        }

        if(aleaCorresp==4){
            jugador[numeroPlayer].jetonJ='%';
        }

        if(aleaCorresp==5){
            jugador[numeroPlayer].jetonJ='?';
        }

        if(aleaCorresp==6){
            jugador[numeroPlayer].jetonJ='£';
        }

        if(aleaCorresp==7){
            jugador[numeroPlayer].jetonJ='$';
        }
    }
}

//RIP
//if(((jugador[numeroJ].jetonJ)!='@')&&(jugador[numeroJ].jetonJ!='*')&&(jugador[numeroJ].jetonJ!='#')&&(jugador[numeroJ].jetonJ!='&')&&(jugador[numeroJ].jetonJ!='%')&&(jugador[numeroJ].jetonJ!='?')&&(jugador[numeroJ].jetonJ!='£')||(jugador[numeroJ].jetonJ!='$')){
