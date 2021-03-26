#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <unordered_map>

using namespace std;

class RandomizedSet {
private:
  unordered_map<int, int> valToIndexMap;
  unordered_map<int, int> indexeToValMap;
  int size;

  void printState() {
    printf("value to index: ");
    for (pair<int, int> p : valToIndexMap) {
      printf("%d: %d, ", p.first, p.second);
    }
    cout << endl;
    printf("index to value: ");
    for (pair<int, int> p : indexeToValMap) {
      printf("%d: %d, ", p.first, p.second);
    }
    cout << endl;
    printf("size: %d", size);
    cout << endl;
  }

public:
  /** Initialize your data structure here. */
  RandomizedSet() {
    valToIndexMap.clear();
    indexeToValMap.clear();
    size = -1;
  }

  /** Inserts a value to the set. Returns true if the set did not already
   * contain the specified element. */
  bool insert(int val) {
    if (valToIndexMap.find(val) == valToIndexMap.end()) {
      size++;
      valToIndexMap[val] = size;
      indexeToValMap[size] = val;
      return true;
    }
    return false;
  }

  /** Removes a value from the set. Returns true if the set contained the
   * specified element. */
  bool remove(int val) {
    if (valToIndexMap.find(val) == valToIndexMap.end()) {
      return false;
    }
    int i = valToIndexMap[val];
    valToIndexMap[indexeToValMap[size]] = i;
    indexeToValMap[i] = indexeToValMap[size];
    valToIndexMap.erase(val);
    indexeToValMap.erase(size);
    size--;
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    if (size != 0) {
      return indexeToValMap[rand() % (size + 1)];
    }
    return indexeToValMap[0];
  }
};
