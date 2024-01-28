"""
another method, update the value to the input array
"""
class Solution:
    def minimumOperations(self, nums):
        ans, s, e = 0, 0, len(nums) - 1
        while s < e:
            if nums[s] > nums[e]:
                nums[e - 1] += nums[e]
                e -= 1
                ans += 1
            elif nums[s] < nums[e]:
                nums[s + 1] += nums[s]
                s += 1
                ans += 1
            else:
                s += 1
                e -= 1
        return ans

MOTAIP = Solution()
assert MOTAIP.minimumOperations([4,3,2,1,2,3,2]) == 4, "ex1 failed"
assert MOTAIP.minimumOperations([4,3,2,1,2,3,1]) == 2, "ex2 failed"
assert MOTAIP.minimumOperations([1,2,3,4]) == 3, "ex3 failed"
print("all pass")
