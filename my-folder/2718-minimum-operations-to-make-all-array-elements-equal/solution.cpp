class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries)
    {
        vector<long long>ans;
        sort(nums.begin() , nums.end());
        vector<long long int> pre(nums.size());
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(i == 0)
                pre[i] = nums[i];
            else
                pre[i] = nums[i] + pre[i - 1];
        }
        for(int i = 0 ; i < queries.size() ; i++)
        {
            long long int m = queries[i];
            long long fin = 0;
            auto it = lower_bound(nums.begin() , nums.end() , m);
            
            if(it != nums.begin())
            {
                it--;
                long long int id = it - nums.begin();
                long long req = (id + 1 ) * m - pre[id];
                fin += req;
            }
            auto it2 = upper_bound(nums.begin() , nums.end() , m);
            if(it2 != nums.end())
            {
                long long int id = it2 - nums.begin();
                long long req = - (nums.size() - id ) * m + (pre[nums.size() - 1] - (id == 0 ? 0 : pre[id - 1]));
                fin += req;
            }
            ans.push_back(fin);
        }
        return ans;
    }
};
