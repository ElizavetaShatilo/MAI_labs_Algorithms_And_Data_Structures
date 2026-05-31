#include <stdio.h>
#include "deque.h"
#include "sort.h"

int main(void) {
    system("chcp 65001 > nul");
    
    printf("========================================\n");
    printf("Лабораторные работы №25 и №26\n");
    printf("Вариант 25: Дек + Конкатенация + Быстрая сортировка Хоара\n");
    printf("========================================\n\n");
    printf("=== Демонстрация 1: Основная ===\n\n");
    
    // Создаем два дека
    deque d1, d2;
    deque_create(&d1);
    deque_create(&d2);
    
    // Заполняем первый дек
    printf("1. Заполнение первого дека:\n");
    deque_push_back(&d1, (data_type){5, 100});
    deque_push_back(&d1, (data_type){2, 200});
    deque_push_back(&d1, (data_type){8, 300});
    deque_push_back(&d1, (data_type){1, 400});
    deque_push_back(&d1, (data_type){4, 500});
    deque_print(&d1);
    
    // Заполняем второй дек
    printf("\n2. Заполнение второго дека:\n");
    deque_push_back(&d2, (data_type){7, 600});
    deque_push_back(&d2, (data_type){3, 700});
    deque_push_back(&d2, (data_type){6, 800});
    deque_push_back(&d2, (data_type){9, 900});
    deque_print(&d2);
    
    // Конкатенация деков
    printf("\n3. Процедура №3: Конкатенация деков (d1 + d2):\n");
    deque_concat(&d1, &d2);
    printf("   Результат конкатенации:\n");
    deque_print(&d1);
    
    // Быстрая сортировка Хоара
    printf("\n4. Метод: Быстрая сортировка Хоара (по ключу):\n");
    quick_sort(&d1, 0, (int)deque_size(&d1) - 1);
    printf("   Результат сортировки:\n");
    deque_print(&d1);

    printf("\n\n=== Демонстрация 2: Дополнительная проверка ===\n\n");
    
    deque d3, d4;
    deque_create(&d3);
    deque_create(&d4);
    
    printf("Дек A: ");
    deque_push_back(&d3, (data_type){10, 1});
    deque_push_back(&d3, (data_type){40, 2});
    deque_push_back(&d3, (data_type){20, 3});
    deque_print(&d3);
    
    printf("Дек B: ");
    deque_push_back(&d4, (data_type){30, 4});
    deque_push_back(&d4, (data_type){50, 5});
    deque_push_back(&d4, (data_type){15, 6});
    deque_print(&d4);
    
    printf("\nКонкатенация A+B: ");
    deque_concat(&d3, &d4);
    deque_print(&d3);
    
    printf("Быстрая сортировка: ");
    quick_sort(&d3, 0, (int)deque_size(&d3) - 1);
    deque_print(&d3);

    printf("\n\n=== Демонстрация 3: Граничные случаи ===\n\n");
    
    deque d5, d6;
    deque_create(&d5);
    deque_create(&d6);
    
    printf("Пустой дек A: ");
    deque_print(&d5);
    
    printf("Дек B с одним элементом: ");
    deque_push_back(&d6, (data_type){42, 999});
    deque_print(&d6);
    
    printf("Конкатенация A+B: ");
    deque_concat(&d5, &d6);
    deque_print(&d5);
    
    printf("Сортировка одного элемента: ");
    quick_sort(&d5, 0, (int)deque_size(&d5) - 1);
    deque_print(&d5);
    
    printf("\nГотово!\n");
    return 0;
}