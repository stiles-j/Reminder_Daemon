/*
Title: display.c
Date: 15/11/28
Description:  This function takes a pointer to a single Reminder node and displays it to stdout
*/

#include <stdio.h>
#include "reminder.h"

void display(Reminder* node)
{
  
  printf("\nTime to send reminder: %s", asctime(localtime(&node->jobTime)));
  
  if (node->maxCount > 1)
    printf("Send reminder: %d times total, once every: %.2f hours\n", node->maxCount, node->offset);
         
  printf("Email: %s\nMessage: %s\nJob number: %.3f\n", node->email, node->message, node->jobNumber);
  
} /*end function display*/
