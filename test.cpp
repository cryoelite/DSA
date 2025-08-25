#include <bits/stdc++.h>
using namespace std;

int main() {
  const int M{1000000007};
  cout << M;
  cout << '\n'
       << "Is M < Int max ? " << boolalpha << (M < numeric_limits<int>::max());
  cout << '\n' << "Size of int ? " << sizeof(int) << " bytes";
  cout << endl;
  return 0;
}
