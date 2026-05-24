#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int indegree[MAX];
int visited[MAX];

int main()
{
    int n = 7;
    int i, j, count = 0;

    // Initialize arrays
    for(i = 0; i < MAX; i++)
    {
        indegree[i] = 0;
        visited[i] = 0;
    }

    // Creating graph
    graph[1][3] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;
    graph[3][5] = 1;
    graph[4][6] = 1;
    graph[5][6] = 1;

    // Calculate indegree
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(graph[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    printf("Topological Order: ");

    while(count < n)
    {
        for(i = 0; i < n; i++)
        {
            // Find source node
            if(indegree[i] == 0 && visited[i] == 0)
            {
                printf("%d ", i);

                visited[i] = 1;
                count++;

                // Remove outgoing edges
                for(j = 0; j < n; j++)
                {
                    if(graph[i][j] == 1)
                    {
                        indegree[j]--;
                    }
                }
            }
        }
    }

    return 0;
}