/* 
Title: freeList.c
Date 15/11/29
Description:  This function takes a pointer to the list of pending reminder jobs, and systematically frees the memory for each node, effectively deleting the entire list.  This is a daemon only function.  This function should be called before load() is called if there is already a list in memory to prevent memory leaks
*/

#include <stdlib.h>
#include "reminder.h"
#include <stdio.h>

void freeList(Reminder* list)
{
  Reminder *current, *temp;
  current = list;
  
  /*find the last node in the list*/
  while (current->next != NULL)
    current = current->next;
  
  /*delete each node*/
  while (current)
  {
    temp = current;
    current = current->last;
    free(temp);
  } /*end while current*/
  
} /*end function freeList*/
