#include <bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int> &arr)
{
    int i = 0, j = 0, size = INT_MAX, sum = 0;
    int n = arr.size();
    while (j < n)
    {
        sum += arr[j];

        while (sum > target)
        {
            size = min(size, j - i + 1);
            sum -= arr[i];
            i++;
        }
        if (sum == target)
        {
            size = min(size, j - i + 1);
        }
        j++;
    }
    if (size == INT_MAX)
        return 0;
    return size;
}
int main()
{
    int n, sum;
    cout << "enter size of array and sum value:\n";
    cin >> n >> sum;
    vector<int> arr(n);
    cout << "Enter array elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int size = minSubArrayLen(sum, arr);
    cout << "Minimum Subarray size is: " << size << endl;
    return 0;
}