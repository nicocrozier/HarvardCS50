#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_user_input(string prompt);

int main(void)
{
    // Gets User Input
    float i = get_user_input("hOw MuCh cHaNgE iS OwEd? ");

    // Converts and Rounds to Cents
    int cents = round(i * 100);

    // Counter starts at 0
    int a = 0;

    // Handels Quarters
    while (cents >= 25)
    {
        cents = cents - 25;
        a++;
    }

    // 10 cents
    while (cents >= 10)
    {
        cents = cents - 10;
        a++;
    }

    // 5 Cents
    while (cents >= 5)
    {
        cents = cents - 5;
        a++;
    }

    // One cent
    while (cents >= 1)
    {
        cents -= 1;
        a++;
    }

    printf("%d\n", a);


}

// Prompt function
float get_user_input(string prompt)
{
    float n;
    do
    {
        n = get_float("%s", prompt);
    }
    while (n <= 0);
    return n;
}
