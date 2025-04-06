# apple-and-orange 
## Input 
First line, `s`-> starting point of sam's house (inclusive range), `t`-> end point (inclusive)
Line 2, `a`-> apple tree location, `b`-> orange tree location
Line 3, `m`-> no. of apples, `n`-> no. of oranges
Line 4, m apples for apples[i], location of fallen apples
Line 5, Same but for oranges[i]
## Problem 
Find the number of apples and oranges in the inclusive range s and t, that is simply process apples and oranges arrays with locations of apple tree and orange tree respectively and check the number of apples and oranges in the range. All the values are positions on x-axis.
## Output 
Line 1, no. of apples
Line 2, no. of oranges
## Constraints 
s,t,a,b,m,n >=1 and <= 1e5
d (apples[i] and oranges[i]) >= -1e5 and <= 1e5
a < s < t < b 
## Observations
We can observe that firstly, sam's house is on +ve x axis, and so is the position of apple and orange tree, and ofcourse there are +ve no. of apples and oranges, but there's atleast 1 for both of them. We can use an unsigned long int for positive values. Secondly, we can see that each apple or orange itself can be either +ve or -ve on the x axis, so we have to use long int. 
Thirdly we can see that the apple tree is always to the left, and orange tree is always to the right of sam's house.
## Solution 
Simply iterate over both arrays adding the value of a and b respectively and checking if the value is in the inclusive range [s,t]. Return the count of apples, and oranges.
TC: O(n) SC: O(1) (we only have 2 result/computation variables, count_apples and count_oranges, these variables can only be +ve and since there are 1e5 number of apples or oranges we can have either value as 1e5, so we can use an unsigned long int for them) 
