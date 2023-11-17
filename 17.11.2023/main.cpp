#include <stdio.h>

void avg_nums()
{
    float nums[15];
    float sumPos = 0;
    int countPos = 0;

    for (int i = 0; i < 15; i++)
    {
        int input;

        printf("Enter num [%d]: ", i + 1);
        scanf("%d", &input);

        nums[i] = input;
    }

    for (int i = 0; i < 15; i++)
    {
        if (nums[i] > 0)
        {
            sumPos += nums[i];
            countPos++;
        }
    }

    printf("Avg: %.2f\n", (float)(sumPos / countPos));
}

void neighbors()
{
    int arr1[10] = {3, 1, 1, 1, 3, 4, 5, 1, 6, 1};
    int arr2[10] = {1};

    int idx = 0;

    for (int i = 0; i < 10; i++)
    {
        if (arr1[i] != arr1[i + 1])
        {
            arr2[idx] = arr1[i];
            idx++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("Num [%d]: %d\n", i, arr2[i]);
    }
}

void min_of_arr()
{
    int arr[10] = {-1, 10, 11, 15, -116, -2, 20, 5, -20, 12};
    int min = arr[0];
    int idx = 0;

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            idx = i;
        }
    }

    printf("Min [%d]: %d\n", idx, arr[idx]);
}

void avg_of_odds()
{
    int arr1[10] = {11, 21, 3, 57, 87, 191, 15, 13, 19, 20};
    float arr2[10] = {0};

    for (int i = 0; i < 10; i++)
    {
        int num = arr1[i];
        float sumOfOdd = 0;
        int countOfOdd = 0;

        while (num > 0)
        {
            int rem = num % 10;

            if (rem % 2 == 1)
            {
                sumOfOdd += rem;
                countOfOdd++;
            }

            num = num / 10;
        }

        if (countOfOdd != 0)
        {
            float avg = (float)(sumOfOdd / countOfOdd);
            arr2[i] = avg;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("Num [%d]: %.2f\n", i, arr2[i]);
    }
}

void second_max()
{
    int arr[10] = {51, 2, 15, 41, 161, 21, 18, 111, 19, 31};
    int max = arr[0];
    int secondMax = arr[0];

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > secondMax)
        {
            if (arr[i] > max)
            {
                secondMax = max;
                max = arr[i];
            }
            else
            {
                secondMax = arr[i];
            }
        }
    }

    printf("Max: %d\n", max);
    printf("Second max: %d\n", secondMax);
}

void count_of_letters()
{
    char letters[7] = {'A', 'C', 'C', 'D', 'C', 'C', 'B'};
    int lettersCount[4] = {};

    for (int i = 0; i < 7; i++)
    {
        lettersCount[letters[i] - 'A'] += 1;
    }

    int idx = 0;
    int max = 0;

    for (int i = 0; i < 4; i++)
    {
        // printf("%d\n", lettersCount[i]);
        if (lettersCount[i] > max)
        {
            idx = i;
            max = lettersCount[i];
        }
    }

    printf("Most used letter: %c - %d\n", (char)('A' + idx), lettersCount[idx]);
}

void x_of_interval()
{
    int arr1[10] = {1, 5, -1, 12, 3, -5, 6, 8, 10, 20};
    int arr2[10] = {3, 7, -5, 16, 5, -10, 9, 11, 12, 25};

    int x;
    printf("Enter x: ");
    scanf("%d", &x);

    for (int i = 0; i < 10; i++)
    {
        int a = arr1[i];
        int b = arr2[i];

        if (x >= 0)
        {
            if (x >= a && x <= b)
            {
                printf("X[%d] is between a[%d] and b[%d]\n", x, arr1[i], arr2[i]);
                return;
            }
        }
        else
        {
            if (x >= b && x <= a)
            {
                printf("X[%d] is between a[%d] and b[%d]\n", x, arr1[i], arr2[i]);
                return;
            }
        }
    }
}

void reverse_nums()
{
    int arr1[5] = {111, 123, 546, 761, 582};
    int arr2[5] = {};

    for (int i = 0; i < 5; i++)
    {
        int num = arr1[i];
        int reversed = 0;

        while (num > 0)
        {
            int rem = num % 10;
            reversed = reversed * 10 + rem;

            num /= 10;
        }

        arr2[i] = reversed;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr2[i]);
    }
}

void ant()
{
    int crumbs[10] = {1, 4, 7, 9, 11, 15, 16, 18, 21, 25};
    int totalPath = 0;

    for (int i = 0; i < 10; i++)
    {
        totalPath = totalPath + crumbs[i] * 2;
    }

    printf("Total path: %d\n", totalPath);
}

int main()
{
    // avg_nums();
    // neighbors();
    // min_of_arr();
    // avg_of_odds();
    // second_max();
    // count_of_letters();
    // x_of_interval();
    // reverse_nums();
    ant();

    return 0;
}