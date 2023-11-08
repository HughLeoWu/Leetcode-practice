/*
  pwwkew -> wke the longest without repeating characters is 3
  to use sliding window to find out the current answer, and then to find out the maximum one
  pwwkew, we will create a character pool to store this
  i = 0
  j = 0 -> len = 1  pool {p = 1},
  j = 1, len = 2;   pool {p = 1, w = 1}
  j = 2, because {w = 2} we can't count this length, so we have forward the other one index and remove it in the pool {p = 0; w = 2} i += 1
  i = 1, j = 2 pool {w = 2} i += 1 pool {w = 1}, 
  i = 2, j = 3 pool {w = 1; k = 1} len = 2, j = 4, pool {w = 1; k = 1; e = 1} len = 3.
  if j == length of string out of the loop  
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) { // s = pwwkew
        unordered_map<char, int> pool;
        int i = 0, j = 0, ans = 0;
        while(j != s.length()) { // j = 0; 1; 2
            pool[s[j]] += 1; // pool {p = 1}; {p = 1; w = 1}; {p = 1; w = 2}; {w = 1; k = 1}
            while(pool[s[j]] == 2) {
                pool[s[i]] -= 1; // pool {w = 2}; {w = 1}
                i += 1;          // i = 1; 2
            }
            ans = max(j - i + 1, ans); // ans = 1; 2
            j += 1; // j = 1; 2; 3
        }
        return ans;
    }
};