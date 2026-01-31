class Solution:
    def minimumK(self, nums: List[int]) -> int:
        l , r = 0 , 1e5

        def good(v):
            cnt = 0
            for num in nums:
                cnt += int((num + v - 1) / v)
            return cnt <= v * v    
        
        while l + 1 < r:
            mid = int((l + r) / 2)
            if good(mid):
                r = mid
            else:
                l = mid
        return r
