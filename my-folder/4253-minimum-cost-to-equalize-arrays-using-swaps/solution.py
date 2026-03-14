class Solution:
    def minCost(self, nums1: list[int], nums2: list[int]) -> int:
        mp1 = {}
        mp2 = {}
        for num in nums1:
            mp1[num] = mp1.get(num,0) + 1

        for num in nums2:
            mp2[num] = mp2.get(num,0) + 1

        for k, v in mp1.items():
            val = v + mp2.get(k,0)
            if val % 2 != 0:
                return -1

        for k , v in mp2.items():
            val = v + mp1.get(k,0)
            if val % 2 != 0:
                return -1

        outward = 0
        for k , v in mp1.items():
            val = v + mp2.get(k,0)
            sp = val // 2
            outward += max(v - sp,0)

        return outward

        
