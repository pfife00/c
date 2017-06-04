#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//accept a single command-line arguement, a string value
int main(int argc, string argv[])
{
    
    //check for incorrect number of input, if incorrect return 1
    if (argc != 2)
    {
        printf("Please enter one value \n");
        return 1;
    }
    
    //assign key to variable k
    string k = argv[1];
    
    //get length of key string
    int key_len = strlen(k);
    
    //check string k to ensure each character is alphabetic.  If not, return 1
    for (int l = 0, m = strlen(k); l < m; l++)
    {
        if (!isalpha(k[l]))
        {
            printf("Please enter only alphabetic letters for the key \n");
            return 1;
        }
    }
    
   //get plaintext from user and assign to variable p
   printf("plaintext: ");
   string p = get_string();
    
    //initialize array the length of plaintext p to store ciphertext output
   char cipher_array[strlen(p)+1];
   
    //loop through string to vary each letter.  i will loop through plaintext  and j will loop through key
    for (int i = 0, j = 0, n = strlen(p); i < n; i++, j++)
    {

        //if character in plaintext is not alphabetic, do not advance key character
        if (!isalpha(p[i]))
        {
            j = j-1;
        }
        
        //if j reaches length of key string, reset j
        else if (j >= key_len)
        {
            j = 0;
        }
        
         //if the array element is alphabetic
         if (isalpha(p[i]))
         {
             //if the letter is uppercase, shift uppercase letter
             if (isupper(p[i]))
             {
                    if(isupper(k[j]))
                    {
                        cipher_array[i] = ((p[i] - 'A' + k[j % strlen(k)] - 'A') % 26) + 'A';
                    }
                    else
                    {
                        cipher_array[i] = ((p[i] - 'A' + k[j % strlen(k)] - 'a') % 26) + 'A';
                    }
                  
                 
             }
             else if (islower(p[i])) //if the letter is lowercase, shift lowercase letter
             
             {
                
                if(isupper(k[j]))
                    {
                        cipher_array[i] = ((p[i] - 'a' + k[j % strlen(k)] - 'A') % 26) + 'a';
                    }
                    else
                    {
                        cipher_array[i] = ((p[i] - 'a' + k[j % strlen(k)] - 'a') % 26) + 'a';
                    }
             }
         }
         
         else  //if the character is not alphabetic, preserve the character - do not shift
             {
                 cipher_array[i] = p[i];
             }
             
    //terminate string with null character
    cipher_array[strlen(p)] = '\0';
    }
    
    printf("ciphertext: %s", cipher_array);
    printf("\n");
    return 0;
}
