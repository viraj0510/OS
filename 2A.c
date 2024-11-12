#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



int main() {
    int n, i;
    pid_t pid;

    printf("Enter number of integers to sort: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the integers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }



    pid = fork();

    if (pid == 0) {

        printf("Child Process: Sorting the array...\n");
        bubbleSort(arr, n);
        printf("Child Process: Sorted array is: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");


        sleep(5);
        
        printf("Child Process: Exiting.\n");
        exit(0);  
    } else {
        
        printf("Parent Process: Sorting the array...\n");
        bubbleSort(arr, n);
        printf("Parent Process: Sorted array is: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        wait(NULL);
        printf("Parent Process: Child has finished execution.\n");

        sleep(2);
        printf("Parent Process: Exiting.\n");
    }

    return 0;
}
