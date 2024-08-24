class Solution
{
public:
    bool validPalindrome(string s)
    {
        int n = s.size();
        int l = 0, r = n - 1;
        string skipL, skipR, temp1, temp2;
        while (l <= r)
        {
            if (s[l] != s[r])
            {
                skipL = s.substr(0, l) + s.substr(l + 1, n);
                skipR = s.substr(0, r) + s.substr(r + 1, n);
                temp1 = skipL;
                temp2 = skipR;
                reverse(skipL.begin(), skipL.end());
                reverse(skipR.begin(), skipR.end());
                return (temp1 == skipL || temp2 == skipR);
            }
            l++;
            r--;
        }
        return true;
    }
};