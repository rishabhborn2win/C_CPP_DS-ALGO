//Program in C of Quick Sort using Divide and Conquer technique

#include <stdio.h>
int arr[100];


void QuickSort(int low,int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (arr[i] <= arr[pivot] && i <= high)
            {
                i++;
            }
            while (arr[j] > arr[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        //Swapping using the pivot element
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        QuickSort( low, j - 1);
        QuickSort( j + 1, high);
    }    
}

//Declaring the main function
int main()
{
    int i, n;
    printf("Enter the size of the array :");
    scanf("%d",&n);
    arr[n] = 5000;
    printf("\nEnter the elements of the array :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEntered array :");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    //Applying the function
    QuickSort(0,n-1);
    printf("\nSorted array :");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}



