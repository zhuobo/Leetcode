#include <iostream>
#include <deque>

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


class FrontMiddleBackQueue2 {
public:
    FrontMiddleBackQueue2() {  }
    
    void pushFront(int val) {
        if ( que1.size() != que2.size() ) {
            adjustToSecond();
        }
        que1.push_front(val);
    }
    
    void pushMiddle(int val) {
        if ( que1.size() != que2.size() ) {
            adjustToSecond();
        }
        que1.push_back(val);
    }
    
    void pushBack(int val) {
        que2.push_back(val);
        if ( que1.size() != que2.size() ) {
            adjustToFirst();
        }
    }
    
    int popFront() {
        if ( que1.empty() ) {
            return -1;
        }
        if ( que1.size() == que2.size() ) {
            adjustToFirst(); 
        }
        int ret = que1.front();
        que1.pop_front();

        return ret;
    }
    
    int popMiddle() {
        int ret = -1;
        if ( que1.empty() ) {
            return ret;
        }
        ret = que1.back();
        que1.pop_back();
        if ( que1.size() != que2.size() ) {
            adjustToFirst();
        }
        return ret;
    }
    
    int popBack() {
        if ( que1.empty() && que2.empty() ) {
            return -1;
        }
        if ( que1.size() != que2.size() ) {
            adjustToSecond();
        }
        int ret = que2.back();
        que2.pop_back();
        return ret;
    }

private:
    void adjustToFirst() {
        int temp = que2.front();
        que2.pop_front();
        que1.push_back(temp);
    }

    void adjustToSecond() {
        int temp = que1.back();
        que1.pop_back();
        que2.push_front(temp);
    }

    deque<int> que1;
    deque<int> que2;
};

int main() {
    FrontMiddleBackQueue2 queue;
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
