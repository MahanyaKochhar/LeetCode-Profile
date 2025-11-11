class Solution {
public:
    int maximumSum(vector<int>& arr)
    {
        if(arr.size() == 1)
        {
            return arr[0];
        }
        using ll = long long;
        vector<ll>kd(arr.size() + 2,0);
        vector<ll>rkd(arr.size() + 2,0);
        kd[0] = -1e13;
        rkd[arr.size() + 1] = -1e13;
        ll ans = -1e13;
        for(int i = 1 ; i <= arr.size(); i++)
        {
            kd[i] = max(kd[i - 1] + arr[i - 1], (ll)arr[i - 1]);
            rkd[arr.size() - i + 1] = max(rkd[arr.size() - i + 2] + (ll)arr[arr.size() - i],(ll)arr[arr.size() - i]);
            ans = max(ans,kd[i]);
        }
        kd[0] = 0;
        rkd[arr.size() + 1] = 0;
        for(int i = 1; i <= arr.size(); i++)
        {
            ans = max(ans,kd[i - 1] + rkd[i + 1]);
        }
        return ans;
    }
};
