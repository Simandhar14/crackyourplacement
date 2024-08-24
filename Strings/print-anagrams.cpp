// User function Template for C++

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &arr)
    {
        // code here
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            string ss = arr[i];
            sort(begin(ss), end(ss));
            mp[ss].push_back(arr[i]);
        }
        vector<vector<string>> ans(mp.size());
        int index = 0;
        for (auto vec : mp)
        {
            for (auto s : vec.second)
            {
                ans[index].push_back(s);
            }
            index++;
        }
        return ans;
    }
};