class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        mx = -1
        prefixGcd = [0 for i in range(len(nums))]
        
        for i in range(len(nums)):
            mx = max(mx,nums[i])
            prefixGcd[i] = math.gcd(mx,nums[i])

        prefixGcd.sort()
        ans = 0
        l , r = 0 , len(nums) - 1
        while l < r:
            ans += math.gcd(prefixGcd[l],prefixGcd[r])
            l += 1
            r -= 1
        return ans
