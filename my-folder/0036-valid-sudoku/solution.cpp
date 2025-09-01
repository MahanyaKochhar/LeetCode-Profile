class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        auto validate = [&](int i , int j) -> bool {
            for(int k = 0 ; k < board.size(); k++)
            {
                if(k == j)
                    continue;
                if(board[i][j] == board[i][k])
                {
                    return false;
                }
            }
            for(int k = 0 ; k < board.size(); k++)
            {
                if(k == i)
                    continue;
                if(board[k][j] == board[i][j])
                {
                    return false;
                }
            }
            int l1 = (i / 3) * 3;
            int r1 = (j / 3) * 3;
            for(int l = l1 ; l < l1 +3 ; l++)
            {
                for(int r = r1; r < r1 + 3;r++)
                {
                    if(i == l && j == r)
                    {
                        continue;
                    }
                    if(board[l][r] == board[i][j])
                    {
                        cout << board[l][r] << " " << board[i][j] << "\n";
                        cout << l << " " << r << " " << i << " " << j;
                        return false;
                    }
                }
            }
            return true;
        };
        for(int i = 0 ; i < board.size(); i++)
        {
            for(int j = 0 ; j < board[i].size(); j++)
            {
                if(board[i][j] != '.')
                {
                    if(!validate(i,j))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
