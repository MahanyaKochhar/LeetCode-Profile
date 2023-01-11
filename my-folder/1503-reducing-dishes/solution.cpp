class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction)
    {
        sort(satisfaction.begin(),satisfaction.end());
        reverse(satisfaction.begin(),satisfaction.end());
        int fin=-1;
        for(int j=satisfaction.size();j>=0;j--)
        {
            int k=j;
            int idx=0;
            int ans=0;
            while(k!=0)
            {
                ans+=(k*satisfaction[idx]);
                idx++;
                k--;
            }
            fin=max(ans,fin);
        }
        return fin;
    }
};
