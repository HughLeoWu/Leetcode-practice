# to find out the maximum weight borader ex: [1,2,3,4,5,...,10], 
# so the maximum is sumation of these weights = 55
# and the minmum of 1 days is the maximun of weights = 10
# if weights = 10, it needs 7 days to transmitted these packages, (1,2,3,4);(5);(6);(7);(8);(9);(10)
#    weights = 11,          6 days -> (1,2,3,4);(5,6);(7);(8);(9);(10)
#            = 55           1 day (1,2,3,4,5,6,7,8,9,10)
# [10,11,12,... 55] -> weights of array
# [7,6,6,6,6,5,5,5,5,4,4,4,3,3,2,... 1] -> days, and then how to find out the begining of 5 (target)?
#  L                 M               R  if M <= Target = R = M
#  L       M         R                  if M > Target -> L = M + 1
#            L M     R
#            ...              
#            L/M/R -> stop return L 
class Solution:
    def shipWithinDays(self, weights, days) -> int:
        minCap = max(weights)
        maxCap = sum(weights)
        while minCap < maxCap:
            middleCap = (minCap + maxCap) // 2
            if(self.DaysofShip(weights, middleCap) <= days):
                maxCap = middleCap
            else:
                minCap = middleCap + 1

        return minCap

    def DaysofShip(self, weights, Cap) -> int:
        currentLoad = 0 # 33
        days = 1
        for weight in weights: # 1,2,3,4,5,6,7,8 
            currentLoad += weight # 32,30,27,23,18,12,5,-3; 16, 10  
            if currentLoad > Cap:
                currentLoad = weight
                days += 1 # 1
        return days 

DoS = Solution()
assert DoS.shipWithinDays([1,2,3,4,5,6,7,8,9,10], 5) == 15, "ex1 failed"
assert DoS.shipWithinDays([3,2,2,4,1,4], 3) == 6, "ex2 failed"
assert DoS.shipWithinDays([1,2,3,1,1], 4) == 3, "ex2 failed"
print("all pass")