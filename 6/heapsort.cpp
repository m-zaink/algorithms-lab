#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (right < n && arr[i] < arr[right])
        largest = right;
    if (left < n && arr[i] < arr[left])
        largest = left;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, i);
    }
}