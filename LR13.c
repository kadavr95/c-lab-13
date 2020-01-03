//Lab 13. Variant 1. Yaskovich Dmitry (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//����������� ���������
#include <stdlib.h>

int filling(int qel, int *array); //��������� �������
int sort(int qel, int *qas, int *qco, int *array);
int output(int qel, int *array);

int main(void)//������� �������
{
	int *array, QuantityOfElements,QuantityOfAssignments=0,QuantityOfComparisons=0;
	printf("Enter quantity of elements in array: ");//������ � ���������� ���������� ��������� � �������
	scanf("%d", &QuantityOfElements);
	array = malloc(QuantityOfElements*sizeof(int));//�������� �������
	filling(QuantityOfElements,array);//���������� �������
	output(QuantityOfElements,array);//����� �������
	sort(QuantityOfElements, &QuantityOfAssignments, &QuantityOfComparisons,array);//���������� �������
	printf("Quantity of assignments: %d\n",QuantityOfAssignments);
	printf("Quantity of comparisons: %d\n",QuantityOfComparisons);
	output(QuantityOfElements,array);//����� ���������������� �������
	fflush(stdin);//�������� ������������
	getchar();
	return 0;
}

int filling(int qel, int *array)//���������� �������
{
	int i;//����������� ����������
	int stime;
	long int ltime;
	ltime=time(NULL);//�������� ��������� ������������������
	stime=(unsigned) ltime/2;
	srand(stime);
	for (i = 1; i <=qel ; i++)//����������
	{
		array[i]=-RAND_MAX+2*rand();
	}
}

int output(int qel, int *array)//����� �������
{
	int i;//����������� ����������
	printf("Array:");//��������������� �����
	for (i = 1; i <=qel ; i++)//�����
	{
		printf("%8d",array[i]);
	}
	printf("\n");//��������������� �����
}

int sort(int qel, int *qas, int *qco, int *array)//���������� �������
{
	int k,j,i; //����������� ����������
	for (k = 2; k <=qel ; k++)//������ �� ���� ��������� ����� �������
	{
		array[0]=array[k];//�������� ������������� �������� � ������� �������
		*qas=*qas+1;//�������� ������������
		j=1;//����� ��������
		while((array[j]<array[0])&&(j<k))//������ �� ��������������� ���������
		{
			j++;//��������� ��������
			*qco=*qco+1;//�������� ���������
		}
		*qco=*qco+1;//�������� ���������
		for (i = k; i > j; i--)//���� ������ ��������
		{
			array[i]=array[i-1];//����� ��������
			*qas=*qas+1;//�������� ������������
		}
		array[j]=array[0];//������� �������� �� ��������
		*qas=*qas+1;//�������� ������������
	}
}
