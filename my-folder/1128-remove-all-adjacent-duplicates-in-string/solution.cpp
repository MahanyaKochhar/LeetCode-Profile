class Solution {
public:
    string removeDuplicates(string s)
    {
        stack<char>st;
        for(auto x : s)
        {
            if(!st.empty() && st.top() == x)
            {
                st.pop();
            }
            else
            {
                st.push(x);
            }
        }
        string tmp = "";
        while(!st.empty())
        {
            tmp.push_back(st.top());
            st.pop();
        }
        reverse(tmp.begin(),tmp.end());
        return tmp;
    }
};
