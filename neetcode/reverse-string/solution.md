# reverse-string 
## Input 
You are given an array of characters which represents a string `s`.

## Problem 
Write a function which reverses a string.

You must do this by modifying the input array in-place with O(1) extra memory.
## Output 
An array of characters which are reverse of string `s`.
## Constraints 
modify the input array in-place with O(1) extra memory.
0 <= s.length < 100,000
s[i] is a printable ascii character.
## Observations 
## Solution 
```cpp
  void reverseString(std::vector<char> &s) {
    if (s.size() <= 1) {
      return;
    }

    auto l{s.begin()};
    auto r{s.end() - 1};
    while (l < r) {
      std::iter_swap(l++, r--);
    }
    return;
  }
```
TC: O(n) SC: O(1) Time taken to solve: 10 mins
## Problem Categories 
2 pointers
## Lessons to remember 
