class Spreadsheet {
public:
    vector<vector<int>>mat;
    Spreadsheet(int rows)
    {
        mat.resize(rows + 1,vector<int>(26,0));
    }

    pair<int,int> getRC(string cell) 
    {
        if(cell[0] >= 65 && cell[0] <= 90)
        {
            int col = cell[0] - 'A';
            string rowStr = cell.substr(1);
            int row = stoi(rowStr);
            return {row,col};
        }
        return {-1,-1};
    }
    
    void setCell(string cell, int value)
    {
        pair<int,int> rc = getRC(cell);
        mat[rc.first][rc.second] = value;
    }
    
    void resetCell(string cell)
    {
        pair<int,int> rc = getRC(cell);
        mat[rc.first][rc.second] = 0;
    }
    
    int getValue(string formula)
    {
        bool seen = false;
        string str1 = "", str2 = "";
        for(int j = 1; j < formula.length();j++)
        {
            if(formula[j] == '+')
            {
                seen = true;
                continue;
            }
            else if(seen == false)
            {
                str1.push_back(formula[j]);
            }
            else
            {
                str2.push_back(formula[j]);
            }
        }
        pair<int,int> rc1 = getRC(str1);
        pair<int,int>rc2 = getRC(str2);
        int v1 = rc1.first == -1 ? stoi(str1) : mat[rc1.first][rc1.second];
        int v2 = rc2.first == -1 ? stoi(str2) : mat[rc2.first][rc2.second];
        return v1 + v2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
