class Solution:
    def twoSum(self, nums, target):
        record = dict()
        for idx, num in enumerate(nums):
            diff = target - num # diff = 7, num = 2; 2, 7
            ans = []
            if record.get(num) != None:
                ans = [record[num], idx]
                break
            record[diff] = idx # record = {7 : 0}
        return ans

TwoSum = Solution()
# example 1 
ans = TwoSum.twoSum([2,7,11,15], 9)
if ans == [0,1]:
    print("example 1 pass")
else:
    print("example 1 fail")