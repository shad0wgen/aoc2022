#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE *file = fopen("./input.txt", "r");
  if (file == NULL)
  {
    perror("Error opening file");
    return 1;
  }

  char line[256];
  int currentSum = 0;
  int highestSum = 0;

  while (fgets(line, sizeof(line), file))
  {
    line[strcspn(line, "\r\n")] = '\0'; // Remove newline characters

    if (strlen(line) > 0)
    {
      currentSum = currentSum + atoi(line);
    }
    else
    {
      if (currentSum > highestSum)
      {
        highestSum = currentSum;
      }
      currentSum = 0;
    }
  }

  fclose(file);

  printf("Result part 1: %d\n", highestSum);

  return 0;
}