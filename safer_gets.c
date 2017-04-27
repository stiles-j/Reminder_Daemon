/* Function safer_gets */

void safer_gets (char array[], int max_chars)
{
  int i;

  /* Read name from input buffer, character by character,   */
  /* up until the maximum number of characters in the array.*/
  /* ------------------------------------------------------ */

  for (i = 0; i < max_chars; i++)
  {
     array[i] = getchar();

     /* If "this" character is the carriage return,      */
     /* replace it with a null terminator and exit loop. */
     /* ------------------------------------------------ */

     if (array[i] == '\n')
     {
       array[i] = '\0';
       break;
     }
   } /* end for */

   /* If we have pulled out the most we can,       */
   /* and, if there are more chars in the buffer,  */
   /* clear out the remaining chars in the buffer. */
   /* This is equivalent to the fflush() function. */
   /* -------------------------------------------- */

   if (i == max_chars )
     if (array[i-1] != '\0')
       while (getchar() != '\n');

   /* Ensure the last element in the array contains the null terminator. */
   /* ------------------------------------------------------------------ */

   array[max_chars-1] = '\0';


} /* end safer_gets */
