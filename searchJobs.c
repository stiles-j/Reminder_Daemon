/*
Title: search.c
Date: 15/11/28
Description: This function takes a pointer to the list of jobs, then offers the user the option to either search by email address or time range.  In either case, the search is a linear search due to the underlying structure of the list being a linked list, and so will quickly become inefficient for large lists
*/

#include <stdio.h>
#include <string.h>
#include "reminder.h"

void searchJobs (Reminder* list)
{
  char email[80];
  char confirm = 'n';
  struct tm tempTime, tempEndTime;
  time_t startTime;
  time_t endTime;
  int hits = 0, selection = 0;
  Reminder* current = list->next; /*start current at the first real node*/
  
  while (selection != 1 && selection != 2)
  {
    printf("\nHow would you like to search?\n1. By email address\n2. By time range\n\n");
    scanf("%d", &selection);
    flushBuff();
  } /*end while*/

  if (selection == 1)
  {
    printf("\nEnter email address: ");
    safer_gets(email, 80);
    
    /*compare each node's email with the search email until we get a match or run out of nodes*/
    while(current)
    {
      if(!strcmp(current->email, email))
      {
        display(current);
        hits++;
      }/*end if*/
      
      current = current->next; 
    } /*end while*/

    if (!hits)
      printf("\nEmail address %s not found\n", email);
    
    printf("\n");
    return;
  } /*end if 1*/
  
  /*if we got here they selected search by time frame*/
  
  while (confirm != 'y' && confirm != 'Y')
  {
    /*get start info*/
    printf("\nStart date (MM/DD/YYYY): ");
    scanf("%d %*c %d %*c %d", &tempTime.tm_mon, &tempTime.tm_mday, &tempTime.tm_year);
    flushBuff();
  
    /*adjustments and error checking on date*/
    tempTime.tm_mon -= 1;
    if (tempTime.tm_year < 2000)
      tempTime.tm_year += 100;
    else
      tempTime.tm_year -= 1900;
  
    printf("\nStart time (HH:MM 24 hour clock): ");
    scanf("%d %*c %d", &tempTime.tm_hour, &tempTime.tm_min);
    flushBuff();
    tempTime.tm_isdst = 0;
    tempTime.tm_sec = 0;
  
    startTime = mktime(&tempTime);
  
    /*get end info*/
    printf("\nEnd date (MM/DD/YYYY): ");
    scanf("%d %*c %d %*c %d", &tempEndTime.tm_mon, &tempEndTime.tm_mday, &tempEndTime.tm_year);
    flushBuff();
  
    /*adjustments and error checking on date*/
    tempEndTime.tm_mon -= 1;
    if (tempEndTime.tm_year < 2000)
      tempEndTime.tm_year += 100;
    else
      tempEndTime.tm_year -= 1900;
  
    printf("\nEnd time (HH:MM 24 hour clock): ");
    scanf("%d %*c %d", &tempEndTime.tm_hour, &tempEndTime.tm_min);
    flushBuff();
    tempEndTime.tm_isdst = 0;
    tempEndTime.tm_sec = 0;
  
    endTime = mktime(&tempEndTime);
    
    printf("\nConfirm search range:");
    printf("\nStart time: %s", asctime(localtime(&startTime)));
    printf("End time: %s", asctime(localtime(&endTime)));
    printf("\nIs this correct? (y/n): ");
    
    scanf("%c", &confirm);
    flushBuff();

  } /* end while confirm*/
  
  
  while (current)
  {
    if (current->jobTime >= startTime && current->jobTime <= endTime)
    {
      display(current);
      hits++;
    }
    current = current->next;
  }/*end while*/
  
  if (!hits)
    printf("\nNo reminders found in time range\n");
  
  printf("\n");
  
} /*end function searchJobs*/
