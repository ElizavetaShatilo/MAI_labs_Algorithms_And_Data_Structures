# Makefile для лабораторных работ №25 и №26
# Вариант: Дек + Конкатенация + Быстрая сортировка Хоара

# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -g -std=c99
LDFLAGS =

# Целевой исполняемый файл
TARGET = prog

# Объектные файлы
OBJS = main.o deque.o sort.o

# Правило по умолчанию
all: $(TARGET)

# Компоновка
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)

# Компиляция main.o
main.o: main.c deque.h sort.h
	$(CC) $(CFLAGS) -c main.c

# Компиляция deque.o
deque.o: deque.c deque.h
	$(CC) $(CFLAGS) -c deque.c

# Компиляция sort.o
sort.o: sort.c deque.h
	$(CC) $(CFLAGS) -c sort.c

# Очистка временных файлов
clean:
	rm -f $(OBJS) $(TARGET)

# Полная пересборка проекта
rebuild: clean all

.PHONY: all clean rebuild