
class Solution
{
public:
    string smallestWindow(string s, string p)
    {
        if (p == "")
            return "-1";
        if (p.length() > s.length())
            return "-1";
        if (s == p)
            return s;
        vector<int> mp(256, 0);
        for (char ch : p)
        {
            mp[ch]++;
        }
        vector<int> hmap(256, 0);
        int l = 0, r = 0;
        string res = "-1";
        int reslen = INT_MAX;
        int currlen = 0;
        int totallen = 0;
        for (auto i : mp)
            if (i > 0)
                totallen++;
        while (r < s.length())
        {
            char ch = s[r];
            hmap[ch]++;
            if (mp[ch] != 0 && mp[ch] == hmap[ch])
                currlen++;
            while (currlen == totallen)
            {
                if ((r - l + 1) < reslen)
                {
                    res = s.substr(l, r - l + 1);
                    reslen = r - l + 1;
                }
                char c = s[l];
                hmap[c]--;
                if (mp[c] != 0 && mp[c] > hmap[c])
                    currlen--;
                l++;
            }
            r++;
        }
        return reslen != INT_MAX ? res : "-1";
    }
};