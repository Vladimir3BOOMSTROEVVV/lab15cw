#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#define LX -8
#define DY -8

int check(double x, double y);
int draw(char g);

void main()
{

    system("chcp 1251");
    while (1)
    {
        char a;
        printf("Принадлежит ли чило область фигуры?(c - проверть; d - нарисовать фигуру; n - закрыть программу)");
        a = getchar();
        if (a == 'c') {
            double x, y;
            printf("Введите x и y: ");
            scanf("%lf %lf", &x, &y);
            // КОНТРОЛЬНЫЙ ПРИМЕР x = 1 y = 3 принадлежит; x = 4 y = 2 не принадлежит
            if (check(x, y)) {
                printf("Точка принадлежит области\n");
            }
            else {
                printf("Точка не принадлежит области\n");
            }
        }
        if (a == 'd') {
            char g;
            printf("Введите символ из которого посторить фигуру:");
            scanf(" %c", &g);
            draw(g);
        }
        if (a == 'n') break;
    }
    return 0;
}

int draw(char g) {
    int x, y;
    char b = ' ';
    for (y = fabs(DY); y >= DY; y -= 1) {
        for (x = fabs(LX); x >= LX;x -= 1) {
            if (check(x, y)) {
                putchar(g);
            }
            else {
                putchar(b);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int check(double x, double y) {
    if ((x >= -2 && x <= 2 && y >= 0 && y <= 4) || (x >= -4 && x <= 5 && y >= -3 && y <= 0)) {
        return 1;
    }
    else {
        return 0;
    }
}
