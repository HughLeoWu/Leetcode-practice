"""
n = 4, k = 2
start
        1        2    3
    2   3   4   3 4   4  
return    return -> code stack back to (i + 1) 
"""
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = list()
        temp = list()
        self.backtrack(n, k, ans, temp, 1)
        return ans
    
    def backtrack(self, n, k, ans, temp, start): # 1; 2; 3; 4
        if(len(temp) == k):
            ans.append(list(temp)) # [1,2]; [1,3]; [1,4]
            return
        else:
            for i in range(start, n + 1):
                temp.append(i)  # temp [1]; [1,2]; [1,3]; [1,4] ; for loop i += 1 => [2]
                self.backtrack(n, k, ans, temp, i + 1)
                temp.pop()      # temp [1]; [1]; [1]; [1]

CB = Solution()
assert CB.combine(4, 2) == [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]], "ex1 failed"
print("all pass")

"""
Time: O(n! / ((k - 1)! * (n - k)!)) a.k.a the "n choose k" 
Space: O(k) the call stack
"""