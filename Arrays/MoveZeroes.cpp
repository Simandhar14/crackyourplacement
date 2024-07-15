class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int count = 0;
        for (int n : nums)
        {
            if (n == 0)
            {
                auto it = find(nums.begin(), nums.end(), 0);
                nums.erase(it);
                nums.push_back(0);
            }
        }
    }
};