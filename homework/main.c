#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))
#define MAXLENGTH 10

typedef struct Animal
{
    char breed[51];
    char habitat[51];
    int age;
    float mass;
} Animal;

typedef struct Animals
{
    Animal *animalsArr;
    int capacity;
    int size;
} Animals;

void addNewAnimal(Animals *animals)
{
    char breed[51];
    char habitat[51];
    int age;
    float mass;

    printf("Please enter the breed: ");
    scanf("%s", breed);

    printf("Please enter the habitat: ");
    scanf("%s", habitat);

    printf("Please enter the age: ");
    scanf("%d", &age);

    printf("Please enter the mass: ");
    scanf("%f", &mass);

    if (strlen(breed) == 0 || strlen(habitat) == 0 || age < 0 || mass < 0)
    {
        printf("Invalid information provided!\n");
        return;
    }

    int size = animals->size;

    if (size == animals->capacity)
    {
        printf("No more space for animals!\n");
        return;
    }

    Animal animal;
    animal.age = age;
    animal.mass = mass;

    strcpy(animal.breed, breed);
    strcpy(animal.habitat, habitat);

    animals->animalsArr[size] = animal;
    animals->size += 1;

    printf("Animal added!\n");
    return;
}

void printAllAnimals(Animals *animals)
{
    if (animals->size == 0)
    {
        printf("No animals found!\n ");
        return;
    }

    for (int i = 0; i < animals->size; i++)
    {
        Animal animal = animals->animalsArr[i];

        printf("[%d] Breed: %s, Habitat: %s, Age: %d, Mass: %.2f\n", i + 1, animal.breed, animal.habitat, animal.age, animal.mass);
    }
}

void searchByBreed(Animals *animals)
{
    if (animals->size == 0)
    {
        printf("No animals found!\n");
        return;
    }

    char breed[51];

    printf("Enter breed to search: ");
    scanf("%s", breed);

    if (strlen(breed) == 0)
    {
        printf("Invalid information provided!\n");
        return;
    }

    int count = 0;

    for (int i = 0; i < animals->size; i++)
    {
        Animal animal = animals->animalsArr[i];

        if (strcmp(animal.breed, breed) == 0)
        {
            printf("[%d] Breed: %s, Habitat: %s, Age: %d, Mass: %.2f\n", i + 1, animal.breed, animal.habitat, animal.age, animal.mass);
            count++;
        }
    }

    printf("Total results found: %d\n", count);
}

int main()
{
    Animal animalsArr[MAXLENGTH];

    Animals animals;
    animals.animalsArr = animalsArr;
    animals.capacity = MAXLENGTH;
    animals.size = 0;

    printf("a - add new animal\np - print all animals\ns - search for animal by breed\ne - exit\n");

    while (1)
    {
        char input;

        printf("Please enter a command: ");
        scanf("\n%c", &input);
        // getchar();

        if (input == 'a')
        {
            addNewAnimal(&animals);
        }
        else if (input == 'p')
        {
            printAllAnimals(&animals);
        }
        else if (input == 's')
        {
            searchByBreed(&animals);
        }
        else if (input == 'e')
        {
            break;
        }
    }
    return 0;
}