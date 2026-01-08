#ifndef FILES_H
#define FILES_H

/**
 * Lee las edades desde un archivo de texto.
 *
 * @param data Puntero doble donde se almacenará el arreglo dinámico.
 * @param count Puntero donde se almacenará la cantidad de elementos leídos.
 */
void read_ages_from_file(int **data, int *count);

/**
 * Escribe las edades en un archivo de respaldo.
 *
 * @param data Arreglo de edades.
 * @param count Cantidad de elementos.
 */
void write_backup_file(int *data, int count);

#endif
