class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int idx=0;
        int c1=0,c2=0;
        vector<int>ans(n);
        vector<int>nums3(m+n);
        while(m!=0&&n!=0)
        {
            if(nums1[c1]<=nums2[c2])
            {
                nums3[idx]=nums1[c1];
                idx++;
                c1++;
                m--;
            }
            else
            {
                nums3[idx]=nums2[c2];
                ans[c2]=idx;
                idx++;
                c2++;
                n--;
            }
            
        }
        while(n!=0)
        {
            nums3[idx]=nums2[c2];
         
            idx++;
            c2++;
            n--;
        }
        while(m!=0)
        {
            nums3[idx]=nums1[c1];
            idx++;
            c1++;
            m--;
        }
        nums1=nums3;
        
        
        
    }
};
