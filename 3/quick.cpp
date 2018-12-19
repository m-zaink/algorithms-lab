#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
int partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int index = l - 1;

    for (int i = l; i < h; ++i)
    {
        if (arr[i] < pivot)
        {
            ++index;
            swap(&arr[index], &arr[i]);
        }
    }

    swap(&arr[index + 1], &arr[h]);
    return index + 1;
}

void quickSort(int arr[], int l, int h)
{

    if (l <= h)
    {
        int pos = partition(arr, l, h);
        quickSort(arr, l, pos - 1);
        quickSort(arr, pos + 1, h);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << "\t";
}

void generateArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 100;
    cout << endl;
    printArray(arr, n);
}

int main()
{
    srand(time(NULL));
    int n;
    cout << "Enter array size : ";
    cin >> n;
    int arr[n];
    generateArray(arr, n);

    cout << "\nSorting array ..." << endl;
    quickSort(arr, 0, n - 1);
    cout << "Sorted array : " << endl;
    printArray(arr, n);

    getchar();
    getchar();
}