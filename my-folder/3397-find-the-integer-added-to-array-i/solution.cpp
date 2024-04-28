class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int>posFreq(2001,0);
        for(int i = 0 ; i < nums2.size() ; i++)
        {
            posFreq[nums2[i]]++;
        }
        for(int j = 0 ; j < nums2.size() ; j++)
        {
            int s = nums2[j] - nums1[0];
            vector<int> tmpFreq(2001,0);
            int e = 0;
            for(int i = 0 ; i <nums1.size() ; i++)
            {
                int ele = nums1[i] + s;
                if(ele < 0)
                {
                    e = 1;
                    break;
                }
                tmpFreq[ele]++;
                if(tmpFreq[ele] <= posFreq[ele])
                    continue;
                else
                {
                    e = 1;
                    break;
                }
            }
            if(e == 0)
                return s;
        }
        return 0;
    }
};
