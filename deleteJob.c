/*
Title: deleteJob.c
Date: 15/11/29
Description:  This fucntion takes a pointer to a job to be removed from the list and a poitner to the list as arguments (the job should be part of the list).  The function will remove the job from the list and free the memory taken by the dead job.  Note that unlike removeJob() this function has no user interface and should only be called by the daemon process.  
*/

#include <stdlib.h>
#include "reminder.h"

void deleteJob(Reminder* deadJob, Reminder* list)
{
  Reminder* current;
  
  current = deadJob->last;
  current->next = deadJob->next;
  /*make sure next is not null before proceeding*/
  if(current->next)
  {
    current = current->next;
    current->last = deadJob->last;
  }/*end if*/
  free(deadJob);
  
}/*end function deleteJob*/
