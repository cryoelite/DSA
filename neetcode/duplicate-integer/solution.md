# duplicate-integer 
## Input 
## Problem 
## Output 
## Constraints 
## Observations 
## Solution 
```
  bool compute() {
    bool result{false};
    std::unordered_set t{std::unordered_set<int>()};
    t.reserve(n);

    for (size_t i{0}; i < n; ++i) {
      if (t.find(arr[i]) == t.end()) {
        t.insert(arr[i]);
      } else {
        result = true;
      }
    }

    return result;
  }
  ```
TC: O(n^2) SC: O(n) Time taken to solve: 1 hr  
## Problem Categories 
## Lessons to remember 
