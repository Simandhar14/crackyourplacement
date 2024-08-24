class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        stringstream ss(path);
        string token;
        while (getline(ss, token, '/'))
        {
            if (token == "" || token == ".")
                continue;
            if (token != "..")
            {
                st.push(token);
            }
            else if (!st.empty())
            {
                st.pop();
            }
        }
        string result = "";
        while (!st.empty())
        {
            result = "/" + st.top() + result;
            st.pop();
        }
        return result.empty() ? "/" : result;
    }
};