#include <bits/stdc++.h>

using namespace std;

void fnGenerateArray(int A[], int n)
{
    cout << "Your generated array is : " << endl;
    for (int i = 0; i < n; ++i)
    {
        A[i] = rand() % 100;
        cout << A[i] << "\t";
    }
    cout << endl;
}

void fnMaxMin(int A[], int n, int **max, int **min, int i);

int main()
{
    srand(time(NULL));

    int *max, *min, n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    int A[n];

    fnGenerateArray(A, n);

    max = min = &A[0];

    fnMaxMin(A, n, &max, &min, 0);

    cout << "Maximum element : " << *max << endl;
    cout << "Minimum element : " << *min << endl;

    getchar();
    getchar();
    return 0;
}

void fnMaxMin(int A[], int n, int **max, int **min, int i)
{
    if (i == n - 1)
        return;

    if (A[i] > **max)
        *max = &A[i];
    if (A[i] < **min)
        *min = &A[i];
    return fnMaxMin(A, n, max, min, i + 1);
}