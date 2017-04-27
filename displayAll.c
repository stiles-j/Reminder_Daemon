/*
Title: displayAll.c
Date: 15/11/27
Description:  This function will take a pointer to the linked list of jobs, then display each one to stdout
*/

#include <stdio.h>
#include "reminder.h"

void displayAll(Reminder* list)
{
  Reminder* current = list->next; /*set current to first real node*/
  
  if (!current)
    printf("\nNo reminders currently scheduled\n");
  
  while (current)
  {
    display(current);
    current = current->next;
  } /*end while*/

  printf("\n");
} /*end function displayAll*/
