# reverse-integer 
## Input 
A single signed 32 bit integer `x`.
## Problem 
Given an int `x`, reverse all of its digits and if reversing exceeds the range for a 32 bit integer, i.e., $[-2^{31}, 2^{31} - 1]$ then return a 0.
## Output 
A single 32 bit signed integer.
## Constraints 
`x` >= $-2^{31}$ and <= $2^{31}-1$  
## Observations 
Even if we have negative integers, say, `-1234` it returns `-4321` meaning signs are left as-is.
## Solution 
One simple direct solution is to first see the number of digits the number has, say `n` which is `4` in case of `1234` then we take a fresh number and get the last digit, which is `4` and multiply it with `10^n` and add it to the fresh number, then we subtract 1 from `n` and go to the next digit `3` and do the same, and so we get our final number. At the end we flip the sign to make it a negative number if `x` was one.
And to check if the number exceeded the range in this operation somewhere, before each addition we check if the addition exceeds the bound or not.
This is an ideal solution as well.
This stackoverflow answer provides a method to check for overflow https://stackoverflow.com/a/1514309. The logic is simple, if we have 2 ints `a` and `b` and we have to find out if `a+b > INT_MAX` (this can't be directly checked as it will overflow and it would wrap around) then all we need to do is check if `b>0`, if not then there's no addition, no overflow, and if `a > INT_MAX - b`, we simply send the b to the other side in the formula and this is indeed something that can be checked directly.


TC: O(1) SC: O(1) Time taken to solve: 1 hr

## Problem Categories 
Numbers
## Lessons to remember 
1. Speed and time taken to solve.
