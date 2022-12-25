#include "dependency.h"
#include "list_node.h"


class Solution {
public:

    // reverse a list in place
    ListNode* reverseListInPlace(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        // step 1: get the initial three pointers, cur, prev, next
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* next = cur->next;
        while (cur) {
            // step 2: rearrange the order of cur, prev and next
            cur->next = prev;

            // step 3: update three pointers
            prev = cur;
            cur = next;
            if (cur) next = cur->next;
        }

        return prev;
    };

    // reverse a list in place
    std::vector<int> reversePrintInPlace(ListNode* head) {
        std::vector<int> result;
        if (!head) {
            return result;
        }

        // step 1: get the initial three pointers, cur, prev, next
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* next = cur->next;
        while (cur) {
            // step 2: rearrange the order of cur, prev and next
            cur->next = prev;

            // step 3: update three pointers
            prev = cur;
            cur = next;
            if (cur) next = cur->next;
        }

        ListNode* new_head = prev;
        while (new_head) {
            result.push_back(new_head->val);
            new_head = new_head->next;
        }

        return result;
    };

    // reverse a list with the help of a container
    std::vector<int> reversePrintWithContainer(ListNode* head) {

        std::vector<int> forward_pass;
        while (head) {
            forward_pass.push_back(head->val);
            head = head->next;
        }

        std::vector<int> reverse_pass;
        for (auto itr = forward_pass.rbegin(); itr != forward_pass.rend(); ++itr) {
            reverse_pass.push_back(*itr);
        }
        return reverse_pass;
    }
};

int main(int argc, char const* argv[]) {

    Solution s;
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    a.next = &b;
    b.next = &c;
    // std::vector<int> result = s.reversePrintInPlace(&a);
    // for (auto itr = result.cbegin(); itr != result.cend(); ++itr) {
    //     std::cout << *itr << std::endl;
    // }
    ListNode* reversed_head = s.reverseListInPlace(&a);
    reversed_head->print();

    return 0;
}
