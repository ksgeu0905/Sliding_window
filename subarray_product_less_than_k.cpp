#include <bits/stdc++.h>
using namespace std;
int numSubarrayProductLessThanK(vector<int> &arr, int k)
{
    int i = 0, j = 0, c = 0, pro = 1;
    int n = arr.size();
    while (j < n)
    {
        pro *= arr[j];

        while (i <= j && pro >= k)
        {
            pro /= arr[i];
            i++;
        }
        if (pro < k)
        {
            c += j - i + 1;
        }
        j++;
    }

    return c;
}
int main()
{
    int n, pro;
    cout << "enter size of array and prod value:\n";
    cin >> n >> pro;
    vector<int> arr(n);
    cout << "Enter array elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count = numSubarrayProductLessThanK(arr,pro);
    cout << "Subarray Count is: " << count << endl;
    return 0;
}