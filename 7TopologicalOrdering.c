#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,k,a[10][10],n,m=0,que[10],flag[10];

    printf("\nEnter the number of vertices in the directed acyclic graph,DAG (value of n)\n");
    scanf("%d", &n);

    for(i=1;i<=n;i++)
    {
        que[i] = 0;
        flag[i] = 0;
    }

    printf("\nEnter the graph data in the form of adjacency matrix:\n");
    for (i = 1; i <= n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);

            if(a[i][j])
                flag[j]++;
        }
    }

    for (k = 0; k < n;k++)
    {
        for (i = 1;i<=n;i++)
        {
            if(!flag[i])
            {
                flag[i] = -1;
                que[++m] = i;

                for(j=1;j<=n;j++)
                {
                    if(a[i][j] && flag[j]>0)
                    {
                        flag[j]--;
                    }
                }
            }
        }
    }

    if(m == n)
    {
        printf("\nThe topological ordering of the vertices of the given directed acyclic graph,DAG is :\n");
        for(i=1;i<=n;i++)
        {
            printf("\n%d\n", que[i]);
        }
    }

    else
    {
        printf("\nThere is no topological ordering for the given vertices:\n");
    }

    return 0;
}