#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
 public:
  vector<vector<int> > threeSum(vector<int> &num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function

    vector<vector<int> > result;
    if (num.size() < 3)
      return result;
    sort(num.begin(), num.end());
    
    vector<int> triplet(3);
    int last_value = num[0] - 1; 
    for (int i = 0; i < num.size() - 2; i++) {
      if (last_value == num[i])
        continue;
      last_value = num[i];
      int j = i + 1;
      int k = num.size() - 1;
      while (j < k) {
        int v = num[i] + num[j] + num[k];
        if (v == 0) {
          triplet[0] = num[i];
          triplet[1] = num[j];
          triplet[2] = num[k];
          result.push_back(triplet);
          while (num[++j] == num[j-1] && j < k);
          while (num[--k] == num[k+1] && j < k); 
        } else if (v < 0) j++;
          else k--;
      }
    }
    return result;
  }
};
int main() {
  Solution s;

  int a[] = {-1, 0, 1, 2, -1, -4};
  vector<int> input;
  for (int i = 0; i < 6; i++)
    input.push_back(a[i]);

  vector<vector<int> > result = s.threeSum(input);
  for (int i = 0; i < result.size(); i++)
    cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;

  return 0;
}
