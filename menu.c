/* Menu function for reminder daemon interface */

#include <stdio.h>

int menu()
{
  int selection = 0;
  
  
  while (selection < 1 || selection > 5)
  {
    printf("Please select by number:\n");
    printf("1. View all reminders\n2. Search for a reminder\n3. Add a reminder\n4. Remove a reminder\n5. Quit\n\nSelection: ");
    scanf("%d", &selection);
    flushBuff();
    
  } /*end while loop*/
  
  return selection;
  
} /*end function menu*/
