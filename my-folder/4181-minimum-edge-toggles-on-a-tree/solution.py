class Solution:
    def minimumFlips(self, n: int, edges: List[List[int]], start: str, target: str) -> List[int]:
        adjlist = [[] for i in range(n)]
        for i, edge in enumerate(edges):
            adjlist[edge[0]].append((edge[1],i))
            adjlist[edge[1]].append((edge[0],i))
        
        st = set()
        toggles = [0 for i in range(n)]
        def dfs(u,p,idx):
            child_toggles = 0
            for t in adjlist[u]:
                v = t[0]
                index = t[1]
                if v != p:
                    dfs(v,u,index)
                    child_toggles += toggles[v]
            
            if start[u] == target[u]:
                if child_toggles % 2 != 0:
                    toggles[u] += 1
                    st.add(idx)
            else:
                if child_toggles % 2 == 0:
                    toggles[u] += 1
                    st.add(idx)
        
        dfs(0,-1,-1)

        if -1 in st:
            return [-1]
        else:
            return sorted(list(st))

