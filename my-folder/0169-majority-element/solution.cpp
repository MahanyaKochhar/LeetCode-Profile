class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int candidate , counter = 0;
        for(auto x : nums)
        {
            if(counter == 0)
            {
                candidate = x;
                counter++;
            }
            else 
            {
                if(x == candidate)
                {
                    counter++;
                }
                else
                {
                    counter--;
                }
            }
        }
        return candidate;
    }
};
