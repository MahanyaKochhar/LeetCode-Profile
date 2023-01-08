class Solution {
public:
    long long maxKelements(vector<int>& nums, int k)
    {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++)
            pq.push(nums[i]);
        int ops=0;
        long long ans=0;
        while(ops<k)
        {
            ans+=pq.top();
            int f=pq.top();
            pq.pop();
            int new_f=(f+3-1)/3;
            pq.push(new_f);
            ops++;
        }
        return ans;
    }
};
