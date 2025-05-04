class Solution {
public:
    vector<vector<int>> specialGrid(int N)
    {
        int curr = pow(2,2 * N) - 1;
        vector<vector<int>>ans(pow(2,N),vector<int>(pow(2,N)));
        auto fillGrid = [&](auto self,pair<int,int>st, pair<int,int>end,int n)-> void {
            if(st.first == end.first && st.second == end.second)
            {
                ans[st.first - 1][st.second - 1] = curr;
                curr--;
                return;
            } 
            int pv = pow(2,n - 1);

            self(self,{st.first,st.second},{pv + st.first - 1,pv + st.second - 1},n - 1);

            self(self,{pv + st.first,st.second},{end.first,pv + st.second - 1},n - 1);

            self(self,{pv + st.first, pv + st.second},{end.first,end.second},n - 1);

            self(self,{st.first,pv + st.second},{pv + st.first - 1,end.second}, n - 1); 
            
        };
        fillGrid(fillGrid,{1,1},{pow(2,N),pow(2,N)},N);
        return ans;
    }
};
