class Solution {
public:
    long long putMarbles(vector<int>& weights, int k)
    {
        vector<long long int>sums;
        for(int i=1;i<weights.size();i++)
        {
            sums.push_back(weights[i]+weights[i-1]);
        }
        sort(sums.begin(),sums.end());
        long long int ans=0;
        int end=sums.size()-1;
        for(int i=0;i<k-1;i++)
        {
            ans+=(sums[end]-sums[i]);
            end--;
        }
        return ans;
    }
};
