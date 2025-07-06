class Solution {
public:
    int trap(vector<int>& height)
    {
        vector<int>lMax(height.size());
        vector<int>rMax(height.size());
        int currL = 0;
        int currR = 0;
        for(int i  = 0 ; i < height.size();i++)
        {
            lMax[i] = currL;
            currL = max(currL,height[i]);
            rMax[height.size() - i - 1] = currR;
            currR = max(currR,height[height.size() - i - 1]);
        }
        int ans = 0;
        for(int i = 0 ; i < height.size();i++)
        {
            int pos = min(lMax[i],rMax[i]);
            if(pos >= height[i])
            {
                ans += pos - height[i];
            }
        }
        return ans;
    }
};
