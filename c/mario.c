#include <stdio.h>
#include <cs50.h>

int main (void)
{
    
    int height;
     do
     {
        printf("Enter Pyramid Height \n");
       height = get_int(); 
     }
   while (height <0 || height > 23);
   
     
     for (int row = 0; row < height; row++)
     {
        for (int col = 0; col < height-row-1; col++)
        {
            printf(" ");
        }
        
        for (int col = 0; col < row + 2; col++)
        {
            printf("#");
        }
        
     printf("\n");
         
     }
     
}