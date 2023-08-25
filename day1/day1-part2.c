#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

int main()
{
  FILE *file = fopen("./input.txt", "r");
  if (file == NULL)
  {
    perror("Error opening file");
    return 1;
  }

  int currentSum = 0;
  int sums[3000]; // Max 3000 lines of input
  int sumsCount = 0;

  char line[256];
  while (fgets(line, sizeof(line), file))
  {
    line[strcspn(line, "\r\n")] = '\0'; // Remove newline characters

    if (strlen(line) == 0)
    {
      sums[sumsCount++] = currentSum;
      currentSum = 0;
    }
    else
    {
      currentSum += atoi(line);
    }
  }

  fclose(file);

  qsort(sums, sumsCount, sizeof(int), compare);
  int sumTopThree = sums[sumsCount - 1] + sums[sumsCount - 2] + sums[sumsCount - 3];

  printf("Result part 1: %d\n", sums[sumsCount - 1]);
  printf("Result part 2: %d\n", sumTopThree);

  return 0;
}