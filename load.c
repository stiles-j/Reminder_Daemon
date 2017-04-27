/*
Title: load.c
Date: 15/11/27
Description: This function will attempt to open the file remindertab in the directory that the application is located in.  If the file exists, it will read the data from the file and call addJob() to create the linked list of reminder jobs.  If the file does not exist the function returns a pointer to a dummy reminderJob that will function as the head of the list
*/

#include <stdlib.h>
#include <stdio.h>
#include "reminder.h"

Reminder* load()
{
  FILE *fp;
  Reminder *nextJob, *list;
  size_t goodRead = 1;
   
  list = (Reminder*) malloc(sizeof(Reminder));
  list->next = NULL;
  list->last = NULL;
  list->jobTime = 0;
  list->jobNumber = 0.0;
  
  /*if no file exists, just return the head of the list*/
  if(!(fp = fopen("remindertab", "r")))
    return list;

  /*populate each field of nextJob from the file then call add() to place it in the list*/
  while (goodRead)
  {
    nextJob = (Reminder*) malloc(sizeof(Reminder));
    
    fread(&nextJob->jobTime, sizeof(time_t), 1, fp);
    fread(&nextJob->offset, sizeof(float), 1, fp);
    fread(&nextJob->count, sizeof(int), 1, fp);
    fread(&nextJob->maxCount, sizeof(int), 1, fp);
    fread(nextJob->email, sizeof(char) * 80, 1, fp);
    /*check return value of last read to verify the read was legitimate*/
    goodRead = fread(nextJob->message, sizeof(char) * 161, 1, fp);
    
    /*verify we have a valid record before adding to list*/
    if (nextJob->jobTime && goodRead)
      addJob(nextJob, list);
    
  } /*end while*/
  
  return list;
  
} /*end function load*/
