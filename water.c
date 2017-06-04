#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int minutes;
    int bottles;
    
   do
   {
       printf("Enter Shower Length in Minutes");
       minutes = get_int(); 
   }
   while (minutes < 0);
   
   bottles = minutes * 12;
   
   printf("Minutes: %i \n", minutes);
   printf("Bottles: %i \n", bottles);
}