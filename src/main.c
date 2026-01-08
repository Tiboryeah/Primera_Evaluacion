#include "../include/files.h"
#include "../include/sorting.h"
#include "../include/ui.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
  int *data = NULL;
  int count = 0;
  int main_op = 0;
  int alg_op = 0;

  while (1) {
    main_op = show_main_menu();

    if (main_op == 2) { // Salir
      break;
    }

    if (main_op == 1) { // Cargar Datos
      read_ages_from_file(&data, &count);

      if (data != NULL && count > 0) {
        wait_for_user();

        // Generar respaldo automático
        write_backup_file(data, count);
        wait_for_user();

        // Sub-menú de algoritmos
        while (1) {
          alg_op = show_algorithm_menu();

          if (alg_op == 5)
            break; // Regresar

          switch (alg_op) {
          case 1:
            bubble_sort(data, count);
            wait_for_user();
            break;
          case 2:
            selection_sort(data, count);
            wait_for_user();
            break;
          case 3:
            insertion_sort(data, count);
            wait_for_user();
            break;
          case 4:
            print_data(data, count);
            wait_for_user();
            break;
          }
        }
      } else {
        printf("\nNo se pudieron cargar datos. Intente nuevamente.\n");
        wait_for_user();
      }
    }
  }

  if (data != NULL) {
    free(data);
  }

  printf("\nPrograma finalizado.\n");
  return 0;
}
