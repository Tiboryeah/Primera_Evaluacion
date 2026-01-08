#ifndef UI_H
#define UI_H

/**
 * Muestra el menú principal y retorna la opción seleccionada.
 */
int show_main_menu();

/**
 * Muestra el menú de algoritmos de ordenamiento y retorna la opción.
 */
int show_algorithm_menu();

/**
 * Muestra las edades en pantalla (paginadas o resumidas).
 */
void print_data(int *data, int count);

/**
 * Pausa la ejecución hasta que el usuario presione Enter.
 */
void wait_for_user();

#endif
