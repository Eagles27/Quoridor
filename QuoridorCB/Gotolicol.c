#include "header_adrien.h"

void gotoligcol(int lig, int col,int nombreJoueur, t_joueur jugador[4])

{
        COORD mycoord;

        mycoord.X = col;
        mycoord.Y = lig;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

        printf("Nombre de joueurs : %d",nombreJoueur);

        mycoord.X = col;
        mycoord.Y = lig+2;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

        printf("Joueur : %s",jugador[3].nomJ);

        mycoord.X = col;
        mycoord.Y = lig+4;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

        printf("Score partie : %d",jugador[3].scoreP);

        mycoord.X = col;
        mycoord.Y = lig+6;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

        printf("Jeton : %c",jugador[3].jetonJ);

        mycoord.X = col;
        mycoord.Y = lig+8;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

        printf("Barrieres restantes : %d\n\n",jugador[3].barrieresR);


        mycoord.X = 30;
        mycoord.Y = 20;
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}
