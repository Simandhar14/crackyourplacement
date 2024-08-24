// User function Template for C++

class Solution
{
public:
    int d[505][2005];
    int rec(int i, int rem, vector<int> &arr, int k)
    {
        if (i == arr.size())
            return 0;
        if (d[i][rem] != -1)
            return d[i][rem];
        int ans;
        if (arr[i] > rem)
        {
            ans = (rem + 1) * (rem + 1) + rec(i + 1, k - arr[i] - 1, arr, k);
        }
        else
        {
            int choice1 = (rem + 1) * (rem + 1) + rec(i + 1, k - arr[i] - 1, arr, k);
            int choice2 = rec(i + 1, rem - arr[i] - 1, arr, k);
            ans = min(choice1, choice2);
        }
        d[i][rem] = ans;
        return d[i][rem];
    }
    int solveWordWrap(vector<int> arr, int k)
    {
        memset(d, -1, sizeof(d));
        return rec(0, k, arr, k);
    }
};