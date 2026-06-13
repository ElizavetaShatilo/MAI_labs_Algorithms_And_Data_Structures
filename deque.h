#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>
#include <stddef.h>

#define DEQUE_CAPACITY 100

typedef int key_type;
typedef int value_type;

// Структура элемента дека
typedef struct {
    key_type key;
    value_type value;
} data_type;

// Структура дека
typedef struct {

    data_type data[DEQUE_CAPACITY];
    size_t size;
    int front;
    int rear;
} deque;

// Базовые операции с деком
void deque_create(deque *d);
bool deque_is_empty(const deque *d);
bool deque_is_full(const deque *d);
size_t deque_size(const deque *d);

// Операции добавления и удаления
void deque_push_front(deque *d, const data_type item);
void deque_push_back(deque *d, const data_type item);
void deque_pop_front(deque *d);
void deque_pop_back(deque *d);

// Операции просмотра
data_type deque_front(const deque *d);
data_type deque_back(const deque *d);
void deque_print(const deque *d);

// Вспомогательные операции
void deque_insert(deque *d, const data_type item);
void deque_erase(deque *d, const key_type key);

// Процедура №3: конкатенация двух деков
void deque_concat(deque *a, const deque *b);

// Доступ по индексу (для сортировки)
data_type deque_get(const deque *d, size_t index);
void deque_set(deque *d, size_t index, const data_type item);

#endif