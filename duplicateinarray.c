#include <stdio.h>
#include <stdlib.h>

void printDuplicates(int arr[], int size) {
    int *frequency = (int *)calloc(1000000, sizeof(int));
    int hasDuplicates = 0;

    for (int i = 0; i < size; i++) {
        frequency[arr[i]]++;
    }

    for (int i = 0; i < size; i++) {
        if (frequency[arr[i]] > 1) {
            printf("%d ", arr[i]);
            frequency[arr[i]] = 0;
            hasDuplicates = 1;
        }
    }

    if (!hasDuplicates) {
        printf("-1\n");
    }

    free(frequency);
}

int main() {
    int array1[] = {2, 10, 10, 100, 2, 10, 11, 2, 11, 2};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    printf("Duplicates in array 1: ");
    printDuplicates(array1, size1);

    printf("\n");

    int array2[] = {5, 40, 1, 40, 100000, 1, 5, 1};
    int size2 = sizeof(array2) / sizeof(array2[0]);
    printf("Duplicates in array 2: ");
    printDuplicates(array2, size2);

    return 0;
}
