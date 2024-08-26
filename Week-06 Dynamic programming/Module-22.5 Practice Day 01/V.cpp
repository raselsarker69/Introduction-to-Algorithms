#include<bits/stdc++.h>
using namespace std;

int check(int arr[],int sz,int result,int sum,int idx) 
{
    // Base case:
    if (idx == sz) 
    {
        return sum == result;
    }

    int sum1 = sum + arr[idx];
    int sum2 = sum - arr[idx];

    // Recursively check both routes
    int route1 = check(arr, sz, result, sum1, idx + 1);
    int route2 = check(arr, sz, result, sum2, idx + 1);

    return route1 || route2;
}

int main() 
{
    int sz, result;
    cin >> sz >> result;

    int arr[sz];
    for (int i = 0; i < sz; i++) 
    {
        cin >> arr[i];
    }

    int flag = check(arr, sz, result, arr[0], 1);

    if (flag) 
    {
        cout << "YES" << endl;
    } 
    else 
    {
        cout << "NO" << endl;
    }

    return 0;
}