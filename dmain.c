/*main function for daemon process for the reminder system*/

#include <unistd.h>
#include <time.h>
#include "reminder.h"
#include <stdio.h>

void main()
{
  /*make this process a daemon*/
  daemon(1, 1);
  
  int count;
  time_t sysTime;
  Reminder *nextJob, *list;
  
  while (1)
  {
    
    list = load();
    nextJob = list->next;
    count = 0;
    
    while (count < 5)
    { 
      sysTime = time(NULL);
      
      if (nextJob && sysTime >= nextJob->jobTime)
      {
        /*brief delay to prevent problems with the smtp client*/
        sleep(10);
        executeJob(nextJob, list);
        save(list);
        break;
      }/*end if*/
      
      count++;
      sleep(60);
      
    } /*end while count*/
    
    freeList(list);
    
  } /*end while 1*/
} /*end main for daemon*/
