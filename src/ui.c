#include "../include/ui.h"
#include <stdio.h>
#include <stdlib.h>


int show_main_menu() {
  int option = 0;
  do {
    system("cls"); // O "clear" en Linux/Mac, pero el usuario está en Windows
    printf("=========================================\n");
    printf("      BENCHMARK DE ORDENAMIENTO\n");
    printf("=========================================\n");
    printf("1. Cargar datos desde archivo\n");
    printf("2. Salir\n");
    printf("-----------------------------------------\n");
    printf("Seleccione una opcion: ");

    if (scanf("%d", &option) != 1) {
      while (getchar() != '\n')
        ; // Limpiar buffer
      option = 0;
    }
  } while (option < 1 || option > 2);
  return option;
}

int show_algorithm_menu() {
  int option = 0;
  do {
    system("cls");
    printf("=========================================\n");
    printf("      ALGORITMOS DE ORDENAMIENTO\n");
    printf("=========================================\n");
    printf("1. Bubble Sort (Burbuja)\n");
    printf("2. Selection Sort (Seleccion)\n");
    printf("3. Insertion Sort (Insercion)\n");
    printf("4. Ver datos originales\n");
    printf("5. Regresar al Menu Principal\n");
    printf("-----------------------------------------\n");
    printf("Seleccione una opcion: ");

    if (scanf("%d", &option) != 1) {
      while (getchar() != '\n')
        ;
      option = 0;
    }
  } while (option < 1 || option > 5);
  return option;
}

void print_data(int *data, int count) {
  system("cls");
  printf("\n--- Visualizacion de Datos ---\n");
  if (count == 0 || data == NULL) {
    printf("No hay datos cargados.\n");
    return;
  }

  int limit = (count > 50) ? 50 : count;
  for (int i = 0; i < limit; i++) {
    printf("%d ", data[i]);
    if ((i + 1) % 10 == 0)
      printf("\n");
  }

  if (count > 50) {
    printf("\n... y %d elementos mas.\n", count - 50);
  } else {
    printf("\n");
  }
}

void wait_for_user() {
  printf("\nPresione Enter para continuar...");
  while (getchar() != '\n')
    ;
  getchar();
}
