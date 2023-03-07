class Solution {
public:
    int findValidSplit(vector<int>& nums)
    {
        vector <int> spf(1e6+1);
        for(int i = 1; i <= 1e6; i++)
            spf[i] = i;
        for(int i = 2; i*i <= 1e6 ;i++)
        {
            if(spf[i] == i)
            {
                for(int j = i*i ; j <= 1e6 ;j += i)
                {
                    if(spf[j] == j)
                        spf[j] = i;
                }
            } 
        }
        set<int> s;
        unordered_map <int,int> mp1, mp2;
        for(int i = 0 ;i < nums.size() ; i++)
        {
            int n = nums[i];
            while(n != 1)
            {
                mp1[spf[n]]++;
                n = n / spf[n];
            }
        }
        for(int i = 0; i < nums.size() - 1 ; i++)
        {
            int n = nums[i];
            while(n != 1)
            {
                mp2[spf[n]]++;
                mp1[spf[n]]--;
                if(mp1[spf[n]] != 0)
                    s.insert(spf[n]);
                else
                {
                    if(s.find(spf[n]) != s.end())
                        s.erase(spf[n]);
                }
                n = n / spf[n];
            }
                if(s.size() == 0)
                    return i;
        }
        return -1;
        
    }
};
