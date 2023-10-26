/*
Assignment Number 5

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/

void bfs(int V, int graph[10][10], int startVertex)
{
    int visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    int queue[V];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear)
    {
        int currentVertex = queue[++front];

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && graph[currentVertex][i] != 1000009)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main()
{
    int V = 4;
    int graph[4][4];
    int i, j;

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (i == j)
            {
                graph[i][j] = 0;
            }
            else
            {
                graph[i][j] = 1000009;
            }
        }
    }

    graph[0][1] = 5;
    graph[0][3] = 10;
    graph[1][2] = 3;
    graph[2][3] = 1;

    bfs(V, graph, 0);

    return 0;
}
