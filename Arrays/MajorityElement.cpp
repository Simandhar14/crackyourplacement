class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int size = nums.size();
        for (int &n : nums)
        {
            mp[n]++;
        }
        for (auto &map : mp)
        {
            if (map.second > size / 2)
                return map.first;
        }
        return -1;
    }
};