#include<stdio.h>
#include<stdlib.h>
#include<time.h>

clock_t start,end;
double cpu_time_used;
int array[100000];

int partition(int array[],int low,int high)
{
    int pivot = array[low];
    int i=low,j=high;
    int temp;

    while(i<j)
    {
        while(array[i] <= pivot && i<high)
        {
            i++;
        }

        while(array[j] > pivot)
        {
            j--;
        }

        if(i<j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    temp = array[low];
    array[low] = array[j];
    array[j] = temp;

    return j;
}

void quicksort(int array[],int low,int high)
{
    if(low<high)
    {
        int pIndex = partition(array,low,high);
        quicksort(array, low, pIndex - 1);
        quicksort(array, pIndex + 1, high);
    }
}

int main()
{
    int i, n;

    printf("\nEnter the number of elements in the array (value of n)\n");
    scanf("%d",&n);

    for (i = 0; i < n;i++)
    {
        array[i] = rand() % 10000;
    }

    printf("\nThe array elements before sorting are:\n");
    for (i = 0;i<n;i++)
    {
        printf("%d ", array[i]);
    }

    start = clock();
    quicksort(array,0,n-1);
    end = clock();

    printf("\nThe array elements after sorting are:\n");
    for (i = 0;i<n;i++)
    {
        printf("%d ", array[i]);
    }

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nThe total time taken for %d elements is : %lf\n", n, cpu_time_used);

    return 0;
}