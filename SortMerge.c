#include <stdio.h>

void merge(int arr[], int kiri, int tengah, int kanan) {
    int i, j, k;
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    int l[n1], r[n2];

    for (i = 0; i < n1; i++) {
        l[i] = arr[kiri + i];
    }
    for (j = 0; j < n2; j++) {
        r[j] = arr[tengah + 1 + j];
    }

    i = 0;
    j = 0;
    k = kiri;

    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            arr[k] = l[i];
            i++;
        } else {
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = l[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = r[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        merge_sort(arr, kiri, tengah);
        merge_sort(arr, tengah + 1, kanan);
        merge(arr, kiri, tengah, kanan);
    }
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(data) / sizeof(data[0]);

    merge_sort(data, 0, n - 1);

    printf("Hasil Merge Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d", data[i]);
        printf(i < n - 1 ? ", " : "\n");
    }

    return 0;
}