#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// arg c(argument count) is a int-type variable, arg v(argument vector) is a a array of string 
bool check_key(string s);

int main(int argc, string argv[])
{
    if (argc != 2 || !check_key(argv[1]))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    int key = atoi(argv[1]); // convert string to integer
    string plainText = get_string("PlainText: "); // asking the user to type the message that he want to enchipher
    
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plainText);  i < len ; i++)
    {
        char c = plainText[i];
        
        if (isalpha(c)) // to check if variable c is alphabet
        {
            char modifyCharacter = 'A';
            if (islower(c))
            {
                modifyCharacter = 'a';
            }
            printf("%c", (c - modifyCharacter + key) % 26 + modifyCharacter);// example (p[i] - 'A' + key)%26 + key
        }
        else 
        {
            printf("%c", c);
        }
    }
    printf("\n");
}
bool check_key(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
    
}
