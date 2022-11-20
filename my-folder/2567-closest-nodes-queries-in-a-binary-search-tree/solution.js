/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number[]} queries
 * @return {number[][]}
 */
var arr=[];
function traverse(root)
{
    if(!root)
        return;
    arr.push(root.val);
    traverse(root.left);
    traverse(root.right);
}
function good(no,mid)
{
    if(arr[mid]>=no)
        return 1;
    else
        return 0;
}
var closestNodes = function(root, queries)
{
    arr=[];
    traverse(root);
    // for(let i=0;i<arr.length;i++)
    //     console.log(arr[i]);
    arr.sort(function(a,b){
        return a-b;
    });
    const ans=[];
    for(let i=0;i<queries.length;i++)
    {
        let no=queries[i];
        let l=-1,r=arr.length;
        while(l+1<r)
        {
        let mid=Math.floor((l+r)/2);
        if(good(no,mid))
            r=mid;
        else
            l=mid;
        }
        if(r==arr.length)
            ans.push([arr[r-1],-1]);
        else
        {
            if(arr[r]==no)
                ans.push([arr[r],arr[r]]);
            else
            {
                if(r==0)
                    ans.push([-1,arr[r]]);
                else
                    ans.push([arr[r-1],arr[r]]);
            }
        }
    }
    return ans;
    
};
