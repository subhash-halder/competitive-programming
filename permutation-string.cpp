#include <iostream>
#include <utility>

using namespace std;

void permutation(string s, int p, int limit) {
  if (p == limit) {
    cout << s << endl;
    return;
  }
  for (int i = p; i <= limit; i++) {
    swap(s[p], s[i]);
    permutation(s, p + 1, limit);
    swap(s[p], s[i]);
  }
}
int main() {

  string s = "abcd";
  permutation(s, 0, s.length() - 1);

  return 0;
}
