#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "macros.h"     // власний заголовний файл з макросами

#define Z 7             // значення z (ціле); змінюючи його, вибираємо гілку

int main()
{
    float x, w;         // x - вхідне значення, w - результат
    char ch;            // відповідь, чи продовжувати виконання програми

    do
    {
        puts("Lab 9.2. Using macros and preprocessing directives");
        puts("Input x:");
        scanf("%f", &x);
        PRINTR(x);
        PRINTR(Z);

#if (Z > 5) && (Z < 10)
        // компілюється, якщо 5 < z < 10
        puts("5 < z < 10: w = min(x,z) * max(x+z, x*z)");
        w = MIN(x, Z) * MAX(x + Z, x * Z);
#else
        // компілюється, якщо z <= 5 або z >= 10
        puts("z <=5 or z >= 10: w = max^2(|x-z|, z)");
        w = SQR(MAX(ABS(x - Z), Z));
#endif                  // завершення блоку умовної компіляції

        PRINTR(w);

        puts("Repeat?  y / n");
        ch = _getch();
    } while (ch == 'y');

    return 0;
}