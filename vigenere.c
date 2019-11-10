#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string get_user_input(string prompt);

//Shift function declared
int shift(char c);


int main(int argc, string argv[])
{

    // Blank string that will be updated to Success or Failure
    int SF = 1;


    // Checks if a key is supplied
    if (argc == 2)
    {
        // Loops through directory
        for (int i = 1; i < argc; i++)
        {
            // Loops through each char in i-th directory
            for (int j = 0, n = strlen(argv[i]); j < n; j++)
            {
                // Converts char's to ASCII decimals
                int a = (int)argv[i][j];

                // Checks if char, converted to ASCII, is a character
                if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
                {
                    // Success
                    SF = 1;
                    //prints ascii delete
                    //printf("%i\n", a);
                }
                else
                {
                    // Fail
                    SF = 0;
                    // Stops the for loop and exits loops
                    j = 10000;
                    return 1;

                }
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }



    if (SF == 1)
    {


        // Counter for cycling through the KEY
        int count = 0;

        int length = strlen(argv[1]);


        // Prompt User for Message, where plaintext = the user input
        string plaintext = get_user_input("plaintext: ");

        printf("ciphertext: ");
        // Loops through each individual char in "plaintext"
        for (int k = 0, w = strlen(plaintext); k < w; k++)
        {
            // if count >= stringlength of KEY, reset to 0
            if (count == length)
            {
                count = 0;
            }

            // Test, to visualize the count
            //printf("%i", count);

            int KEY = shift(argv[1][count]);
            //printf("%i\n", KEY);


            if (islower(plaintext[k]))
            {
                printf("%c", (plaintext[k] - 'a' + KEY) % 26 + 'a');
                count++;

            }
            else if (isupper(plaintext[k]))
            {
                printf("%c", (plaintext[k] - 'A' + KEY) % 26 + 'A');
                count++;

            }
            else
            {
                printf("%c", plaintext[k]);
            }

        }
        printf("\n");

    }
    else
    {
        printf("Usage: ./caesar\n");
    }






}

// Keep prompting the user for plaintext if they do not type anything
string get_user_input(string prompt)
{
    string n;
    do
    {
        n = get_string("%s", prompt);
    }
    while (n <= 0);
    return n;
}


// Shift Function
int shift(char c)
{
    int KEY = (int) c;
    if (KEY >= 97)
    {
        KEY -= 97 ;
        return KEY;
    }
    else
    {
        KEY -= 65;
        return KEY;
    }
}
