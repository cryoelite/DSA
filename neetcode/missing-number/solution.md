# missing-number 
## Input 
An array `nums` with `n` elements, where `n` is inferred.
## Problem 
Given an array `nums` with `n` elements where the array has elements in the range [0,n] (both inclusive) without any duplicates and only one number missing. Find the missing number.
## Output 
The missing number.
## Constraints 
`n` >= 1 and <= 1000
## Observations 
Array has `n` elements but it is supposed to have `n+1` because `0` and `n` are included in that range, and every integer in the range `0` to `n` appears once in it except one. 

## Solution 
Question: Is the array sorted ? If yes the solution is trivial, just go over the array and find the element that doesn't match its position.
Let's assume not.
One basic solution is to use a frequency array, wherein we just mark all the elements as `1` or boolean `true` that exist in `nums`, this can be a fixed size array so SC will be O(1) and we simply iterate over it again to find the element in the range `0` to `n` (inclusive) that doesn't exist in `nums`.
TC is O(n) and SC is O(1) but constant factors here can be improved.

One better solution is a hashmap, but whilst it's lookup TC is average of O(1), in worst case it is O(n) so it might not be more performant than the previous solution.

The best solution is to make use of XOR again. XOR's property of cancelling out duplicates is useful here as well. And the way we make duplicates is by first iterating over the range `O` to `n` (inclusive) and XOR everything. Now we do the same with `nums` and there will be one element from the normal iteration that won't repeat hence won't be cancelled out by XOR, the missing number. Hence we can just return it.

```cpp
  int compute() {
    int result{0};

    for (size_t i{0}; i <= n; ++i) {
      result ^= i;
      if (i<n) {
        result ^= arr[i];
      }
    }


    return result;
  }
```
It doesn't matter if we use a separate loop or the same loop to go over the array because all that matters is if `result` has the occurence of any element twice, so if array has the element repeated on the same index or later or earlier than `i`, it wouldn't matter because `result` has will or has already XORed it exactly once.
One more thing is, `0`. `0` is also an element that has to be checked, and we can see that `result` initializes with a value of `0`. So does that mean it won't be able to detect the lack of `0` ? no. This is because `0` is a bit special, in which `0` XOR with `0` will give a `0` no matter
how many times it is XORed, and `0` is what is left if all elements cancel out. Since our array misses one element, if all elements cancel out what's left ? `0`. And one element is missing, so that means `0` is the missing element. Hence why it works with `0` as well.

TC: O(n) SC: O(1) Time taken to solve: 10 mins
## Problem Categories 
Bit Manipulation
## Lessons to remember 
