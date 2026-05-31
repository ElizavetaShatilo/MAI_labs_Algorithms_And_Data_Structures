#include "deque.h"

// Вспомогательная функция: обмен двух элементов
static void swap(data_type *a, data_type *b) {
    data_type temp = *a;
    *a = *b;
    *b = temp;
}

// Функция разделения для быстрой сортировки
static int partition(deque *d, int low, int high) {
    // Выбираем опорный элемент
    int mid = (low + high) / 2;
    
    // Медиана из трех: low, mid, high
    // Сортируем эти три элемента
    if (deque_get(d, low).key > deque_get(d, mid).key)
        swap(&d->data[(d->front + low) % DEQUE_CAPACITY], 
             &d->data[(d->front + mid) % DEQUE_CAPACITY]);
    if (deque_get(d, low).key > deque_get(d, high).key)
        swap(&d->data[(d->front + low) % DEQUE_CAPACITY], 
             &d->data[(d->front + high) % DEQUE_CAPACITY]);
    if (deque_get(d, mid).key > deque_get(d, high).key)
        swap(&d->data[(d->front + mid) % DEQUE_CAPACITY], 
             &d->data[(d->front + high) % DEQUE_CAPACITY]);
    
    // Опорный элемент - медиана
    data_type pivot = deque_get(d, mid);
    
    int i = low - 1;
    int j = high + 1;
    
    // Разбиение массива на две части
    while (1) {
        do {
            i++;
        } while (deque_get(d, i).key < pivot.key);

        do {
            j--;
        } while (deque_get(d, j).key > pivot.key);

        if (i >= j)
            return j;

        swap(&d->data[(d->front + i) % DEQUE_CAPACITY], 
             &d->data[(d->front + j) % DEQUE_CAPACITY]);
    }
}

// Быстрая сортировка Хоара
// Рекурсивно сортирует подмассив от low до high
void quick_sort(deque *d, int low, int high) {
    if (low < high) {
        // Получаем индекс опорного элемента
        int pi = partition(d, low, high);
        
        // Рекурсивно сортируем левую часть
        quick_sort(d, low, pi);
        
        // Рекурсивно сортируем правую часть
        quick_sort(d, pi + 1, high);
    }
}