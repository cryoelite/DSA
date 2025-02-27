# Plus Minus
## Input
An integer n which is the size of arr
Then n elements, in which each element is an integer
## Problem
We have to find the ratio of pos, neg and zero values in the array out of the size n. The main problem is that we have to define the precision to 6 decimal digits for the outputs.
## Output
pos, neg and zero ratios, which are decimal values with precision of 6 digits
## Constraints
n >= 0 and <= 100
arr[i] >= -100 and arr[i] <= 100
## Observations
We can see that, n is quite small, and we can also see that elements are small, so short int for the values and size_t for n.
The result will be a positive floating value. The float type is single precision, fp32, and we can see [here](https://en.wikipedia.org/wiki/Single-precision_floating-point_format) that it can have upto 7 decimal digits, which is good enough. 
## Solution
By implementation.