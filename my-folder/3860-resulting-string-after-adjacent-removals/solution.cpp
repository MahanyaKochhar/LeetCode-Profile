class Solution {
public:
    string resultingString(string s)
    {
        stack<int>st;
        for(int i = 0 ; i < s.length(); i++)
        {
            if(st.empty())
            {
                st.push(s[i] - 'a');
            }
            else
            {
                int curr = st.top();
                int alp = s[i] - 'a';
                if(alp == (curr + 1) % 26 || alp == (curr - 1 + 26) % 26)
                {
                    st.pop();
                }
                else
                {
                    st.push(alp);
                }
            }
        }
        string ans = "";
        while(!st.empty())
        {
            int curr = st.top(); 
            st.pop();
            ans.push_back(curr + 'a');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
