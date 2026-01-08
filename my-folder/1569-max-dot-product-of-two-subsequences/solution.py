class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        dp = [[0 for _ in range(len(nums2))] for _ in range(len(nums1))]
        dp[0][0] = nums1[0] * nums2[0]
        for i in range(1,len(nums2)):
            dp[0][i] = max(dp[0][i - 1],nums1[0] * nums2[i])
        
        for i in range(1,len(nums1)):
            dp[i][0] = max(dp[i - 1][0],nums1[i] * nums2[0])

        for i in range(1, len(nums1)):
            for j in range(1,len(nums2)):
                dp[i][j] = max(dp[i - 1][j - 1] + nums1[i] * nums2[j], max(dp[i - 1][j], max(nums1[i] * nums2[j],dp[i][j - 1])))
        
        return dp[len(nums1) - 1][len(nums2) - 1]
