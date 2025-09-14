# add-binary 
## Input 
2 strings, `a` and `b`
## Problem 
The strings `a` and `b` consist of binary values, add them and return a string with the binarry addition on the given strings.
## Output 
A single string with the binary strings `a` and `b` added.
## Constraints 
a.size() and b.size() >=1 and <= 10,000
`a` and `b` only consist of `0` and `1` characters
`a` and `b` don't have leading zeroes, except for the number `0`, which is represented as `0`.
## Observations 
We can't directly convert `a` and `b` into an integer because the length is too big to store in an integer. Hence we have to firstly, solve parts of the strings and secondly implement some adding functionality.
## Solution 
One direct solution is to make our own adder logic, where we compare the characters and based on each character we define addition logic, we also would need to take care of carry's and a simple iteration over all characters would do.
TC will be O(m) where `m` is max(a.size(),b.size()) or something like that and SC will be O(m).
```cpp
  int char_bit_to_int(char elem) {
    return (static_cast<int>(elem) - static_cast<int>('0'));
  }
  char int_to_char_bit(int elem) {
    return (static_cast<char>((elem) + static_cast<int>('0')));
  }

  /// Results are reversed, that is if the result of `01` + `01` = `10` then
  /// this will return `01`
  std::array<char, 2> rev_adder(int x, int y, int carry) {
    int sum{x + y + carry};
    auto res{std::array<char, 2>({'0', '0'})};
    res[0] = int_to_char_bit(sum & 1);
    res[1] = int_to_char_bit((sum & (1 << 1)) != 0);

    return res;
  }
  std::string compute() {
    std::string result{};
    int carry{0};

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    for (size_t i{0}; i < std::max(a.size(), b.size()); ++i) {
      int val1{0};
      int val2{0};

      if (i < a.size()) {
        val1 = char_bit_to_int(a[i]);
      }
      if (i < b.size()) {
        val2 = char_bit_to_int(b[i]);
      }
      auto res{rev_adder(val1, val2, carry)};
      carry = char_bit_to_int(res[1]);
      result += res[0];
    }
    if (carry) {
      result += int_to_char_bit(carry);
    }
    std::reverse(result.begin(), result.end());

    return result;
  }
```
The logic is simple, we first reverse both `a` and `b` because if we have a string like `101` and `10` we would want to add them like so
```
 101
+ 10
----- 
```
but in our solution we want to iterate over each position and take elements from both `a` and `b`, starting from the right of `a` and `b`.
We can either use a reverse iterator, or a normal iterator on both and decrement. Or we can flip the strings, whilst the latter is worse in time complexity it is simpler to do.

Then we simply iterate over the arrays and for each position we add 3 values, `a[i]`, `b[i]` and carry. One thing to keep in mind is conversion, we can avoid conversion to int altogether but we would have more verbose addition logic, and anyway, in our code we don't convert int to char or char to int, we simply cast and manage offset and casting a type doesn't cause any performance loss unless there's some check involved.

For every addition we handle the first bit and the second bit differently, the first bit we take and append to result, the latter bit we put in the carry.
Finally we reverse the result string.

TC: O(max(n,m)) where `n` is `a.size()` and `m` is `b.size()` but the constant factors might be higher SC: O(max(n,m)) Time taken to solve: 2 hour for implementation 1 day for problem
## Problem Categories 
Bit manipulation
## Lessons to remember 
1. Reduce time for implementation based problems, check the solution if stuck.
2. 
