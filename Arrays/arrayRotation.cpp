/*

5 2
1 2 3 4 5

reverse from 0 to d-1
1 2 ==> 2 1
final array = 2 1 3 4 5

reverse from d to n-1
3 4 5 ==> 5 4 3
final array = 2 1 5 4 3

reverse from 0 to n-1
2 1 5 4 3 ==> 3 4 5 1 2
final array = 3 4 5 1 2


*/
#include <bits/stdc++.h>
using namespace std;
void reverseArray(int *arr, int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int main()
{
    int n, d;
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverseArray(arr, 0, d - 1);
    reverseArray(arr, d, n - 1);
    reverseArray(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}