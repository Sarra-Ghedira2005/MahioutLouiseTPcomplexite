//
// Created by user on 26/05/2025.
//
#ifndef MAIN_H
#define MAIN_H

// --- Variables globales ---
extern int counter_rec;
extern int counter_iter;

// --- Fonctions utilitaires ---
int *new_array(int n);
void delete_array(int *a);
void build_array(int *a, int n);

// --- Fonctions de comptage ---
void reset_counters();
void increment_counter_rec();
void increment_counter_iter();

// Les fonctions de tri:
int *merge_aux(int *a, int n, int *b, int m);
void merge(int *t, int l, int mid, int r);
void merge_sort(int *t, int l, int r);

#endif

