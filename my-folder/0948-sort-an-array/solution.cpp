class Solution {
public:
    void merge(vector<int>&arr,int l,int mid,int r)
    {
        vector<int>temp1,temp2;
        for(int i=l;i<=mid;i++)
        {
            temp1.push_back(arr[i]);
        }
        for(int i=mid+1;i<=r;i++)
            temp2.push_back(arr[i]);
        int i=0,j=0;
        int pos=l;
        while(i<temp1.size()&&j<temp2.size())
        {
            if(temp1[i]<=temp2[j])
            {
                arr[pos]=temp1[i];
                i++;
                pos++;
            }
            else
            {
                arr[pos]=temp2[j];
                j++;
                pos++;
            }
        }
        while(i<temp1.size())
        {
            arr[pos]=temp1[i];
            i++;
            pos++;
        }
        while(j<temp2.size())
        {
            arr[pos]=temp2[j];
            j++;
            pos++;
        }

    }
    void mergeSort(vector<int>&arr,int l,int r)
    {
        if(l>=r)
            return;
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);

    }
    vector<int> sortArray(vector<int>& nums)
    {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};
