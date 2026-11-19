// macros.h
// Власний заголовний файл з макровизначеннями
// Лабораторна робота № 9.2. Варіант 4

#ifndef MACROS_H
#define MACROS_H

// піднесення до квадрата
#define SQR(x) ((x)*(x))

// модуль (абсолютне значення)
#define ABS(x) (((x) < 0) ? -(x) : (x))

// найбільше з двох значень
#define MAX(y, z) (((y) > (z)) ? (y) : (z))

// найменше з двох значень
#define MIN(y, z) (((y) < (z)) ? (y) : (z))

// виведення повідомлення та значення дійсного числа
#define PRINTR(w) puts("control output"); \
        printf(#w "=%f\n", (float)(w))

#endif