import bisect
class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        fin = 0
        for i in range(32):
            d = [ 10**12 for i in range(len(nums) + 2)]
            d[0] = -10**9
            for num in nums:
                if num & (1 << i):
                    idx = bisect.bisect_right(d,num)
                    if num > d[idx - 1] and num < d[idx + 1]:
                        d[idx] = num
            ans = 0
            for i in range(1,len(d)):
                if d[i] != 10**12:
                    ans = i
            fin = max(fin,ans)
        return fin
