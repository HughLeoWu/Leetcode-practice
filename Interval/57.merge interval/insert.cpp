/*
in order to keep the O(n) time complexity, we need to insert the newinterval to intervals first
we use a flag to detect the newinterval insert in interval or not.
ex: interval = [[1,3],[6,9]], newInterval [2,5] -> we will get the new interval [[1,3],[2,5],[6,9]]
and then to implement the problem 56 as below
we can create the answer and append the merage array if there can be merged
ex:
|========================| 
| --- | (1,3)
  | ---- |  (2,6)
               | - | (8,10)
First, we need to do the sort function for making sure it is a increase sequence [2,6], [1,3] -> [1,3], [2,6]
answer [1,3] -> next step would be [1,6] because curr answer "3" is larger than next interval of the first value, 
the answer[i][1] would be update to the maximum value. On the other hand, it only needs to append the new interval in the answer 

time complexity O(n)
space complexity O(1)
*/
#include <iostream>
#include <vector>

using namespace std;
       
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool isIntervalInserted = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[0] < intervals[i][0]) {
                // Found the position, insert the interval and break from the loop.
                intervals.insert(intervals.begin() + i, newInterval);
                isIntervalInserted = true;
                break;
            }
        }
        if (!isIntervalInserted) { 
            intervals.push_back(newInterval);
        }
        for(auto interval: intervals) {                    // implement merge interval approach 
            if(ans.size() == 0 or interval[0] > ans[ans.size() - 1][1])
                ans.push_back(interval);
            else
                ans[ans.size() - 1][1] = max(interval[1], ans[ans.size() - 1][1]);
        }
        return ans;
    }