class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        if (t.size() > n)
            return "";
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        for (char &ch : t)
        {
            mp[ch]++;
        }
        int count = t.size();
        int min_window = INT_MAX;
        int start_i = 0;
        while (j < n)
        {
            char ch = s[j];
            if (mp[ch] > 0)
                count--;
            mp[ch]--;
            while (count == 0)
            {
                int window = j - i + 1;
                if (window < min_window)
                {
                    min_window = window;
                    start_i = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                {
                    count++;
                }
                i++;
            }
            j++;
        }
        return min_window == INT_MAX ? "" : s.substr(start_i, min_window);
    }
};