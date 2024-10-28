#ifndef MEMORY_H
#define MEMORY_H

#include <cstdlib>

// Función para asignar memoria dinámicamente
template <typename T>
T* allocateMemory(size_t size) {
    return new T[size];
}

// Función para liberar memoria asignada dinámicamente
template <typename T>
void deallocateMemory(T* ptr) {
    delete[] ptr;
}

#endif // MEMORY_H