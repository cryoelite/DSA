# single-number 
## Input 
An array of ints, nums with length n (inferred).
## Problem 
Given an array of ints, where every int appears twice except one. Find the one integer that doesn't.
## Output 
The one non-recurring integer.
## Constraints 
n >=1 and <= 10000
nums[i] >= -10000 and <= 10000
## Observations 
Array is non-empty, meaning there will be at-least 1 element, there will always be a non-recurring integer, meaing there will be 1 element in nums, or 3 (because 1 non-recurring, 2 recurring elements), or 5, and so on. 
## Solution 
We can use XOR operation between integers, the property of XOR is that if we have 2 elements a and b, and we XOR them, if they are the same XOR returns a `0`, otherwise not. And it is transitive, meaning if `a XOR b XOR c` is an operation, and a and b are same, then c will be returned. XOR is an error detecting operation for the same reason. 

TC: O(n) SC: O(1) Time taken to solve: 30 mins 
Spent time debugging and fixing configs
## Problem Categories 
Bit Manipulation
## Lessons to remember 
1. Learn topics to the point, there's an endless well of topics to cover. We can't reasonably cover everything and be fast. Stick to the problem and the logic for it.
2. XOR is an operation that we can use to find unique elements in any given list/array.
3. Whilst we could have used short int for `n` and nums[i], we didn't because the problem gave us an int. Converting types needlessly is not only a time waste but also performance slowdown as types have to be carefully converted, upcasting could be much simpler but downcasting results in a brittle code that only works for the given constraints and any change to the constraints can involve huge changes. A normal `int` is more than enough for most problems, stick to it unless the problem or the performance is improved.
