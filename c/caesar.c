#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//accept a single command-line arguement, a non-negative integer
int main(int argc, string argv[])
{
    //check for incorrect number of input, if incorrect return 1
    if (argc != 2)
    {
        printf("Please enter one value \n");
        return 1;
    }
    
    printf("plaintext: ");
    string s = get_string();
    
    char cipher_array[strlen(s)];
    //loop through string to very each letter
    for (int i = 0, n = strlen(s); i < n; i++)
    {
         
         //if the array element is alphabetic
         if (isalpha(s[i]))
         {
             //if the letter is uppercase, shift uppercase letter
             if (isupper(s[i]))
             {

                  cipher_array[i] = (((s[i] + atoi(argv[1]) -'A')) % 26) + 'A';
                 
             }
             else if (islower(s[i])) //if the letter is lowercase, shift lowercase letter
             
             {
                //shift letter by provided key.  
                cipher_array[i] = (((s[i] + atoi(argv[1]) - 'a')) % 26) + 'a';
             }
             
         }
         else  //if the character is not alphabetic, preserve the character - do not shift
             {
                 cipher_array[i] = s[i];
             }
             
        //terminate string with null character
        cipher_array[strlen(s)] = '\0';
    }
    
    printf("ciphertext: %s", cipher_array);
    printf("\n");
    return 0;
    
}