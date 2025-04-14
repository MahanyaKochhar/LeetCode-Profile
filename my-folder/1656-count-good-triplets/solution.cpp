class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c)
    {
        int cnt = 0;
        for(int i = 0; i < arr.size();i++)
        {
            for(int j = i + 1 ; j < arr.size();j++)
            {
                for(int k = j + 1; k < arr.size();k++)
                {
                    int v1 = abs(arr[i] - arr[j]);
                    int v2 = abs(arr[j] - arr[k]);
                    int v3 = abs(arr[i] - arr[k]);
                    if(v1 <= a && v2 <= b && v3 <= c)
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
