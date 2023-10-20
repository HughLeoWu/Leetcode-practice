#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int DayofTransmitted(int cap, vector<int> &arr) {
        int curDayReq = 0;
        int temp = cap; // temp 32
        for(auto weight: arr) { // 
            cap -= weight;       
            if(cap < 0) {
                curDayReq++;
                cap = temp - weight;
            }
        }
        return ++curDayReq;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int minCap = 0, maxCap = 0;
        for(auto weight: weights) {
            maxCap += weight;
            minCap = max(minCap, weight);
        } // l 4, r = 16
        while(minCap < maxCap) {
            int mid = (minCap + maxCap) / 2;
            int curDayReq = DayofTransmitted(mid, weights);
            if(curDayReq > days) {
                minCap = mid + 1;
            } else {
                maxCap = mid;
            }
        }
        return minCap;
    }
};

int main() {
    Solution DoS;
    vector<int> weights ({1,2,3,4,5,6,7,8,9,10});
    cout << DoS.shipWithinDays(weights, 5) << endl; // 15
    vector<int> weights1 ({3,2,2,4,1,4});
    cout << DoS.shipWithinDays(weights1, 3) << endl; // 6
    vector<int> weights2 ({1,2,3,1,1}); 
    cout << DoS.shipWithinDays(weights2, 4) << endl; // 3
}