class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int>st;
        set<int>toErase;
        for(int i = 0 ; i < s.length();i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else if(s[i] == ')')
            {
                if(!st.empty())
                {
                    st.pop();
                }
                else
                {
                    toErase.insert(i);
                }

            }
        }
        while(!st.empty())
        {
            toErase.insert(st.top());
            st.pop();
        }
        string ans = "";
        for(int i = 0 ; i < s.length();i++)
        {
            if(toErase.find(i) != toErase.end())
            {
                continue;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};
