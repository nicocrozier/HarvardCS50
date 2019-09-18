#include <cs50.h>
#include <stdio.h>

int get_user_input(string prompt);

int main(void)
{
    int i = get_user_input("Enter a number between 1 & 8: ");

    //main for loop that prints each row
    int p;
    for (p = 1; p <= i; p++)
    {
        //prints the space between pyramids
        int k;
        for (k = p - i; k < 0; ++k)
        {
            printf(" ");
        }
        //prints the hashes on the left
        int m;
        for (m = 0; m < p; ++m)
        {
            printf("#");
        }

        //prints the spaces between the two pyramids
        printf("  ");

        //prints the hashes on the right
        int o;
        for (o = 0; o < p; ++o)
        {
            printf("#");
        }
        printf("\n");
    }



}

// Prompt function, to get user input
int get_user_input(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);

    }
    while (n <= 0 || n >= 9);
    return n;
}
