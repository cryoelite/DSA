# reverse-integer 
## Input 
One 32 bit signed integer `x`
## Problem 
Return `x` after reversing each of its digits, that is `1234` becomes `4321` and so on. There's a catch, and that is, after reversing if `x` goes out the 32 bit range, i.e., `x` is exceeding the range $-2^{31}$ to $2^{31}-1$, then we should return a `0` instead.
## Output 
A reversed 32 bit signed integer, the reverse of `x`.
## Constraints 
`x` >= $-2^{31}$ and <= $2^{31}-1$
## Observations 
## Solution 
```cpp
  int compute() {
    constexpr int k_int_max{std::numeric_limits<int>::max()};
    constexpr int k_int_min{std::numeric_limits<int>::min()};
    int result{0};
    while (x != 0) {
      if ((result > k_int_max / 10) ||
          (result < k_int_min / 10)) {
        return 0;
      }
      result = result * 10 + x % 10;
      x /= 10;
    }

    return result;
  }
```
These are loose bound checks, that is say we have `997` as limit and we give `899`, it will return `998` which is out of bounds. A better bound check can be introduced by also checking for sum where `result*10 > k_int_max - sumvalue` (and something similar for negative bound check) after the first check.
TC: O(k) SC: O(1) Time taken to solve: 1 hr
where `k` are the number of digits in `x`.
## Problem Categories 
## Lessons to remember 
