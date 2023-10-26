/*
Assignment Number 5

Student Information:
- Bratin Mondal (Roll Number - 21CS10016)
- Somya Kumar (Roll Number - 21CS30050)
*/

void floydWarshall(int V, int graph[10][10])
{
	int dist[10][10];
	int i, j, k;
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			dist[i][j] = graph[i][j];
		}
	}
	for (k = 0; k < V; k++)
	{
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{
				if (dist[i][k] != 10005 && dist[k][j] != 10005)
				{
					int potential_distance = dist[i][k] + dist[k][j];
					if (potential_distance < dist[i][j])
					{
						dist[i][j] = potential_distance;
					}
				}
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

	// Set specific edge weights
	graph[0][1] = 5;
	graph[0][3] = 10;
	graph[1][2] = 3;
	graph[2][3] = 1;
	floydWarshall(V, graph);

	return 0;
}
