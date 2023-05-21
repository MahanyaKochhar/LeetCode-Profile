class Solution {
public:
    bool check(int curr_sum , string s , int pos, int ans,int sum)
    {
        if(pos == s.length())
        {
            if(sum + curr_sum == ans)
                return true;
            else
                return false;
        }
        return check(curr_sum * 10 + s[pos] - '0' , s , pos + 1 , ans, sum) || check(s[pos] - '0' , s , pos + 1 , ans , sum + curr_sum);
        
    }
    int punishmentNumber(int n)
    {
        int fin = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            int ans = i * i ;
            string s = to_string(ans);
            if(check(0, s , 0,i,0))
            {
                fin += ans;
            }
                
        }
        return fin;
    }
};
