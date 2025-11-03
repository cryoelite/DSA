# remove-element 
## Input 
You are given an integer array nums and an integer val
## Problem 
Your task is to remove all occurrences of val from nums in-place. 
After removing all occurrences of val, return the number of remaining elements, say k, such that the first k elements of nums do not contain val.

Note:

The order of the elements which are not equal to val does not matter.
It is not necessary to consider elements beyond the first k positions of the array.
To be accepted, the first k elements of nums must contain only elements not equal to val.

Basically, the if the array is size n, and there are m occurences of val, and k = n-m, then the first `k` elements of the array shouldn't have val, that's the only requirement.
## Output 
`k` from an array where first `k` elements are not `val`
## Constraints 
0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
## Observations
The values are very small in range, and since order doesn't matter in the resultant array, we can also use a fixed size frequency array to create the resultant array. 
~~Also we don't actually need to modify the array, as the answer just wants int `k` which is just searching the array for values that are not `val`. But since it is an implementation type question, might as well solve it properly.~~ 
The question requests the array to be returned.
## Solution 
Just take array and 2 pointers, one on each end, and swap values which are equal to `val` on the left with the right one then decrement the right one and check again on left and continue. This way we just swap out the first `k` elements of vals which are swapped with values at the end.

TC: O(n) SC: O(1) Time taken to solve: 30 mins
## Problem Categories 
## Lessons to remember 
