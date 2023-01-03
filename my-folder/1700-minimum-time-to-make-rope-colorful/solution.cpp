class Solution {
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int ans=0;
        int sum=neededTime[0];
        int maxi=neededTime[0];
        for(int j=1;j<colors.length();j++)
        {
            if(colors[j]==colors[j-1])
            {
                maxi=max(maxi,neededTime[j]);
                sum+=neededTime[j];
            }
            else
            {
                ans+=sum-maxi;
                sum=neededTime[j];
                maxi=neededTime[j];
            }
        }
        ans+=sum-maxi;
        return ans;
    }
};
