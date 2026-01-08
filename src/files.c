#include "../include/files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void read_ages_from_file(int **data, int *count) {
  FILE *file;
  char path[100];
  int total = 0;
  int temp_val;
  int i = 0;

  // Podríamos mejorar esto pasando el path como argumento, pero mantenemos la
  // interactividad por ahora.
  printf("\nIngrese el nombre del archivo (ej. setdatosedades.txt): ");

  // Limpiar buffer
  while (getchar() != '\n' && !feof(stdin))
    ;

  if (scanf("%99[^\n]", path) != 1) {
    printf("Error leyendo la entrada.\n");
    return;
  }

  file = fopen(path, "r");
  if (file == NULL) {
    printf("\nError: No se pudo abrir el archivo '%s'.\n", path);
    *data = NULL;
    *count = 0;
    return;
  }

  printf("\nLeyendo archivo...\n");

  // Contar elementos
  while (fscanf(file, "%d", &temp_val) == 1) {
    total++;
  }

  if (total == 0) {
    printf("El archivo esta vacio.\n");
    fclose(file);
    *data = NULL;
    *count = 0;
    return;
  }

  rewind(file);

  // Asignar memoria
  if (*data != NULL)
    free(*data);
  *data = (int *)malloc(total * sizeof(int));
  if (*data == NULL) {
    printf("Error de memoria.\n");
    fclose(file);
    *count = 0;
    return;
  }

  // Leer datos
  while (i < total && fscanf(file, "%d", &(*data)[i]) == 1) {
    i++;
  }

  fclose(file);
  *count = total;
  printf("Lectura exitosa: %d edades cargadas.\n", total);
}

void write_backup_file(int *data, int count) {
  FILE *file;
  const char *filename = "edades_respaldo.txt";

  file = fopen(filename, "w");
  if (file == NULL) {
    printf("Error creando archivo de respaldo.\n");
    return;
  }

  fprintf(file, "--- Respaldo de Edades ---\n\n");
  for (int i = 0; i < count; i++) {
    fprintf(file, "Edad %d: %d\n", i + 1, data[i]);
  }

  fclose(file);
  printf("Archivo de respaldo '%s' creado exitosamente.\n", filename);
}
