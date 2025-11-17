

#include <stdio.h>

#define TEN_AGOROT_TO_SHEKEL ((float)0.1)
#define HALF_SHEKEL_TO_SHEKEL ((float)0.5)
#define TWO_SHEKEL_TO_SHEKEL (2)
#define FIVE_SHEKEL_TO_SHEKEL (5)
#define TEN_SHEKEL_TO_SHEKEL (10)


/*------------------------------------------------------
* Function Name - handlePayment
*
* Function Purpose - handle the costumer payment procces
*
* Parameters –  chosenDrink: char, the user chosen drink
*
* Return Values - 1 for failiure, 0 on succes
*
* Author - Daniel Siboni
-------------------------------------------------------*/
int handlePayment(char chosenDrink) {
    unsigned int tenAgorot = 0, halfShekel = 0, shekel = 0, twoShekel = 0, fiveShekel = 0, tenShekel = 0;
    printf("Enter amount of 0.1 NIS: ");
    if(scanf("%u", &tenAgorot) != 1)
        return 1;
    printf("Enter amount of 0.5 NIS: ");
    if(scanf("%u", &halfShekel) != 1)
        return 1;
    printf("Enter amount of 1 NIS: ");
    if(scanf("%u", &shekel) != 1)
        return 1;
    printf("Enter amount of 2 NIS: ");
    if(scanf("%u", &twoShekel) != 1)
        return 1;
    printf("Enter amount of 5 NIS: ");
    if(scanf("%u", &fiveShekel) != 1)
        return 1;
    printf("Enter amount of 10 NIS: ");
    if(scanf("%u", &tenShekel) != 1)
        return 1;

    float sumOfPayment = (TEN_AGOROT_TO_SHEKEL * tenAgorot) 
                        + (HALF_SHEKEL_TO_SHEKEL * halfShekel)
                        + shekel
                        + (TWO_SHEKEL_TO_SHEKEL * twoShekel)
                        + (FIVE_SHEKEL_TO_SHEKEL * fiveShekel)
                        + (TEN_SHEKEL_TO_SHEKEL * tenShekel);

    printf("The machine received payment of %.2f NIS\n\n", sumOfPayment);

    if(chosenDrink == COLA && twoShekel == 3 && fiveShekel == 3 && tenShekel == 7)
        printf("Special agent, please respond!!!\n\n")
    
    return 0;
}