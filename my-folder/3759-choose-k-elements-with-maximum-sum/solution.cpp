class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector<pair<int,int>>p;
         for(int i = 0 ; i < nums1.size();i++)
         {
            p.push_back({nums1[i],i});
         }
        sort(p.begin(),p.end());
        priority_queue<long long>pq;
        long long run = 0;
        int curr = 0;
        vector<long long>ans(nums1.size());
        for(int i = 1 ; i < p.size(); i++)
        {
            if(p[i].first > p[i - 1].first)
            {
                for(int l = curr ; l <= i - 1; l++)
                {
                    int index = p[l].second;
                    if(pq.size() < k)
                    {
                        pq.push(-nums2[index]);
                        run += nums2[index];
                    }
                    else
                    {
                        int ele = -pq.top();
                        pq.pop();
                        run -= ele;
                        pq.push(-max(ele,nums2[index]));
                        run += max(ele,nums2[index]);
                    }
                }
                curr = i;
            }
            ans[p[i].second] = run;
        }
        return ans;
        
    }
};
