#include <stdio.h>

void dividable_by_3()
{
    int input;
    printf("Enter number: ");
    scanf("%d", &input);

    if (input % 3 == 0)
    {
        printf("%d is dividable by 3\n", input);
    }
    else
    {
        printf("%d is not dividable by 3\n", input);
    }
}

void dividable_by_5_7()
{
    int input;
    printf("Enter number: ");
    scanf("%d", &input);

    if (input % 5 == 0 && input % 7 == 0)
    {
        printf("%d is dividable by 5 and 7\n", input);
    }
    else
    {
        printf("%d is not dividable by 5 and 7\n", input);
    }
}

void positive_negative_zero()
{
    int input;
    printf("Enter number: ");
    scanf("%d", &input);

    if (input < 0)
    {
        printf("%d is negative\n", input);
    }
    else if (input > 0)
    {
        printf("%d is positive\n", input);
    }
    else
    {
        printf("%d is zero\n", input);
    }
}

void triangle()
{
    int a;
    printf("Enter a: ");
    scanf("%d", &a);

    int b;
    printf("Enter b: ");
    scanf("%d", &b);

    int c;
    printf("Enter c: ");
    scanf("%d", &c);

    if (a % 2 == 0)
    {
        printf("%d is even\n", a);
    }

    if (b % 2 == 0)
    {
        printf("%d is even\n", b);
    }

    if (c % 2 == 0)
    {
        printf("%d is even\n", c);
    }
}

void dividable_by_5_and_not_2()
{
    int input;

    printf("Enter input: ");
    scanf("%d", &input);

    if (input % 5 == 0 && input % 2 == 1)
    {
        printf("%d is dividable by 5 and is not even\n", input);
    }
}

void is_char_number()
{
    char input;
    printf("Enter char: ");
    scanf("%c", &input);

    if (input >= '0' && input <= '9')
    {
        printf("%c is number\n", input);
    }
    else
    {
        printf("%c is not a number\n", input);
    }
}

void is_char_uppercase_lowercase()
{
    char input;
    printf("Enter char: ");
    scanf("%c", &input);

    if (input >= 'a' && input <= 'z')
    {
        printf("%c is lowercase\n", input);
    }
    else if (input >= 'A' && input <= 'Z')
    {
        printf("%c is uppercase\n", input);
    }
    else
    {
        printf("%c is not a letter\n", input);
    }
}

void square()
{
    int x, y;
    printf("Enter x and y: ");
    scanf("%d %d", &x, &y);

    int a;
    printf("Enter a: ");
    scanf("%d", &a);

    double topLeft = a * 0.75; // a-bottomRight
    double bottomRight = -a * 0.25;

    if (x <= topLeft && x >= bottomRight)
    {
        if (y <= topLeft && y >= bottomRight)
        {
            printf("x:%d y:%d are in the square\n", x, y);
        }
    }
}

void right_angled_triangle()
{
    int a, b, c;
    printf("Enter a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);

    int squareC = a * a + b * b;

    if (squareC == c * c)
    {
        printf("Triangle is rights angled\n");
    }
}

int main()
{
    //   dividable_by_3();
    // dividable_by_5_7();
    // positive_negative_zero();
    // triangle();
    // dividable_by_5_and_not_2();
    // is_char_number();
    // is_char_uppercase_lowercase();
    // square();
    right_angled_triangle();

    return 0;
}