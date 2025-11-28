#include <stdio.h>

// Struktur untuk menyimpan data material
typedef struct {
    int z;   // Nomor Atom
    double density;   // Massa Jenis (g/cm^3)
    char name[20];   // Nama unsur
} element;

// Implementasi Binary Search untuk Struct
int find_element_binary(element table[], int n, int target_z) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (table[mid].z == target_z) {
            return mid;
        } else if (table[mid].z < target_z) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    // Dataset Parsial (Terurut berdasarkan Z)
    element periodic_table[] = {
        {1, 0.000089, "Hydrogen"},
        {2, 0.000178, "Helium"},
        {6, 2.26, "Carbon"},
        {13, 2.70, "Aluminum"},
        {14, 2.33, "Silicon"},
        {26, 7.87, "Iron"},
        {29, 8.96, "Copper"},
        {79, 19.32, "Gold"}
    };

    int n = 8;
    int search_z = 2; // Mencari Helium

    int index = find_element_binary(periodic_table, n, search_z);

    if (index != -1) {
        printf("Unsur Ditemukan: %s\n", periodic_table[index].name);
        printf("Nomor Atom: %d\n", periodic_table[index].z);
        printf("Massa Jenis: %.6f g/cm^3\n", periodic_table[index].density);
    } else {
        printf("Unsur dengan Z = %d tidak ada dalam database.\n", search_z);
    }

    return 0;
}