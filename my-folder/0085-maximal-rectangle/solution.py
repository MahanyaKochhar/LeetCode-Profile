class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        ans = 0
        pre = [[0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
        for i in range(len(matrix)):
            if matrix[i][0] == "1":
                pre[i][0] = 1
            for j in range(1,len(matrix[0])):
                if matrix[i][j] == "1":
                    pre[i][j] += pre[i][j - 1] + 1
                else:
                    pre[i][j] = 0
        
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                mini = pre[i][j]
                ans = max(ans,mini)
                for k in reversed(range(i)):
                    rows = i - k + 1
                    cols = min(mini,pre[k][j])
                    mini = cols
                    ans = max(ans,rows * cols)
        
        return ans
        
