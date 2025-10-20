# sum-of-two-integers 
## Input 
2 integers, `a` and `b`
## Problem 
Given 2 integers, `a` and `b`, return the sum of them without using `+` or `-` operators.
## Output 
A single integer representing the sum of `a` and `b`.
## Constraints 
`a`,`b` >= -1000 and <= 1000
## Observations 
`a` and `b` are quite small, even their sum can be held in a short int as it has a range of 0 to 65535. Still, let's stick to int.
## Solution 
One basic solution is to simply iterate over all positions of the binary representation of the numbers and for each position add the value at `position[i]` of both `a` and `b`'s binary representation and handle the carry. Using a simply if else logic, this can be implemented.
2 edge cases to be handled, are, since the number is a signed number, it will be in 2's complement and secondly if adding 2 numbers overflows, then we need to handle that edge case as well.
TC will be O(1) as the size of any int is fixed, and SC will be O(1) but the logic can likely be improved.

One slightly better solution is to use XOR, XOR can be used here as well. The reason is, if there's 2 bits, `0` and `1` and they are added, we get `1`, if we have `1` and `1` we get `10` and that's exactly what the output of XOR is as well, which is an interesting use case for it. Now if we have 3 bits, `1`, `1` and `0`, we add them and get `10`, with XOR between these 3 we get `0` as well, and for `1`, `1` and `1`, we get `1` after adding, same with XORing them. Hence, XOR between 3 bits, `a[i]`, `b[i]` and carry will return us the expected value for the position. And we can separately check if there's a carry and store it as well, and hence we can avoid the if-else logic for adding entirely.
However, finding the carry is tricky for 3 bits, a[i], b[i] and carry we have to perform operations on these to find out of they return a carry or not.

A better solution and one that takes on this one is to use the whole of the number itself. 
We XOR a and b, and then we get all the positions where addition would happen in a single operation.
Next to find out carries, we AND a and b, and this returns all the positions that will return a carry. 
Now we have carry and addition results and we have to add them again, so as to 'add' the carries.
So we XOR carry and addition but with 1 change, the carry number is left shifted by 1. This is because, we found out the positions that generated a carry and now to add them we need to shift them to the left by 1 so that they can be added to the next position, as a carry is supposed to do.
Again we find a result and again we check for carry and loop this.
For ex.
Adding
```
a= 1;
b= 1;
```
First we XOR them and we get
```
a^b =
 0001
^0001
-----
 0000     
```
Now we have the result of addition, now to find out the carries
```
a&b = 
 0001
&0001
-----
 0001
```
And we see that this did result in a number that has 1 bit somewhere, meaning there's a carry, and so we add the carry to the result, after we shift the carry to the left by 1 (`carry<<1`)
```
result^carry =
 0000
^0010
-----
 0010
```
And we check if there's a carry
```
result&carry =
 0000
&0010
-----
 0000
```
Which is a 0, hence no position generates a carry and hence our addition is finished. If there was anything again we would repeat this.
Hence our final result = 0010 which is 2
And we have added 1 + 1 = 2.
Since negative numbers are represented as 2s complement, bit operations work between numbers without any extra logic as if they were normal. Hence even if we have a negative integer, we can just work like normal and that edge case takes care of itself.
```cpp
  int compute() {
    int result{a ^ b};
    int carry{(a & b) << 1};
    while (carry != 0) {
      int tmp{((result & carry) << 1)};
      result = result ^ carry;
      carry = tmp;
    }

    return result;
  }
```
TC: O(1) SC: O(1) Time taken to solve: 25 mins
## Problem Categories 
Bit Manipulation
## Lessons to remember 
1. XOR has an interesting property that it returns the same result as addition would, however carry needs to be found out and that's tricky.
2. AND can be used between 2 numbers to find out all positions that return a carry and can hence be used to find out 'carries' which can be added to the XORed value to make up for the weakness of XOR. Given we keep in mind that left shifting by 1 is necessary, as we find out the positions that make a carry and then to use them we need to add them to the next positions as carry's normally work in addition.
3. The way to solve problems is, you have 30 minutes per problem, spend 5 figuring out something. If something doesn't immediately click, look at the hints and the solution and don't try to implement it out right away, see the whole solution fully. And then understand it and implement it. Only after having done 100s of problems do you try to think about solutions for 10 or so minutes, until then, speed is important and getting concepts, not trying to wreak your brain on every problem, be fast.
4. Be mindful of swaps, if there's an operation that requires a previous value of a variable, then be careful if you don't use the new value. This is particularly important in implementations like these because you can easily not see that, in our solution we have `result` and `carry` and we use the old value of `carry` as well as the new one, there's a value swap/old-value-new-value thing happening, be careful here.
