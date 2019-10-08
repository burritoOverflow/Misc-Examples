#include <time.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{

  if (argc < 2 || argc > 11)
  {
    printf("Usage: %s and up to ten filenames as args", argv[0]);
    exit(EXIT_FAILURE);
  }

  int numFiles = argc - 1;

  time_t lastAccessedArr[numFiles];
  time_t lastModifiedArr[numFiles];

  struct stat statStruct;

  // set the initial values for each file in the arrays
  for (int i = 0; i < numFiles; i++)
  {
    if (stat(argv[i + 1], &statStruct) != -1)
    {
      lastAccessedArr[i] = statStruct.st_atime;
      lastModifiedArr[i] = statStruct.st_mtime;
    }
    else
    {
      perror("stat failed");
      exit(EXIT_FAILURE);
    }
  }

  while (1)
  {
    for (int i = 0; i < numFiles; i++)
    {
      bool modified = false;

      if (stat(argv[i + 1], &statStruct) != -1)
      {
        if (statStruct.st_mtime != lastModifiedArr[i])
        {
          printf("Last modified: %s", ctime(&statStruct.st_mtime));
          // time modified, update the value at the corresponding index
          lastModifiedArr[i] = statStruct.st_mtime;
          modified = true;
        }

        if (statStruct.st_atime != lastAccessedArr[i])
        {
          if (!modified)
          {
            printf("Last accessed: %s", ctime(&statStruct.st_atime));
          }
          lastAccessedArr[i] = statStruct.st_atime;
        }
      }
      else
      {
        perror("stat failed");
        exit(EXIT_FAILURE);
      }

    }
    // sleep(1);
  }

}
