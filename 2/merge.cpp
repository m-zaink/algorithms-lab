#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int n, int b[], int bL, int c[], int cL)
{
    int i = 0, j = 0, k = 0;

    while (i < bL && j < cL)
    {
        if (b[i] < c[j])
        {
            arr[k++] = b[i++];
        }
        else
        {
            arr[k++] = c[j++];
        }
    }
    if (i == bL)
    {
        while (j < cL)
        {
            arr[k++] = c[j++];
        }
    }
    if (j == cL)
    {
        while (i < bL)
        {
            arr[k++] = b[i++];
        }
    }
}

void mergeSort(int arr[], int n)
{
    if (n >= 2)
    {
        int bL, cL;
        if (n % 2 == 0)
            bL = cL = n / 2;
        else
        {
            bL = n / 2 + 1;
            cL = n / 2;
        }

        int B[bL], C[cL];
        int k = 0;
        for (int i = 0; i < bL; i++)
        {
            B[i] = arr[k];
            k++;
        }

        for (int j = 0; j < cL; ++j)
        {
            C[j] = arr[k];
            k++;
        }

        mergeSort(B, bL);
        mergeSort(C, cL);

        merge(arr, n, B, bL, C, cL);
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
    int n;
    cout << "Enter array size : ";
    cin >> n;
    int arr[n];
    generateArray(arr, n);

    cout << "\nSorting array ..." << endl;
    mergeSort(arr, n);
    cout << "Sorted array : " << endl;
    printArray(arr, n);

    getchar();
    getchar();
}