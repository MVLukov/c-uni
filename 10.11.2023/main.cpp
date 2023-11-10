#include <stdio.h>

void tablica()
{
    int a;
    printf("Enter a: ");
    scanf("%d", &a);

    for (int i = 1; i < 11; i++)
    {
        printf("%d * %d = %d\n", a, i, a * i);
    }
}

void ocenki()
{
    int marks[7] = {};
    int avg = 0;

    for (int i = 0; i < 7; i++)
    {
        printf("Enter mark: ");
        scanf("%d", &marks[i]);

        avg += marks[i];
    }

    printf("Average is %.2f\n", (double)avg / 7);
}

void pyramid1()
{
    for (int row = 1; row < 5; row++)
    {
        for (int col = 0; col < row; col++)
        {
            printf("%d", row);
        }

        printf("\n");
        /* code */
    }
}

void pyramid2()
{
    int num = 1;

    for (int row = 1; row < 5; row++)
    {
        for (int col = 0; col < row; col++)
        {
            printf("%d ", num);
            num++;
        }

        printf("\n");
    }
}

void sum_to_1000()
{
    int sum = 0;

    // while (sum < 1000)
    // {
    //     int a;
    //     printf("Enter num: ");
    //     scanf("%d", &a);

    //     sum += a;
    // }

    // do
    // {
    //     int a;
    //     printf("Enter num: ");
    //     scanf("%d", &a);

    //     sum += a;
    // } while (sum < 1000);

    for (;;)
    {
        if (sum > 1000)
            break;

        int a;
        printf("Enter num: ");
        scanf("%d", &a);

        sum += a;
    }

    printf("Sum: %d\n", sum);
}

void symmetric_nums()
{
    for (int i = 100; i < 1000; i++)
    {
        int n = i;
        int rem = 0;
        int reversed = 0;

        while (n > 0)
        {
            rem = n % 10;
            n /= 10;

            reversed = reversed * 10 + rem;
        }

        if (i == reversed)
        {
            printf("Symmetric number: %d\n", i);
        }
    }
}

void is_num_contains_one()
{
    for (int i = 100; i < 1000; i++)
    {
        int n = i;

        while (n > 0)
        {
            int rem = n % 10;
            n /= 10;

            if (rem == 1)
            {
                printf("Num contains 1: %d\n", i);
                break;
            }
        }
    }
}

void acceding()
{
    for (int i = 100; i < 1000; i++)
    {
        int n = i;
        int count = 0;

        while (n > 0)
        {
            int rem = n % 10;
            n /= 10;

            if (rem > n % 10)
            {
                count++;
            }
        }

        if (count == 3)
        {
            printf("%d\n", i);
        }
    }
}

int reversedNum(int num)
{
    int rem = 0;
    int reversed = 0;

    while (num > 0)
    {
        rem = num % 10;
        num /= 10;

        reversed = reversed * 10 + rem;
    }

    return reversed;
}

void natural_nums()
{
    for (int m = 10; m < 100; m++)
    {
        int a = reversedNum(m);

        for (int n = 10; n < 100; n++)
        {
            int b = reversedNum(n);

            if (a * b == m * n)
            {
                printf("%d * %d = %d * %d\n", a, b, m, n);
                // break;
            }
        }
    }
}

void is_num_dividable_by_its_nums()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        int num = i;
        int numLength = 0;
        int count = 0;

        while (num > 0)
        {
            int rem = num % 10;
            num /= 10;

            if (rem != 0 && i % rem == 0)
            {
                count++;
            }

            numLength++;
        }

        if (count == numLength)
        {
            printf("Num: %d\n", i);
        }
    }
}

void sum_of_nums_equal()
{
    int a, b;
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    int sumA = 0;
    int sumB = 0;
    int m = a;
    int n = b;

    while (m > 0)
    {
        int rem = m % 10;
        m /= 10;

        sumA += rem;
    }

    while (n > 0)
    {
        int rem = n % 10;
        n /= 10;

        sumB += rem;
    }

    if (sumA == sumB)
    {
        printf("Sum of A[%d] and B[%d] is [%d]\n", a, b, sumA);
    }
}

int main()
{
    // tablica();
    // ocenki();

    // pyramid1();
    // pyramid2();

    // sum_to_1000();
    // symmetric_nums();
    // is_num_contains_one();
    // acceding();
    // natural_nums();
    // is_num_dividable_by_its_nums();
    sum_of_nums_equal();

    return 0;
}