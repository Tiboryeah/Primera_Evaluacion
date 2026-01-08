# Sorting Algorithms Benchmark

Este proyecto es una implementación modular en C diseñada para comparar el rendimiento de tres algoritmos clásicos de ordenamiento: **Bubble Sort**, **Selection Sort** e **Insertion Sort**.

## 🚀 Características

- **Modularidad**: Código separado en componentes lógicos (UI, I/O, Algoritmos).
- **Benchmark**: Medición precisa del tiempo de ejecución de cada algoritmo usando `clock()`.
- **Persistencia**: Lectura de datasets desde archivos de texto y generación de respaldos.
- **Portabilidad**: Código C estándar compatible con la mayoría de los compiladores.

## 🛠️ Estructura del Proyecto

```
.
├── include/        # Archivos de cabecera (.h)
├── src/            # Código fuente (.c)
├── Makefile        # Script de compilación automatizada
├── setdatosedades.txt # Dataset de prueba
└── README.md       # Documentación
```

## 📋 Requisitos

- Compilador GCC
- Make (opcional, pero recomendado)

## ⚙️ Compilación y Ejecución

Si tienes `make` instalado:

```bash
make run
```

Si deseas compilar manualmente:

```bash
gcc -Iinclude src/*.c -o sorting_benchmark.exe
./sorting_benchmark.exe
```

## 📊 Complejidad Algorítmica

| Algoritmo       | Mejor Caso | Caso Promedio | Peor Caso |
|-----------------|------------|---------------|-----------|
| **Bubble Sort** | O(n)       | O(n²)         | O(n²)     |
| **Selection**   | O(n²)      | O(n²)         | O(n²)     |
| **Insertion**   | O(n)       | O(n²)         | O(n²)     |

## 📝 Uso

1. Al iniciar, seleccione la opción para cargar datos.
2. Ingrese el nombre del archivo de datos (ej. `setdatosedades.txt`).
3. Seleccione el algoritmo que desea probar.
4. El programa mostrará los datos ordenados (parcialmente si son muchos) y el tiempo que tomó ordenarlos.

---
*Optimizado y refactorizado como demostración de buenas prácticas en programación estructurada.*
