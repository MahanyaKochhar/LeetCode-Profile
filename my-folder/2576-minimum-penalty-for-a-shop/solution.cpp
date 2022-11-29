class Solution {
public:
    int bestClosingTime(string customers)
    {
        vector<int>pre(customers.length(),0);
        for(int i=0;i<customers.length();i++)
        {
            if(customers[i]=='Y')
            {
                pre[i]=((i==0)? 1:pre[i-1]+1);
            }
            else
                pre[i]=(i==0)?0:pre[i-1];
        }
        
        int fin=customers.length();
        for(int i=0;i<customers.length();i++)
        {
            int ans=(i)-((i==0)?0:pre[i-1]);
            ans+=pre[customers.size()-1]-((i==0)?0:pre[i-1]);
            fin=min(fin,ans);
        }
        if(customers.length()-pre[customers.size()-1]<fin)
        {
            return customers.length();
        }
        else
        {
            for(int i=0;i<customers.size();i++)
        {
                int ans=(i)-(i==0?0:pre[i-1]);
                ans+=pre[customers.size()-1]-(i==0?0:pre[i-1]);
                if(ans==fin)
                    return i;
        } 
        }
        return 0;
    }
};
