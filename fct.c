//
// Created by louis on 26/05/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

int counter_rec = 0;
int counter_iter = 0;

//Les fonctions de comptage
void reset_counters() {
    counter_rec = 0;
    counter_iter = 0;
}

void increment_counter_rec() {
    counter_rec++;
}

void increment_counter_iter() {
    counter_iter++;
}

//Utilitaires:
int *new_array(int n) {
    return (int *) malloc(n * sizeof(int));
}

void delete_array(int *a) {
    free(a);
}

void build_array(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = n - i;
    }
}

// --- MERGE AUX ---
// Complexité : O(n + m)
int *merge_aux(int *a, int n, int *b, int m) {
    int *c = new_array(n + m);
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
        increment_counter_iter();
    }

    while (i < n) c[k++] = a[i++];
    while (j < m) c[k++] = b[j++];

    return c;
}

// --- MERGE ---
// Complexité : O(r - l + 1)
void merge(int *t, int l, int mid, int r) {
    printf("Merging [%d, %d] and [%d, %d]\n", l, mid, mid + 1, r);

    int n1 = mid - l + 1;
    int n2 = r - mid;
    int *left = t + l;
    int *right = t + mid + 1;

    int *c = new_array(n1 + n2);
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            c[k++] = left[i++];
        } else {
            c[k++] = right[j++];
        }
        increment_counter_iter();
    }

    while (i < n1) c[k++] = left[i++];
    while (j < n2) c[k++] = right[j++];

    for (int i = l; i <= r; i++) {
        t[i] = c[i - l];
    }

    printf("Merged [%d, %d] and [%d, %d] into {", l, mid, mid + 1, r);
    for (int i = l; i <= r; i++) printf("%d ", t[i]);
    printf("}\n");

    delete_array(c);
}

// --- MERGE SORT ---
// Complexité : O(n log n)
void merge_sort(int *t, int l, int r) {
    printf("Sorting [%d, %d]\n", l, r);
    if (l < r) {
        increment_counter_rec();
        int mid = l + (r - l) / 2;
        merge_sort(t, l, mid);
        merge_sort(t, mid + 1, r);
        merge(t, l, mid, r);
    }
    printf("Sorted [%d, %d]\n", l, r);
}
