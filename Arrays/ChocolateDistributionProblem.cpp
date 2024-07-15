class Solution
{
public:
    long long findMinDiff(std::vector<long long> a, long long n, long long m)
    {
        if (m > n)
            return -1;

        sort(a.begin(), a.end());

        long long ans = LLONG_MAX;

        for (long long i = 0; i <= n - m; i++)
        {
            long long current_diff = a[i + m - 1] - a[i];
            ans = min(ans, current_diff);
        }

        return ans;
    }
};