#include "dependency.h"

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
private:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *cur = head;
        if (!cur)
            return nullptr;
        ListNode *prev = head->next;
        ListNode *next = nullptr;

        while (prev)
        {
            head->next = next;
            head = prev;
            prev = prev->next;
            next = cur;
            cur = head;
        }
        head->next = next;

        return head;
    }

public:
    vector<int> reversePrint(ListNode *head)
    {
        ListNode *cur = head;
        while (cur)
        {
            cout << cur->val << endl;
            cur = cur->next;
        }

        cout << endl;

        cur = reverseList(head);
        vector<int> result;
        while (cur)
        {
            cout << cur->val << endl;
            result.push_back(cur->val);
            cur = cur->next;
        }

        return result;
    }

    vector<int> reversePrint1(ListNode *head)
    {
        vector<int> result;
        stack<int> stk;
        ListNode *cur = head;
        while (cur)
        {
            stk.push(cur->val);
            cur = cur->next;
        }
        while (!stk.empty())
        {
            int i = stk.top();
            stk.pop();
            result.push_back(i);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{

    ListNode head(1);
    ListNode node1(2);
    ListNode node2(3);
    head.next = &node1;
    node1.next = &node2;

    Solution s;
    // s.reversePrint(&head);
    s.reversePrint(nullptr);

    return 0;
}
