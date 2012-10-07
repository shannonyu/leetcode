// Type your C++ code and click the "Run Code" button!
// Your code output will be shown on the left.
// Click on the "Show input" button to enter input data to be read (from stdin).

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int> &num, int target) {
    sort(num.begin(), num.end());

    int num_size = num.size();
    int cur_min_value = INT_MAX;
    int cur_min_sum = -1;
    for (int i = 0; i < num_size - 2; i++) { 
      int j = i + 1; 
      int k = num.size() - 1; 
      while (j < k) { 
        int sum = num[i] + num[j] + num[k];
        int v = sum - target;
        if (v == 0)
          return target;
        else if (v < 0) j++;
        else k--;
        v = v > 0 ? v : -v; 
        if (cur_min_value > v) {
          cur_min_value = v;
          cur_min_sum = sum;
        }
      }
    }
    return cur_min_sum;
  }
};

int main() {
  Solution s;
  int a[] = {-1, 2, 1, -4};
  vector<int> input;
  for (int i = 0; i < 4; i++)
    input.push_back(a[i]);
  cout << s.threeSumClosest(input, 1) << endl;

  return 0;
}
