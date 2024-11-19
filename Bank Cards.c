#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char CardT;
int choice, CardNum, cpt, oper, temp, sum, d;
bool Q1 = false;
bool Q2 = false;

int main()
{
    /*---------Desplaying the menu--------- */
    do
    {
        printf("-------------------- MENU ----------------------\n-  1 : Enter Card Type : A, B, C);             -\n-  2 : Enter and check of the card number ---> -\n-  A (8 digits) ; B (7 digits) ; C (6 digits)  -\n-  3 : Checking the card validity              -\n-  4 : Exit                                    -\n------------------------------------------------\nWhat is your choice ---> :   ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Q1 = true;
            do
            {
                printf("Card Type : A (8 Digits) ; B (7 Digits); C (6 Digits) : ");
                scanf(" %c", &CardT);
            } while (CardT != 'A' && CardT != 'B' && CardT != 'C');
            break;

        case 2:
            if (Q1 == false)
            {
                printf("Please choose a Card Type in first\n");
            }
            else
            {
                Q2 = true;
                int sauv;
                switch (CardT)
                {
                case 'A':
                    do
                    {
                        printf("Please enter your card number : ");
                        scanf("%d", &CardNum);
                        sauv = CardNum;
                        cpt = 0;
                        while (sauv != 0)
                        {
                            cpt++;
                            sauv = sauv / 10;
                        }

                    } while (cpt != 8);
                    break;

                case 'B':
                    do
                    {
                        printf("Please enter your card number : ");
                        scanf("%d", &CardNum);
                        sauv = CardNum;
                        cpt = 0;
                        while (sauv != 0)
                        {
                            cpt++;
                            sauv = sauv / 10;
                        }

                    } while (cpt != 7);
                    break;

                case 'C':
                    do
                    {
                        printf("Please enter your card number : ");
                        scanf("%d", &CardNum);
                        sauv = CardNum;
                        cpt = 0;
                        while (sauv != 0)
                        {
                            cpt++;
                            sauv = sauv / 10;
                        }
                    } while (cpt != 6);

                    break;
                }
            }
            break;

        case 3:
            if (Q1 == false || Q2 == false)
            {
                printf("Process Question 1 and 2 in First\n");
            }
            else
            {
                temp = CardNum;
                sum = 0;
                while (temp != 0)
                {
                    d = ((temp % 100) / 10) *2;
                        while (d != 0)
                        {
                            sum = sum+ d% 10;
                            d = d / 10;
                        }
                    sum = sum + temp % 10;
                    temp= temp /100;
                }
                if (sum % 10 == 0)
                {
                    printf("\n--------------- Card Validity ------------------\nCard type : '%c' with number : %d\nCalculated sum by the method = %d\nThe last digit is 0 ----> Valid Card\n", CardT, CardNum, sum);
                }
                else {
                    printf("\n--------------- Card Validity ------------------\nCard type : '%c' with number : %d\nCalculated sum by the method = %d\nThe last digit is not 0 ----> Invalid Card\n", CardT, CardNum, sum);
                }
            }
            break;

        case 4:
            oper = 1;

            break;

        default:
            printf("\n-------------- Error of choice! ----------------\n");
            break;
        }
    } while (oper == 0);
    printf("\n--------------- End of program -----------------\n");
}
