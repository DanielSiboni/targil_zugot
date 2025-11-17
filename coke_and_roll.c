/*------------------------------------------------------
* Filename: coke_and_roll.c
* Description:
* Author:
-------------------------------------------------------*/

#include <stdio.h>

#define TEN_AGOROT_TO_SHEKEL ((float)1/10)
#define HALF_SHEKEL_TO_SHEKEL ((float)1/2)
#define TWO_SHEKEL_TO_SHEKEL (2)
#define FIVE_SHEKEL_TO_SHEKEL (5)
#define TEN_SHEKEL_TO_SHEKEL (10)
#define COLA ('C')
#define DIAT_COLA ('D')
#define ORANGEADE ('O')
#define SCHWEPPES ('S')
#define GRAPES ('G')
#define WATER ('W')
#define UNDEFINED_DRINK ('0')

char select_drink_input();
float getDrinkCost(char drink);
int handlePayment(char chosenDrink);
void print_user_choices();
void print_change(float change);

int main() {
    char user_ans = '0';
    while (user_ans != 'E'){
        print_user_choices();
        user_ans = select_drink_input();
        if (user_ans == UNDEFINED_DRINK){
            continue;
        }
        printf("The price of the drink is %f NIS\n", getDrinkCost(user_ans));
        handlePayment(user_ans);
    }
    return 0;
}

/*------------------------------------------------------
* Function Name - getDrinkCost
*
* Function Purpose - get the cost of the drink
*
* Parameters –  drink: char, a drink
*
* Return Values - float, the cost of the chosen drink
*
* Author - Daniel Siboni
-------------------------------------------------------*/
float getDrinkCost(char drink) {
    switch (drink)
    {
    case COLA:
        return 5.2;
    case DIAT_COLA:
        return 7.2;
    case ORANGEADE:
        return 3.4;
    case SCHWEPPES:
        return 4.5;
    case GRAPES:
        return 3.5;
    case WATER:
        return 2.5;
    default:
        return 0;
    }
}

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
int handlePayment(char chosenDrink)
{
    unsigned int tenAgorot = 0, halfShekel = 0, shekel = 0, twoShekel = 0, fiveShekel = 0, tenShekel = 0;
    printf("Enter amount of 0.1 NIS: ");
    if (scanf("%u", &tenAgorot) != 1)
        return 1;
    printf("Enter amount of 0.5 NIS: ");
    if (scanf("%u", &halfShekel) != 1)
        return 1;
    printf("Enter amount of 1 NIS: ");
    if (scanf("%u", &shekel) != 1)
        return 1;
    printf("Enter amount of 2 NIS: ");
    if (scanf("%u", &twoShekel) != 1)
        return 1;
    printf("Enter amount of 5 NIS: ");
    if (scanf("%u", &fiveShekel) != 1)
        return 1;
    printf("Enter amount of 10 NIS: ");
    if (scanf("%u", &tenShekel) != 1)
        return 1;

    float sumOfPayment = (TEN_AGOROT_TO_SHEKEL * tenAgorot) + (HALF_SHEKEL_TO_SHEKEL * halfShekel) + shekel + (TWO_SHEKEL_TO_SHEKEL * twoShekel) + (FIVE_SHEKEL_TO_SHEKEL * fiveShekel) + (TEN_SHEKEL_TO_SHEKEL * tenShekel);

    printf("The machine received payment of %.2f NIS\n\n", sumOfPayment);

    if(chosenDrink == COLA && tenAgorot == 1 && twoShekel == 3 && fiveShekel == 3 && tenShekel == 7)
        printf("Special agent, please respond!!!\n\n");

    printf("%f \n", sumOfPayment);
    printf("%f\n", getDrinkCost(chosenDrink));
    float salesChange = sumOfPayment - getDrinkCost(chosenDrink);
    printf("%f\n", salesChange);

    //print_change(salesChange);
    
    return 0;
}

/*------------------------------------------------------
* Function Name - [print_user_choices]
*
* Function Purpose - [prints the choices to the screen]
*
* Parameters –  NONE
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
void print_user_choices()
{
  printf("Please select the drink you would like to order:\n\n");

  printf("press 'C' for Coca-Cola\n\n");
  printf("press 'D' for Diet-Cola\n\n");
  printf("press 'O' for Orangeade\n\n");
  printf("press 'S' for Schweppes\n\n");
  printf("press 'G' for Grape juice\n\n");
  printf("press 'W' for Mineral water\n\n");
}

/*------------------------------------------------------
* Function Name - [print_change]
*
* Function Purpose - [gives back the total change in the available coins(prints it to the screen)]
*
* Parameters –  [float change]
*
* Return Values - NONE
*
* Author - [Kiran Kabaso]
-------------------------------------------------------*/
void print_change(float change)
{
  // possible coins: 10, 5, 2, 1, 0.5, 0.1
  int count_coin_10 = 0;
  int count_coin_5 = 0;
  int count_coin_2 = 0;
  int count_coin_1 = 0;
  int count_coin_05 = 0;
  int count_coin_01 = 0;

  printf("%f\n", change);

  while (change > 0)
  {
    if (change >= 10)
    {
      ++count_coin_10;
      change -= 10;
    }
    else if (change >= 5)
    {
      ++count_coin_5;
      change -= 5;
    }
    else if (change >= 2)
    {
      ++count_coin_2;
      change -= 2;
    }
    else if (change >= 1)
    {
      ++count_coin_1;
      change -= 1;
    }
    else if (change >= 0.5)
    {
      ++count_coin_05;
      change -= 0.5;
    }
    else if (change >= 0.1)
    {
      ++count_coin_01;
      change -= 0.1;
    }
    else{
        printf("!");
    }
  }

  // print the change
  printf("Machine returned %d coins of 0.1 NIS\n", count_coin_01);
  printf("Machine returned %d coins of 0.5 NIS\n", count_coin_05);
  printf("Machine returned %d coins of 1 NIS\n", count_coin_1);
  printf("Machine returned %d coins of 2 NIS\n", count_coin_2);
  printf("Machine returned %d coins of 5 NIS\n", count_coin_5);
  printf("Machine returned %d coins of 10 NIS\n", count_coin_10);

  return;
}

/*------------------------------------------------------
* Function Name - select_drink_input.c
* Function Purpose -  Check the choice of the drink of the user.
* Parameters – 
* Return Values - A char represents the choice of drink of the user.
* Author - Stav Menashe.
-------------------------------------------------------*/
char select_drink_input(){
    char user_input;
    int check_input;
    check_input = scanf("%c", &user_input);

    if (check_input != 1 && user_input != COLA && user_input != DIAT_COLA && user_input != ORANGEADE &&
        user_input != SCHWEPPES && user_input != GRAPES && user_input != WATER){
        printf("No such drink, try again!\n");
        return '0';
    }
    return user_input;
}