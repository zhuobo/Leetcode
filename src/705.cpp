#include <vector>

using std::vector;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() : table(1000001, false){ }
    
    void add(int key) {
        table[key] = true;
    }
    
    void remove(int key) {
        table[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return table[key];
    }
private:
    vector<bool> table;
};
