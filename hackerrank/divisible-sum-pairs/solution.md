# divisible-sum-pairs 
## Input 
First line 2 ints, n and k
Second line n space separated ints, values of arr[i].
## Problem 
Given an array of ints and a value k, we have to find the number of (i, j) pairs where arr[i]+arr[j]/k == 1.
## Output 
A single integer that denotes the number of such pairs.
## Constraints 
n>=2 and <= 100
k>=1 and <= 100
arr[i]>=1 and <= 100
## Observations 
n is a positive int and can be max 100, same for k and arr[i], we will also sum values arr[i] + arr[j] so at max a temp value of 200 could exist, and lastly the result can be at most n pairs if each pair was just a single element but we will need 2 elements for a pair so n/2 might be the max. no. of pairs, which is 50. 
So we can use unsigned short int for everything.
## Solution 
There are 2 solutions that I can think of and was able to see, first is the most basic and simple solution of trying out every pair and making sure they are unique. We do this by having a loop that goes from 0 to n and for each iteration we check i to n elements, the reason we go i to n is that this ensures if we have 2 elements like 1,....,4 and we get a pair (1, 4) as we already looked forward, when we are at 4, we don't check the previous elements and so we don't get a (4,1). Since every element before it has checked itself against every element at the current index and forward, it is ensured that this current element has no unchecked pair with an element behind it (that is those elements have already checked theirselves against this element).
This would have a TC of O(n^2) as first we get ``n*(n-1)`` then ``n*(n-2)`` and so on, essentially an n^2 upper bound.

The second solution is a bit more clever as we preprocess all elements against the target element k. So we create buckets, and in each bucket we store the distance from the current element. Say we have k = 5 and element is 1, then we see that we need 4 for this element, and it goes in the bucket with key 1, and say we have another element 6, this too needs a 4 to be divisible by k, so it should go in the bucket 1 too. We can see that modulo has an interesting property that it classifies any element against the mod element as to how far it is from it, and we can see by example that all it does is in the equation a+b=k or multiple of k (as a+b/k needs to be 1), it gives us exactly that. We can also see that elements in each bucket are always pairable from a bucket whose key added to it equals k. That is bucket 1's all elements are pairable with bucket 4's elements.
We can use a map or just a simple array of size k (as there will be k buckets), and we can first initialize the buckets and then check all k buckets, and add all counts.
The way we count and make sure we only count one way is, if `i== (k-i %k)` that is when say we have a bucket 0, which is the elements that are all multiples of k directly, then they can only pair amongst each other, and if we were to pair them we would see that the pairs for {3,6,9,12} would go (3,6), (3,9), (3,12) then for 6 we would see (6,9), (6,12) and for 9 we would see (9,12), as we see, since we need unique elements we don't consider the previous elements and for each element we can see, n-1 choices for the first element, n-2 for the third one and so on till we get n-n or 0 choices. Total we have (n-1)+(n-2)+...(n-n) which is n((-1)+(-2)...) and this series' sum has the general formula n(n-1)/2, https://stackoverflow.com/a/37847498/13036358. So when i==j we have n(n-1)/2 pairs, and this isn't just when i==0, it is also true when i is say exactly at k/2, so if k was 6, bucket 3 would have all elements that can be paired with each other only as well. 
Next when ``i!=(k-i%k)``, then we can simply do count[i] * count[k-i%k], as if there are 3 elements in bucket 1 and 4 in bucket 4 and k is 5, then all elements of bucket 1 will make a pair with bucket 4 and get count[i] * count[k-i%k] pairs.
We do ``k-i%k`` for the second element because if i is 0, then k-i would just give us k, and we know our count array starts at 0 (as we have put elements that mod with k directly in 0th index, as that is the remainder), so it wouldn't give us the right index, hence we mod it.
We can go for k/2 checks instead of k, from 0 to k/2, as to keep buckets from checking the previous element if we stop at halfway, we won't match the elements after the half point with the previous ones and hence give us duplicate pairs. That is, for bucket 1 and `k-i%k` would give us 4, but when we are at 4, it would give us 1, and since we have already match the elements in 1 with 4, it would give us double the count, so we can do either of 2 checks, either we stop at halfway as beyond halfway we would only get the second element as smaller than the first element or we check if ``i<j``.

TC: O(n+k/2) SC: O(k) Time taken to solve: NA (Too much time taken (3 days))

An elegant solution:
```cpp
 int divisibleSumPairs(int n, int k, vector<int>ar) {
   auto bucket{vector<int>(k,0)};
    int count = 0;
    for (int elem : ar) {
        int modValue = elem % k;
        count += bucket[(k - modValue) % k]; // adds # of elements in complement bucket
        bucket[modValue]++;                  // saves in bucket
    }
    return count;
}

```
TC of O(n) and SC of O(k).
## Mistakes made 

1. Didn't solve it in one go, lacked complete focus.
2. When stuck with the algorithm, thought too long about it and didn't use much help.
3. The solution that I described as a result of the fragmented approach made it harder for me to summarize my entire thinking.