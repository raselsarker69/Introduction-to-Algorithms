#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int nums[N];

void merge(int l, int r, int mid) 
{
    int left_size = mid - l + 1;
    int L[left_size];

    int right_size = r - mid;
    int R[right_size];

    for (int i = 0; i < left_size; i++)
        L[i] = nums[l + i];

    for (int i = 0; i < right_size; i++)
        R[i] = nums[mid + 1 + i];

    int lp = 0, rp = 0;
    int i = l;
    while (lp < left_size && rp < right_size) 
    {
        if (L[lp] >= R[rp]) 
        {
            nums[i] = L[lp];
            lp++;
        } 
        else 
        {
            nums[i] = R[rp];
            rp++;
        }
        i++;
    }

    while (lp < left_size) 
    {
        nums[i] = L[lp];
        lp++;
        i++;
    }

    while (rp < right_size) 
    {
        nums[i] = R[rp];
        rp++;
        i++;
    }
}

void mergesort(int l, int r) 
{
    if (l >= r) return;
        
    int mid = (l + r) / 2;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    merge(l, r, mid);
}

int main() 
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> nums[i];
    }

    mergesort(0, n - 1);

    for (int i = 0; i < n; i++) 
    {
        cout << nums[i] << " ";
    }
    return 0;
}