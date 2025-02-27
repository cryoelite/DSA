# Diagonal Difference
## Input
An integer `n` 
Then, `n` integers for an integer array arr, in `n` lines, so an `n`x`n` matrix arr
## Problem
Calculate the absolute difference between the sums of the diagonals
## Output
An integer, the absolute difference
## Constraints
arr[i][j] >= -100 and <= 100
## Observations
We can see that any element is not larger than 100, ln(100) is 6.6 so we only need 2^7 per element. So each element can fit in a short int.
There's no constraints for n so we have to take the largest possible size for the result, that is a long long int.
Result will never be a negative value because of abs()
## Solution
Simple iteration and adding all elements at i==j for i starting at 0 to n to give `sum_forward` and then going from largest n to 0 for i, getting `sum_backward`
Then getting `abs(sum_forward-sum_backward)` which is the result

> A simple observation is that, the diagonal has i and j same, so we only need to iterate `n` times instead of nxn, with each element at i,i. Another observation is that, the backward diagonal has the same `i` or the y axis and only the x axis or j is different so in the same loop we can get the forward diagonal's element at (i, i) and the second's element at (i, n-i-1) where n-i means the element from the right and -1 because 0 indexing.

TC: O(n) SC: O(1)
