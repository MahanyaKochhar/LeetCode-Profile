class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector<int> nums3;
        int l = 0,r = 0;
        while(l < m && r < n)
        {
            if(nums1[l] <= nums2[r])
            {
                nums3.push_back(nums1[l]);
                l++;
            }
            else
            {
                nums3.push_back(nums2[r]);
                r++;
            }
        }

        while(l < m)
        {
            nums3.push_back(nums1[l]);
            l++;
        }

        while(r < n)
        {
            nums3.push_back(nums2[r]);
            r++;
        }
        
        int i = 0;
        for(auto x: nums3)
        {
            nums1[i] = x;
            i++;
        }

    }
};
