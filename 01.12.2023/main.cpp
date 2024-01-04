#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>

#define LEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))

void read_reverse()
{
    char name[64];

    printf("Enter name: ");
    fgets(name, 64, stdin);

    for (int i = (int)strlen(name) - 1; i >= 0; i--)
    {
        printf("%c", name[i]);
    }

    printf("\n");
}

void count_symbols()
{
    char input[64];

    printf("Enter input: ");
    fgets(input, 64, stdin);

    int count = 0;

    for (int i = 0; i < (int)strlen(input) - 1; i++)
    {
        switch (input[i])
        {
        case '.':
            count++;
            break;
        case ',':
            count++;
            break;
        case '!':
            count++;
            break;
        case '?':
            count++;
            break;
        case '-':
            count++;
            break;
        case ';':
            count++;
            break;
        default:
            break;
        }
    }

    printf("Count: %d\n", count);
}

void count_letter()
{
    char input[5][64];

    int count = 0;

    for (int i = 0; i < LEN(input); i++)
    {
        printf("Enter word [%d]: ", i);
        fgets(input[i], 64, stdin);

        for (int j = 0; j < (int)strlen(input[i]) - 1; j++)
        {
            if (input[i][j] == 'a' || input[i][j] == 'A')
            {
                count++;
            }
        }
    }

    printf("Count of a/A is: %d\n", count);
}

char *array_splice(char *arr, int length, int start, int end)
{
    char *result = (char *)malloc(sizeof(char) * (end - start + 1));
    int idx = 0;

    for (int i = 0; i < length; i++)
    {
        if (i >= start && i <= end)
        {
            result[idx] = arr[i];
            idx++;
        }
    }
    return result;
}

void longest_word()
{
    char input[64] = "This is a simple sentence.";

    int max = 0;
    int idx[2] = {};
    int wordCount = 0;

    for (int i = 0; i < (int)strlen(input); i++)
    {
        if (!isspace(input[i]) && input[i] != '.')
        {
            wordCount++;
        }
        else
        {
            if (wordCount > max)
            {
                max = wordCount;
                idx[0] = i - max;
                idx[1] = i - 1;
            }
            wordCount = 0;
        }
    }

    char *word = array_splice(input, (int)strlen(input), idx[0], idx[1]);
    printf("Longest word [%s] count: %d\n", word, max);

    free(word);
}

void reversed_num()
{
    char input[6] = "121";
    char reversed[6];
    int idx = 0;

    for (int i = (int)strlen(input) - 1; i >= 0; i--)
    {
        reversed[idx] = input[i];
        idx++;
    }

    if (strcmp(input, reversed) == 0)
    {
        printf("Num reversed [%s] is equal to num [%s]\n", reversed, input);
    }
    else
    {
        printf("Num reversed [%s] is not equal to num [%s]\n", reversed, input);
    }
}

void middleName_add()
{
    char name[64] = "Ivan Petrov";
    char middleName[64];
    char newName[64];
    char *splitted_name;

    printf("Enter middle name: ");
    fgets(middleName, 64, stdin);

    splitted_name = strtok(name, " ");

    int idx = 0;
    int idxSplitted = 0;

    while (splitted_name != NULL)
    {
        if (idxSplitted == 1)
        {
            for (char *ch = middleName; *ch != '\n'; ch++)
            {
                newName[idx] = *ch;
                idx++;
            }
        }
        else
        {
            for (char *ch = splitted_name; *ch != '\0'; ch++)
            {
                newName[idx] = *ch;
                idx++;
            }

            splitted_name = strtok(NULL, " ");
        }

        idxSplitted++;
        newName[idx++] = ' ';
    }

    newName[idx++] = '\0';

    printf("%s\n", newName);
}

int main()
{
    // read_reverse();
    // count_symbols();
    // count_letter();
    // longest_word();
    // reversed_num();
    middleName_add();

    return 0;
}