# reverse-bits 
## Input 
An unsigned 32-bit integer `n`
## Problem 
Given `n`, reverse the binary representation of it and return the unsigned integer formed by doing so
## Output 
An unsigned integer which is formed of the bits reversed in `n`.
## Constraints 
`n` is >=0 and <= unsigned 32 bit integer max
## Observations 
We can use unsigned long long to represent this integer.
## Solution 
One basic solution is to go over each of the 32 bits and check and set them in a new integer from the left.
TC will be O(1) and SC will be O(1) as well however the constant factor can probably still be reduced.
Still this is a good enough solution.

```cpp
  uint32_t compute() {
    uint32_t result{0};

    for (size_t i{0}; i < 32; ++i) {
      if (n & (1 << i)) {
        result |= (1 << (31 - i));
      }
    }
    return result;
  }
```
TC: O(1) SC: O(1) Time taken to solve: 5 mins, implementation: 10 mins
## Problem Categories 
Bit Manipulation
## Lessons to remember 
1. The left shift operation is very handy, keep it in the back of your head for all bit related questions.
