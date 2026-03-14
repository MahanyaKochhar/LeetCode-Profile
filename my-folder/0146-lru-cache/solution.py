from sortedcontainers import SortedSet
class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.time = 0
        self.mp = {}
        self.st = SortedSet()
    def get(self, key: int) -> int:
        x, y = self.mp.get(key,(-1,-1))
        self.time += 1
        if y != -1:
            self.st.remove((x,key))
            self.st.add((self.time,key))
            self.mp[key] = (self.time,y)
        return y

    def put(self, key: int, value: int) -> None:
        self.time += 1
        x,y = self.mp.get(key,(-1,-1))
        if y != -1:
            self.mp[key] = (self.time,value)
            self.st.remove((x,key))
            self.st.add((self.time,key))
        else:
            if len(self.mp) == self.capacity:
                x,y = self.st[0]
                del self.mp[y]
                self.st.remove((x,y))
            self.mp[key] = (self.time,value)
            self.st.add((self.time,key))

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
