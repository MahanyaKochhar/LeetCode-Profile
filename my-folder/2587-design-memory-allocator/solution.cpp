class Allocator {
public:
    vector<int>arr;
    Allocator(int n)
    {
        arr.resize(n,0);
    }
    
    int allocate(int size, int mID)
    {
        int cnt=0;
        int lidx=-1;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
            {
                cnt++;
                if(cnt==size)
                {
                    lidx=i;
                    break;
                }
            }
            else
                cnt=0;
        }
        if(lidx==-1)
            return -1;
        while(size!=0)
        {
            arr[lidx]=mID;
            lidx--;
            size--;
        }
        return lidx+1;
    }
    
    int free(int mID)
    {
        int cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==mID)
            {
                arr[i]=0;
                cnt++;
            }
        }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
