#include <stdio.h>
#include <stdlib.h>

void writeNumsToFile()
{
    FILE *f = fopen("./nums", "wb");

    while (true)
    {

        printf("Enter num: ");
        int input = 0;
        scanf("%d", &input);

        fwrite(&input, sizeof(int), 1, f);
        // fprintf(f, "%d\n", input);

        if (input == 0)
        {
            break;
        }
    }

    fclose(f);
}

void readNumsFromFile()
{
    FILE *f = fopen("./nums", "rb");

    if (f == NULL)
    {
        printf("FILE NOT FOUND\n");
        return;
    }

    while (true)
    {
        int num = 0;
        // fscanf(f, "%d", &num);
        fread(&num, sizeof(int), 1, f);
        printf("Num: %d\n", num);

        if (feof(f))
        {
            return;
        }
    }

    fclose(f);
}

typedef struct Object
{
    char name[65];
    char color[15];
    float area;
    char uid[65];
} Object;

void structsToFile()
{
    Object objects[3] = {
        {"n1", "red", 25.0, "123"},
        {"n2", "green", 125.0, "122"},
        {"n3", "blue", 225.0, "133"}};

    FILE *f = fopen("objects", "wb");

    // for (int i = 0; i < 3; i++)
    {
        fwrite(objects, sizeof(Object), 3, f);
    }

    fclose(f);
}

void structsFromFile()
{
    FILE *f = fopen("objects", "rb");

    if (f == NULL)
    {
        printf("FILE IS NOT FOUND!\n");
        return;
    }

    Object objects[3] = {};

    for (int i = 0; i < 3; i++)
    {
        Object object;
        fread(&object, sizeof(object), 1, f);

        objects[i] = object;
    }

    float area = 0;

    for (int i = 0; i < 3; i++)
    {
        area += objects[i].area;
    }

    printf("Total area: %.2f\n", area);

    fclose(f);
}

int main()
{
    // writeNumsToFile();
    // readNumsFromFile();
    structsToFile();
    structsFromFile();

    return 0;
}