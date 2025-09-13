class Solution {
public:
    int smallestAbsent(vector<int>& nums)
    {
        double avg = 0, sum = 0;
        map<int,int>mp;
        for(auto& x : nums)
        {
            mp[x]++;
            sum += x;
        }
        avg = sum / nums.size();
        for(int i = 1 ; i <= 101;i++)
        {
            if(i > avg && mp[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }
};
