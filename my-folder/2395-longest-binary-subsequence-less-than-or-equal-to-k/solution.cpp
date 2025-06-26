class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sm = 0;
        int cnt = 0;
        int cl = k;
        int bit = (int) (log(k) / log(2));
        
        bit++;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[s.size() - 1 - i];
            if (ch == '1') {
                if (i <= bit && sm + (1 << i) <= k) {
                    sm += 1 << i;
                    cnt++;
                }
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};
