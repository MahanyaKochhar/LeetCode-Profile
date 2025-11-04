class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x)
    {
        vector<int>ans;
        for(int i = 0 ; i <= nums.size() - k; i++)
        {
            map<int,int>mp;
            set<pair<int,int>>st;
            int fin = 0;
            for(int j = i ; j < i + k; j++)
            {
                mp[nums[j]]++;
            }
            for(auto [k,v] : mp)
            {
                st.insert({v,k});
            }
            int fq = 0;
            for(auto it = st.rbegin(); it != st.rend(); it++)
            {
                fq++;
                pair<int,int>pa = *it;
                fin += pa.first * pa.second;
                if(fq == x)
                {
                    break;
                }
            }
            ans.push_back(fin);
        }
        return ans;
    }
};
