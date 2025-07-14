class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values)
    {
        int ans = 0;
        int maxSoFar = values[0] + 0;
        for(int i = 1; i < values.size();i++)
        {
            ans = max(ans,maxSoFar + values[i] - i);
            maxSoFar = max(maxSoFar,values[i] + i);
        }
        return ans;
    }
};
