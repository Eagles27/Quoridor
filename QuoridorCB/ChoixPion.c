#include "header_adrien.h"

void choixPion(t_joueur jugador[4],int numeroJ)
{

    srand(time(NULL));

    //8 pions : 0@ 1* 2# 3& 4% 5? 6£ 7$
    int aleaCorresp;


    if(((jugador[numeroJ].jetonJ)!='@')&&(jugador[numeroJ].jetonJ!='*')&&(jugador[numeroJ].jetonJ!='#')&&(jugador[numeroJ].jetonJ!='&')&&(jugador[numeroJ].jetonJ!='%')&&(jugador[numeroJ].jetonJ!='?')&&(jugador[numeroJ].jetonJ!='£')||(jugador[numeroJ].jetonJ!='$')){
        //Si pas de jeton

        //attribution d'un alea à variable



        aleaCorresp=rand()%8;
        printf("C BON JE SUIS RENTRE et alea vaut : %d",aleaCorresp);




        if(aleaCorresp==0){
            jugador[numeroJ].jetonJ='@';
        }

        if(aleaCorresp==1){
            jugador[numeroJ].jetonJ='*';
        }

        if(aleaCorresp==2){
            jugador[numeroJ].jetonJ='#';
        }

        if(aleaCorresp==3){
            jugador[numeroJ].jetonJ='@';
        }

        if(aleaCorresp==4){
            jugador[numeroJ].jetonJ='%';
        }

        if(aleaCorresp==5){
            jugador[numeroJ].jetonJ='?';
        }

        if(aleaCorresp==6){
            jugador[numeroJ].jetonJ='£';
        }

        if(aleaCorresp==7){
            jugador[numeroJ].jetonJ='$';
        }
    }
}
