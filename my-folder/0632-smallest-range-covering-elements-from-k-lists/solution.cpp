class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums)
    {
        int v1=INT_MAX;
        int v2;
        int ans=INT_MAX;
        multiset<pair<int,int>>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert({nums[i][0],i});
        }
        vector<int>pos(nums.size(),0);
        while(true)
        {
            auto it=s.begin();
            int x=it->first;
            int y=it->second;
            auto it2=s.end();
            it2--;
            int a=it2->first;
            int b=it2->second;
            s.erase(s.begin());
            if(a-x<ans)
            {
                v1=x;
                v2=a;
                ans=a-x;
            }
            else if(a-x==ans&&v1>x)
            {
                v1=x;
                v2=a;
                ans=a-x;
            }
            pos[y]++;
            if(pos[y]==nums[y].size())
                break;
            s.insert({nums[y][pos[y]],y});
            
            
        }
        vector<int>fin;
        fin.push_back(v1);
        fin.push_back(v2);
        return fin;
    }
};
