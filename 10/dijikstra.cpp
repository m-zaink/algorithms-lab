#include <bits/stdc++.h>
#include <time.h>
#include <sys/time.h>


using namespace std;

void printSolution(int dist[], int n, int src)
{
    cout << endl;
    cout << "Vertex\tDistance";

    for (int i = 0; i < n; ++i)
    {
        if (src != i)
            cout << i << "\t" << dist[i] << endl;
    }
}

int findMin(bool visited[], int dist[], int n)
{
    int key, min = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i] && min > dist[i])
        {
            key = i;
            min = dist[i];
        }
    }

    return key;
}

void dijikstra(int graph[100][100], int n, int src)
{
    int dist[n], u;
    bool visited[n];
    for (int i = 0; i < n; ++i)
        dist[i] = INT_MAX, visited[i] = false;
    dist[src] = 0;
    u = findMin(visited, dist, n);
    visited[u] = true;

    for (int j = 0; j < n; ++j)
    {
        if (!visited[j] && dist[j] > (graph[u][j] + dist[u]))
        {
            dist[j] = graph[u][j] + dist[u];
        }
    }

    printSolution(dist, n, src);
}

int main()
{
    struct timeval tv;
    int V, src, temp;
    cout << "Enter the number of vertices : ";
    cin >> V;
    int graph[100][100];
    cout << "Enter the weight matrix(type 999 for infinited dist) : " << endl;
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j) {
            cin >> temp;
            if(temp >= 999)
                graph[i][j] = INT_MAX;
            else
                graph[i][j] = temp;
        }
    }
    gettimeofday(&tv, 0);
    float stime = tv.tv_sec + tv.tv_usec / 1000000.0;
    dijikstra(graph, V, src);
    gettimeofday(&tv, 0);

    float etime = tv.tv_sec + tv.tv_usec / 1000000.0;

    cout << "Running time : " << stime - etime << " seconds." << endl;

    FILE *fp;
    fp = fopen("filename", "w");

    fprintf(fp, "%d\t%lf\n", 1, stime - etime);
    return 0;
}