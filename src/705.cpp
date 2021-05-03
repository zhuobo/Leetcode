#include "structure.h"
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


class MyHashSet2 {
public:
    MyHashSet() : table_(table_len_, nullptr) {  }
    
    void add(int key) {
        // not repeat
        if ( contains(key) ) {
            return;
        }
        int index = key % table_len_;
        ListNode* head = table_[index];
        ListNode* node = new ListNode(key);
        node->next = head;
        table_[index] = node;
    }
    
    void remove(int key) {
        if ( !contains(key) ) {
            return;
        }
        int index = key % table_len_;
        ListNode* head = table_[index];
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;
        while ( curr->next != nullptr ) {
            if ( curr->next->val == key ) {
                ListNode* next = curr->next->next;
                delete curr->next;
                curr->next = next;
                break;
            }
            curr = curr->next;
        }
        table_[index] = dummy->next;
        delete dummy;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = key % table_len_;
        ListNode* head = table_[index];
        while ( head != nullptr ) {
            if ( head->val == key ) {
                return true;
            }
            head = head->next;
        }
        return false;
    }
private:
    vector<ListNode*>    table_;
    constexpr static int table_len_ = 769;
};
