#include "dependency.h"
#include "list_node.h"

void ListNode::print() {
    ListNode* cur = this;
    while (cur) {
        std::cout << cur->val << std::endl;
        cur = cur->next;
    }
}