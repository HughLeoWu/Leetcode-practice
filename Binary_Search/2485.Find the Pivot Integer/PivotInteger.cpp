/*
    brute force: time O(n^2); sapce O(1)
    n = 8
    if pivot = 8 -> 36 v.s. 8
       pivot = 7 -> 28 v.s. 15
       pivot = 6 -> 21 == 21

    binary search: time O(n*logn); Space O(1)
    n = 10,
    if pivot = 5 => 15 < 45 -> left = piv + 1
       pivot = 7 => 28 < 34 -> left = piv + 1 
       pivot = 9 => 45 > 19 -> right = piv - 1
       pivot = 8 => 36 > 27 -> right = piv - 1
       right = pivot - 1, left <= right is not true anymore -> break the loop and return -1
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int left = 0, right = n;
        int pivot = (left + right) / 2;
        while(left <= right) {
            int sum1 = 0, sum2 = 0;
            for(int idx = 0; idx <= pivot; idx++) {
                sum1 += idx;
            }
            for(int idx = pivot; idx <= n; idx++) {
                sum2 += idx;
            }
            if(sum1 > sum2) {
                right = pivot - 1;
            } else if (sum1 < sum2) {
                left = pivot + 1;
            } else {
                return pivot;
            }
            pivot = (left + right) / 2;
        }
        return -1;
    }
};

int main() {
    Solution PIV;
    cout << PIV.pivotInteger(8) << endl; // 6
    cout << PIV.pivotInteger(1) << endl; // 1
    cout << PIV.pivotInteger(4) << endl; // -1
}