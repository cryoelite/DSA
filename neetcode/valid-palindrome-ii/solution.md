# valid-palindrome-ii 
## Input 
You are given a string s
## Problem 
return true if the s can be a palindrome after deleting at most one character from it.
## Output 
a bool
## Constraints 
1 <= s.length <= 100,000
s is made up of only lowercase English letters.
## Observations 
## Solution 
Since we know we have exact 1 skip, we can easily solve this. By just checking if there's a position where left and right pointer don't have the same value, then checking the string excluding the left element and then checking the string excluding the right element. If either of those substrings make a palindrome then the string does have a palindrome with exactly 1 character skipped.
TC: O(n) SC: O(1) Time taken to solve: 20 mins
## Problem Categories 
## Lessons to remember 
