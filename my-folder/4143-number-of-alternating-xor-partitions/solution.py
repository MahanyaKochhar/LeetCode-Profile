class Solution:
    def alternatingXOR(self, nums: List[int], target1: int, target2: int) -> int:
        mod = 10**9 + 7
        dp1 = [0 for i in range(len(nums) + 1)]
        dp2 = [0 for i in range(len(nums) + 1)]
        mp1 = {}
        mp2 = {}
        mp2[0] = 1
        pre = 0
        for i in range(1,len(nums) + 1):
            pre = pre ^ nums[i - 1]
            dp1[i] = mp2.get(pre ^ target1,0)
            dp2[i] = mp1.get(pre ^ target2,0)
            mp1[pre] = (mp1.get(pre,0) +  dp1[i]) % mod
            mp2[pre] = (mp2.get(pre,0) + dp2[i]) % mod
        
        return ((dp1[len(nums)] + dp2[len(nums)]) % mod)
