# breaking-best-and-worst-records 
## Input 
First line has an integer n, then second line has n space separated integers for the array scores.
## Problem 
The array scores has integers where each element is a score, we have to track how many times maria (the scorer) has broken her biggest score and her smallest score, where the biggest and the smallest score change to the biggest or smallest score going from left to right (past seasons to future seasons of her play).
The first score is her base and doesn't add to any count.
## Output 
An array of 2 elements, result, where result[0] is the count of biggest score breaks and result[1] is the count of smallest score breaks.
## Constraints 
n >= 1 and <= 1000
scores[i] >= 0 and <= 1e8
## Observations 
We can see that n can at most be just 1000 and will be positive, so an unsigned short int will suffice, as for each element of scores, we have to use long int, we can use unsigned as it will also be +ve. As for result array, we can have n-1 counts for biggest/smallest count at most (as in the worst case, each element is bigger/smaller than the previous one and so except the first element which won't be counted, we have n-1 counts), so at most the value can be 999, which can fit in unsigned short int as well. 
## Solution 
Simply iterate over the array keeping track of max. and min. element and updating them when a bigger/smaller element is found and update the result's 0th or 1st index.

TC: O(n) SC: O(1) 
