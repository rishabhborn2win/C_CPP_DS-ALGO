
#include<stdio.h> 

// Swapping function declaration 
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high- 1; j++) 
	{ 
	    //comparing the elements with pivot element
		if (arr[j] < pivot) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

//quick sorting function
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

// Driver program to test above functions 
int main() 
{   
	int n = 5;
	int arr[n],i,j;
	//Saving a Array
	printf("Enter any five numbers of array: \n");
	for(i=0; i<5 ; i++){
	    scanf("%d", &arr[i]);
	}
	printf("Array Before Sorting: \n");
    printArray(arr, 5);
	//Applying Quick Sort
	quickSort(arr, 0, n-1); 
	printf("Array After Sorting : \n"); 
	printArray(arr, n); 
	return 0; 
} 
