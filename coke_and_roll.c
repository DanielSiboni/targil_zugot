

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

  while (change != 0)
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