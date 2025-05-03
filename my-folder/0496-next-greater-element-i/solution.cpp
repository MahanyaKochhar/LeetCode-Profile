class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int>ans(nums1.size());
        for(int i = 0 ; i < nums1.size() ; i++)
        {
            int idx;
            for(int j = 0 ; j < nums2.size(); j++)
            {
                if(nums2[j] == nums1[i])
                {
                    idx = j;
                    break;
                }
            }
            vector<int>result(nums2.size(),-1);
            stack<int>s;
            for(int k = idx; k < nums2.size(); k++)
            {
                while(!s.empty() && nums2[k] > nums2[s.top()])
                {
                    int l = s.top();
                    s.pop();
                    result[l] = k;
                }
                s.push(k);
            }
            if(result[idx] != -1)
            {
                ans[i] = nums2[result[idx]];
            }
            else
            {
                ans[i] = -1;
            }
        }
        return ans;
    }
};
