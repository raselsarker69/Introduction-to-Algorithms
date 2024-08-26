#include<bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int n, int x, int mid) 
{
    int prv = a[0];
    int cnt = 1;

    for (int i = 1; i < n; i++) 
    {
        if (a[i] - prv >= mid) 
        {
            prv = a[i];
            cnt++;
        }
    }
    return cnt >= x;
}

int largestDistance(int a[], int n, int x) 
{
    sort(a, a + n);
    int lo = 1; 
    int hi = a[n - 1] - a[0];
    int result = 0;

    while (lo <= hi) 
    {
        int mid = lo + (hi - lo) / 2;

        if (isPossible(a, n, x, mid)) 
        {
            result = mid;
            lo = mid + 1;
        } 
        else 
        {
            hi = mid - 1;
        }
    }
    return result;
}

int main() 
{
    int t;
    cin >> t;

    while (t--) 
    {
        int n, x;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
        }

        cin >> x;
        int maxDistance = largestDistance(a, n, x);
        cout << maxDistance << endl;
    }
    
    return 0;
}