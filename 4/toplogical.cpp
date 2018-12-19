#include <bits/stdc++.h>

using namespace std;

const int INF = 9999;

int adj[100][100];

class Node
{
  public:
    int in;
    bool visited;
};

int findSrc(Node arr[], int n) {
    for (int i = 0; i < n; ++i) {
        if(!arr[i].visited && arr[i].in == 0) {
            arr[i].visited = true;
            return i;
        }
    }
    return -1;
}

void updateArr(Node arr[], int pos, int n) {
    for (int i = 0; i < n; ++i) {
        if(i != pos && adj[pos][i] != INF) {
            arr[i].in--;
        }
    }
}

void topologicalSort(Node arr[], int n)
{
    int pos = findSrc(arr, n);
    if(pos == -1)
        return;
    cout << pos << endl;
    updateArr(arr, pos, n);
    topologicalSort(arr, n);
}

int main() {
    
    return 0;
}