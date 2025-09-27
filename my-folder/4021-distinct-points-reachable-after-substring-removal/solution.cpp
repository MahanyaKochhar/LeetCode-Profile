class Solution {
public:
    int distinctPoints(string s, int k)
    {
        vector<vector<int>>coord(s.length() + 1, vector<int>(4,0));
        for(int i = 1 ; i <= s.length();i++)
        {
            coord[i][0] += coord[i - 1][0] + (s[i - 1] == 'U' ? 1 : 0);
            coord[i][1] += coord[i - 1][1] + (s[i - 1] == 'D' ? 1 : 0);
            coord[i][2] += coord[i - 1][2] + (s[i - 1] == 'L' ? 1 : 0);
            coord[i][3] += coord[i - 1][3] + (s[i - 1] == 'R' ? 1 : 0);
        }
        set<pair<int,int>>st;
        for(int i = k ; i <= s.length();i++)
        {
            int u = coord[s.length()][0];
            int d = coord[s.length()][1];
            int l = coord[s.length()][2];
            int r = coord[s.length()][3];
            int nu = coord[i][0] - coord[i - k][0];
            int nd = coord[i][1] - coord[i - k][1];
            int nl = coord[i][2] - coord[i - k][2];
            int nr = coord[i][3] - coord[i - k][3];
            int remu = u - nu, remd = d - nd, reml = l - nl, remr = r - nr;
            int netu = remu - remd;
            int netr = remr - reml;
            st.insert({netu,netr});
        }
        return st.size();
    }
};
