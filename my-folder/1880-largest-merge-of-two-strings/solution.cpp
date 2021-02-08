class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i=0,j=0;
        string ans="";
        while(i<word1.length()||j<word2.length())
        {
        if(i!=word1.length()&&(word1[i]>word2[j]||(j==word2.length())))
        {
        ans.push_back(word1[i]);
        i++;
        }
        else if(j!=word2.length()&&(word2[j]>word1[i]||i==word1.length()))
        {
        ans.push_back(word2[j]);
        j++;
        }
        else
        {
        int c=i,d=j;
        while(word1[c]==word2[d]&&(c!=word1.length())&&d!=word2.length())
        {
        c++,d++;
        }
        if(c!=word1.length()&&(word1[c]>word2[d]||(d==word2.length())))
        {
       
        ans.push_back(word1[i]);
        
            i++;
        }
        else
        {
       
        ans.push_back(word2[j]);
        
            j++;
        }
        }
        }
        return ans;
    }
};
