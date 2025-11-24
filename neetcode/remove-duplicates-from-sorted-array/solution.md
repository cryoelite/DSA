# remove-duplicates-from-sorted-array 
## Input 
You are given an integer array nums
## Problem 
nums is sorted in non-decreasing order. Your task is to remove duplicates from nums in-place so that each element appears only once.

After removing the duplicates, return the number of unique elements, denoted as k, such that the first k elements of nums contain the unique elements.
Note:

The order of the unique elements should remain the same as in the original array.
It is not necessary to consider elements beyond the first k positions of the array.
To be accepted, the first k elements of nums must contain all the unique elements.
## Output 
Return k as the final result.
## Constraints 
nums is sorted in non-decreasing order
1 <= nums.length <= 30,000
-100 <= nums[i] <= 100
## Observations 
We have to modify nums such that the first `k` elements are unique. And we have to return this `k`. The array may have duplicates and hence `k` can be <= `n` (size of nums).
## Solution 
TC: O() SC: O() Time taken to solve:  
## Problem Categories 
## Lessons to remember 
