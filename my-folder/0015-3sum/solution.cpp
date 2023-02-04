class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        map<int,int>mp2;
        for(int i=0;i<nums.size();i++)
        {
            mp2[nums[i]]++;
        }
        vector<int>nums1;
        for(auto x:mp2)
        {
            for(int j=0;j<min(3,x.second);j++)
                nums1.push_back(x.first);

        }
        vector<vector<int>>ans;
        map<int,int>mp;
        set<pair<int,pair<int,int>>>s1;
        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]++;
        }
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=i+1;j<nums1.size();j++)
            {
                int s=nums1[i]+nums1[j];
                multiset<int>d;
                if(mp.find(-s)!=mp.end())
                {
                    if((nums1[i]==-s||nums1[j]==-s))
                    {
                        if(nums1[i]==nums1[j])
                        {
                            if(mp[-s]<=2)
                                continue;
                        }
                        else
                        {
                            if(mp[-s]<=1)
                                continue;
                        }
                    }
                        
                    d.insert(nums1[i]);
                    d.insert(nums1[j]);
                    d.insert(-s);
                    vector<int>n;
                    for(auto x:d)
                    {
                        n.push_back(x);
                    }
                    if(s1.find({n[0],{n[1],n[2]}})==s1.end())
                        s1.insert({n[0],{n[1],n[2]}});
                }
            }
        }
        for(auto x:s1)
        {
            ans.push_back({x.first,x.second.first,x.second.second});
        }
        return ans;
    }
};
