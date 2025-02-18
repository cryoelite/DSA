# Compare the triplets
## Input
An int array of size 3, `a`
And another int array of size 3, `b`
## Problem
Create an int array c of size 2. Compare `a[i]` to `b[i]`, and if `a[i]>b[i]`, c[0]++, if `a[i]<b[i]` then c[1]++, otherwise nothing.
## Output
Return the array c
## Constraints
a[i] >= 1 and a[i] <= 100
b[i] >= 1 and b[i] <= 100
## Observations
The sum can't exceed 200, so c[i] >=2 and c[i] <=200, meaning an unsigned short int is enough.
## Solution
Simply iterate over the range `n`, and for each `i`, compare `a[i]` and `b[i]` and update `c`.
 

