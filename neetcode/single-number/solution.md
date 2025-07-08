# single-number 
## Input 
An array of ints, and an implicit size n
## Problem 
For a given array of ints, where every integer appears twice except one, which only appears once. We have to find it in O(n), and use O(1) space.
## Output 
A single integer that only appeared once.
## Constraints 
n >=1 and <= 10000
arr[i] >= -10000 and <= 10000
## Observations 
We can see that the values of arr are within the range -10K to +10K, meaning we need a signed int. We can use a short signed int as it has the range -32K to +32K.
## Solution 
This is a problem about bit manipulation, as we can use a single signed short integer and XOR (in c++ done with '^' symbol) every number that appears in the array with it. XOR has the property, that it only gives 1 when exactly 1 bit out of 2 is 1. Meaning if there's 2 numbers in binary, 001 and 001, since they repeat the first time they XOR with our number (set at 0 initially), our number becomes 0001 and the second time they are XORed we get 0000, so the number "loses" the number that repeats, but doesn't for the number that doesn't repeat. 
What if we have intersecting bits ?
Say we have 0011, 0001 and 0011.
Then, 0011 XOR 0000 XOR 0001 would give us 
0010
Then 0010 XOR 0011 would give us
0001
and hence our original number is returned from the mix. 
This operation effectively removes a repeating bit combination and exactly and only that from a number.

TC: O(n) SC: O(1) Time taken to solve: ~20-30 mins, most of the time was just spent doing other irl stuff
## Problem Categories
Bit Manipulation
## Lessons to remember 
1. Try to finish the problem in one go.
2. Learn logic gates.
