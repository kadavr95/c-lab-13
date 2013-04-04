//Lab 13. Variant 1. Yaskovich Dmitry (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//подключение библиотек
#include <stdlib.h>

int filling(int qel, int *array); //прототипы функций
int sort(int qel, int *qas, int *qco, int *array);
int output(int qel, int *array);

int main(void)//главная функция
{
	int *array, QuantityOfElements,QuantityOfAssignments=0,QuantityOfComparisons=0;
	printf("Enter quantity of elements in array: ");//запрос и считывание количества элементов в массиве
	scanf("%d", &QuantityOfElements);
	array = malloc(QuantityOfElements*sizeof(int));//создание массива
	filling(QuantityOfElements,array);//заполнение массива
	output(QuantityOfElements,array);//вывод массива
	sort(QuantityOfElements, &QuantityOfAssignments, &QuantityOfComparisons,array);//сортировка массива
	printf("Quantity of assignments: %d\n",QuantityOfAssignments);
	printf("Quantity of comparisons: %d\n",QuantityOfComparisons);
	output(QuantityOfElements,array);//вывод отсортированного массива
	fflush(stdin);//ожидание пользователя
	getchar();
	return 0;
}

int filling(int qel, int *array)//заполнение массива
{
	int i;//определение переменных
	int stime;
	long int ltime;
	ltime=time(NULL);//создание случайной последовательности
	stime=(unsigned) ltime/2;
	srand(stime);
	for (i = 1; i <=qel ; i++)//заполнение
	{
		array[i]=-RAND_MAX+2*rand();
	}
}

int output(int qel, int *array)//вывод массива
{
	int i;//определение переменных
	printf("Array:");//вспомогательный вывод
	for (i = 1; i <=qel ; i++)//вывод
	{
		printf("%8d",array[i]);
	}
	printf("\n");//вспомогательный вывод
}

int sort(int qel, int *qas, int *qco, int *array)//сортировка массива
{
	int k,j,i; //определение переменных
	for (k = 2; k <=qel ; k++)//проход по всем элементам после первого
	{
		array[0]=array[k];//передача сравниваемого элемента в нулевой элемент
		*qas=*qas+1;//операция присваивания
		j=1;//сброс счетчика
		while((array[j]<array[0])&&(j<k))//проход по отсортированным элементам
		{
			j++;//изменение счетчика
			*qco=*qco+1;//операция сравнения
		}
		*qco=*qco+1;//операция сравнения
		for (i = k; i > j; i--)//цикл сдвига значений
		{
			array[i]=array[i-1];//сдвиг значения
			*qas=*qas+1;//операция присваивания
		}
		array[j]=array[0];//вставка элемента из нулевого
		*qas=*qas+1;//операция присваивания
	}
}
