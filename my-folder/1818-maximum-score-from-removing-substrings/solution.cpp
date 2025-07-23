class Solution {
public:
    int maximumGain(string s1, int x, int y)
    {
        int ans = 0;
        vector<bool>vis(s1.length(),false);
        char fr,sr;
        int add1,add2;
        auto compute = [&] (string s,char fr,char sr,int add) -> void
        {
            stack<int>st;
            for(int i = 0 ; i < s.length() ; i++)
            {
                if(s[i] != fr && s[i] != sr)
                {
                    while(!st.empty())
                    {
                        st.pop();
                    }
                }
                else
                {
                    if(s[i] == fr)
                    {
                        st.push(i);
                    }
                    else
                    {
                        if(!st.empty())
                        {
                            vis[st.top()] = true;
                            vis[i] = true;
                            ans += add;
                            st.pop();
                        }
                    }
                }
            }
        };

        if(x >= y)
        {
            fr = 'a';
            sr = 'b';
            add1 = x;
            add2 = y;
        }
        else
        {
            fr = 'b';
            sr = 'a';
            add1 = y;
            add2 = x;
        }
        compute(s1,fr,sr,add1);
        string upd = "";
        for(int i = 0 ; i < s1.length();i++)
        {
            if(!vis[i])
            {
                upd.push_back(s1[i]);
            }
        }
        compute(upd,sr,fr,add2);
        return ans;
    }
};
