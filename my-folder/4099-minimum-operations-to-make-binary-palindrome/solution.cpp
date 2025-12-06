class Solution {
public:
    vector<int> minOperations(vector<int>& nums)
    {
        
        vector<int>ans;
        vector<int>poss;
        poss.push_back(0);

        auto exp = [](int a ,int b) -> int {
            int res = 1;
            while(b != 0)
            {
                if(b & 1)
                {
                    res = res * a;
                }
                a = a * a;
                b = b / 2;
            }
            return res;
        };
        
        for(int i = 1 ; i <= 5000 ; i++)
        {
            int no = i;
            string rep = "";
            while(no != 0)
            {
                if(no & 1)
                {
                    rep.push_back('1');
                }
                else
                {
                    rep.push_back('0');
                }
                no = no / 2;
            }
            string r1 = rep;
            reverse(rep.begin(),rep.end());
            if(r1 == rep)
            {
                poss.push_back(i);
            }
        }

        for(int i = 0; i < nums.size(); i++)
        {
            int v = nums[i];
            int closest = 5000;
            auto it = upper_bound(poss.begin(), poss.end(), v);
            if(it != poss.end()) {
                closest = *it - v;
            }
            if(it != poss.begin()) {
                closest = min(closest, v - *prev(it));
            }
            ans.push_back(closest);
        }
        return ans;
    }
};
