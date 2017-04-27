/*
Title: getJob.c
Description: This function interactively gets information for a new reminder job from a user, stores it in a Reminder struct, then calls add() to place the struct in the appropriate position in the list
Date: 15/11/27
*/

#include <stdio.h>
#include <stdlib.h>
#include "reminder.h"

void getJob(Reminder* list)
{
  Reminder *newJob = (Reminder*) malloc(sizeof(Reminder));
  struct tm sendTime;
  char repeat;
  char correct;
  
  do
  {
    printf("\nEmail address to send reminder to: ");
    scanf("%s", newJob->email);
    flushBuff();
  
    printf("\nDate to send reminder(MM/DD/YYYY): ");
    scanf("%d %*c %d %*c %d", &sendTime.tm_mon, &sendTime.tm_mday, &sendTime.tm_year);
    flushBuff();
    
    /*adjustments and error checking on date*/
    sendTime.tm_mon -= 1;
    if (sendTime.tm_year < 2000)
      sendTime.tm_year += 100;
    else
      sendTime.tm_year -= 1900;
  
    printf("\nTime to send remdinder (HH:MM 24 hour clock): ");
    scanf("%d %*c %d", &sendTime.tm_hour, &sendTime.tm_min);
    flushBuff();
    sendTime.tm_isdst = 0;
    sendTime.tm_sec = 0;
  
    /*set up recurring reminders*/
    printf("\nShould this reminder be sent more than once? (y/n): ");
    scanf("%c", &repeat);
    flushBuff();
  
    if (repeat == 'y' || repeat == 'Y')
    {
      printf("\nHow many times should the reminder be sent?: ");
      scanf("%d", &newJob->maxCount);
      flushBuff();
    
      printf("\nHow long between reminders (in hours): ");
      scanf("%f", &newJob->offset);
      flushBuff();
    
    } /*end if*/
    else
    {
      newJob->maxCount = 1;
      newJob->offset = 0;
    } /*end else*/
    
    printf("Enter reminder message (160 characters maximum):\n");
    safer_gets(newJob->message, 160);
  
  
    /*confirm input*/
    printf("\nPlease confirm the following is correct:\n");
    printf("\nEmail address: %s\nDate and time to send: %s", newJob->email, asctime(&sendTime));
    printf("Message:\n%s", newJob->message);
    if (repeat == 'y' || repeat =='Y')
    {
      printf("\nSender reminder %d times, every %2.2f hours", newJob->maxCount, newJob->offset);
      
    }/*end if */
    
    printf("\nIs this correct? (y/n): ");
    scanf("%c", &correct);
    flushBuff();
  
  } while (correct != 'y' && correct != 'Y'); /*end do/while correct*/
  
  newJob->jobTime = mktime(&sendTime);
  
  addJob(newJob, list);
  
  printf("\n");
  
} /*end function getJob*/
