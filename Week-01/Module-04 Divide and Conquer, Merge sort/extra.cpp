#include <bits/stdc++.h>
using namespace std;

int binarySearch1(int ar[], int n, int x)
{
    int l, r, mid,firstidx=-1;
    l = 0; r = n - 1;
    
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (x == ar[mid])
        {
            firstidx= mid;
            r=mid-1;
        }    
        else if (ar[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return firstidx;  //kujay pawa jay ni
}

int binarySearch2(int ar[], int n, int x)
{
    int l, r, mid,secondidx=-1;
    l = 0; r = n - 1;
    
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (x == ar[mid])
        {
            secondidx= mid;
            r=mid-1;
        }    
        else if (ar[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return secondidx;  //kujay pawa jay ni
}

int main()
{
    int n, k;
    cin >> n;
    int ar[n];

    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    cin >> k;

    int firstidx = binarySearch1(ar, n, k);
    int secondidx = binarySearch2(ar, n, k);
    if (firstidx!=secondidx)
        cout << "YES" << " ";
    else
        cout << "NO" << " ";

    return 0;
}