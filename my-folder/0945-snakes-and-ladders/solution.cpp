class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board)
    {
        int sz = board.size();
        vector<int>rolls(board.size() * board.size() + 1,-1);
        vector<int>vis(board.size() * board.size() + 1,false);
        using pii = pair<int,int>;
        queue<pii>q;
        q.push({1,0});
        rolls[1] = 0;
        auto getPosition = [&](int nx) -> pii {
            int ogRow = (nx + board.size() - 1) / board.size();
            int row = board.size() - ogRow;
            int ogCol = nx % board.size();
            int col;
            if(ogRow % 2 == 0)
            {
                col = (board.size() - ogCol) % board.size();
            }
            else
            {
                col = (ogCol - 1 + board.size()) % board.size();
            }
            return {row,col};
        };
        while(!q.empty())
        {
            pii x = q.front();
            q.pop();
            int curr = x.first;
            int moves = x.second;
            for(int j = 1 ; j <= 6; j++)
            {
                int nx = min(curr + j, sz * sz);
                pii pos = getPosition(nx);
                int dest = nx;
                cout << nx << " " << pos.first << " " << pos.second << "\n";
                if(board[pos.first][pos.second] != -1)
                {
                   dest = board[pos.first][pos.second];
                }
                if(!vis[dest])
                {
                    vis[dest] = true;
                    rolls[dest] = moves + 1;
                    q.push({dest,moves + 1});
                }
            }
        }
        return rolls[board.size() * board.size()];
    }
};
