# single-number 
## Input 
An array of ints, nums (size n, infer automatically)
## Problem 
In an array nums, all numbers appear twice except one number, find this number.
## Output 
The number which doesn't occur twice.
## Constraints 
n >= 1 and <= 10000
nums[i] >= -10000 and <= 10000
## Observations 
n is always a positive int and not that big, nums[i] is the same but it can be negative as well. 
## Solution 
We simply iterate over the array and XOR the values, XOR is an operation that gets cancelled out when same values are given, hence any distinct value can be detected by it. It is a boolean operation meant to detect errors because of this property.

TC: O(n) SC: O(1) Time taken to solve: NA
## Problem Categories 

Bit Manipulation
## Lessons to remember 

1. Solve the problem whole in one go, don't put it for later.
2. Learn boolean algebra basics, the why of XOR being like the way it is, is also important.
3. Had an error with the result where it was always 1. I didn't check the return type of the `singleNumber()` when i modifed it from the template. Always check if the template is correctly modified. Can be resolved if we do the problem in one go directly.
   
