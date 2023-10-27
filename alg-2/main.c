#include <stdio.h>

#define LEN(arr) ((int)(sizeof(arr) / sizeof(arr[0])))

void no_duplicate_neighbors()
{
  int arr1[] = {1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 2, 2, 3, 2, 3, 4, 4, 4, 4, 5};
  int arr2[LEN(arr1)] = {0};
  int idx = 0;

  for (int i = 0; i < LEN(arr1); i++)
  {
    if (arr1[i] != arr1[i + 1])
    {
      arr2[idx] = arr1[i];
      idx++;
    }
  }

  for (int i = 0; i < LEN(arr2); i++)
  {
    if (arr2[i] != 0)
      printf("%d\n", arr2[i]);
  }
}

void second_biggest()
{
  int arr1[10] = {25, 51, 11, 51, 3, 41, 25, 13, 50, 3};
  int biggest = 0;
  int second = 0;

  for (int i = 0; i < LEN(arr1); i++)
  {
    if (arr1[i] > biggest)
    {
      second = biggest;
      biggest = arr1[i];
    }
    else
    {
      if (arr1[i] > second && arr1[i] < biggest)
      {
        second = arr1[i];
      }
    }
  }

  printf("BIGGEST = %d SECOND = %d\n", biggest, second);
}

void average_of_odds()
{
  int arr1[10] = {251, 511, 333, 473, 31, 41, 95, 13, 101, 517};
  float arr2[10] = {0};

  for (int i = 0; i < LEN(arr1); i++)
  {
    int curr = arr1[i];
    int odd_count = 0;
    int sum = 0;

    while (curr > 0)
    {
      int num = curr % 10;

      if (num % 2 == 1)
      {
        odd_count++;
        sum += num;
      }

      curr /= 10;
    }

    arr2[i] = (sum / (float)odd_count);
  }

  for (int i = 0; i < LEN(arr2); i++)
  {
    printf("AVERAGE = %.2f\n", arr2[i]);
  }
}

void reversed_numbers()
{
  int arr1[10] = {251, 511, 333, 473, 31, 41, 95, 13, 101, 517};
  int arr2[10] = {0};

  for (int i = 0; i < LEN(arr1); i++)
  {
    int curr = arr1[i];
    int new_num = 0;

    while (curr > 0)
    {
      int num = curr % 10;

      new_num = new_num * 10 + num;

      curr /= 10;
    }

    arr2[i] = new_num;
  }

  for (int i = 0; i < LEN(arr2); i++)
  {
    printf("REVERSED NUMS = %d\n", arr2[i]);
  }
}

int main()
{
  // no_duplicate_neighbors();
  // second_biggest();
  // average_of_odds();
  reversed_numbers();

  return 0;
}