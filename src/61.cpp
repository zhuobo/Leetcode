// Author:          Drinkwater
// Email:           tanzhuobo@gmail.com
// Last modified:   2021.03.27
// Filename:        61.cpp
// Descripton:       

#include "structure.h"

// ### 方法1：成环
// 将链表练成环，然后找到新的头节点即可，这里对比数组有很大的优势，因为如果是数组，则需要移动数据！

// ### 代码

// ```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if ( head == nullptr || head->next == nullptr ) {
            return head;
        }
        int num_nodes = 1;
        ListNode* curr = head;
        while ( curr->next != nullptr ) {
            ++num_nodes;
            curr = curr->next;
        }
        k %= num_nodes;
        if ( k == 0 ) {
            return head;
        }
        curr->next = head;
        ListNode* new_head = nullptr;
        ListNode* new_tail = nullptr;
        for ( int i = 0; i < num_nodes - k - 1; ++i ) {
            head = head->next;
        }
        new_head = head->next;
        new_tail = head;
        new_tail->next = nullptr;
        return new_head;
    }
};
// ```

// ### 方法2：翻转
// 这个方法可以用在数组上，先整个链表翻转，然后翻转前k个，最后翻转后count-k个，即可得到结果。

// ```cpp
class Solution2 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if ( head == nullptr ) {
            return head;
        }
        int num_nodes = 0;
        ListNode* curr = head;
        while ( curr != nullptr ) {
            ++num_nodes;
            curr = curr->next;
        }
        k %= num_nodes;
        if ( k == 0  ) {
            return head;
        }
        head = reverse(head);
        curr = head;
        for ( int i = 0; i < k - 1; ++i ) {
            curr = curr->next;
        }
        ListNode* head1 = head;
        ListNode* head2 = curr->next;
        curr->next = nullptr;
        head = reverse(head);
        head2 = reverse(head2);
        head1->next = head2;
        return head;
    }
private:
    ListNode* reverse(ListNode*  head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while ( head != nullptr ) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    } 
};
// ```

