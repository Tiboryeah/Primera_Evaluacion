CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Lista de fuentes y objetos
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Nombre del ejecutable
TARGET = $(BIN_DIR)/sorting_benchmark

# Regla principal
all: directories $(TARGET)

# Crear directorios necesarios
directories:
	@if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"
	@if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"

# Enlazar objetos
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

# Compilar fuentes a objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	@if exist "$(OBJ_DIR)" rmdir /s /q "$(OBJ_DIR)"
	@if exist "$(BIN_DIR)" rmdir /s /q "$(BIN_DIR)"
	@echo Limpieza completada.

# Ejecutar el programa
run: all
	$(TARGET)

.PHONY: all clean run directories
