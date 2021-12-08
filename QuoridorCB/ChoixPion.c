#include "header_adrien.h"

void choixPion(t_joueur jugador[4],int numeroPlayer)
{
    //Ancien : 8 pions : 0@ 1* 2# 3& 4% 5? 6£ 7$
    //Mi-Nouveau : 8 pions : 0,0x0E 1,0x0F 2,0x02 3,0x04 4,0x05 5,0x06 6,0x9C 7,0x09
    //Nouveau : 11 pions dont 3 de secours : 0,0X40 1,0x2A 2,0x23 3,0x26 4,0x25 5,0x3F 6,0x9C 7,0x24 8,0xF5 9,0x9D 10,0xED

    srand(time(NULL));

    int aleaCorresp=0;

    int PS1=-1;

    int PS2=-1;

    //int ancienAleaCorresp;

    //jugador[numeroPlayer].jetonJ='1';

    //if (jugador[numeroPlayer].jetonJ=='1'){

    //ancienAleaCorresp=aleaCorresp;

    //while(ancienAleaCorresp==aleaCorresp)
    //{

    //printf("Nom debut : %s\n\n",jugador[numeroPlayer].nomJ);
    //printf("Jeton debut : %c\n\n",jugador[numeroPlayer].jetonJ);


    do
    {
        printf("%c, %d", jugador[numeroPlayer].jetonJ, numeroPlayer);
        system("PAUSE");
        aleaCorresp=rand()%8;
        //printf("aleaCorresp : %d\n\n", aleaCorresp);

        //}
        //if(ancienAleaCorresp!=aleaCorresp)
        //{

        if((aleaCorresp==0)&&(jugador[0].jetonJ!=0X40)&&(jugador[1].jetonJ!=0X40)&&(jugador[2].jetonJ!=0X40)&&(jugador[3].jetonJ!=0X40))
        {
            jugador[numeroPlayer].jetonJ=0X40;
            //printf("\nIF 0 ; cara : %c\n\n",jugador[numeroPlayer].jetonJ);
        }

        else if((aleaCorresp==1)&&(jugador[0].jetonJ!=0x2A)&&(jugador[1].jetonJ!=0x2A)&&(jugador[2].jetonJ!=0x2A)&&(jugador[3].jetonJ!=0x2A))
        {
            jugador[numeroPlayer].jetonJ=0x2A;
            //printf("\nIF 1 ; cara : %c\n\n",jugador[numeroPlayer].jetonJ);
        }

        else if((aleaCorresp==2)&&(jugador[0].jetonJ!=0x23)&&(jugador[1].jetonJ!=0x23)&&(jugador[2].jetonJ!=0x23)&&(jugador[3].jetonJ!=0x23))
        {
            jugador[numeroPlayer].jetonJ=0x23;
            //printf("\nIF 2 ; cara : %c\n\n",jugador[numeroPlayer].jetonJ);
        }

        else if((aleaCorresp==3)&&(jugador[0].jetonJ!=0x26)&&(jugador[1].jetonJ!=0x26)&&(jugador[2].jetonJ!=0x26)&&(jugador[3].jetonJ!=0x26))
        {
            jugador[numeroPlayer].jetonJ=0x26;
            //printf("\nIF 3 ; cara : %c\n\n",jugador[numeroPlayer].jetonJ);
        }

        else if((aleaCorresp==4)&&(jugador[0].jetonJ!=0x25)&&(jugador[1].jetonJ!=0x25)&&(jugador[2].jetonJ!=0x25)&&(jugador[3].jetonJ!=0x25))
        {
            jugador[numeroPlayer].jetonJ=0x25;
            //printf("\nIF 4 ; cara : %c\n\n",jugador[numeroPlayer].jetonJ);
        }

        else if((aleaCorresp==5)&&(jugador[0].jetonJ!=0x3F)&&(jugador[1].jetonJ!=0x3F)&&(jugador[2].jetonJ!=0x3F)&&(jugador[3].jetonJ!=0x3F))
        {
            jugador[numeroPlayer].jetonJ=0x3F;
            //printf("\nIF 5 ; cara : %c\n\n",jugador[numeroPlayer].jetonJ);
        }

        else if((aleaCorresp==6)&&(jugador[0].jetonJ!=0x9C)&&(jugador[1].jetonJ!=0x9C)&&(jugador[2].jetonJ!=0x9C)&&(jugador[3].jetonJ!=0x9C))
        {
            jugador[numeroPlayer].jetonJ=0x9C;
            //printf("\nIF 6 ; cara : %c\n\n",jugador[numeroPlayer].jetonJ);
        }

        else if((aleaCorresp==7)&&(jugador[0].jetonJ!=0x24)&&(jugador[1].jetonJ!=0x24)&&(jugador[2].jetonJ!=0x24)&&(jugador[3].jetonJ!=0x24))
        {
            jugador[numeroPlayer].jetonJ=0x24;
            //printf("\nIF 7 ; cara : %c\n\n",jugador[numeroPlayer].jetonJ);
        }
        else if(PS1==-1)
        {
            jugador[numeroPlayer].jetonJ=0xF5;
            PS1=1;
        }
        else if(PS2==-1)
        {
            jugador[numeroPlayer].jetonJ=0x9D;
            PS2=1;
        }
        else
        {
            jugador[numeroPlayer].jetonJ=0xED;
        }

        //printf("%s joue avec %c\n\n",jugador[numeroPlayer].nomJ,jugador[numeroPlayer].jetonJ);

    }
    while(((jugador[numeroPlayer].jetonJ=='1')||((jugador[0].jetonJ==jugador[1].jetonJ)||(jugador[0].jetonJ==jugador[2].jetonJ)||(jugador[0].jetonJ==jugador[3].jetonJ)||(jugador[1].jetonJ==jugador[2].jetonJ)||(jugador[1].jetonJ==jugador[3].jetonJ)||(jugador[2].jetonJ==jugador[3].jetonJ))));

}

//RIP
//if(((jugador[numeroJ].jetonJ)!='@')&&(jugador[numeroJ].jetonJ!='*')&&(jugador[numeroJ].jetonJ!='#')&&(jugador[numeroJ].jetonJ!='&')&&(jugador[numeroJ].jetonJ!='%')&&(jugador[numeroJ].jetonJ!='?')&&(jugador[numeroJ].jetonJ!='£')||(jugador[numeroJ].jetonJ!='$')){
