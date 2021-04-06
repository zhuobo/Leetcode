#include <iostream>

using namespace std;

struct Node {
    int   val_;
    Node* prev_;
    Node* next_;
    Node() = default;
    Node(int val) : val_(val), prev_(nullptr), next_(nullptr) {}
};

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() : tail_(nullptr), count_(0) {
        head_ = new Node(-1);
        tail_ = new Node(-1);
        midd_ = head_;
        head_->next_ = tail_;
        tail_->prev_ = head_;
    }
    
    void pushFront(int val) {
        Node* new_node = new Node(val);
        Node* next = head_->next_;
        next->prev_ = new_node;
        new_node->next_ = next;
        head_->next_ = new_node;
        new_node->prev_ = head_;
        if ( size() == 0 ) {
            midd_ = midd_->next_;
        } else if ( size() % 2 == 1 ) {
            midd_ = midd_->prev_;
        }
        ++count_;
    }
    
    void pushMiddle(int val) {
        Node* new_node = new Node(val);
        if ( size() % 2 == 0 ) {
            new_node->next_ = midd_->next_;
            new_node->next_->prev_ = new_node;
            midd_->next_ = new_node;
            new_node->prev_ = midd_;
            midd_ = midd_->next_;
        } else {
            new_node->prev_ = midd_->prev_;
            new_node->prev_->next_ = new_node;
            midd_->prev_ = new_node;
            new_node->next_ = midd_;
            midd_ = midd_->prev_;
        }
        ++count_;
    }
    
    void pushBack(int val) {
        Node* new_node = new Node(val);
        Node* prev = tail_->prev_;
        prev->next_ = new_node;
        new_node->prev_ = prev;
        tail_->prev_ = new_node;
        new_node->next_ = tail_;
        if ( size() == 0 ) {
            midd_ = midd_->next_;
        } else if ( size() % 2 == 0 ) {
            midd_ = midd_->next_;
        }
        ++count_;
    }
    
    int popFront() {
        int ret = -1;
        if ( size() >= 1 ) {
            if ( size() % 2 == 0 ) {
                midd_ = midd_->next_;
            }
            if ( size() == 1 ) {
                midd_ = head_;
            }
            Node* to_delete = head_->next_;
            ret = to_delete->val_;
            head_->next_ = to_delete->next_;
            to_delete->next_->prev_ = head_;
            delete to_delete;
            --count_;
        }
        return ret;
    }
    
    int popMiddle() {
        int ret = -1;
        if ( size() < 1 ) {
            return ret;
        }
        Node* to_delete = midd_;
        ret = to_delete->val_;
        to_delete->prev_->next_ = to_delete->next_;
        to_delete->next_->prev_ = to_delete->prev_;
        if ( size() % 2 == 0 ) {
            midd_ = to_delete->next_;
        } else {
            midd_ = to_delete->prev_;
        }
        delete to_delete;
        --count_;
        return ret;
    }
    
    int popBack() {
        int ret = -1;
        if ( size() >= 1 ) {
            if ( size() % 2 == 1 ) {
                midd_ = midd_->prev_;
            }
            Node* to_delete = tail_->prev_;
            ret = to_delete->val_;
            tail_->prev_ = to_delete->prev_;
            to_delete->prev_->next_ = tail_;
            delete to_delete;
            --count_;
        }
        return ret;
    }

private:
    int size() {
        return count_;
    }
    Node* head_;
    Node* midd_;
    Node* tail_;
    int   count_;
};


int main() {
    FrontMiddleBackQueue queue;
    queue.pushFront(1);
    queue.pushBack(2);
    queue.pushMiddle(3);
    queue.pushMiddle(4);
    cout << queue.popMiddle() << endl;
    cout << queue.popMiddle() << endl;
    cout << queue.popMiddle() << endl;
    cout << queue.popMiddle() << endl;
    cout << queue.popMiddle() << endl;
    cout << queue.popMiddle() << endl;
    cout << queue.popMiddle() << endl;
    cout << queue.popMiddle() << endl;
    cout << queue.popMiddle() << endl;
    cout << queue.popMiddle() << endl;
    cout << queue.popMiddle() << endl;
    cout << queue.popMiddle() << endl;
    cout << queue.popMiddle() << endl;
    cout << queue.popMiddle() << endl;
}
