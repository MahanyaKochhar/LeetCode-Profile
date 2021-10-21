class Solution {
public:
    int ans=1;
    void recursion(string s,int idx,set<string>&st)
    {
        if(idx>=s.length())
        {
            ans=max(ans,int(st.size()));
            return;
        }
        for(int i=1;i+idx<=s.length();i++)
        {
                string s1=s.substr(idx,i);
                if(st.find(s1)==st.end())
                {
                    st.insert(s1);
                    recursion(s,i+idx,st);
                    st.erase(s1);
                }
            }
        
        return ;
    }
    int maxUniqueSplit(string s)
    {
        set<string>st;
        recursion(s,0,st);
        return ans;
    }
};
