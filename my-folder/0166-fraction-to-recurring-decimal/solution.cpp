class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        int neg = (numerator < 0 && denominator > 0) || (denominator < 0 && numerator > 0);
        using ll = long long;
        ll num1 = (ll)abs((ll)numerator);
        ll den1 = abs((ll)denominator);
        int f = num1 / den1;
        string ans = to_string(f);
        bool decimal = false;
        set<int>seen;
        int dig = -1;
        map<int,int>mp;
        while(num1 % den1 != 0)
        {
            ll rem = num1 % den1;
            rem *= 10;
            num1 = rem;
            if(decimal == false)
            {
                decimal = true;
                ans.push_back('.');
            }
            if(!seen.contains(num1))
            {
                ans += (to_string(num1 / den1));
                mp[num1] = ans.size() - 1;
                seen.insert(num1);
            }
            else
            {
                dig = num1;
                break;
            }
        }
        string fin = ans;
        if(dig != -1)
        {
            int e = 0;
            fin = "";
            fin.push_back(')');
            for(int j = ans.length() - 1 ; j >= 0 ; j--)
            {
                if(mp[dig] == j)
                {
                    fin.push_back(ans[j]);
                    fin.push_back('(');
                    e = 1;
                }
                else
                {
                    fin.push_back(ans[j]);
                }
            }
            reverse(fin.begin(),fin.end());
        }
        return neg && (fin[0] != '-') ? "-" + fin : !neg && fin[0] == '-' ? fin.substr(1) : fin;
    }
};
