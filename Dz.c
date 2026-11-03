#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 1251");
    int A[100];
    int n;
    int first = -1, last = -1;
    int count;
    printf("Введите количество элементов: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("A[%d] = ", i + 1);
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }
    if (first != -1 && first != last) {
        count = last - first - 1;
        printf("Количество элементов между нулями: %d\n", count);
    }
    else {
        printf("В массиве меньше двух нулей\n");
    }

    return 0;
}
