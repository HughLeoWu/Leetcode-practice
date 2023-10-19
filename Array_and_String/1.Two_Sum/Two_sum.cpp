/*
 follow up, to use hashmap and record the current diff to the key, and the index is value
 ex: target = 9, nums = [2,7,11,15]
     hashmap = {7 = 0; 2 = 1; ...}
     when we check the element in the hashmap, nums[1] = 7, and "7" is in the hashmap of index 0
     so, we can make sure the result is "[hasmap[nums[index], index]]" 
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
       
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        unordered_map<int, int> record; // record {diff: index}
        for(int idx = 0; idx < nums.size(); idx++) {
            if(record.find(nums[idx]) != record.end()) {
                ans[0] = record[nums[idx]];
                ans[1] = idx;
                return ans;
            }
            record[target - nums[idx]] = idx; // record {7: 1}
        }
        return ans;
    }
};

int main()
{
    Solution two_sum;
    // example 1 Input: nums = [2,7,11,15], target = 9
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = two_sum.twoSum(nums, target);
    vector<int> res = {0, 1};
    if(ans == res)
        cout << "example 1 pass" << endl;
    else
        cout << "example 1 fail" << endl;
    
    // example 2 Input: nums = [3,2,4], target = 6
    nums = {3,2,4};
    target = 6;
    res = {1, 2};
    ans = two_sum.twoSum(nums, target);
    if(ans == res)
        cout << "example 2 pass" << endl;
    else
        cout << "example 2 fail" << endl;
        
    // example 3 Input: nums = [3,3], target = 6
    nums = {3,3};
    target = 6;
    res = {0, 1};
    ans = two_sum.twoSum(nums, target);
    if(ans == res)
        cout << "example 3 pass" << endl;
    else
        cout << "example 3 fail" << endl;
    return 0;
}