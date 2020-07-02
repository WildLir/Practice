
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


int* masx(int(*a)[N], int* x, void (*pfunc)(int[N][N]))
{
	int min, max, i, j, avg;
	pfunc(a);
	for (j = 0; j < N; j++)
	{
		max = a[0][j];
		min = a[0][j];
		for (i = 0; i < N; i++)
		{
			if (max < a[i][j])
				max = a[i][j];
			if (min > a[i][j])
				min = a[i][j];

		}
		avg = (max + min) / 2;
		x[j] = avg;

	}
	return x;

}
int summa(int x[N], int i, int& sum, int min)
{
	if (i < N)
	{
		if (x[i] != min)
		{
			sum = sum + x[i];
			return summa(x, i + 1, sum, min);
		}
	}
	return sum;
}

int masy(int x[N])
{
	int i, sum, min;
	sum = 0;
	min = x[0];
	for (i = 0; i < N; i++)
		if (min > x[i])
			min = x[i];
	i = 0;
	summa(x, i, sum, min);
	return sum;
}


int main()
{
	setlocale(LC_CTYPE, "");
	int a[N][N], c, x[N];
	void (*pfunc)(int[N][N]);
	pfunc = &input_matr;
	do
	{
		printf("Ввод матрицы:\n1 - с клавиатуры\n2- из файла\n");
		scanf("%d", &c);
	} while (c != 1 && c != 2);
	switch (c)
	{
	case 1: pfunc = &input_matr;
		break;
	case 2: pfunc = &input_matr_file;
	}
	output(masx(a, x, pfunc), a);
	printf("\nY = %d", masy(x));
}