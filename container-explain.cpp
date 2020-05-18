#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <forward_list>

using namespace std;

bool f(int a, int b) { return b < a; }

void vecrotDemo() {
  cout << "************** vector demo start ************* \n";
  // Create a vector containing integers
  vector<int> v = {7, 5, 16, 8};
  list<int> l = {1, 2, 3};

  // Add two more integers to vector
  v.push_back(25);
  v.push_back(13);
  v.push_back(50);
  v.push_back(50);
  v.push_back(50);
  v.push_back(60);

  sort(v.begin(), v.end());

  bool present = binary_search(v.begin(), v.end(), 6);
  cout << "present no 6: " << present << endl;

  present = binary_search(v.begin(), v.end(), 16);
  cout << "present no 16: " << present << endl;

  auto itr = lower_bound(v.begin(), v.end(), 50);
  cout << "first occurrence of 50 or gretter : " << *itr << endl;

  itr = upper_bound(v.begin(), v.end(), 50);
  cout << "number just greater than 50 : " << *itr << endl;

  // Iterate and print values of vector
  cout << "Sorted vector: ";
  for (auto i = v.begin(); i < v.end(); i++) {
    std::cout << *i << " ";
  }
  cout << endl;
  sort(v.begin(), v.end(), f);
  cout << "Reverse Sorted vector in iterator function : ";
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
  cout << "************** vector demo end ************* \n";
}

void setDemo() {
  cout << "************** set demo start ************* \n";
  // Set by default mantain ascending order
  set<int> s;
  s.insert(4);
  s.insert(3);
  s.insert(1);
  cout << "Print set: ";
  for (int i : s) {
    cout << i << " ";
  }
  cout << endl;

  auto it = s.find(4);
  if (it == s.end()) {
    cout << "it is not present \n";
  } else {
    cout << "it is present \n";
    cout << *it << endl;
  }

  auto itr = s.lower_bound(3);
  cout << "number greater than or equal to 3: " << *itr << endl;
  itr = s.upper_bound(3);
  cout << "number strictly greater than 3: " << *itr << endl;

  cout << "************** set demo end ************* \n";
}

void mapDemo() {
  cout << "************** map demo start ************* \n";
  map<char, int> m;
  string name = "subhash";
  for (char c : name) {
    m[c]++;
  }
  cout << "s occurs in subhash is: " << m['s'] << " times \n";
  cout << "************** map demo end ************* \n";
}

int main() {
  vecrotDemo();
  setDemo();
  mapDemo();
}
