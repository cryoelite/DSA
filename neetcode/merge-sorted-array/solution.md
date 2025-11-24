# merge-sorted-array 
## Input 
You are given two integer arrays nums1 and nums2, along with two integers m and n
## Problem 
m is the number of valid elements in nums1,
n is the number of elements in nums2.
The array nums1 has a total length of (m+n), with the first m elements containing the values to be merged, and the last n elements set to 0 as placeholders.

Your task is to merge the two arrays such that the final merged array is also sorted in non-decreasing order and stored entirely within nums1.
You must modify nums1 in-place and do not return anything from the function.
## Output 
Nothing, nums1 has to be modified in place. So nums1 if anything.
## Constraints 
both arrays are sorted in non-decreasing order already
0 <= m, n <= 200
1 <= (m + n) <= 200
nums1.length == (m + n)
nums2.length == n
-1,000,000,000 <= nums1[i], nums2[i] <= 1,000,000,000
## Observations 
Basically nums1 has the size m+n, nums2 has the size n. In nums1, the first m elements are the parts of nums1 that are already sorted in non decreasing order, and the rest `n` elements are 0. In nums2, all n elements are sorted already. We have to merge nums1 and nums2 into nums1 such that nums1 is still sorted in non decreasing order.
## Solution 

TC: O() SC: O() Time taken to solve:  
## Problem Categories 
## Lessons to remember 
