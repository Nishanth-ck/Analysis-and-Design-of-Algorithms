#include<stdio.h>
#include<stdlib.h>

int visited[10],min,ne=1,mincost=0,cost[10][10];
int i,j,u,v,n;

int main()
{
    printf("\nEnter the number of vertices in the graph (value of n)\n");
    scanf("%d",&n);

    printf("\nEnter the graph data in the form of adjacency matrix:\n");
    for (i = 1; i <= n;i++)
    {
        for (j = 1; j <= n;j++)
        {
            scanf("%d",&cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[1] = 1;
    for (i = 2; i <= n;i++)
    {
        visited[i] = 0;
    }

    printf("\nThe edges of the minimum cost spanning tree using Prim's Algorithm are:\n");

    while(ne < n)
    {
        min = 999;
        for (i = 1; i <= n;i++)
        {
            for (j = 1; j <= n;j++)
            {
                if(cost[i][j] < min)
                {
                    if(visited[i] == 0)
                        continue;

                    else
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(visited[u] == 0 || visited[v] == 0)
        {
            printf("%d Edge(%d,%d) : %d\n",ne++,u,v,min);
            mincost += min;
            visited[v] = 1;
        }

        cost[u][v] = cost[v][u] = 999;
    }

    printf("\nThe mincost of the minimum cost spanning using Prim's Algorithm is : %d\n",mincost);

    return 0;
}