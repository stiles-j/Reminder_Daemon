/*main function for reminder daemon interface*/

#include <stdio.h>
#include <stdlib.h>
#include "reminder.h"

int main()
{
  int selection = 0;
  Reminder* list = load();

  while (selection != 5)
  {
    selection = menu();
  
    switch (selection)
    {
      case 1:
        displayAll(list);
        break;
      case 2:
        searchJobs(list);
        break;
      case 3:
        getJob(list);
        break;
      case 4:
        removeJob(list);
        break;
      case 5:
        break;
      default:
        printf("\nSelection invalid\n");
        break;
    }; /*end switch*/
  
  } /*end while*/
    
  save(list);
  
  return 0;
  
} /*end main*/
