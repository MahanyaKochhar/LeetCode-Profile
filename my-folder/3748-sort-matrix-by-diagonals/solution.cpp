class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid)
    {
        vector<vector<int>>ans(grid.size(),vector<int>(grid[0].size(),0));
        auto fill = [&](int i , int j,string dir) {
            int st = i, en = j;
            vector<int>tmp;
            while(st >= 0 && st < grid.size() && en >= 0 && en < grid.size())
            {
                tmp.push_back(grid[st][en]);
                st++;
                en++;
            }
            if(dir == "DEC")
            {
                sort(tmp.rbegin(),tmp.rend());
            }
            else
            {
                sort(tmp.begin(),tmp.end());
            }
            int k = 0;
            while(i >= 0 && i < grid.size() && j >= 0 && j < grid.size())
            {
                ans[i][j] = tmp[k];
                k++;
                i++;
                j++;
            }
        };

        for(int i = 0 ; i < grid.size();i++)
        {
            int j = 0;
            fill(i,j,"DEC");
        }

        for(int j = 1 ; j < grid.size() ; j++)
        {
            int i = 0;
            fill(i,j,"INC");
        }
        return ans;
        
    }
};
