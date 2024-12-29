class Solution {
public:
    string answerString(string word, int numFriends)
    {
        if(numFriends == 1)
        {
            return word;
        }
        int lar = -1;
        char larC;
        int maxSub = word.length() - (numFriends - 1);
        vector<string>poss;
        for(auto ch : word)
        {
            if(ch - 'a' > lar)
            {
                lar = ch - 'a';
                larC = ch;
            }
        }
        for(int i = 0 ; i < word.length();i++)
        {
            if(word[i] == larC)
            {
                poss.push_back(word.substr(i,maxSub));
            }
        }
        sort(poss.begin(),poss.end());
        return poss[poss.size() - 1];
    }
};
