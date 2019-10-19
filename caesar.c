#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string get_user_input(string prompt);


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

                // Checks if char, converted to ASCII, is a number between 0&9
                if (a >= 48 && a <= 57)
                {
                    // Success
                    SF = 1;
                }
                else
                {
                    // Fail
                    SF = 0;
                    // Stops the for loop and exits loops
                    j = 10000;

                }
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Prints Success or Failure
    //printf("%s",SF);





    if (SF == 1)
    {
        // Converts string to int
        int KEY;
        KEY = atoi(argv[1]);



        // Prompt User for Message, where plaintext = the user input
        string plaintext = get_user_input("plaintext: ");

        printf("cipertext: ");
        // Loops through each individual char in "plaintext"
        for (int k = 0, w = strlen(plaintext); k < w; k++)
        {

            if (islower(plaintext[k]))
            {
                printf("%c", (plaintext[k] - 'a' + KEY) % 26 + 'a');

            }
             else if (isupper(plaintext[k]))
            {
                printf("%c", (plaintext[k] - 'A' + KEY) % 26 + 'A');

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
