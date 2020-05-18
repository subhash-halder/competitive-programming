#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace ::std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> v;
    double ret = 0;
    int l1 = nums1.size();
    int l2 = nums2.size();
    int i1 = 0;
    int i2 = 0;
    int counter = 0;
    while (i1 < l1 || i2 < l2) {
      int newVal = INT32_MAX;
      bool i1Inserted = false;
      if (i1 < l1) {
        newVal = nums1[i1];
        i1++;
        i1Inserted = true;
      }
      if (i2 < l2 && nums2[i2] < newVal) {
        newVal = nums2[i2];
        i2++;
        if (i1Inserted) {
          i1--;
        }
      }
      v.push_back(newVal);
    }
    for (int a : v) {
      cout << a << " ";
    }
    cout << endl;
    int fl = v.size();
    if (fl % 2 != 0) {
      ret = v[ceil(fl / 2)];
    } else {
      int f = fl / 2;
      ret = (v[f - 1] + v[f]) / 2.0;
    }
    return ret;
  }
};

int main() {
  Solution s = Solution();
  vector<int> v1 = {1, 2};
  vector<int> v2 = {3, 4};
  double ret = s.findMedianSortedArrays(v1, v2);
  cout << "Result is : " << ret;
  cout << endl;
  return 0;
}
