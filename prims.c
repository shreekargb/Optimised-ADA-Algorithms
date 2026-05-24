#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define max 100
int main()
{   int v;
    int graph[max][max];
    int visited[max]={0};
    int edges = 0 , cost = 0;
    printf("Enter the total number of vertices : ");
    scanf("%d",&v);
    printf("Enter cost adjacency matrix : ");
    for(int i = 0;i<v;i++)
    {
        for(int j = 0;j<v;j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    int x,y;
    visited[0]=1;
    while(edges<v-1)
    {
        int min = INT_MAX;
         x=-1;
         y=-1;
        for(int i = 0;i<v;i++)
        {
            if(visited[i])
            {
                for(int j=0;j<v;j++)
                {
                    if(!visited[j] && graph[i][j] && graph[i][j]<min)
                    {
                        min=graph[i][j];
                        x=i;
                        y=j;
                    }

                }
            }
        }
        printf(" \n Edge %d -> %d weight = %d",x,y,min);
        visited[y]=1;
        cost = cost + min;
        edges++;
    }
    printf("\n Total cost = %d",cost);

}