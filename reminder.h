/*include file for reminder daemon project.  Struct definitions, function headers and symbolic constants go here*/

#include <time.h>

struct reminderJob
{
  time_t  jobTime; /*The time the job should run*/
  float   offset; /*The amount of time before running the job again*/
  int     count;  /*The number of times the job has been run*/
  int     maxCount;   /*The maximum times the job should be run*/
  char    email[80];  /*The email address the message should be sent to*/
  char    message[161];  /*The message to be sent to the recipient*/
  float   jobNumber;     /*a unique number to identify this job by*/
  struct reminderJob *next;
  struct reminderJob *last;
};
typedef struct reminderJob Reminder;

/*function declarations*/
int menu();
void getJob(Reminder*);
void flushBuff();
void safer_gets (char[], int);
void addJob(Reminder*, Reminder*);
void display(Reminder*);
void displayAll(Reminder*);
Reminder* load();
void save (Reminder*);
void removeJob(Reminder*);
void searchJobs (Reminder*);

/*daemon specific functions*/
void deleteJob(Reminder*, Reminder*);
void executeJob(Reminder*, Reminder*);
void freeList(Reminder*);
