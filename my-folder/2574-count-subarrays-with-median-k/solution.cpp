class Solution {
public:
    int countSubarrays(vector<int>& nums, int k)
    {
        int idx;
        for(int i=0 ; i<nums.size() ;i++)
        {
            if(nums[i] == k)
            {
                idx = i;
                break;
            }
        }
        int curr = 0;
        map< int , int > mp;
        for(int j = idx ; j < nums.size() ; j++)
        {
            if(nums[j] > nums[idx])
            {
                curr++;
            }
            else if(nums[j] < nums[idx])
                curr--;
            mp[curr]++;
            
        }
        int now=0,ans =0;
        for(int j = idx ; j >= 0 ; j--)
        {
            if(nums[j] > nums[idx])
            {
                now++;
            }
            else if(nums[j] < nums[idx])
                now--;
            ans += (mp[-now] + mp[-now+1]);

        }
        return ans;
    }
};
