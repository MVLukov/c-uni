#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <chrono>

#define MAXSIZE 10

typedef struct Point
{
    int x;
    int y;
    char name[5];
} Point;

typedef struct PointsList
{
    Point list[MAXSIZE];
    int size;
    int capacity;
} PointsList;

void addCoordinates(PointsList *points)
{
    if (points->size == MAXSIZE)
    {
        return;
    }

    int x = 0;
    int y = 0;
    char name[5] = {};

    printf("Enter X: ");
    scanf("%d", &x);

    printf("Enter Y: ");
    scanf("%d", &y);

    printf("Enter name: ");
    scanf("%s", name);

    getchar();

    Point point;
    point.x = x;
    point.y = y;
    strcpy(point.name, name);

    points->list[points->size] = point;
    points->size++;

    printf("Point added!\n");
}

void printPointsList(PointsList *points)
{
    if (points->size == 0)
    {
        return;
    }

    for (int i = 0; i < points->size; i++)
    {
        Point point = points->list[i];

        if (point.x == point.y && point.x >= 0)
        {
            printf("**Point: %s(%d, %d)\n", point.name, point.x, point.y);
        }
        else
        {
            printf("Point: %s(%d, %d)\n", point.name, point.x, point.y);
        }
    }
}

int main()
{
    PointsList points;
    addCoordinates(&points);
    addCoordinates(&points);
    addCoordinates(&points);

    printPointsList(&points);

    return 0;
}