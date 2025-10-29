# concatenation-of-array 
## Input 
## Problem 
## Output 
## Constraints 
## Observations 
## Solution 
```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        size_t n{nums.size()};
        vector<int> res {vector<int>(n*2,0)};
        for(size_t i {0}; i<(n*2); ++i) {
            res[i]=nums[i%n];
        }
        return res;
    }
};
```
TC: O(n) SC: O(n) Time taken to solve: 5 min
## Problem Categories 
Array
## Lessons to remember 
1. Speed matters, directly solve on neetcode and only use IPOCOS (the categories in these `solution.md`s) for big/tedious problems (medium/hard/contest)
