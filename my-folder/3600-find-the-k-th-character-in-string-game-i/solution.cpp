class Solution {
public:
    char kthCharacter(int k)
    {
        string curr = "a";
        while(true)
        {
            if(curr.length() >= k)
            {
                break;
            }
            string gen = "";
            for(int i = 0 ; i < curr.length();i++)
            {
                int v = (curr[i] - 'a' + 1) % 26;
                char ch = 'a' + v;
                gen.push_back(ch);
            }
            curr += gen;
        }
        return curr[k - 1];
    }
};
