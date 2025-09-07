class Solution {
public:
    vector<int> sumZero(int n)
    {
        vector<int>ans;
        if(n % 2 != 0)
        {
            ans.push_back(0);
            n--;
        }
        int uq = n / 2;
        int cnt = 1;
        while(uq != 0)
        {   
            ans.push_back(cnt);
            ans.push_back(cnt * -1);
            uq--;
            cnt++;
        }
        return ans;
    }
};
