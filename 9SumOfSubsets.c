#include<stdio.h>
#include<stdlib.h>

void printSubset(int subset[],int size)
{
    int i;
    printf("\n { ");
    for (i = 0;i<size;i++)
    {
        printf(" %d ", subset[i]);
    }
    printf(" } \n");
}

void findSubset(int set[],int n,int target)
{
    int i,j;
    int subset[n];
    int totalSubsets = 1 << n;

    for(i=0;i<totalSubsets;i++)
    {
        int sum = 0;
        int subSetsize = 0;

        for (j = 0; j < n;j++)
        {
            if(i & (1<<j))
            {
                subset[subSetsize++] = set[j];
                sum += set[j];
            }
        }

        if(sum == target)
        {
            printSubset(subset, subSetsize);
        }
    }
}

int main()
{
    int i,n,target,set[10];

    printf("\nEnter the total number of elements in the set (value of n)\n");
    scanf("%d",&n);

    printf("\nEnter the elements of the set:\n");
    for (i = 0; i < n;i++)
    {
        scanf("%d", &set[i]);
    }

    printf("\nEnter the target to find the sum:\n");
    scanf("%d",&target);

    findSubset(set,n,target);

    return 0;
}