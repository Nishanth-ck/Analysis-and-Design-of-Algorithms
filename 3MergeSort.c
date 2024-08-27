#include<stdio.h>
#include<stdlib.h>
#include<time.h>

clock_t start,end;
double cpu_time_used;
int array[1000000];

void merge(int array[],int left[],int right[],int left_size,int right_size)
{
    int i=0,j=0,k=0;

    while(i<left_size && j<right_size)
    {
        if(left[i] < right[j])
        {
            array[k] = left[i];
            i++;
        }

        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while(i<left_size)
        {
            array[k] = left[i];
            i++;
            k++;
        }

    while(j<right_size)
        {
            array[k] = right[j];
            j++;
            k++;
        }
}

void mergesort(int array[],int n)
{
    int i;

    if(n<=1)
    {
        return;
    }

    int mid = n/2;
    int left[mid];
    int right[n-mid];

    for (i = 0; i < mid;i++)
    {
        left[i] = array[i];
    }

    for (i = mid; i < n;i++)
    {
        right[i-mid] = array[i];
    }

    mergesort(left,mid);
    mergesort(right,n-mid);

    merge(array, left, right, mid, n - mid);
}

int main()
{
    int i,n;

    printf("\nEnter the number of elements in the array:(value of n)\n");
    scanf("%d",&n);

    for (i = 0;i<n;i++)
    {
        array[i] = rand() % 10000;
    }

    printf("\nThe array elements before sorting are:\n");
    for (i = 0;i<n;i++)
    {
        printf(" %d ",array[i]);
    }

    start = clock();
    mergesort(array, n);
    end = clock();

    printf("\nThe array elements after sorting are:\n");
    for (i = 0;i<n;i++)
    {
        printf(" %d ",array[i]);
    }

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nThe time taken to sort %d elements is : %lf", n, cpu_time_used);

    return 0;
}