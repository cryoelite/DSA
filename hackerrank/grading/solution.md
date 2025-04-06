# grading 
## Input 
An integer `n`, and then `n` integers for an array `arr` 
## Problem 
Given `n` integers, for each integer, return a rounded or same value. The rounding depends on a simple logic.
The integer has to be rounded up to the next multiple of 5 if the difference between the next multiple of 5 and this integer is <3. For ex.: 84 will be rounded up to 85, but if we have 57, it will not be rounded.
Values should be >=38 to be rounded.
## Output 
An array `result` with all the processed values.
## Constraints 
n>=1 and <= 60
arr[i] >=0 and <= 100
## Observations 
Since n and arr[i] are so small, we can use an unsigned short int for both, which is still pretty large as it can hold values up to 65535.
## Solution 
Simply iterate ands store the result or directly output it for no space complexity.
TC: O(n) SC: O(n) 
