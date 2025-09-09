# number-of-one-bits 
## Input 
A non-negative 32-bit integer `n`.
## Problem 
Given this integer, find the number of `1`s in its binary representation.
## Output 
The number of `1`s.
## Constraints 
`n` is 32 bits, hence it is a `uint32_t` or an `unsigned long int` by the C++ standard.
## Observations 
Since `n` is non-negative, or an `unsigned int`, it won't be stored in 2s complement (Check notes for it). Hence we can directly check each bit without fearing it is inverted and one added.
## Solution 
We can check for each bit with `n & (1<<i)`, where `i` goes from `1` to `32` (exclusive). This will return a true for each bit that is set to `1` and we can add those counts. This is a O(1) TC and O(1) SC solution as the count is fixed.

In C++20, there's std::popcount, that returns the number of `1`s in an integer or a bitset.
In C++11, there's std::bitset, this type can take an int and then allow special bit operations on it. One such is the `count()` method which returns the number of `1`s or trues in a bitset.

A very cool solution is `n & (n-1)` as long as `n` isn't `0`. This runs a loop only as many times as there are `1`s in the integer and is a pretty neat trick.
How it works: Say `n` is `1001`, then `n&(n-1)` will do `1001 & 1000` and that will return `1000` and since `n` isn't `0` yet we get a count. Now we do it again and get `1000 & 0111`, as `0111` is `1` subtracted from `1000` (remember how binary works, 0 is 0, 1 is 1, 10 is 2, 11 is 3 and so on, so the reverse is how the values look after being subtracted). This operation gives `0` and we get another count since `n` wasn't `0` already. And we are done, now `n` is `0` and we have our count as `2`.
Why this works: Intuitively, AND is an operation to filter or keep only what overlaps between 2 sets/numbers etc. The reason why this works is because the way binary subtraction works, we have 2 numbers `n` and `n-1`, so when we do `n-1` the rightmost `1` bit in `n` is guaranteed to be `0`. This is because subtracting `1` removes a `1`, and if the LSB or the rightmost bit of `n` isn't `1` then it will bring over `1` from the bit that is `1` on the left, turning that set `1` bit to `0`. And the result will be that `n-1` would have 0 or more `1`s from the right but the rightmost `1` that was already there in `n` will have become `0`. Now when we AND `n` and `n-1`, that rightmost `1` of `n` will be `0` but every bit to its left will be intact and hence when we will AND both `n` and `n-1` the leftpart from the rightmost `1` of `n` will come out same as it will be unchanged, but the right part will be completely cancelled out by the AND operation.
For ex.:
Say `n` = `100100`
Then `n-1` = `100011` as `0`-`1` in binary means carrying `1` from the left until a `1` is found, which is turned `0`. 
Now as we can see the place to the left of the rightmost `1` of `n` is same as before, but at its position and to its right it has changes.
Hence doing `n` & `n-1`
```
 100100
&100011
=100000
```
And we have essentially peeled off the rightmost `1` with this operation.
Since we have shown that `n&(n-1)` is essentially just peeling off the rightmost `1`, it stands to reason that this operation will execute only and exactly as many times as there is a `1` in `n` and hence why this trick only triggers this operation `k` times where `k` are the number of `1`s in `n`.

TC: O(k) SC: O(1) Time taken to solve: 30 mins + 1 day for all the concepts of boolean algebra
## Problem Categories 
Bit Manipulation
## Lessons to remember 
1. Be faster in understanding concepts. Or rather, shorten your notes since that is the time taking part.
2. `n&(n-1)` is an operation to peel off rightmost `1`s in a binary number.
