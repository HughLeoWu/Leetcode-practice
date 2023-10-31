/*
we can create the answer and append the merage array if there can be merged
ex:
|========================| 
| --- | (1,3)
  | ---- |  (2,6)
               | - | (8,10)
First, we need to do the sort function for making sure it is a increase sequence [2,6], [1,3] -> [1,3], [2,6]
answer [1,3] -> next step would be [1,6] because curr answer "3" is larger than next interval of the first value, 
the answer[i][1] would be update to the maximum value. On the other hand, it only needs to append the new interval in the answer 
*/
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort

using namespace std;
       
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> answer; 
        for(auto interval: intervals) { // interval [1,3]; [2,6]; [8,10]
            if(answer.size() == 0) {
                answer.push_back(interval); // answer [[1,3]]
            } else {
                if(answer[answer.size() - 1][1] >= interval[0]) {
                    // answer [[1,6]]
                    answer[answer.size() - 1][1] = max(answer[answer.size() - 1][1], interval[1]);
                } else {
                    // answer [[1,6],[8,10]]
                    answer.push_back(interval);
                }
            }
        }
        return answer;
    }
};

int main()
{
    Solution Merge;
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> output = {{1,6}, {8,10}, {15,18}};
    vector<vector<int>> ans = Merge.merge(intervals);
    if(ans == output)
        cout << "example 1 pass" << endl;
    else
        cout << "example 1 fail" << endl;

    return 0;
}