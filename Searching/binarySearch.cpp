#include <bits/stdc++.h>
using namespace std;

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int *arr, int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    return i + 1;
}

void quickSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);

        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int binarySearch(int *arr, int l, int r, int n)
{
    if (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == n)
        {
            return mid;
        }
        else if (arr[mid] > n)
        {
            return binarySearch(arr, l, mid - 1, n);
        }
        else
        {
            return binarySearch(arr, mid + 1, r, n);
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    cout<<binarySearch(arr,0,n-1,4081);
    return 0;
}