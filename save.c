/*
Title: save.c
Date: 15/11/27
Description: This function will save the full contents of the linked list to the file remindertab for later use
*/

#include <stdio.h>
#include <stdlib.h>
#include "reminder.h"

void save (Reminder* list)
{
  FILE* fp;
  Reminder* current;
  
  current = list->next; /*set current to the first real node*/

  if(!(fp = fopen("remindertab", "w")))
  {
    printf("\nFatal Error: Unable to save remindertab\n");
    exit(1);
  } /*end if*/
  
  while (current)
  {
    fwrite(&current->jobTime, sizeof(time_t), 1, fp);
    fwrite(&current->offset, sizeof(float), 1, fp);
    fwrite(&current->count, sizeof(int), 1, fp);
    fwrite(&current->maxCount, sizeof(int), 1, fp);
    fwrite(current->email, sizeof(char) * 80, 1, fp);
    fwrite(current->message, sizeof(char) * 161, 1, fp);
    
    current = current->next;
    
  } /*end while*/
  
  fclose(fp);
  
} /*end function save*/
