class Solution {
public:
    int bestClosingTime(string customers)
    {
        vector<int>pre(customers.length() + 1,0);
        vector<int>suff(customers.length() + 2,0);
        for(int i = 1 ; i <= customers.length() ; i++)
        {
            pre[i] += pre[i - 1] + ((customers[i - 1] == 'N') ? 1 : 0);
            suff[customers.length() - i + 1] += suff[customers.length() - i + 2] + ((customers[customers.length() - i] == 'Y') ? 1 : 0);
        }
        int ans = INT_MAX;
        int fin = -1;
        for(int i = 1 ; i <= customers.length() ; i++)
        {
            int pen = pre[i - 1] + suff[i];
            if(pen < ans)
            {
                ans = pen;
                fin = i - 1;
            }
        }
        if(pre[customers.length()] < ans)
        {
            fin = customers.length();
        }
        return fin;
    }
};
