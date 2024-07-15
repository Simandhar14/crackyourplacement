class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> hmap;
        for (int n : nums)
        {
            hmap[n]++;
            if (hmap[n] > 1)
                return n;
        }
        return -1;
    }
};