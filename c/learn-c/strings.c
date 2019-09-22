#include <stdio.h>
#include <string.h>

int main(void)
{
  /* define first_name */
  /* define last_name */
  char name[100];
  char * first_name = "John";
  char last_name[3] = "Doe";

  last_name[0] = 'B';
  // sends first_name + " " + last_name to name
  sprintf(name, "%s %s", first_name, last_name);
  // cmp the first 8 bytes of name with "John Boe"
  if (strncmp(name, "John Boe", 8) == 0)
  {
      printf("Done!\n");
  }

  // sets a null byte on index 0
  name[0] = '\0';
  // appends 5 bytes of first_name and overwrites the terminating null byte ('\0')
  strncat(name,first_name, 5);
  // appends 3 bytes of last_name and overwrites the terminating null byte ('\0')
  strncat(name,last_name, 3);

  printf("%s\n",name);

  return 0;
}
