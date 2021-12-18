#include <stdio.h>

void InputArray(int** array, int* elementsCount)
{
	printf("Enter elements count of the array:");
	scanf_s("%d", elementsCount);
	printf("\n");

	*array = new int[*elementsCount];

	printf("Enter elements:\n");
	for (int i = 0; i < *elementsCount; i++)
	{
		printf("%d element:", i + 1);
		scanf_s("%d", &(*array)[i]);
	}
}

void OutputArray(int* array, int elementsCount)
{
	printf("This is your array:\n");
	for (int i = 0; i < elementsCount; i++)
	{
		printf("%d ", array[i]);
	}
}

//void TaskD(int* array, int elementsCount, int** newArray, int* newElementsCount)
//{
//	int min = array[0];
//	int max = array[0];
//
//	int edge0 = 0;
//	int edge1 = 0;
//
//	for (int x = 0; x < elementsCount; x++)
//	{
//		if (array[x] < min)
//		{
//			min = array[x];
//			edge0 = x;
//		}
//		if (array[x] > max)
//		{
//			max = array[x];
//			edge1 = x;
//		}
//	}
//
//	if (edge0 > edge1)
//	{
//		int temp = edge0;
//		edge0 = edge1;
//		edge1 = temp;
//	}
//
//	int countBetweenEdgesToDelete = 0;
//
//	for (int x = edge0 + 1; x < edge1; x++)
//	{
//		if ((array[x] % 2) == 0)
//			countBetweenEdgesToDelete++;
//	}
//	*newElementsCount = elementsCount - countBetweenEdgesToDelete;
//
//	*newArray = new int[(*newElementsCount)];
//
//	int id = 0;
//	for (int x = 0; x < elementsCount; x++)
//		if (!(x > edge0&& x < edge1 && array[x] % 2 == 0))
//		{
//			(*newArray)[id] = array[x];
//			id++;
//		}
//}

//void TaskD(int** array, int* elementsCount)
//{
//	int min = (*array)[0];
//	int max = (*array)[0];
//
//	int edge0 = 0;
//	int edge1 = 0;
//
//	for (int x = 0; x < (*elementsCount); x++)
//	{
//		if ((*array)[x] < min)
//		{
//			min = (*array)[x];
//			edge0 = x;
//		}
//		if ((*array)[x] > max)
//		{
//			max = (*array)[x];
//			edge1 = x;
//		}
//	}
//
//	if (edge0 > edge1)
//	{
//		int temp = edge0;
//		edge0 = edge1;
//		edge1 = temp;
//	}
//
//	int countBetweenEdgesToDelete = 0;
//
//	for (int x = edge0 + 1; x < edge1; x++)
//	{
//		if (((*array)[x] % 2) == 0)
//			countBetweenEdgesToDelete++;
//	}
//	int temporaryElementsCount = (*elementsCount) - countBetweenEdgesToDelete;
//	int* temporaryArray = new int[temporaryElementsCount];
//
//	int id = 0;
//	for (int x = 0; x < (*elementsCount); x++)
//		if (!(x > edge0&& x < edge1 && (*array)[x] % 2 == 0))
//		{
//			temporaryArray[id] = (*array)[x];
//			id++;
//		}
//
//	delete[*elementsCount] array;
//
//	*elementsCount = temporaryElementsCount;
//	*array = temporaryArray;
//}

void TaskDShift(int** array, int* elementsCount)
{
	int min = (*array)[0];
	int max = (*array)[0];

	int edge0 = 0;
	int edge1 = 0;

	for (int x = 0; x < (*elementsCount); x++)
	{
		if ((*array)[x] < min)
		{
			min = (*array)[x];
			edge0 = x;
		}
		if ((*array)[x] > max)
		{
			max = (*array)[x];
			edge1 = x;
		}
	}

	if (edge0 > edge1)
	{
		int temp = edge0;
		edge0 = edge1;
		edge1 = temp;
	}

	int temporaryElementsCount = 0;
	int id = 0;
	for (int x = 0; x < (*elementsCount); x++)
		if (!(x > edge0&& x < edge1 && (*array)[x] % 2 == 0))
		{
			(*array)[id] = (*array)[x];
			id++;
			temporaryElementsCount++;
		}
	*elementsCount = temporaryElementsCount;
}


void UpdateArray(int** array, int* elementsCount)
{
	TaskDShift(array, elementsCount);
}

int main()
{
	int* num;
	int elementsCount;

	InputArray(&num, &elementsCount);
	UpdateArray(&num, &elementsCount);
	printf("\n");
	OutputArray(num, elementsCount);

	return 0;
}