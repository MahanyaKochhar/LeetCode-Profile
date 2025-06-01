class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k)
    {
        vector<vector<int>>fin(grid.size() - k + 1,vector<int>(grid[0].size() - k + 1));
        for(int i = 0 ; i < grid.size();i++)
        {
            for(int j = 0 ; j < grid[0].size(); j++)
            {
                int bi = i + k - 1;
                int bj = j + k - 1;
                if(bi < grid.size() && bj < grid[0].size())
                {
                    vector<int>nums;
                    for(int l = i ; l <= bi ; l++)
                    {
                        for(int m = j ; m <= bj ; m++)
                        {
                            nums.push_back(grid[l][m]);
                        }    
                    }
                    sort(nums.begin(),nums.end());
                    long long ans = 1e11;
                    for(int j = 1 ; j < nums.size();j++)
                    {
                        if(nums[j] != nums[j - 1])
                        {
                            ans = min(ans,(long long)(abs(nums[j] - nums[j - 1])));
                        }
                    }
                    if(ans == 1e11)
                    {
                        ans = 0;
                    }
                    fin[i][j] = ans;
                }
            }    
        }
        return fin;
    }
};
