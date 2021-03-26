#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#define assertm(exp, msg)                                                      \
  cout << "testing: " << msg << endl;                                          \
  assert(exp);                                                                 \
  cout << "passed" << endl;

using namespace std;

class Solution {
public:
  double angleClock(int hour, int minutes) {
    minutes = minutes % 60;
    hour = hour % 12;
    double minuteAngle = minutes * 6;
    double hourAngle = hour * 30 + minutes * 0.5;
    return min(abs(minuteAngle - hourAngle),
               360 - abs(minuteAngle - hourAngle));
  }
};

int main() {
  Solution sol = Solution();

  struct testCase {
    int hour;
    int minutes;
    double angle;
  };

  testCase t[] = {{3, 15, 7.5}, {12, 0, 0},    {4, 50, 155},
                  {3, 30, 75},  {12, 30, 165}, {1, 57, 76.5}};

  cout << "Testing ......\n";
  for (testCase tc : t) {
    double ress = sol.angleClock(tc.hour, tc.minutes);
    assertm(ress == tc.angle, ress)
  }
  cout << endl;
}
