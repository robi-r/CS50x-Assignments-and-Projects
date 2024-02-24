#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("C=%i\n", coins);
    printf("Q=%i\n", quarters);
    printf("D=%i\n", dimes);
    printf("N=%i\n", nickels);
    printf("P=%i\n", pennies);
}

int get_cents(void)
{
    // TODO
    int cents;
    do{
        cents=get_int("Cents:");
    }while(cents<0);
    return cents;
}

int calculate_quarters(int cents)
{
    // TODO
    int q=25,count;
    count=cents/q;
    if(count>=1)
    {
        return count;
    }
    else
    {
     return 0;
    }

}

int calculate_dimes(int cents)
{
    // TODO
    int d=10,count;
    count=cents/d;
    if(count>=1){
        return count;
    }
    else{
   return 0;
    }

}

int calculate_nickels(int cents)
{
    int n=5,count;
    count=cents/n;
    if(count>=1){
        return count;
    }
    else
    {
   return 0;
    }
}

int calculate_pennies(int cents)
{
    // TODO
    int p=1,count;
    count=cents/p;
    if(count>=1){
        return count;
    }
    else
    {
   return 0;
    }

}
