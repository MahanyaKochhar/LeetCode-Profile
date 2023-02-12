long long int binaryexp(long long int A,long long int B)
{
    long long int res=1;
    while(B>0)
    {
        if(B&1)
            res=res*A;
        A=A*A;
        B=B/2;
    }
    return res;
}
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries)
    {
        vector<vector<int>>ans;
        map<int,pair<int,int>>mp;
        for(int len=1;len<=min(31,(int)s.length());len++)
        {
            int cnt=0;
            int curr_val=0;
            int lft=0,rft=len-1;
            for(int i=len-1;i>=0;i--)
            {
                curr_val+=((s[i]-'0')*binaryexp(2,cnt));
                cnt++;
            }
            cnt--;
            for(int k=len;k<s.length();k++)
            {
                if(mp.find(curr_val)==mp.end())
                    mp[curr_val]={lft,rft};
                curr_val-=((s[lft]-'0')*binaryexp(2,cnt));
                curr_val*=2;
                curr_val+=(s[k]-'0');
                lft++;
                rft++;
            }
            if(mp.find(curr_val)==mp.end())
                    mp[curr_val]={lft,rft};
        }
       
        for(int i=0;i<queries.size();i++)
        {
           int req= queries[i][0]^queries[i][1];
           if(mp.find(req)==mp.end())
               ans.push_back({-1,-1});
            else
                ans.push_back({mp[req].first,mp[req].second});
        }
        return ans;
    }
};
