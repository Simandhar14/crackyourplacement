class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int total = 0;
        for (int n : cardPoints)
        {
            total += n;
        }
        int ans = INT_MIN;
        int score = 0;
        int j = 0;
        int n = cardPoints.size();
        if (k == n)
            return total;
        for (int i = 0; i < n; i++)
        {
            score += cardPoints[i];
            if (i >= n - k - 1)
            {
                ans = max(ans, total - score);
                score -= cardPoints[j];
                j++;
            }
        }
        return ans;
    }
};