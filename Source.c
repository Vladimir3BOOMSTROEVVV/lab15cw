#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define N 10
#define N2 100

double calculate(double x);

int main() {
	setlocale(LC_CTYPE, "RUS");
	t1();
	t2();
}

int t1() {
	float A[N], B[N], temp, sum = 0, sred;
	for (int i = 0; i < N; i++)
	{
		printf("a[%d] = ", i + 1);
		scanf("%f", &temp);
		A[i] = temp;
		B[i] = temp;
	}
	printf("\nиндекс\tисходное значение\tновое значение");
	for (int i = 0; i < N; i++) {
		B[i] *= 2;
		printf("\n%6.d\t%15.2f\t\t\t%15.2f", i + 1, A[i], B[i]);
	}
	for (int i = 0; i < N; i++) {
		sum += B[i];
	}
	sred = sum / N;
	printf("\nСреднее арифметическо: %f", sred);
}

int t2() {
	float A[N2], x, step;
	float sum1 = 0, sum2 = 0, sred = 0;
	int k1 = 0, k2 = 0;
	step = 2.0 / (N2 - 1);
	for (int i = 0; i < N2; i++) {
		x = i * step;
		A[i] = calculate(x);
		printf("%f\n", A[i]);
	}
	for (int i = 0; i < N2; i++) {
		if (A[i] > 0) {
			sum1 += A[i];
			k1 += 1;
		}
		if (A[i] < 0) {
			sum2 += A[i];
			k2 += 1;
		}
	}
	if (k1 > 0) {
		sred = sum1 / k1;
	}

	printf("Массив A\n");
	printf("Сумма положительных: %.2f\n", sum1);
	printf("Сумма отрицательных: %.2f\n", sum2);
	printf("Количество положительных: %d\n", k1);
	printf("Количество отрицательных: %d\n", k2);
	printf("Среднее положительных: %.2f\n", sred);
	return 0;
}

double calculate(double x) {
	return x * x + 3 * x - 1;
}
