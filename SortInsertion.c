#include <stdio.h>

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;

    }
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(data) / sizeof(data[0]);

    insertion_sort(data, n);

    printf("Hasil Insertion Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d", data[i]);
        printf(i < n - 1 ? ", " : "\n");
    }

    return 0;
}