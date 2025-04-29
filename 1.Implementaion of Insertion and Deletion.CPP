#include <stdio.h>

#define MAX 100

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertAtPosition(int arr[], int *size, int element, int position) {
    if (*size >= MAX) {
        printf("Insertion failed: Array is full.\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Insertion failed: Invalid position.\n");
        return;
    }
    // Shift elements to the right
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i-1];
    }
    arr[position] = element;
    (*size)++;
    printf("Inserted %d at position %d.\n", element, position);
}

void deleteAtPosition(int arr[], int *size, int position) {
    if (*size == 0) {
        printf("Deletion failed: Array is empty.\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("Deletion failed: Invalid position.\n");
        return;
    }
    printf("Deleted element %d from position %d.\n", arr[position], position);
    // Shift elements to the left
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i+1];
    }
    (*size)--;
}

int main() {
    int arr[MAX], size, choice, element, position;

    printf("Enter initial size of the array: ");
    scanf("%d", &size);

    if (size > MAX || size < 0) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at a position\n");
        printf("2. Delete from a position\n");
        printf("3. Display array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert at (0-based index): ");
                scanf("%d", &position);
                insertAtPosition(arr, &size, element, position);
                break;

            case 2:
                printf("Enter position to delete from (0-based index): ");
                scanf("%d", &position);
                deleteAtPosition(arr, &size, position);
                break;

            case 3:
                displayArray(arr, size);
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

