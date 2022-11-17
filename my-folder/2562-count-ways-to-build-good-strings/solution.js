/**
 * @param {number} low
 * @param {number} high
 * @param {number} zero
 * @param {number} one
 * @return {number}
 */
var countGoodStrings = function(low, high, zero, one)
{
    const arr=[];
    const mod=1e9+7;
    for(let i=0;i<=high;i++)
    {
        arr.push([0,0]);
    }
    arr[0][0]=1;
    arr[0][1]=0;
    for(let i=1;i<=high;i++)
    {
        if(i>=zero)
        {
            arr[i][0]=(arr[i-zero][0]+arr[i-zero][1])%mod;
        }
        if(i>=one)
        {
            arr[i][1]=(arr[i-one][0]+arr[i-one][1])%mod;
        }
    }
    let ans=0;
    for(let i=low;i<=high;i++)
    {
        ans=(ans+arr[i][0]+arr[i][1])%mod;
    }
    return ans;
};
