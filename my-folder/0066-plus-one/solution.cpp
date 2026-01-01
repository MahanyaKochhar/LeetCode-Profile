class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        for(int i = digits.size() - 1 ; i >= 0 ; i--)
        {
            int c = (digits[i] + 1) % 10;
            digits[i] = c;
            if(c != 0)
            {
                break;
            }
        }
        if(digits[0] == 0)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
