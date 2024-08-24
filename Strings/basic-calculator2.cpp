class Solution
{
public:
    int calculate(string s)
    {
        stack<int> st;
        int n = s.size();
        char sign = '+';
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (isdigit(ch))
            {
                int val = 0;
                int pop, ans;
                while (i < n && isdigit(s[i]))
                {
                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                if (sign == '+')
                {
                    st.push(val);
                }
                else if (sign == '-')
                {
                    st.push(-val);
                }
                else if (sign == '*')
                {
                    pop = st.top();
                    ans = pop * val;
                    st.pop();
                    st.push(ans);
                }
                else if (sign == '/')
                {
                    pop = st.top();
                    ans = pop / val;
                    st.pop();
                    st.push(ans);
                }
            }
            else if (ch != ' ')
            {
                sign = ch;
            }
        }
        int res = 0;
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};