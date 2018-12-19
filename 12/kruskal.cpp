#include <bits/stdc++.h>

using namespace std;

class Edge
{
  public:
    int source, dest, cost;
};

bool compare(Edge e1, Edge e2)
{
    return e1.cost < e2.cost;
}

int findParent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return findParent(parent[v], parent);
}

void kruskals(Edge *input, int V, int E)
{
    sort(input, input + E, compare);

    Edge *output = new Edge[V - 1];

    int *parent = new int[V];

    for (int i = 0; i < V; ++i)
    {
        parent[i] = i;
    }

    int count = 0, i = 0;

    while (count != V - 1)
    {
        Edge cur = input[i];

        //Check cycle
        int sourceParent = findParent(cur.source, parent);
        int destParent = findParent(cur.dest, parent);

        if (sourceParent != destParent)
        {
            output[count] = cur;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }

    for (int i = 0; i < V - 1; ++i)
    {
        if (output[i].source < output[i].dest)
            cout << output[i].source << " " << output[i].dest << " " << output[i].cost << endl;
        else
            cout << output[i].dest << " " << output[i].source << " " << output[i].cost << endl;
    }
}

int main()
{
    int V, E;

    cin >> V >> E;

    Edge *input = new Edge[E];

    for (int i = 0; i < E; ++i)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].cost = w;
    }
}