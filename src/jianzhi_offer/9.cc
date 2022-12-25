/*
 * 用两个栈实现队列
 */

#include "dependency.h"

class CQueue {

private:
    std::stack<int> in_stack_, out_stack_;

    void in2out() {
        while (!in_stack_.empty()) {
            out_stack_.push(in_stack_.top());
            in_stack_.pop();
        }
    }

public:
    CQueue() {
    }

    void appendTail(int value) {
        in_stack_.push(value);
    }

    int deleteHead() {
        if (out_stack_.empty()) {
            if (in_stack_.empty()) {
                return -1;
            }
            in2out();
        }
        int value = out_stack_.top();
        out_stack_.pop();
        return value;
    }
};

int main(int argc, char const* argv[]) {
    std::cout << "jianzhi_offer 09: 用两个栈实现队列" << std::endl;
    CQueue* cqueue = new CQueue();
    cqueue->appendTail(1);
    cqueue->appendTail(2);
    cqueue->appendTail(3);
    std::cout << cqueue->deleteHead() << std::endl;
    std::cout << cqueue->deleteHead() << std::endl;
    std::cout << cqueue->deleteHead() << std::endl;
    return 0;
}