#include<bits/stdc++.h>
using namespace std;

void mergeSortedArrays(int arr1[],int arr2[],int size1,int size2,int mergedArr[])
{
    int i=0;  //index for array1
    int j=0;  //index for array2
    int k=0;  //index mergearray

    //Merge the two arrays while both have element
    while(i<size1 && j<size2)
    {
        if(arr1[i]<=arr2[j])
        {
            mergedArr[k]=arr1[i];
            i++;
        }
        else
        {
            mergedArr[k]=arr2[j];
            j++;
        }
        k++;
    }
}
int main()
{
    
    return 0;
}