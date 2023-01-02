class Solution {
public:
    bool detectCapitalUse(string word)
    {
       for(int i=0;i<word.length();i++)
       {
           if(word[i]==' ')
           {
               continue;
           }
           else
           {
               if(i==0)
                    continue;
               else if(i==1)
               {
                   if(word[i-1]>=65&&word[i-1]<=90)
                        continue;
                    else
                    {
                        if(word[i]>=65&&word[i]<=90)
                            return false;
                    }
               }
               else if((97<=word[i]&&word[i]<=122)&&(97<=word[i-1]&&word[i-1]<=122))
                continue;
               else if((65<=word[i]&&word[i]<=90)&&(word[i-1]>=65&&word[i-1]<=90))
                continue;
               else
                return false;
           }
       }
       return true; 
    }
};
