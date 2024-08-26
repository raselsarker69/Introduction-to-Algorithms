#include <bits/stdc++.h>
using namespace std;

int binarySearch(int ar[], int n, int x)
{
    int l, r, mid;
    l = 0; r = n - 1;
    
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (x == ar[mid])
            return mid;
        else if (ar[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;  //kujay pawa jay ni
}

int main()
{
    int n, x;
    cin >> n;
    int ar[n];

    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    cin >> x; 

    int idx = binarySearch(ar, n, x);
    if (idx == -1)
        cout << "Not Found" << " ";
    else
        cout << idx << " ";

    return 0;
}