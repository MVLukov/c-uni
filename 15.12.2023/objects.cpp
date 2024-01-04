#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <chrono>

typedef struct Object
{
    char color[10];
    char type[20];
    float area;
} Object;

typedef struct ObjectList
{
    Object list[10];
    int size;
} ObjectList;

void addObject(ObjectList *objects)
{
    if (objects->size + 1 == 10)
        return;

    char color[10];
    char type[20];
    float area = 0.0;

    printf("Enter color: ");
    scanf("%s", color);
    getchar();

    printf("Enter type: ");
    scanf("%s", type);
    getchar();

    printf("Enter area: ");
    scanf("%f", &area);
    getchar();

    Object object;
    object.area = area;
    strcpy(object.color, color);
    strcpy(object.type, type);

    objects->list[objects->size] = object;
    objects->size += 1;

    printf("Object added!\n");
}

void countRedObjects(ObjectList *objects)
{
    if (objects->size == 0)
    {
        return;
    }

    int count = 0;

    for (int i = 0; i < objects->size; i++)
    {
        Object object = objects->list[i];

        if (strcmp(object.color, "red") == 0)
        {
            count++;
        }
    }

    printf("Red objects: %d\n", count);
}

void totalAreaOfYellowObjects(ObjectList *objects)
{
    if (objects->size == 0)
    {
        return;
    }

    float area = 0;

    for (int i = 0; i < objects->size; i++)
    {
        Object object = objects->list[i];

        if (strcmp(object.color, "yellow") == 0)
        {
            area += object.area;
        }
    }

    printf("Yellow objects total area: %.2f\n", area);
}

void smallestWhiteArea(ObjectList *objects)
{
    if (objects->size == 0)
    {
        return;
    }

    float area = objects->list[0].area;

    for (int i = 0; i < objects->size; i++)
    {
        Object object = objects->list[i];

        if (strcmp(object.color, "white") == 0)
        {
            if (object.area < area)
            {
                area = (float)object.area;
            }
        }
    }

    printf("White objects smallest area: %.2f\n", area);
}

int main()
{
    ObjectList objects;
    objects.size = 0;

    addObject(&objects);
    addObject(&objects);
    addObject(&objects);
    addObject(&objects);
    addObject(&objects);

    countRedObjects(&objects);
    totalAreaOfYellowObjects(&objects);
    smallestWhiteArea(&objects);

    return 0;
}