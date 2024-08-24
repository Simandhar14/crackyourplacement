class Solution
{
public:
    int dp[1001][1001];
    int solve(string &t, string &s, int n, int i, int index)
    {
        if (dp[i][index] != -1)
            return dp[i][index];
        if (index == t.size())
        {
            return 1;
        }
        if (i >= n)
            return 0;
        int count = 0;
        if (s[i] == t[index])
        {
            count += solve(t, s, n, i + 1, index + 1);
        }
        count += solve(t, s, n, i + 1, index);
        dp[i][index] = count;
        return count;
    }

    int numDistinct(string s, string t)
    {
        int n = s.size();
        if (t.size() > n)
            return 0;
        memset(dp, -1, sizeof(dp));
        return solve(t, s, n, 0, 0);
    }
};