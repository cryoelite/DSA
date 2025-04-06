# kangaroo 
## Input 
4 ints, x1 v1 and x2 v2
## Problem 
Given 2 kangaroos who jump at the same time (as the question says "...same location same time"), whose starting point is x1 and x2 respectively, and who jump with distance v1 and v2 respectively, find out if there's a point of time when both of them are at the same location (at the same time). 
## Output 
Should be a string "YES" or "NO", denoting if the kangaroos come together at the same place at the same time as part of their jumps.
## Constraints 
x1 < x2 and x1 >= 0 
x2 > x1 and x2 <= 10000
v1, v2 >= 1 and v1,v2 <= 10000
## Observations 
We can see that x1 can be 0, x2 can't be 0 because it is always larger than x1 so if x1 is 0 then it will have to be 1 or greater. Similarly, x2 can be at most 10000 but x1 can at most be 9999. v1 and v2 will always be 1 or greater meaning the kangaroos always jump forward. All 4 values are in the range 0 to 1e4, so we can use unsigned short int for these values.
## Solution 
Using some basic maths, we can get that the formula 
$$ x_1 + y * v_1 = x_2 + z * v_2 $$ 
must be true if the 2 kangaroos meet at the same place. This is because, if x1 is the starting point, then at each jump v1 gets added, so we get ``x1+v1+v1+v1...``, we can say v1 gets multiplied by y times, where y is the no. of jumps he makes, so we get ``x1+ y*v1``, and we can generalize and say y is 0 at starting point so we just get x1. Same for x2 and v2, so we get ``x2+z*v2``. Now they must be equal if the kangaroos are at the same location, ``x1+y*v1 = x2+z*v2``.
So if this holds then the kangaroos meet otherwise they don't. Now one more addition is that they must meet at the same time, that the jumps should be equal as well, as they jump at the same time, so we get ``y=z``, and our formula becomes 
$$x_1 + y * v_1 = x_2 + y * v_2$$
Finally simplifying the formula for `y`, which we do to find the jump at which they both meet, which we do because we want to see if they meet, as if they do they must meet at some jump, so finding `y` means we find where they meet, if at any place, we can get the formula 
$$y= (x_1-x_2)/(v_2-v_1)$$ 
and using any example such as x1=4, v1=1, and x2=2,v2=2 we can find values like y=2, which gives us 6 for both the equations ``4+(2*1)=2+(2*2) = 6``. So we can see that positive values of y mean they both meet at some point so we can return a "YES". Some more examples would give us that fractional, negative or a 0 in either numerator or denominator means they don't meet in the future of time and we can return a "NO".

TC: O(1) SC: O(1) 
