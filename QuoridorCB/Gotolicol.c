#include "header_adrien.h"

void menucote(int lig, int col,int nombreJoueur, t_joueur jugador[4],int numeroPlayer)

{
        COORD mycoord;

        mycoord.X = col;
        mycoord.Y = lig;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

        printf("Nombre de joueurs : %d",nombreJoueur);

        mycoord.X = col;
        mycoord.Y = lig+2;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

        printf("Joueur : %s",jugador[numeroPlayer].nomJ);

        mycoord.X = col;
        mycoord.Y = lig+4;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

        printf("Score partie : %d",jugador[numeroPlayer].scoreP);

        mycoord.X = col;
        mycoord.Y = lig+6;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

        printf("Jeton : %c",jugador[numeroPlayer].jetonJ);

        mycoord.X = col;
        mycoord.Y = lig+8;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

        printf("Barrieres restantes : %d\n\n",jugador[numeroPlayer].barrieresR);


        mycoord.X = 30;
        mycoord.Y = 20;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}
