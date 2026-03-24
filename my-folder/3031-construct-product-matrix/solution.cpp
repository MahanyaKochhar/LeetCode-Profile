class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid)
    {
        using ll = long long;
        const int mod = 12345;
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size(), 0));
        vector<int> elements;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                elements.push_back(grid[i][j]);
            }
        }
        vector<ll> pre(elements.size());
        vector<ll> suff(elements.size());
        pre[0] = elements[0] % mod;
        suff[elements.size() - 1] = elements[elements.size() - 1] % mod;
        for (int i = 1; i < elements.size(); i++)
        {
            pre[i] = (pre[i - 1] * elements[i]) % mod;
            suff[elements.size() - i - 1] = (suff[elements.size() - i] * elements[elements.size() - i - 1]) % mod;
        }
        int curr_row = 0, curr_col = 0;
        for (int i = 0; i < elements.size(); i++)
        {
            int l = 1, r = 1;
            if (i - 1 >= 0)
            {
                l = pre[i - 1];
            }
            if (i + 1 < elements.size())
            {
                r = suff[i + 1];
            }
            ans[curr_row][curr_col] = (l % mod * r % mod) % mod;
            curr_col++;
            if(curr_col >= grid[0].size())
            {
                curr_col = 0;
                curr_row++;
            }
        }
        return ans;
    }
};
