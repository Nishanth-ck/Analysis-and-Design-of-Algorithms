#include<stdio.h>
#include<stdlib.h>

int parent[10],min,ne=1,mincost=0,cost[10][10];
int i, j, a, b, u, v, n;

int find(int i)
{
    while(parent[i])
        i = parent[i];
    return i;
}

int union1(int i,int j)
{
    if(i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    printf("\nEnter the number of vertices in the graph (value of n)\n");
    scanf("%d",&n);

    printf("\nEnter the graph data in the form of cost adjacency matrix:\n");
    for (i = 1; i <= n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\nThe edges of the minimum cost spanning tree using Kruskal's Algorithm are:\n");

    while(ne < n)
    {
        min = 999;
        for(i=1;i<=n;i++)
        {

            for(j=1;j<=n;j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(union1(u,v))
        {
            printf("\n%d Edge (%d,%d) : %d\n",ne++,a,b,min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nThe total mincost of the spanning tree using Kruskal's Algorithm is : %d",mincost);

    return 0;
}
