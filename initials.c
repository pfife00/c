#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int counter = 0;
int number_of_spaces;


int main(void)
{
    //get user input
    string s = get_string();
    
    //find number of instances of space character
    for (int char_count = 0, str_length = strlen(s); char_count < str_length; char_count++)
    {
        if (s[char_count] == ' ')
        {
            number_of_spaces++;
        }
    }
    
    //initilize array to store initials with length of number of spaces in string
        char initials[number_of_spaces+1];
    
    if (s !=NULL)
    {
        initials[0] = toupper(s[0]);
        
        //iterate number of spaces times
        for (int i = 1,  n = strlen(s); i < n; i++)
        {
            if(s[i] == ' ')
            {
                counter++;
                initials[counter] = toupper(s[i+1]);
            }
        }
    }
    
    printf("%s\n", initials);
    
}