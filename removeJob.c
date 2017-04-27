/*
Title: remove.c 
Date: 15/11/28
Description: This function takes a pointer to the list as an argument.  It will prompt the user for the job number to be removed, search the list for the job number, and remove it.  If the job number is not found, it will inform the user before returning
*/

#include <stdio.h>
#include <stdlib.h>
#include "reminder.h"

void removeJob(Reminder* list)
{
  float jobNumber;
  char confirm = 'z';
  Reminder* temp;
  Reminder* current = list->next; /*set current to first real node in list*/
  
  printf("\nJob number to be deleted: ");
  scanf("%f", &jobNumber);
  flushBuff();
  
  /*if this isn't the job we're looking for, move along, move along*/
  while(current->jobNumber != jobNumber && current->next != NULL)
    current = current->next;
  
  /*if we are at the end of the list and we haven't found the jobNumber, it does not exist so punt*/
  if (!current->next && current->jobNumber != jobNumber)
  {
    printf("\nJob number %.3f not found\n\n", jobNumber);
    return;
  } /*end if*/
  
    printf("\nAre you sure you want to delete this job?\n");
    display(current);
  
  while (confirm != 'n' && confirm != 'N' && confirm != 'y' && confirm != 'Y')
  {
    printf("\n(y/n): ");
    scanf("%c", &confirm);
    flushBuff();
  } /*end while*/
  
  if (confirm == 'n' || confirm == 'N')
    return;
  
  /*if we have made it this far, rewire, and ditch the current node*/
  temp = current->last;
  temp->next = current->next;
  
  /*verify temp->next is not null before trying to adjust the next node*/
  if (temp->next)
  {
    temp = temp->next;
    temp->last = current->last;
  } /*end if*/
  
  free(current);
  
} /*end function remove*/
