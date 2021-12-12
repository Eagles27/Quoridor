#include "Header_Pierre.h"


///Fonction renvoyant 1 si la barriere a ete posee sinon -1
///Elle prend en entree des donnees saisies par l'utilisateur via un autre sous programme
int placer_barriere(int tab[17][17], int place[2], char saisie)
{
    ///0. DDV
    int nl=23, nc=3;

    ///Test si la place choisie est libre
    if(!((place[0]%2==1)&&(place[1]%2==1)))
    {
        if((saisie == 'h')||(saisie == 'H'))
        {
            //On test si la barriere sort du plateau
            if(place[1]==0)
            {
                Color(15,0);
                gotoligcol(nl+6, nc);
                Color(15, 10);
                printf("Placement invalide\n");
                Color(15,0);
                system("PAUSE");
                return -1;
            }
            else
            {
                //Sinon on regarde si la case dans la direction adjacente a celle voulue est libre
                if((tab[place[1]][place[0]]==1)&&(tab[place[1]-1][place[0]]==1)&&(tab[place[1]-2][place[0]]==1))
                {
                    //On place 3 barrieres les deux devant les cases + la jonction
                    tab[place[1]][place[0]]=3;
                    tab[place[1]-1][place[0]]=3;
                    tab[place[1]-2][place[0]]=3;
                    return 1;
                }
                else
                {
                    //La case adjacente n'est pas libre donc on renvoie -1 pour que l'utilisateur place une barriere a nouveau
                    Color(15,0);
                    gotoligcol(nl+6, nc);
                    Color(15, 10);
                    printf("Placement invalide\n");
                    Color(15,0);
                    system("PAUSE");
                    return -1;
                }
            }
        }

        else if((saisie == 'b')||(saisie == 'B'))
        {
            //On test si la barriere sort du plateau
            if(place[1]==16)
            {
                Color(15,0);
                gotoligcol(nl+6, nc);
                Color(15, 10);
                printf("Placement invalide\n");
                Color(15,0);
                system("PAUSE");
                return -1;
            }
            else
            {
                //Sinon on regarde si la case dans la direction adjacente a celle voulue est libre
                if((tab[place[1]][place[0]]==1)&&(tab[place[1]+1][place[0]]==1)&&(tab[place[1]+2][place[0]]==1))
                {
                    //On place 3 barrieres les deux devant les cases + la jonction
                    tab[place[1]][place[0]]=3;
                    tab[place[1]+1][place[0]]=3;
                    tab[place[1]+2][place[0]]=3;
                    return 1;
                }
                else
                {
                    //La case adjacente n'est pas libre donc on renvoie -1 pour que l'utilisateur place une barriere a nouveau
                    Color(15,0);
                    gotoligcol(nl+6, nc);
                    Color(15, 10);
                    printf("Placement invalide\n");
                    Color(15,0);
                    system("PAUSE");
                    return -1;
                }
            }
        }

        else if((saisie == 'g')||(saisie == 'G'))
        {
            //On test si la barriere sort du plateau
            if(place[0]==0)
            {
                Color(15,0);
                gotoligcol(nl+6, nc);
                Color(15, 10);
                printf("Placement invalide\n");
                Color(15,0);
                system("PAUSE");
                return -1;
            }
            else
            {
                //Sinon on regarde si la case dans la direction adjacente a celle voulue est libre
                if((tab[place[1]][place[0]]==1)&&(tab[place[1]][place[0]-1]==1)&&(tab[place[1]][place[0]-2]==1))
                {
                    //On place 3 barrieres les deux devant les cases + la jonction
                    tab[place[1]][place[0]]=3;
                    tab[place[1]][place[0]-1]=3;
                    tab[place[1]][place[0]-2]=3;
                    return 1;
                }
                else
                {
                    //La case adjacente n'est pas libre donc on renvoie -1 pour que l'utilisateur place une barriere a nouveau
                    Color(15,0);
                    gotoligcol(nl+6, nc);
                    Color(15, 10);
                    printf("Placement invalide\n");
                    Color(15,0);
                    system("PAUSE");
                    return -1;
                }
            }
        }

        else if((saisie == 'd')||(saisie == 'D'))
        {
            //On test si la barriere sort du plateau
            if(place[0]==16)
            {
                Color(15,0);
                gotoligcol(nl+6, nc);
                Color(15, 10);
                printf("Placement invalide\n");
                Color(15,0);
                system("PAUSE");
                return -1;
            }
            else
            {
                //Sinon on regarde si la case dans la direction adjacente a celle voulue est libre
                if((tab[place[1]][place[0]]==1)&&(tab[place[1]][place[0]+1]==1)&&(tab[place[1]][place[0]+2]==1))
                {
                    //On place 3 barrieres les deux devant les cases + la jonction
                    tab[place[1]][place[0]]=3;
                    tab[place[1]][place[0]+1]=3;
                    tab[place[1]][place[0]+2]=3;
                    return 1;
                }
                else
                {
                    //La case adjacente n'est pas libre donc on renvoie -1 pour que l'utilisateur place une barriere a nouveau
                    Color(15,0);
                    gotoligcol(nl+6, nc);
                    Color(15, 10);
                    printf("Placement invalide\n");
                    Color(15,0);
                    system("PAUSE");
                    return -1;
                }
            }
        }
    }
    ///La place choisie n'est pas libre donc on renvoie -1 pour que l'utilisateur place une barriere a nouveau
    else
    {
        Color(15,0);
        gotoligcol(nl+6, nc);
        Color(15, 10);
        printf("Placement invalide\n");
        Color(15,0);
        system("PAUSE");
        return -1;
    }
    return -1;
}
