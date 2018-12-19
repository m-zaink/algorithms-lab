#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int fnBinary(int A[], int key, int l, int h);

void fnGenerateArray(int A[], int n);

int main()
{
    srand(time(NULL));

    int n, key;
    cout << "Enter the size of the array : ";
    cin >> n;

    int A[n];
    fnGenerateArray(A, n);

    cout << "Enter the key : ";
    cin >> key;

    int pos = fnBinary(A, key, 0, n - 1);

    if (pos >= 0)
        cout << "The key " << key << " was found at pos = " << pos + 1 << endl;
    else
        cout << "The key " << key << " was not found " << endl;

    getchar();
    getchar();

    return 0;
}

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

int fnBinary(int A[], int key, int l, int h)
{
    if (l > h)
        return -1;

    int mid = (l + h) / 2;

    if (A[mid] == key)
        return mid;
    else if (A[mid] > key)
        h = mid - 1;
    else
        l = mid + 1;

    return fnBinary(A, key, l, h);
}