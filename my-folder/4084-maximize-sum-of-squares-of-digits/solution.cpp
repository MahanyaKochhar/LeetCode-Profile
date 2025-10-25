class Solution {
public:
    string maxSumOfSquares(int num, int sum)
    {
        string ans = "";
        for(int i = 0 ; i < num;i++)
        {
            int curr = min(sum, 9);
            sum -= curr;
            ans.push_back(curr + '0');
        }
        return sum == 0 ? ans : "";
    }
};
