class Solution {
public:
    int minSetSize(vector<int>& arr)
    {
        int n = arr.size();
        vector<int>s(1e5 + 1,0);
        for(int i = 0 ; i < arr.size();i++)
        {
            s[arr[i]]++;
        }
        sort(s.rbegin(),s.rend());
        int cnt = 0;
        int sz = 0;
        for(auto x : s)
        {
            cnt += x;
            sz++;
            if(cnt >= n / 2)
            {
                break;
            }
        }
        return sz;
    }
};
