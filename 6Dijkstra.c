#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define INF 999

void dijkstra(int n,int source,int cost[MAX][MAX],int dist[MAX])
{
    int i,j,flag[MAX],count,minDist,nextNode;

    for(i=1;i<=n;i++)
    {
        flag[i] = 0;
        dist[i] = cost[source][i];
    }

    flag[source] = 1;
    dist[source] = 0;
    count = 1;

    while(count < n)
    {
        minDist = INF;

        for(i=1;i<=n;i++)
        {
            if(dist[i] < minDist && !flag[i])
            {
                minDist = dist[i];
                nextNode = i;
            }
        }

        flag[nextNode] = i;
        count++;

        for (i = 1; i <= n;i++)
        {
            if(!flag[i] && (minDist + cost[nextNode][i] < dist[i]))
            {
                dist[i] = minDist + cost[nextNode][i];
            }
        }
    }
}

int main()
{
    int i,j,n,source,cost[MAX][MAX],dist[MAX];

    printf("\nEnter the number of vertices in the graph (value of n)\n");
    scanf("%d",&n);

    printf("\nEnter the graph data in the form of adjacency matrix:\n");
    for (i = 1; i <= n;i++)
    {
        for (j = 1; j <= n;j++)
        {
            scanf("%d",&cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("\nEnter the source vertex number ( 1 to n )\n");
    scanf("%d",&source);

    dijkstra(n,source,cost,dist);

    printf("\nThe shortest path of the vertices of the vertices from the source vertex : %d using Djikstra's Algorithm is :\n", source);
    for(i=1;i<=n;i++)
    {
        if(i != source)
        {
            printf("\n%d ---> %d : %d\n", source, i, dist[i]);
        }
    }

    return 0;
}