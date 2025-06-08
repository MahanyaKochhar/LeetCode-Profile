class Solution {
public:
    int countPermutations(vector<int>& complexity)
    {
        const int mod = 1e9 + 7;
        for(int i = 1 ; i < complexity.size();i++)
        {
            if(complexity[0] >= complexity[i])
            {
                return 0;
            }
        }
        int n = complexity.size();
        long long fact = 1;
        for(int j = 1 ; j < n ; j++)
        {
            fact = (fact % mod * j % mod) % mod;
        }
        return (int)fact;
    }
};
