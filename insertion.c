#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000000   // Maximum dataset size

// Insertion Sort function
void insertionSort(int arr[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// PrintS first few elements to verify correctness
void printSample(int arr[], int n)
{
    int i, limit = n < 20 ? n : 20; // print max 20 elements
    for (i = 0; i < limit; i++)
    {
        printf("%d ", arr[i]);
    }
    if (n > 20)
        printf("...");  // THIS LINE indicate more elements exist
    printf("\n");
}

int main()
{
    int n, i;
    int *arr;
    int choice;

    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid input.\n");
        return 1;
    }

    arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Do you want to enter the data manually or generate automatically?\n");
    printf("Enter 1 for manual input, 2 for automatic generation: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter %d number(s):\n", n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
    }
    else
    {
        printf("Generating dataset automatically...\n");
        srand(time(NULL));
        for (i = 0; i < n; i++)
        {
            arr[i] = rand();
        }
        printf("Dataset generated.\n");
    }

    printf("Sample of unsorted array:\n");
    printSample(arr, n);

    printf("Starting insertion sort...\n");
    clock_t start = clock();

    insertionSort(arr, n);

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorting completed.\n");
    printf("Sample of sorted array:\n");
    printSample(arr, n);

    printf("Time taken to sort %d elements: %.3f seconds\n", n, time_taken);

    free(arr);

    return 0;
}
