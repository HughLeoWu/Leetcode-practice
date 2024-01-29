/* 
 time O(log n) -> the solution should be binary search  
 we can use the middle point and compare the neigbor point, e.g. middle point = (left + right) / 2, and compare the mid and mid + 1
 we can figure out two cases to determine should move which direction (left side or right side) 
 case1: mid > mid + 1 -> to seek left side
 case2: otherwise to seek right side
 ex: nums = [1,2,3,1] -> mid = 3 -> 1 return 2
            [1,2,1,3,5,6,4] -> mid = 3 -> 6 -> 4 return 5
 for special case 1. [3] -> 0
             case 2. [3,4,5] -> mid = 4 -> 5 return 2
             case 3. [5,4,3] -> mid = 4 -> 5 return 0
 space O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1; // l 0 r 3
        while(l < r) {
            int mid = (l + r) / 2; // mid 1, 2, 
            if(nums[mid] > nums[mid + 1])
                r = mid;  
            else
                l = mid + 1; // l = 2, 3
        }
        return l;
    }
};

int main() {
    Solution FPE;
    vector<int> nums = {1,2,3,1};
    cout << FPE.findPeakElement(nums) << endl; // 2
}