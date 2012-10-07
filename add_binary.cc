#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    int len = a.size() > b.size() ? a.size() : b.size();
    int carry = 0;
    string result;

    int ta, tb;
    for (int k = 0; k < len; k++) {
      if (k < a.size()) ta = a[a.size() - k - 1] - '0'; else ta = 0;
      if (k < b.size()) tb = b[b.size() - k - 1] - '0'; else tb = 0;
      int sum = ta + tb + carry;
      carry = sum / 2;
      sum = sum % 2;
      result.push_back('0' + sum);
    }
    if (carry)
      result.push_back('1');
    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution s;
  string a("11");
  string b("1");
  cout << s.addBinary(a, b) << endl;
  return 0;
}
