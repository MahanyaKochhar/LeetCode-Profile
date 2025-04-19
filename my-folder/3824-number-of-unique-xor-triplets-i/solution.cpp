class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 1 || n == 2)
        {
            return n;
        }
        int i = 0;
        while(n != 0)
        {
            n = n >> 1;
            i++;
        }
        int fin = pow(2,i);
        return fin;
    }
};
