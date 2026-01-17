class Solution:
    def bestTower(self, towers: List[List[int]], center: List[int], radius: int) -> List[int]:
        sorted_towers = sorted(towers,key = lambda x : (x[0],x[1]))
        ans = [-1,-1]
        curr_max = -1
        for tower in sorted_towers:
            dist = abs(tower[0] - center[0]) + abs(tower[1] - center[1])
            if dist <= radius:
                if tower[2] > curr_max:
                    curr_max = tower[2]
                    ans = [tower[0],tower[1]]

        return ans
