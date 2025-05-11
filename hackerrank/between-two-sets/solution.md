# between-two-sets 
## Input 
The first line is an integer n and m, space separated
Second and third line are then n elements of array a and m elements of array b, space separated integers
## Problem 
Find out all the integers where each element satisfies 2 conditions, first that all the elements of array a are factors of this element and second that this element is a factor to all the elements of array b.
For ex.:
In a=[2,6] and b=[24,36], the integers that satisfy the 2 conditions are 6 and 12.
## Output 
Return the size of the array which has the elements that satisfy the 2 conditions.
## Constraints 
n,m >=1 and <= 10
a[i],b[j] >=1 and <=100
## Observations 
We can see that n,m and arrays have elements that are firstly positive only, so we can use an unsigned integer, and secondly have a max value of 100, so we can use an unsigned short for both of them.
## Solution 
We have to find elements which satisfy the 2 conditions, say x is an element then x%a[i] should be 0 and b[j]%x should also be 0 for all elements of a and b.
The first condition is defining what an LCM is, that is the Least Common Multiple, which is the number that is the smallest common multiple of a given set of numbers. And the second condition is defining the GCD, which is the number that is the greatest common divisor of a given set of numbers. 
Hence we have 2 numbers, LCM which is the smallest number that can be divided by all elements of a, and GCD which is the biggest number that can divide all elements of b, that means x must be greater than LCM atleast to divide all elements of a, and it can at most be GCD of b to divide all elements of b. The upper bound of a number that is divisible by a doesn't matter because it can be infinite, as a number x is divisible, then multiples of x would be divisible as well given they share factors with the numbers of a. Similarly the lower bound of a number that divides b doesn't matter because it will always be >=1. That means x can be between LCM and GCD as for it to divide all elements of a it must be >= LCM and for it to divide b it must be <= GCD. 
Furthermore, we can say that multiples of LCM would only be the numbers that can be divided by a, and if the multiples divide the GCD then those multiples are the values that we need. That is, say x is at LCM as it is the starting point of an iteration, then if GCD%x == 0 then x divides GCD, and division is [transitive](https://www.chilimath.com/lessons/basic-math-proofs/if-a-divides-b-and-b-divides-c-then-a-divides-c/) so x also divides all elements of b. Now multiples of the LCM cover all elements that can be divided by elements of a (not all multiples of LCM though, but all the elements that are divisible by elements of a are multiples of LCM), this is because LCM is the smallest element that divides all elements of a and any number that can be divisible by all elements of a must also be divisible by the LCM, as the LCM is a multiple of elements of a so if LCM is a multiple and so is x then they have same factors, and that means that x must be divisible by LCM as it has the same factors, and if x is divisibile then x is a multiple of the LCM, hence all the integers that are divisible by all elements of a, are multiples of the LCM.

So, we simply find the LCM of a, GCD of b and find out all multiples of LCM of a that divide the GCD of b. Those elements are our solution.
The resultant numbers would be between max(a) and min(b) so they would be unsigned short ints as well (this is because x can't be smaller than max(a) as then it wouldn't be divisible by all elements of a, in other words, x has to be atleast as big as the max of a, and similarly, if its greater than the smallest element of b then it won't be able to divide all elements of b). 

TC: O(n+m+max(b)) SC: O(1) 
