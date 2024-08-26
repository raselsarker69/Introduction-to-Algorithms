#include<bits/stdc++.h>
using namespace std;

const int INF = -1000000;

int maxPath(vector<vector<int>>& arr, int row, int col, int start, int end) {
 
    if (start == row - 1 && end == col - 1) 
    {
        return arr[start][end];
    }

    if (start >= row || end >= col) 
    {
        return INF;
    }
    int right = maxPath(arr, row, col, start, end + 1);
    int down = maxPath(arr, row, col, start + 1, end);

    return arr[start][end] + max(right, down);
}

int main() 
{
    int row, col;
    cin >> row >> col;

    vector<vector<int>> arr(row, vector<int>(col));

    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            cin >> arr[i][j];
        }
    }

    int result = maxPath(arr, row, col, 0, 0);

    cout << result << endl;

    return 0;
}