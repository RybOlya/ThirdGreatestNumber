#include <stdio.h>

int* arr;
size_t arrSize = 10;

int findThirdGreatestNum(int arr[],int n)
{
	int max1 = arr[0];
	for (int i = 1; i < n; i++) 
		if (arr[i] > max1) 
			max1= arr[i];  
	int max2 = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] > max2 && arr[i] < max1)
			max2 = arr[i];
	int max3 = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] > max3 && arr[i] < max2)
			max3 = arr[i];
	return max3;
}
int main()
{
	int res, n;
	arr = calloc(arrSize, sizeof(int));
	if(arr==NULL)
	{
		printf("Array not located");
		return 1;
	}
	printf(" Enter array size: ");
	scanf_s("%i", &n);

	if (n < 3)
	{
		printf(" Invalid Input \n");
		n = 0;
		return 1;
	}
	else if (n > arrSize)
	{
		arrSize *= 2;
		arr = realloc(arr, arrSize * sizeof(int));
		if (arr == NULL)
		{
			printf("Array not relocated");
			return 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf(" Enter %i element: ", i + 1);
		scanf_s("%i", &arr[i]);
	}
	res =  findThirdGreatestNum(arr, n);
	printf("\n Third greatest number is %i\n", res);
	free(arr);
}