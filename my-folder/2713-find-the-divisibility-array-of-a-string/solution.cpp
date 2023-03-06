class Solution {
public:
    vector<int> divisibilityArray(string word, int m)
    {
        long long int prev = 0;
        vector <int> ans;
        for(int i = 0 ;i < word.length(); i++)
        {
            int x = word[i] - '0';
            long long int curr = prev * 10 + x;
            prev = curr % m;
            if(prev == 0)
            {
                ans.push_back(1);
            }
            else
                ans.push_back(0);
            

        }
        return ans;
    }
};
