#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

int main() {
    // TEST 1 — merge_aux
    int A[] = {1, 3, 5, 7}, B[] = {2, 4, 6, 8};
    int *C = merge_aux(A, 4, B, 4);
    printf("Résultat merge_aux : ");
    for (int i = 0; i < 8; i++) printf("%d ", C[i]);
    printf("\n");
    delete_array(C);

    // TEST 2 — merge
    int T[] = {1, 3, 5, 7, 2, 4, 6, 8};
    merge(T, 0, 3, 7);
    printf("Résultat merge : ");
    for (int i = 0; i < 8; i++) printf("%d ", T[i]);
    printf("\n");

    // TEST 3 — merge_sort avec numéro étudiant
    int ID[] = {2, 0, 2, 3, 0, 7, 7, 8};
    int size = sizeof(ID) / sizeof(ID[0]);
    printf("Original array : ");
    for (int i = 0; i < size; i++) printf("%d ", ID[i]);
    printf("\n");

    merge_sort(ID, 0, size - 1);

    printf("Sorted array : ");
    for (int i = 0; i < size; i++) printf("%d ", ID[i]);
    printf("\n");

    // TEST 4 — Analyse complexité
    int *sizes = new_array(15);
    sizes[0] = 1;
    for (int i = 1; i < 15; i++) sizes[i] = 2 * sizes[i - 1];

    printf("\nn\t#calls\t#comp.\tnlogn\tc*nlogn\n");

    for (int i = 0; i < 15; i++) {
        int n = sizes[i];
        int *a = new_array(n);
        build_array(a, n);

        reset_counters();
        merge_sort(a, 0, n - 1);
        double nlogn = n * log2(n);
        double c = (double) counter_iter / nlogn;

        printf("%d\t%d\t%d\t%.2f\t%.2f\n", n, counter_rec, counter_iter, nlogn, c * nlogn);

        delete_array(a);
    }

    delete_array(sizes);
    return 0;
}
