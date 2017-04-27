/*
Title: addJob.c
Date: 15/11/27
Description:  This function takes a pointer to a new job to be added to the linked list of jobs and a pointer to the existing list.  addJob() will search the list, finding where the job belongs in a chronological sequence, and add it at that location.  
*/

#include "reminder.h"

void addJob(Reminder* newJob, Reminder* list)
{
  Reminder *currentJob = list->next;
  
  if(!currentJob)
    currentJob = list;
  
  /*iterate through the list, checking the currentJob->time vs newJob->time*/
  while (newJob->jobTime > currentJob->jobTime && currentJob->next != NULL)
    currentJob = currentJob->next;
    
  /*compare job times to place the newJob where it belongs in the list*/
  if (currentJob->jobTime > newJob->jobTime)
    currentJob = currentJob->last;
  
  newJob->next = currentJob->next;
  newJob->last = currentJob;
  currentJob->next = newJob;
  
  /*assign job number*/
  newJob->jobNumber = currentJob->jobNumber +1;
  
  /*if the newJob didn't get put at the end of the list, move current to the job after the new job and set its last to the new job*/
  if (newJob->next != NULL)
  {
    currentJob = newJob->next;
    currentJob->last = newJob;
  } /*end if*/
  
  /*check for jobNumber collisions*/
  if (newJob->jobNumber == currentJob->jobNumber)
    newJob->jobNumber += 0.001;
  
} /*end function addJob*/
