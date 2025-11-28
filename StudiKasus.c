#include <stdio.h>

// Menggunakan Bubble Sort sederhana untuk float / double
void simple_sort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            } 
        }
    }
}

int main() {
    // Data Energi Kinetik (dalam Joule)
    double energi[] = {4.5, 2.1, 0.5, 9.8, 1.2};
    int n = 5;

    printf("Energi Sebelum: ");
    for (int i = 0; i < n; i++) {
        printf("%.1f", energi[i]);
        printf(i < n - 1 ? ", " : "\n");
    }

    simple_sort(energi, n);

    printf("\nEnergi Sesudah: ");
    for (int i = 0; i < n; i++) {
        printf("%.1f", energi[i]);
        printf(i < n - 1 ? ", " : "\n");
    }

    return 0;
}