# counting-bits 
## Input 
A single integer `n`.
## Problem 
Given an integer `n`, return the number of bits with `1` for all numbers between `0` and `n` (both inclusive) in an array where `arr[i]` is the number of `1`s for `i`.
## Output 
An array of integers of size `n+1`
## Constraints 
`n` >= 0 and <= 1000
## Observations 
Output array will be size `n+1`, we just have to iterate from `0` to `n` (inclusive).
## Solution 
We can use the same trick as counting `1`s for each value of `i` from `0` to `n` (inclusive), create a vector and store the count of `1`s for each `i` in a sub-loop. 
TC will be O(nk) and SC will be O(n).

TC: O() SC: O() Time taken to solve:  
## Problem Categories 
## Lessons to remember 
