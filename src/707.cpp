#include "structure.h"

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() : head_(nullptr), tail_(nullptr), count_(0) {

    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if ( index >= size() ) {
            return -1;
        }
        ListNode* curr = head_;
        for ( int i = 0; i < index; ++i ) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* new_node = new ListNode(val);
        if ( empty() ) {
            head_ = new_node;
            tail_ = new_node;
        } else {
            new_node->next = head_;
            head_ = new_node;
        }
        ++count_;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* new_node = new ListNode(val);
        if ( empty() ) {
            head_ = new_node;
            tail_ = new_node;
        } else {
            tail_->next = new_node;
            tail_ = new_node;
        }
        ++count_;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if ( index > size() ) {
            return;
        }
        if ( index <= 0 ) {
            addAtHead(val);
        } else if ( index == size() ) {
            addAtTail(val);
        } else {
            ListNode* new_node = new ListNode(val);
            ListNode* curr = head_;
            for ( int i = 0; i < index - 1; ++i ) {
                curr = curr->next;
            }
            new_node->next = curr->next;
            curr->next = new_node;
            ++count_;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if ( index >= size() ) {
            return;
        }
        if ( index == 0 ) {
            ListNode* to_delete = head_;
            head_ = to_delete->next;
            delete to_delete;
        } else {
            ListNode* curr = head_;
            for ( int i = 0; i < index - 1; ++i ) {
                curr = curr->next;
            }
            ListNode* to_delete = curr->next;
            curr->next = to_delete->next;
            if ( to_delete == tail_ ) {
                tail_ = curr;
            }
            delete to_delete;
        }
        --count_;
    }

private:
    bool empty() {
        return head_ == nullptr && tail_ == nullptr;
    }

    int size() {
        return count_;
    }

    ListNode* head_;
    ListNode* tail_;
    int       count_;
};
