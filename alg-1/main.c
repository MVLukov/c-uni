#include <stdio.h>
#include <math.h>

void swap(double *a, double *b)
{
  double temp = *a;
  *a = *b;
  *b = temp;
}

void sort(double array[], int size) // sort array, selection sort, slow
{
  for (int i = 0; i < size - 1; i++)
  {
    int min_idx = i;

    for (int j = i + 1; j < size; j++)
    {
      if (array[j] > array[min_idx])
      {
        min_idx = j;
      }
    }

    swap(&array[min_idx], &array[i]);
  }
}

void biggest_diagonal()
{
  int coordinates[10][2] = {
      {1, 2},
      {3, 6},
      {1, 7},
      {0, 4},
      {-5, 2},
      {-3, -2},
      {1, -2},
      {6, -1},
      {0, -3},
      {0, 2}};

  double diagonals[10];

  for (int i = 0; i < 10; i++)
  {
    diagonals[i] = sqrt(pow(coordinates[i][0], 2) + pow(coordinates[i][1], 2));

    // printf("C=%f\n", diagonal);
  }

  sort(diagonals, 10);

  for (int i = 0; i < 10; i++)
  {
    printf("C=%f\n", diagonals[i]);
  }
}

void volume_of_aquariums()
{
  int aquariums[10][3] = {
      {30, 40, 120},
      {120, 150, 150},
      {60, 20, 60},
      {100, 100, 55},
      {90, 75, 65},
      {120, 40, 70},
      {45, 35, 55},
      {30, 50, 75},
      {50, 75, 80},
      {35, 46, 45}};

  for (int i = 0; i < 10; i++)
  {
    /* code */
    int volume = aquariums[i][0] * aquariums[i][1] * aquariums[i][2] / 1000;
    printf("a=%d, b=%d, c=%d, Volume=%d liters\n", aquariums[i][0], aquariums[i][1], aquariums[i][2], volume);
  }
}

void marks()
{
  int marks[] = {
      2, 3, 5, 4, 3, 4, 5, 6, 3, 4, 5, 2, 4, 4, 5, 3, 3, 2, 5, 2};

  int count = 0;

  for (int i = 0; i < 20; i++)
  {
    if (marks[i] == 6)
    {
      count += 1;
    }
  }

  double percentage = ((double)count / 20) * 100;

  printf("percentage is %.2f\n", percentage);
}

void smallest_number()
{
  unsigned int number = 1324;
  unsigned int min = __INT_MAX__;

  // printf("%d", min);

  while ((unsigned int)number != 0)
  {
    unsigned int current = number % 10;

    if (current < min)
    {
      min = current;
    }
    number /= 10;
  }

  printf("smallest number %d\n", min);
}

void average()
{
  int array[] = {
      1, -1, 5, -12, -3, 4, 8, 9, 11, 7, -2, 15};

  double average[2][2] = {{0, 0}, {0, 0}};

  for (int i = 0; i < (int)(sizeof(array) / sizeof(array[0])); i++)
  {
    if (array[i] < 0)
    {
      average[0][0] += 1.0;
      average[0][1] += array[i];
    }
    else
    {
      average[1][0] += 1.0;
      average[1][1] += array[i];
    }
  }

  double a = (double)(average[0][1] / average[0][0]);
  double b = (double)(average[1][1] / average[1][0]);

  printf("total = %.2f, sum = %.2f, average = %.2f\n", average[0][0], average[0][1], a);
  printf("total = %.2f, sum = %.2f, average = %.2f\n", average[1][0], average[1][1], b);

  if (fabs(a) < fabs(b))
  {
    printf("negative is closer to 0\n");
  }
  else
  {
    printf("positive is closer to 0\n");
  }
}

int main()
{
  // biggest_diagonal();
  // volume_of_aquariums();
  // marks();
  // smallest_number();
  average();

  return 0;
}
