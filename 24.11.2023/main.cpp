#include <stdio.h>

#define LEN(arr) ((int)((sizeof(arr) / sizeof(arr[0]))))

void students_marks()
{
    int arr[5][5] = {
        {2, 3, 3, 4, 5},
        {4, 5, 3, 4, 6},
        {3, 3, 4, 4, 5},
        {5, 5, 6, 4, 5},
        {6, 4, 5, 3, 5}};

    int markSum = 0;
    int markCount = 0;

    for (int i = 0; i < LEN(arr); i++)
    {
        int tempMarkSum = 0;
        int tempMarkCount = 0;
        int worstMarkCount = 0;

        for (int k = 0; k < LEN(arr[i]); k++)
        {
            markSum += arr[i][k];
            tempMarkCount += 1;
        }

        if (worstMarkCount < 2)
        {
            markSum += tempMarkSum;
            markCount += tempMarkCount;
        }
    }

    float avgMark = (float)markSum / markCount;

    printf("Average marks of all students: %.2f\n", avgMark);
}

void smallest_numbers_in_array()
{
    int arr[5][5] = {
        {2, 5, 4, -5, 3},
        {12, 15, -40, -5, 3},
        {200, 351, 681, -521, 1337},
        {-1, -5, -100, -4, 3},
        {1, 2, 3, -5, 10}};

    int idxArr[LEN(arr)] = {};

    for (int i = 0; i < LEN(arr); i++)
    {
        int idx = 0;
        int min = arr[i][0];

        for (int k = 0; k < LEN(arr[i]); k++)
        {
            if (arr[i][k] < min)
            {
                min = arr[i][k];
                idx = k;
            }
        }

        idxArr[i] = idx;
    }

    for (int i = 0; i < LEN(idxArr); i++)
    {
        printf("Smallest num in arr[%d][%d] is %d\n", i, idxArr[i], arr[i][idxArr[i]]);
    }
}

void product_nums_array()
{
    int arr[5][5] = {
        {2, 5, 4, 0, 3},
        {12, 15, -40, -5, 3},
        {0, 351, 0, -521, 1337},
        {-1, -5, -100, -4, 0},
        {1, 0, 3, -5, 10}};

    int productArr[LEN(arr)];

    for (int i = 0; i < LEN(arr); i++)
    {
        int product = 1;

        for (int k = 0; k < LEN(arr[i]); k++)
        {
            if (arr[i][k] != 0)
            {
                product *= arr[i][k];
            }
        }

        productArr[i] = product;
    }

    for (int i = 0; i < LEN(productArr); i++)
    {
        printf("Product for arr[%d] is: %d\n", i, productArr[i]);
    }
}

void avg_nums_array()
{
    int arr[5][5] = {
        {2, 5, 4, 0, 3},
        {12, 15, -40, -5, 3},
        {0, 351, 0, -521, 1337},
        {-1, -5, -100, -4, 0},
        {1, 0, 3, -5, 10}};

    float avgArr[LEN(arr)];

    for (int i = 0; i < LEN(arr); i++)
    {
        int tempSum = 0;
        int tempCount = 0;

        for (int k = 0; k < LEN(arr[i]); k++)
        {
            if (arr[i][k] != 0)
            {
                tempSum += arr[i][k];
                tempCount += 1;
            }
        }

        float avg = (float)tempSum / tempCount;

        avgArr[i] = avg;
    }

    for (int i = 0; i < LEN(avgArr); i++)
    {
        printf("Avg for arr[%d] is: %.2f\n", i, avgArr[i]);
    }
}

void sum_not_on_diagonals_array()
{
    int arr[5][5] = {
        {2, 3, 3, 4, 5},  // 3 + 3 + 4 = 10
        {4, 5, 3, 4, 6},  // 4 + 3 + 6 = 13
        {3, 3, 4, 4, 5},  // 3 + 3 + 4 + 5 = 15
        {5, 5, 6, 4, 5},  // 5 + 6 + 5 = 16
        {6, 4, 5, 3, 5}}; // 4 + 5 + 3 = 12

    int sum = 0;

    for (int i = 0; i < LEN(arr); i++)
    {
        int tmpSum = 0;

        for (int j = 0; j < LEN(arr[i]); j++)
        {
            int idxDigA = i;
            int idxDigB = (LEN(arr[i]) - 1) - i;

            if (idxDigA != j)
            {
                if (idxDigB != j)
                {
                    tmpSum += arr[i][j];
                }
            }
        }

        printf("SUM: %d\n", tmpSum);
        sum += tmpSum;
    }

    printf("SUM: %d\n", sum);
}

void acceding_array()
{
    int arr[5][5] = {
        {2, 3, 3, 4, 5},
        {4, 5, 7, 9, 14}, // acd
        {3, 4, 4, 4, 5},
        {-15, -10, -9, -7, 5}, // acd
        {6, 4, 5, 3, 5}};

    bool arrIdx[LEN(arr)];

    for (int i = 0; i < LEN(arr); i++)
    {
        arrIdx[i] = true;

        for (int j = 1; j < LEN(arr[i]); j++)
        {
            int prev = arr[i][j - 1];

            if (arr[i][j] <= prev)
            {
                arrIdx[i] = false;
                break;
            }
        }
    }

    for (int i = 0; i < LEN(arrIdx); i++)
    {
        printf("Acceding rows: arr[%d]: %s\n", i, (arrIdx[i] == true ? "Yes" : "No"));
    }
}

void volume_rooms()
{
    float rooms[4][4] = {
        {2.45, 3.50, 2.5, 0.0},
        {12, 15.50, 4.5, 0.0},
        {8.75, 4.50, 2.5, 0.0},
        {5.75, 3.50, 3, 0.0},
    };

    float maxVolume[2] = {};

    for (int i = 0; i < LEN(rooms); i++)
    {
        float volume = rooms[i][0] * rooms[i][1] * rooms[i][2];
        rooms[i][3] = volume;

        if (volume > maxVolume[1])
        {
            maxVolume[0] = i;
            maxVolume[1] = volume;
        }
    }

    printf("Room with biggest volume is: %.0f, %.2f m^3\n", maxVolume[0], maxVolume[1]);
}

void magic_square()
{
    int const SIZE_SQUARE = 3;

    int arr[SIZE_SQUARE][SIZE_SQUARE] = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}};

    int sumDigA = 0;
    int sumDigB = 0;

    int rowsSum[3];
    int colsSum[3];

    for (int i = 0; i < LEN(arr); i++)
    {
        int tmpSumRow = 0;

        for (int j = 0; j < LEN(arr[i]); j++)
        {
            if (i == j)
            {
                sumDigA += arr[i][j];
            }

            if ((LEN(arr[i]) - 1) - i == j)
            {
                sumDigB += arr[i][j];
            }

            tmpSumRow += arr[i][j];
        }

        rowsSum[i] = tmpSumRow;
    }

    for (int i = 0; i < LEN(arr); i++)
    {
        int tmpColSum = 0;

        for (int j = 0; j < LEN(arr[i]); j++)
        {
            tmpColSum += arr[j][i];
        }

        colsSum[i] = tmpColSum;
    }

    // printf("dig SIZE_SQUARE: %d\n", sumDigA);
    // printf("dig b: %d\n", sumDigB);

    int equalCount = 0;

    if (sumDigA == sumDigB)
    {
        equalCount += 2;
    }

    for (int i = 0; i < LEN(rowsSum); i++)
    {
        if (sumDigA == rowsSum[i])
        {
            equalCount += 1;
        }

        if (sumDigA == colsSum[i])
        {
            equalCount += 1;
        }
        // printf("Row [%d]: %d\n", i, rowsSum[i]);
    }

    if (equalCount == (SIZE_SQUARE * 2) + 2)
    {
        printf("Square is magic\n");
    }
    else
    {
        printf("Square is not magic\n");
    }

    // printf("Equals: %d\n", equalCount);
}

int main()
{
    // students_marks();
    // smallest_numbers_in_array();
    // product_nums_array();
    // avg_nums_array();
    // sum_not_on_diagonals_array();
    acceding_array();

    // volume_rooms();
    // magic_square();

    return 0;
}