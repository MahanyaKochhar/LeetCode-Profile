class Solution {
public:
    long long countGood(vector<int>& nums, int k)
    {
         int l=0,r=0;
         long long int count=0;
         map<long long int,long long int>mp;
         long long int ans=0;
         while(r<nums.size())
         {
                 int ele=nums[r];
                 count+=mp[ele];
                 mp[ele]++;
                 while(count>=k&&l<r)
                {
                    ans+=(nums.size()-(r));
                    count-=(mp[nums[l]]*(mp[nums[l]]-1))/2;
                    mp[nums[l]]--;
                    count+=(mp[nums[l]]*(mp[nums[l]]-1))/2;
                    l++;
                }
                 r++;
         }
            return ans;
         }
};
