#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>

#include "tp-bib.h"

#define data "tp-data.txt"
#define maxepreuve 20
#define maxuniv 45
#define MAX_ATH 15
#define MAX_NUMATH 13500

int main() {
    ptr tabju[maxepreuve][maxuniv];
    int numet, numep, numath;
    int sizeuniv = maxuniv, sizeepreuve = maxepreuve;
    char tabuniv[maxuniv][100], tabepreuve[maxepreuve][25], nomath[25], prenomath[25], institution[100], etablissement[100];

    int choice;

    create_tabju(tabju, tabuniv, tabepreuve); 

    Sleep(200);
    Intro();

    MainPage();

    do {

        choice = MainMenu();

        switch (choice) {
            case 1:
                // Add Athlete
                system("cls");
                Header();

                printf("     \033[1m| Sign In A New Athlete To The Games\033[0m                                               \n\n\n");
                printf("     Insert The Number Of \033[0;94mThe University Institution\033[0m : ");
                scanf("%d", &numet);
                while ((numet > (sizeuniv) ) || (numet < 1))
                {
                    printf("\033[A \33[2K \r     Insert The Number Of \033[0;94mThe University Institution\033[0m \033[0;31m( Enter a number from 1 to %d )\033[0m : ", sizeuniv);
                    scanf("%d", &numet);
                }
                
                printf("     Insert The Number Of \033[0;94mThe Event\033[0m : ");
                scanf("%d", &numep);
                while ((numep > (sizeepreuve) ) || (numep < 1))
                {
                    printf("\033[A \33[2K \r     Insert The Number Of \033[0;94mThe Event\033[0m \033[0;31m( Enter a number from 1 to %d )\033[0m : ", sizeepreuve);
                    scanf("%d", &numep);
                }

                printf("\n     Insert The Information Of \033[0;94mThe Athlete\033[0m :                               \n");
                printf("                                        ID : ");
                scanf("%d", &numath);
                while (rechnumath(numath, tabju, sizeepreuve, sizeuniv))
                {
                    printf("\033[A \33[2K \r                  ID \033[0;31m( ID Already Exists )\033[0m : ");
                    scanf("%d", &numath);
                }

                printf("                                First Name : ");
                consumeBuffer();
                readstr(prenomath, 25);
                printf("                                 Last Name : ");
                readstr(nomath, 25);
                

                printf("\n\n     University Institution : %s ", tabuniv[numet-1]);
                printf("\n     Sport Event : %s ", tabepreuve[numep-1]);
                printf("\n     Athlete : %s %s    ID : %05d \n\n", prenomath, nomath, numath);

                addath(numath, nomath, prenomath, numet, numep, tabju, sizeepreuve, sizeuniv);
                printf("     Please, Click \"\033[0;94mENTER\033[0m\" To Return To The Main Menu ...");
                getchar();
                break;
                
            case 2:
                // List Athletes by Institution
                system("cls");
                Header();
                printf("     \033[1m|  Display Athletes Information Of An niversity Institute\033[0m                                               \n\n\n");
                printf("     Please, Insert The Name Of \033[0;94mThe University Institution\033[0m To Display Athletes : ");
                readstr(institution, 100);
                listathet(institution, tabuniv, tabepreuve, tabju, sizeepreuve, sizeuniv);
                printf("\n\n     Click \"\033[0;94mENTER\033[0m\" To Return To The Main Menu ...");
                getchar();
                break;
            case 3:
                // without Athlete
                system("cls");
                Header();
                printf("     \033[1m| Check Wether No Athlete Is Signed In To An Event                                               \033[0m\n\n\n");
                
                printf("     Insert The Number Of \033[0;94mThe Sport Event\033[0m : ");
                scanf("%d", &numep);
                while ((numep > (sizeepreuve) ) || (numep < 1))
                {
                    printf("\033[A \33[2K \r     Insert The Number Of \033[0;94mThe Event\033[0m \033[0;31m( Enter a number from 1 to %d )\033[0m : ", sizeepreuve);
                    scanf("%d", &numep);
                }
                getchar();
                numep--;

                if ( withoutath(tabju, numep, sizeuniv))
                {
                    printf("\n\n     No Athlete Is Registered To The Sport Event \033[0;33m\033[1m%s\033[0m.", tabepreuve[numep]);
                }
                else 
                {
                    int sum = 0;

                    for (int i = 0; i < sizeuniv; i++)
                    {
                        sum = sum + length_llc(tabju[numep][i]);
                    }

                    printf("\n\n     There are \033[0;33m\033[1m%d\033[0m Athletes Registered To The Sport Event \033[0;33m\033[1m%s\033[0m.", sum, tabepreuve[numep]);
                }

                printf("\n\n\n     Please, Click \"\033[0;94mENTER\033[0m\" To Return To The Main Menu ...");
                getchar();
                break;
            case 4:
                // Display Athletes
                listju(tabju, tabuniv, tabepreuve, sizeepreuve, sizeuniv);

                break;
            case 5:
                // Delete uni
                system("cls");
                Header();
                printf("     \033[1m| Delete An Institution From Participating In The Games\033[0m                                               \n\n\n");
                printf("     Please, Insert The Name Of \033[0;94mThe University Institution\033[0m To Delete : ");
                readstr(etablissement, 100);
                printf("\n");
                delet(etablissement, tabuniv, tabju, sizeepreuve, &sizeuniv);
                printf("\n     Please, Click \"\033[0;94mENTER\033[0m\" To Return To The Main Menu ...");
                getchar();
                break;
            case 6:
                // Delete Ath
                do
                {
                    choice = SubMenu2();

                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        Header();
                        printf("     \033[1m| Delete Athletes From Participating In The Games | Delete One Athlete\033[0m                                               \n\n\n");
                        printf("     Insert The Number Of \033[0;94mThe University Institution\033[0m : ");
                        scanf("%d", &numet);
                        while ((numet > (sizeuniv) ) || (numet < 1))
                        {
                            printf("\033[A \33[2K \r     Insert The Number Of \033[0;94mThe University Institution\033[0m \033[0;31m( Enter a number from 1 to %d )\033[0m : ", sizeuniv);
                            scanf("%d", &numet);
                        }
                        numet--;
                        
                        printf("     Insert The Number Of \033[0;94mThe Sport Event\033[0m : ");
                        scanf("%d", &numep);
                        while ((numep > (sizeepreuve) ) || (numep < 1))
                        {
                            printf("\033[A \33[2K \r     Insert The Number Of \033[0;94mThe Event\033[0m \033[0;31m( Enter a number from 1 to %d )\033[0m : ", sizeepreuve);
                            scanf("%d", &numep);
                        }
                        numep--;
             
                        getchar();

                        if ( tabju[numep][numet] == NULL )
                        {
                            printf("\n     \033[0;41mNo Athlete Is Registered To The Sport Event \033[1m%s\033[0m", tabepreuve[numep]);
                            printf("\n     \033[0;41mFrom \033[1m%s\033[0m\033[0;41m !\033[0m", tabuniv[numet]);
                        }
                        else 
                        {

                            printf("\n     \033[0;104m                                                                                                      \033[0m\n");
                            printf("     \033[0;104m\033[1m  %-100s\033[0m\n",tabepreuve[numep]);
                            printf("     \033[0;104m                                                                                                      \033[0m\n");

                            printf("     \033[0;43m                                                                                                      \033[0m\n");
                            printf("     \033[0;43m\033[1m  %-100s\033[0m\n",tabuniv[numet]);
                            printf("     \033[0;43m                                                                                                      \033[0m\n");

                            print_llc(tabju[numep][numet]);

                            printf("\n     Please, Insert The ID Number Of \033[0;94mThe Athlete\033[0m To Delete : ");
                            scanf("%d", &numath);
                            getchar();

                            delath(&tabju[numep][numet], numath);
                        }

                        printf("\n\n\n     Please, Click \"\033[0;94mENTER\033[0m\" To Return To The Menu ...");
                        getchar();
                        break;
                    
                    case 2 :
                        system("cls");
                        Header();
                        printf("     \033[1m| Delete Athletes From Participating In The Games | Delete All Athletes Registered To A Sport Event                                               \n\n\n");
                        
                        printf("     Insert The Number Of \033[0;94mThe Sport Event\033[0m : ");
                        scanf("%d", &numep);
                        while ((numep > (sizeepreuve) ) || (numep < 1))
                        {
                            printf("\033[A \33[2K \r     Insert The Number Of \033[0;94mThe Event\033[0m \033[0;31m( Enter a number from 1 to %d )\033[0m : ", sizeepreuve);
                            scanf("%d", &numep);
                        }
                        getchar();
                        numep--;

                        if ( withoutath(tabju, numep, sizeuniv))
                        {
                            printf("\n\n     \033[0;41mNo Athlete Is Registered To The Sport Event \033[1m%s\033[0m\033[0;41m !\033[0m", tabepreuve[numep]);
                        }
                        else 
                        {
                            for (int i = 0; i < sizeuniv; i++)
                            {
                                tabju[numep][i] = NULL;
                            }

                            printf("\n\n     \033[0;42mThe Athletes Registered To The Sport Event \033[1m%s\033[0m\033[0;42m Have Been Deleted Successfully !\033[0m", tabepreuve[numep]);
                        }

                        printf("\n\n\n     Please, Click \"\033[0;94mENTER\033[0m\" To Return To The Menu ...");
                        getchar();
                        break;

                    default:
                        break;
                    }

                } while (choice != 3);

                break;

            case 7:
                // delemptylines
                system("cls");
                Header();
                printf("     \033[1m| Delete Sport Events With No Registered Athletes\033[0m                                               \n\n");
                pleasewait(3);
                delemptylines(tabju, tabepreuve, &sizeepreuve, sizeuniv);

                printf("\n\n\n     Please, Click \"\033[0;94mENTER\033[0m\" To Return To The Main Menu ...");
                getchar();
                break;
            case 8:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\t To Confirm Your Choice To Exit The Program. Please, Click \033[0;94mEnter\033[0m\n");
                printf("\t\t\tIn Case You Want To Continue, Click On \033[0;94mAny Key\033[0m From Your Keyboard");
                int ch = getch();
                if (ch == 13)
                {
                    break;
                }
                else 
                {
                    choice = 1;
                }
                break;

            default:
                break;
        }
        
    } while (choice != 8);
    
    return 0;
}