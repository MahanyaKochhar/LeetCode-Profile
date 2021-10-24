class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power)
    {
        if(tokens.size()==0)
            return 0;
        sort(tokens.begin(),tokens.end());
       vector<int>pre(tokens.size()+1,0);
        for(int i=0;i<tokens.size();i++)
        {
            pre[i+1]=pre[i]+tokens[i];
        }
        int ans=0;
        int cnt=0;
        while(true)
        {
            int j=0;
            int sc=0;
            int cp=0;
            cp+=pre[tokens.size()]-pre[tokens.size()-cnt]+power;
            sc=sc-cnt;
            while(j!=tokens.size()-cnt&&cp>=tokens[j])
            {
                sc++;
                cp=cp-tokens[j];
                j++;
            }
            ans=max(sc,ans);
            cnt++;
            if(ans==0)
                break;
            if(cnt==tokens.size())
                break;
        }
        return ans;
        
    }
};
