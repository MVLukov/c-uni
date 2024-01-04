#include <stdio.h>
#include <stdlib.h>

void addNumsToFile()
{
    FILE *f = fopen("./nums2", "wb");

    while (true)
    {

        printf("Enter num: ");
        int input = 0;
        scanf("%d", &input);

        if (input == 0)
            break;

        fwrite(&input, sizeof(int), 1, f);
    }

    fclose(f);
}

void readNumsFromFile()
{
    FILE *f = fopen("./nums2", "rb");

    int numsSize = 10;
    int *nums = new int[numsSize]; //(int *)malloc(sizeof(int) * numsSize);
    int idx = 0;

    if (f == NULL)
    {
        printf("FILE NOT FOUND\n");
        return;
    }

    while (true)
    {
        if (idx == numsSize - 1)
        {
            // int *tmp = (int *)malloc(sizeof(int) * numsSize * 2);
            numsSize *= 2;
            nums = (int *)realloc(nums, sizeof(nums) * numsSize);
        }

        int num = 0;
        // fscanf(f, "%d", &num);
        fread(&num, sizeof(int), 1, f);
        nums[idx] = num;
        idx++;
        printf("Num: %d\n", num);

        if (feof(f))
        {
            return;
        }
    }

    fclose(f);
    free(nums);
}

int main()
{
    addNumsToFile();
    readNumsFromFile();
    return 0;
}