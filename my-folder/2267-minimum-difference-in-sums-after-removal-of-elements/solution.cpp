class Solution {
public:
    long long minimumDifference(vector<int>& nums)
    {
        using ll = long long;
        int sz = nums.size() / 3;
        ll sum = 0;
        priority_queue<int>pq;
        vector<ll>lMin(nums.size(),-1);
        vector<ll>lMax(nums.size(),-1);
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(pq.size() < sz)
            {
                sum += nums[i];
                pq.push(nums[i]);
            }
            else
            {
                lMin[i - 1] = sum;
                auto x = pq.top();
                pq.pop();
                sum -= x;
                int toInsert = min(x,nums[i]);
                sum += toInsert;
                pq.push(toInsert);
            }
        }
        lMin[nums.size() - 1] = sum;
        sum = 0;
        while(!pq.empty())
        {
            pq.pop();
        }
        for(int j = nums.size() - 1; j >= 0 ; j--)
        {
            if(pq.size() < sz)
            {
                sum += nums[j];
                pq.push(-nums[j]);
            }
            else
            {
                lMax[j + 1] = sum;
                auto x = pq.top();
                pq.pop();
                sum -= (-x);
                int toInsert = max(-x,nums[j]);
                sum += toInsert;
                pq.push(-toInsert);
            }
        }
        lMax[0] = sum;
        ll ans = 1e11;
        for(int i = 0 ; i < nums.size() - 1; i++)
        {
            if(lMin[i] != -1 && lMax[i + 1] != -1)
            {
                ans = min(ans,lMin[i] - lMax[i + 1]);
            }
        }
        return ans;
    }
};
