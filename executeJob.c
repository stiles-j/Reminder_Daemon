/*
Title: executeJob.c
Date: 15/11/29
Description: This function takes a pointer to the job to be executed, and the full list (the job should be part of the list already).  The function will build the command string, and execute the job.  It will then check if the job needs to be re-scheduled to occur again, and do so, or delete the job if not.  
*/

#include <stdlib.h>
#include <string.h>
#include "reminder.h"

void executeJob(Reminder* job, Reminder* list)
{
  long delay;
  char command[300];
  
  /*build command to system and execute.  Note, the code in the below section assumes mutt is configured on the host system as an email client.  If using a different client (such as mailx), substitute in the name of the client for mutt below*/
  strcpy(command, "echo \"");
  strcat(command, job->message);
  strcat(command, "\" | mutt -s \"Reminder\" ");
  strcat(command, job->email);
  system(command);
  
  /*check if we have any repeats left.  Reschedule the job if so, delete the job if not*/
  job->count++;
  if(job->count < job->maxCount)
  {
    delay = job->offset * 3600;
    job->jobTime += delay;
  } /*end if*/
  else
    deleteJob(job, list);
  
} /*end function executeJob*/
