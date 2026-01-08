#include "../include/sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubble_sort(int *arr, int n) {
  int *temp_arr;
  int aux;
  clock_t start_time, end_time;
  double seconds;
  int i, j;

  // Crear una copia para no modificar el arreglo original (para propósitos de
  // demostración)
  temp_arr = (int *)malloc(n * sizeof(int));
  if (temp_arr == NULL) {
    printf("Error: No se pudo asignar memoria.\n");
    return;
  }
  for (int z = 0; z < n; z++)
    temp_arr[z] = arr[z];

  start_time = clock();

  // Algoritmo Burbuja
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (temp_arr[j] > temp_arr[j + 1]) {
        aux = temp_arr[j];
        temp_arr[j] = temp_arr[j + 1];
        temp_arr[j + 1] = aux;
      }
    }
  }

  end_time = clock();
  seconds = (double)(end_time - start_time) / CLOCKS_PER_SEC;

  printf("\n--- Resultados Ordenamiento Burbuja ---\n");
  // Mostrar solo los primeros 10 y últimos 10 si son muchos datos
  int limit = (n > 20) ? 10 : n;
  for (int x = 0; x < limit; x++) {
    printf("Edad %d: %d\n", x + 1, temp_arr[x]);
  }
  if (n > 20)
    printf("... (%d datos mas) ...\n", n - 20);

  printf("\nTiempo de ejecucion: %.6f segundos\n", seconds);

  free(temp_arr);
}

void selection_sort(int *arr, int n) {
  int *temp_arr;
  int min_idx, aux;
  clock_t start_time, end_time;
  double seconds;
  int i, j;

  temp_arr = (int *)malloc(n * sizeof(int));
  if (temp_arr == NULL)
    return;
  for (int z = 0; z < n; z++)
    temp_arr[z] = arr[z];

  start_time = clock();

  // Algoritmo de Selección
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (temp_arr[j] < temp_arr[min_idx]) {
        min_idx = j;
      }
    }
    aux = temp_arr[min_idx];
    temp_arr[min_idx] = temp_arr[i];
    temp_arr[i] = aux;
  }

  end_time = clock();
  seconds = (double)(end_time - start_time) / CLOCKS_PER_SEC;

  printf("\n--- Resultados Ordenamiento Seleccion ---\n");
  int limit = (n > 20) ? 10 : n;
  for (int x = 0; x < limit; x++) {
    printf("Edad %d: %d\n", x + 1, temp_arr[x]);
  }
  if (n > 20)
    printf("... (%d datos mas) ...\n", n - 20);

  printf("\nTiempo de ejecucion: %.6f segundos\n", seconds);

  free(temp_arr);
}

void insertion_sort(int *arr, int n) {
  int *temp_arr;
  int key, j;
  clock_t start_time, end_time;
  double seconds;
  int i;

  temp_arr = (int *)malloc(n * sizeof(int));
  if (temp_arr == NULL)
    return;
  for (int z = 0; z < n; z++)
    temp_arr[z] = arr[z];

  start_time = clock();

  // Algoritmo de Inserción
  for (i = 1; i < n; i++) {
    key = temp_arr[i];
    j = i - 1;
    while (j >= 0 && temp_arr[j] > key) {
      temp_arr[j + 1] = temp_arr[j];
      j = j - 1;
    }
    temp_arr[j + 1] = key;
  }

  end_time = clock();
  seconds = (double)(end_time - start_time) / CLOCKS_PER_SEC;

  printf("\n--- Resultados Ordenamiento Insercion ---\n");
  int limit = (n > 20) ? 10 : n;
  for (int x = 0; x < limit; x++) {
    printf("Edad %d: %d\n", x + 1, temp_arr[x]);
  }
  if (n > 20)
    printf("... (%d datos mas) ...\n", n - 20);

  printf("\nTiempo de ejecucion: %.6f segundos\n", seconds);

  free(temp_arr);
}
