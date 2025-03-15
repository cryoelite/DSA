# birthday-cake-candles 
## Input 
First line `n`, second line `n` integers, for the integer array `candles[]`.
## Problem 
Given `n` candles, find the number of the tallest candles. So if the tallest candle is `4` then count the number of `4`s in the array.
## Output 
Return the count of the tallest candle in the array.
## Constraints 
n >=1 and <= 1e5
candles[i] >=1 and <= 1e7
## Observations 
We can see that the result would be a number <= n, so it would be <= 1e5. So we can use an unsigned long int for both. Each element is also within 1e9 so unsigned long int can be used for each element as well.
## Solution 
We can simply track the count of the largest element and iterate over the array, so having 2 variables we iterate over the array. When we find a larger element till our current position, we reset the count and set this element to be the largest.

TC: O(n) SC: O(1) 
