#include <stdio.h>
int findThirdGreatestNum(int arr[], int n);

int main()
{
	int* arr; //stores array address as value
	size_t arrSize = 10; 
	int res;
	size_t userSize;
	arr = calloc(arrSize, sizeof(int));
	if(arr==NULL)
	{
		printf("Array not located");
		return 1;
	}
	printf(" Enter array size: ");
	scanf_s("%i", &userSize);
	if (userSize < 3 || userSize < 0)// 3 is minimum array size to find third max array number 
	{
		printf(" Invalid Input \n");
		userSize = 0;
		return 1;
	}
	//if entered array size is bigger than primary size of array,
	//double amount of elements and rmove arrays location
	else if (userSize > arrSize)
	{
		arrSize *= 2;
		arr = realloc(arr, arrSize * sizeof(int));
		if (arr == NULL)
		{
			printf("Array not relocated");
			return 1;
		}
	}
	for (size_t i = 0; i < userSize; i++)
	{
		printf(" Enter %i element: ", i + 1);
		scanf_s("%i", &arr[i]);
	}
	res =  findThirdGreatestNum(arr, userSize);
	printf("\n Third greatest number is %i\n", res);
	free(arr);//deallocate memory used for array
}
int findThirdGreatestNum(int arr[],int n)
{
	// Initialize first maximum element
	int max1 = arr[0];

	// Traverse array elements
	// from second and compare
	// every element with current max
	for (size_t i = 1; i < n; i++)
		if (arr[i] > max1) 
			max1= arr[i];  
	int max2 = 0;
	// Repeat to find second max
	// and third max member 
	for (size_t i = 0; i < n; i++)
		if (arr[i] > max2 && arr[i] < max1)
			max2 = arr[i];
	int max3 = 0;
	for (size_t i = 0; i < n; i++)
		if (arr[i] > max3 && arr[i] < max2)
			max3 = arr[i];
	return max3;
}