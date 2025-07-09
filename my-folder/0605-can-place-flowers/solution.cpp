class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int i = 0,cnt = 0;
        int ans = 0;
        while(i < flowerbed.size() && flowerbed[i] != 1)
        {
            cnt++;
            i++;
        }
        if(i == flowerbed.size())
        {
            
            return ((cnt + 2 - 1) / 2)  >= n ? true : false;
        }
        ans += cnt / 2;
        int j = flowerbed.size() - 1;
        cnt = 0;
        while(j > 0 && flowerbed[j] != 1)
        {
            j--;
            cnt++;
        }
        ans += cnt / 2;
        cnt = 0;
        for(int k = i + 1; k < j ; k++)
        {
            if(flowerbed[k] == 1)
            {
                ans += (cnt + 2 - 1) / 2 - 1;
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }

        ans += max(0,((cnt + 2 - 1) / 2 - 1));
        cout << ans;
        return ans >= n ? true : false;
    }
};
