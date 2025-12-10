class Solution {
public:
    int countPermutations(vector<int>& complexity)
    {
        int min = complexity[0];
        const int mod = 1e9 + 7;
        for(int i = 1; i < complexity.size(); i++)
        {
            if(complexity[i] <= min)
            {
                return 0;
            }
        }
        long long ans = 1;
        for(int i = 1 ; i < complexity.size() ; i++)
        {
            ans = (ans * i) % mod;
        }
        return ans;
    }
};
