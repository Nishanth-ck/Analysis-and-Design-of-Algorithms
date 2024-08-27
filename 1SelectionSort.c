#include<stdio.h>
#include<time.h>

clock_t start,end;
double cpu_time_used;
int array[1000000];

void selectionsort(int arr[],int n)
{
    int i,j,temp,min;

    for (i = 0; i < n - 1;i++)
    {
        min = i;

        for (j = i + 1; j < n;j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int i, n;

    printf("\nEnter the number of elements in the array:(value of n)\n");
    scanf("%d",&n);

    for (i = 0; i < n;i++)
    {
        array[i] = rand() % 10000;
    }

    printf("\nArray elements before sorting are:\n");

    for(i=0;i<n;i++)
    {
        printf(" %d ", array[i]);
    }

    start = clock();
    selectionsort(array,n);
    end = clock();

    printf("\nArray elements after sorting are:\n");

    for(i=0;i<n;i++)
    {
        printf(" %d ", array[i]);
    }

    cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nThe time taken to sort %d elements is : %lf\n",n,cpu_time_used);

    return 0;
}