class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity)
    {
        sort(capacity.rbegin(),capacity.rend());
        int sum = 0;
        for(auto& x : apple)
        {
            sum += x;
        }
        int ans = 0;
        int curr = 0, i = 0;
        while(curr < sum)
        {
            ans++;
            curr += capacity[i];
            i++;
        }
        return ans;
    }
};
