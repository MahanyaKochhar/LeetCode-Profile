class Solution {
public:
    bool check(vector<int>& nums) {
        int l=nums.size();
        vector<int>nums2=nums;
        sort(nums2.begin(),nums2.end());
        for(int n=0;n<l;n++)
        {
            int e=0;
            for(int i=0;i<l;i++)
            {
                if(nums2[i]==nums[(i+n)%l])
                    continue;
                else
                {
                    e=1;
                break;
                }
            }
            if(e==0)
                return true;
            else
                continue;
        }
            return false;
        }
    };
