class Solution:
    def pivotInteger(self, n: int) -> int:
        l = 0 
        r = n
        piv = int((l + r) / 2)
        while(l <= r):
            l_sum = 0 
            r_sum = 0
            for i in range(piv + 1):
                l_sum += i
            for j in range(piv, n + 1):
                r_sum += j
            
            if(l_sum < r_sum):
                l = piv + 1
            elif(l_sum > r_sum):
                r = piv - 1
            else:
                return piv
            piv = int((l + r) / 2)
        return -1