#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#define LX -8
#define DY -8

int check(double x, double y);
void draw(char g);

int main()
{
    system("chcp 1251");
    while (1)
    {
        char a;
        printf("Принадлежит ли чило область фигуры?(c - проверть; d - нарисовать фигуру; n - закрыть программу)\n");
        printf("Ваш выбор: ");
        scanf(" %c", &a);
        switch (a)
        {
        case 'c':
        {
            double x, y;
            printf("Введите x и y: ");
            scanf("%lf %lf", &x, &y);
            if (check(x, y)) {
                printf("Точка принадлежит области\n");
            }
            else {
                printf("Точка не принадлежит области\n");
            }
            break;
        }
        case 'd':
        {
            char g;
            printf("Введите символ, из которого построить фигуру: ");
            scanf(" %c", &g);
            draw(g);
            break;
        }
        case 'n':
            printf("Программа завершена\n");
            return 0;
        default:
            printf("Неверный выбор! Попробуйте снова.\n");
            break;
        }
        printf("\n");
    }
    return 0;
}

void draw(char g)
{
    int x, y;
    char b = ' ';
    for (y = fabs(DY); y >= DY; y -= 1) {
        for (x = fabs(LX); x >= LX; x -= 1) {
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

int check(double x, double y)
{
    if ((x >= -2 && x <= 2 && y >= 0 && y <= 4) ||
        (x >= -4 && x <= 5 && y >= -3 && y <= 0)) {
        return 1;
    }
    else {
        return 0;
    }
}
