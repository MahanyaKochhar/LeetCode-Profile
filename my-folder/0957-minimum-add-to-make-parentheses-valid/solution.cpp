class Solution {
public:
    int minAddToMakeValid(string s)
    {
        stack<int>st;
        int ans = 0;
        for(int i = 0; i < s.length();i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if(st.empty())
                {
                    ans++;
                }
                else
                {
                    st.pop();
                }
            }
        }
        ans += st.size();
        return ans;
    }
};
