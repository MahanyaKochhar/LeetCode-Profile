class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        /*
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int t=target;
            t=t-nums[i];
            auto it=lower_bound(nums.begin(),nums.end(),t);
            if(*it==t)
            {
                vector<int>ans{i,int(it-nums.begin())};
                return ans;
            }
        }
        return jlt;
    } */
        vector<int>jlt;
       vector<pair<int,int>>p;
        for(int i=0;i<nums.size();i++)
        {
            p.push_back({nums[i],i});
        }
        sort(p.begin(),p.end());
        vector<int>temp;
        for(int i=0;i<p.size();i++)
        {
            temp.push_back({p[i].first});
        }
        for(int i=0;i<temp.size();i++)
        {
            int t=target-temp[i];
            auto it2=temp.begin()+i;
            auto it=lower_bound(it2+1,temp.end(),t);
            if(it!=temp.end()&&*it==t)
            {
                int idx=it-temp.begin();
                vector<int>ans{p[i].second,p[idx].second};
                return ans;
            }
            auto it3=lower_bound(temp.begin(),it2-1,t);
            if(it3!=temp.end()&&*it3==t)
            {
                int idx=it3-temp.begin();
                vector<int>ans{p[i].second,p[idx].second};
                return ans;
            }
        }
        return jlt;
    }
};
