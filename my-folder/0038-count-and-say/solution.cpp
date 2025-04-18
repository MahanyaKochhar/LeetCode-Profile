class Solution {
public:
    string countAndSay(int n)
    {
        string s = "1";
        auto rle = [&] () -> void {
            int fr = 1;
            string gen = "";
            for(int i = 1 ; i < s.length();i++)
            {
                if(s[i] == s[i - 1])
                {
                    fr++;
                }
                else
                {
                    gen += to_string(fr);
                    gen.push_back(s[i - 1]);
                    fr = 1;
                }
            }
            gen += to_string(fr);
            gen.push_back(s[s.length() - 1]);
            s = gen;
        };

        int i = 2;
        while(i <= n)
        {
            rle();
            i++;
        }
        return s;
    }
};
