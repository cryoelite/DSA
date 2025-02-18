# A very big sum
## Input
An integer `n`, and then `n` elements of an integer array `arr`
## Problem
Sum up all the elements of `arr`. THe main problem is, that each `arr[i]` can be very large and hence the sum would be as well.
## Output
A single integer which is the sum of elements of `arr`
## Constraints
n >= 1 and n<= 10
arr[i] >= 0 and arr[i] <= 1e10
## Observations
We can see that n is very small, and also that arr[i] is always a whole number, i.e., 0 or greater. This means we can use an unsigned long int which is atleast 2^32 or ~10^10 for each number `arr[i]`. However the sum might be 10^11, hence we can use unsigned long long int for the result, which is 2^64 and can contain the value.
## Solution
Implement the observation