# majority-element 
## Input 
Given an array nums of size n
## Problem 
return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times in the array. 
## Output 
An int, the majority element.
## Constraints 
You may assume that the majority element always exists in the array.
1 <= nums.length <= 50,000
-1,000,000,000 <= nums[i] <= 1,000,000,000
## Observations 
## Solution 
One simple solution is to use an unordered map and keep track of the counts, then find the highest count element. Or a priority queue. The average time complexity would be n and space would be O(n). 
However we can look at the question again, the fact that the majority element exists more than n/2, or more than half of the time as compared to every other element combined is an important element.
What we can do is we can keep track of highest count element and its count, and for every occurence of it we increment the count and for every unoccurence of it we decrement it, and if the count is going to be negative we track the element that would do that. And this way we find the majority element. The logic here is, that if an element occurs >n/2 times, then by definition it will have a count that will be greater than every other element combined, and hence no matter what order elements occur in the array, the majority element will always be the element left in this logic.
For ex.:
For 
n=7, n/2=3.5 or 3 so element must be >3 times, 
[1,2,2,2,1,2,6]
Starts with res=1, count = 1, then next element makes the count = 0, then after that res = 2, count = 1, then count = 2, then count becomes 1, then 2 again, and then at the end 1 with res = 1.
[2,2,2,2,1,1,6]
Same story.
[1,6,5,2,2,2,2]
Same story.
Hence we can observe that no matter the order, the majority element will have a count that will always be able to survive being cancelled out by another element, no matter what the other element is. If there wasn't a n/2 speciality, then this logic would fall through, and we'd need to use some other logic like a map.

TC: O(n) SC: O(1) Time taken to solve:  30 mins
## Problem Categories 
## Lessons to remember 
