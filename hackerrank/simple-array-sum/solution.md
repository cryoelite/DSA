# Simple Array Sum
## Input
An int `n`, size of array. And then `n` elements, an array of integers `arr`
6
1 2 3 4 10 11 
## Problem
Find the sum of elements in `arr`
## Output
An integer `x` which is the sum of all elements of `arr`
31
## Constraints
n > 0 and <= 1000
arr[i] > 0 and <= 1000
## Observations
any arr[i] would be very small positive only integer, so we can use unsigned integer, there can be max 1000 elements with each a value of 1000 max, so 1000*1000 is the max sum, thats 10^6 or 1e6. The output type should be a long int, https://en.cppreference.com/w/cpp/language/types#Data_models, as the minimum possible width is 32 bits, which is 10^9.
n and arr[i] can be int.
## Solution
Simply iterate over each element, add it to a 0 initialized sum, and return the sum.


