class Solution {
public:
    set<int>s;
    void dfs(int a , int b, vector<vector<bool>>& vis, vector<vector<int>>& conn, vector<vector<char>>& board, int cc)
    {
        vis[a][b] = true;
        conn[a][b] = cc;
        vector<int> hz = {1,-1,0,0};
        vector<int> vr = {0,0,1,-1};
        for(int i = 0 ; i < hz.size() ; i++)
        {
            int x = hz[i] + a;
            int y = vr[i] + b;
            if(x < 0 || x >= conn.size() || y < 0 || y >= conn[0].size())
            {
                s.insert(cc);
            }
            else if(!vis[x][y] && board[x][y] == 'O')
            {
                dfs(x,y,vis,conn,board,cc);
            }
        }
    }

    void solve(vector<vector<char>>& board)
    {
        vector<vector<bool>>vis(board.size(),vector<bool>(board[0].size(),false));
        vector<vector<int>>conn(board.size(),vector<int>(board[0].size(),0));
        s.clear();
        int cc = 1;
        for(int i = 0 ; i < board.size();i++)
        {
            for(int j = 0 ; j < board[i].size() ; j++)
            {

                if(!vis[i][j] && board[i][j] == 'O')
                {
                    dfs(i,j,vis,conn,board,cc);
                    cc++;
                }
            }
        }

        for(int i = 0 ; i < conn.size() ; i++)
        {
            for(int j = 0 ; j < conn[0].size() ; j++)
            {
                if(conn[i][j] != 0)
                {
                    if(s.find(conn[i][j]) == s.end())
                    {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
};
