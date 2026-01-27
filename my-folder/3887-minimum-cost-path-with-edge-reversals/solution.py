import heapq
class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        adjlist = [[] for i in range(n)]
        for edge in edges:
            adjlist[edge[0]].append((edge[1],edge[2]))
            adjlist[edge[1]].append((edge[0],edge[2] * 2))
        
        pq = []
        d = [1e12 for i in range(n)]
        d[0] = 0
        heapq.heappush(pq,(0,0))
        while pq:
            v, nd = heapq.heappop(pq)
            if nd == n - 1:
                return v
            if v != d[nd]:
                continue
            for edge in adjlist[nd]:
                node = edge[0]
                wt = edge[1]
                if d[node] > d[nd] + wt:
                    d[node] = d[nd] + wt
                    heapq.heappush(pq,(d[node],node))
        
        return -1
