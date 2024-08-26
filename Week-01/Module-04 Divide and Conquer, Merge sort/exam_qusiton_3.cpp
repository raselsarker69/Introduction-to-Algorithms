#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int x) 
{
    int l = 0, r = n - 1;
    while (l <= r) 
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) 
        {
            if(arr[mid-1]==x) return 1;
            if(arr[mid+1]==x) return 1; 
            return -1;
        }  
        else if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;     
    }
    
}

int main() 
{
    int n ,k; 
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>k;
    int nm = binarySearch(arr, n, k);

    if (nm != -1) 
    {
        cout << "YES" << endl;
    } 
    else 
    {
        cout << "NO" << endl;
    }
    return 0;
}