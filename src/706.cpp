#include <vector>

using std::vector;

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() : table(1000001, -1) {

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        table[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return table[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        table[key] = -1;
    }
private:
    vector<int> table;
};

struct Node {
    int     key_;
    int     val_;
    Node*   next;
    Node() = default;
    Node(int key, int val) : key_(key), val_(val), next(nullptr) {}
};

class MyHashMap2 {
public:
    /** Initialize your data structure here. */
    MyHashMap() : table_(table_len_, nullptr) { }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key % table_len_;
        Node* head = table_[index];
        while ( head != nullptr ) {
            if ( head->key_ == key ) {
                head->val_ = value;
                return;
            }
            head = head->next;
        }
        Node* node = new Node(key, value);
        node->next = table_[index];
        table_[index] = node;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key % table_len_;
        Node* head = table_[index];
        while ( head != nullptr ) {
            if ( head->key_ == key ) {
                return head->val_;
            }
            head = head->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = key % table_len_;
        Node* head = table_[index];
        Node* dummy = new Node();
        dummy->next = head;
        Node* curr = dummy;
        while ( curr->next != nullptr ) {
            if ( curr->next->key_ == key ) {
                Node* next = curr->next->next;
                delete curr->next;
                curr->next = next;
                break;
            }
            curr = curr->next;
        }
        table_[index] = dummy->next;
        delete dummy;
    }

private:
    static constexpr int table_len_ = 769;

    vector<Node*>        table_;
};
