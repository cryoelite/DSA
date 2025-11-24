# is-palindrome 
## Input 
Given a string s
## Problem 
Return true if `s` is a palindrome, otherwise return false.
A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

s = "Was it a car or a cat I saw?"

Output: true
Input: s = "tab a cat"

Output: false
## Output 
A boolean
## Constraints 
1 <= s.length <= 1000
s is made up of only printable ASCII characters.
Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).
## Observations 
Search case-insensitive and ignore all non-alphanumeric characters.
## Solution 
TC: O(n) SC: O(1) Time taken to solve:  10 mins
## Problem Categories 
## Lessons to remember 
1. For character searches, like isalphanumeric or isdigit or isalpha (is an alphabet), C++, python and likely other langs provide already existing helper functions. Use them.
2. 