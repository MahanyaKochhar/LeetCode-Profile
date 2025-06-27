class Solution {
public:
    int maximumSwap(int num)
    {
        int ans = num;
        string s = to_string(num);
        for(int i = 0 ; i < s.length(); i++)
        {
            for(int j = i + 1; j < s.length(); j++)
            {
                string copy = s;
                swap(copy[i],copy[j]);
                ans = max(ans,stoi(copy));
            }
        }
        return ans;
    }
};
