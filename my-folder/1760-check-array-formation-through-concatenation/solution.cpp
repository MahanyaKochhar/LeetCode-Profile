class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int l1=arr.size();
        int l2=pieces.size();
        int c=0;
        int e=0,f=0;
        int ans=0;
        while(c<l1)
        {
             f=0;
            for(int j=0;j<l2;j++)
            {
                if(pieces[j][0]==arr[c])
                {
                    f=1;
                    int k=pieces[j].size();
                    for(int l=0;l<k;l++)
                    {
                        if(pieces[j][l]==arr[c])
                        {
                            c++;
                        }
                        else
                        {
                            e=1;
                            break;
                        }
                    }
                    
                }
               
                if(e==1||(f==0&&j==l2-1))
                {
                    ans=1;
                    break;
                }
                if(f==1)
                    break;
            }
            if(ans==1)
            {
                break;
        }
    }
        if(ans==1)
            return false;
        else
            return true;
}};
