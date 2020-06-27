
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#define N 5

void input_matr_file(int a[][N])
{
	int i, j;
	FILE* fp;
	fp = fopen("in.txt", "r");
	if (fp)
	{
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				fscanf(fp, "%d", &a[i][j]);
	}
	else printf("Входной файл отсутствует\n");
}

void input_matr(int a[N][N])
{
	int i, j;
	printf("Введите элементы матрицы А: \n");
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &a[i][j]);
}

void output(const int x[], const int a[N][N])
{
	int i, j;
	FILE* fp;
	printf("Матрица А:\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
	printf("Массив Х:\n");
	for (i = 0; i < N; i++)
		printf("%d ", x[i]);
	printf("\n");
	fp = fopen("out.txt", "w");
	for (i = 0; i < N; i++)
		fprintf(fp, "%5d", x[i]);
	fclose(fp);
}
