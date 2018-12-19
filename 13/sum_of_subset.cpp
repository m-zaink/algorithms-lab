#include <bits/stdc++.h>
using namespace std;

int arr[100], n, tSum;

void print(bool inc[])
{
    cout << "\n{ ";
    for (int i = 0; i < n; ++i)
    {
        if (inc[i])
        {
            cout << arr[i] << " ";
        }
    }
    cout << " }\n";
}

void subset(bool inc[], int prev, int sum)
{
    if (sum == tSum)
        print(inc);
    else if (sum > tSum)
        return;
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (inc[i] || i < prev)
                continue;
            if (sum < tSum)
            {
                sum += arr[i];
                inc[i] = true;
                subset(inc, i, sum);
                sum -= arr[i];
                inc[i] = false;
            }
        }
    }
}

int main()
{
    bool inc[n];
    cout << "Enter the number of elements : ";
    cin >> n;

    cout << "Enter the elements in the array : " << endl;
    for (int i = 0; i < n; ++i)
    {
        inc[i] = false;
        cin >> arr[i];
    }

    cout << "Enter the max sum : ";
    cin >> tSum;
    subset(inc, 0, 0);

    getchar();
    getchar();
}