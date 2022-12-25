#ifndef DSA_LIST_NODE_H_
#define DSA_LIST_NODE_H_

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    void print();
};

#endif // DSA_LIST_NODE_H_