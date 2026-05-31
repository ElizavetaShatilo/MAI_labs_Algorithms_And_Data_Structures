#include <stdio.h>
#include "deque.h"

// Создание пустого дека
void deque_create(deque *d) {
    d->size = 0;
    d->front = 0;
    d->rear = -1;
}

// Проверка на пустоту
bool deque_is_empty(const deque *d) {
    return d->size == 0;
}

// Проверка на заполненность
bool deque_is_full(const deque *d) {
    return d->size == DEQUE_CAPACITY;
}

// Получение текущего размера
size_t deque_size(const deque *d) {
    return d->size;
}

// Добавление элемента в начало
void deque_push_front(deque *d, const data_type item) {
    if (deque_is_full(d)) return;
    
    // Сдвигаем указатель front влево
    d->front = (d->front - 1 + DEQUE_CAPACITY) % DEQUE_CAPACITY;
    d->data[d->front] = item;
    d->size++;
}

// Добавление элемента в конец
void deque_push_back(deque *d, const data_type item) {
    if (deque_is_full(d)) return;
    
    // Сдвигаем указатель rear вправо
    d->rear = (d->rear + 1) % DEQUE_CAPACITY;
    d->data[d->rear] = item;
    d->size++;
}

// Удаление элемента из начала
void deque_pop_front(deque *d) {
    if (deque_is_empty(d)) return;
    
    // Сдвигаем указатель front вправо
    d->front = (d->front + 1) % DEQUE_CAPACITY;
    d->size--;
}

// Удаление элемента из конца
void deque_pop_back(deque *d) {
    if (deque_is_empty(d)) return;
    
    // Сдвигаем указатель rear влево
    d->rear = (d->rear - 1 + DEQUE_CAPACITY) % DEQUE_CAPACITY;
    d->size--;
}

// Просмотр первого элемента
data_type deque_front(const deque *d) {
    return d->data[d->front];
}

// Просмотр последнего элемента
data_type deque_back(const deque *d) {
    return d->data[d->rear];
}

// Получение элемента по индексу (для сортировки)
data_type deque_get(const deque *d, size_t index) {
    return d->data[(d->front + index) % DEQUE_CAPACITY];
}

// Установка элемента по индексу (для сортировки)
void deque_set(deque *d, size_t index, const data_type item) {
    d->data[(d->front + index) % DEQUE_CAPACITY] = item;
}

// Печать содержимого дека
void deque_print(const deque *d) {
    printf("Deque (size=%zu): ", d->size);
    printf("[");
    for (size_t i = 0; i < d->size; i++) {
        data_type elem = deque_get(d, i);
        printf("(%d,%d)", elem.key, elem.value);
        if (i < d->size - 1) printf(", ");
    }
    printf("]\n");
}

// Вставка элемента
void deque_insert(deque *d, const data_type item) {
    deque_push_back(d, item);
}

// Удаление элемента по ключу
void deque_erase(deque *d, const key_type key) {
    for (size_t i = 0; i < d->size; i++) {
        data_type elem = deque_get(d, i);
        if (elem.key == key) {
            for (size_t j = i; j < d->size - 1; j++) {
                deque_set(d, j, deque_get(d, j + 1));
            }
            deque_pop_back(d);
            return;
        }
    }
}

// Конкатенация двух деков
// Добавляет все элементы из дека b в конец дека a
void deque_concat(deque *a, const deque *b) {
    for (size_t i = 0; i < b->size; i++) {
        if (deque_is_full(a)) return;
        deque_push_back(a, deque_get(b, i));
    }
}