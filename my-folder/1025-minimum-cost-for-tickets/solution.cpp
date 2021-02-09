class Solution {
public:
        map<int,int>mp;
        int dp[366];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
            mp[1]=costs[0];
            mp[7]=costs[1];
            mp[30]=costs[2];
            memset(dp,-1,sizeof(dp));
            int ans=minans(days,costs,0);
            return ans;
    }
        int minans(vector<int>days,vector<int>costs,int pos)
        {
                if(pos>=days.size())
                        return 0;
                if(dp[pos]!=-1)
                        return dp[pos];
            int best=INT_MAX;
        for(auto x:mp)
        {
                auto it=upper_bound(days.begin(),days.end(),x.first+days[pos]-1);
                        int newpos=it-days.begin();
             best=min(x.second+minans(days,costs,newpos),best);   
        }
                dp[pos]=best;
                return best;
    }
};
