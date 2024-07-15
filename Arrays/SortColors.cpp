class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] < nums[i])
                {
                    swap(nums[j], nums[i]);
                }
            }
        }
    }
};