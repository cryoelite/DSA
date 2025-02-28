# mini-max-sum 
## Input 
5 space separated integers
## Problem
Find the sum that can be calculated using any 4 integers such that it is the minimum sum of any 4 elements, and similarly find the maximum sum. 
## Output 
min sum and max sum
## Constraints 
arr[i] >=1 and <= 10^9
## Observations 
Each element is positive so we can use an unsigned integer, and the range is 1 to 10^9, so we have to use long long int, or unsigned long long int.
The sum would be within 10^9 or at most 10^10.
## Solution
One simple solution is to sort, and then we know the first 4 are the smallest elements and the last 4 are the biggest. 
TC is O(nlogn) and SC would be O(1)

A faster approach is that we find the min. element and the max. element and the whole array sum, then we just subtract the max. element from it to get the min. sum and the min. element from it to get the max sum. This is possible only because we have to only take out 1 element from the sum, if it were more we would have to track the elements better.
TC is O(n) and SC O(1)