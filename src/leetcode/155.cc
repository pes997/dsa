/**
 * 155. min_stack 最小栈
 *
 * 首先，一般思路是用一个变量min，保存当前的最小值，
 * 最小值可以在添加新元素时通过比较新元素和min的大小
 * 进行判断。
 *
 * 问题在于，如果从集合中删除元素，那么，min的值也要
 * 随之变化。如果是一般的集合，比如list，删除的操作
 * 可能是任意元素，那么就必须通过遍历剩余所有元素来
 * 重新确定min的值。
 *
 * 这个问题特殊之处在于，使用的集合是stack，由于stack
 * 的操作是LIFO（Last In First Out），这样，删除的
 * 元素就只可能是栈顶元素，确保了唯一性。那么就可以借助
 * 一个辅助栈，称之为min_stack。每当添加新元素时，min_stack
 * 也将当前集合的min值添加（push到min_stack的栈顶）。
 * 删除（pop）元素时，也同时删除min_stack栈顶元素。
*/

#include "dependency.h"

class MinStack {
private:

    std::stack<int> main_stack_, min_stack_;

public:
    MinStack() {
        min_stack_.push(INT_MAX);
    }

    void push(int x) {
        if (x < min_stack_.top()) {
            min_stack_.push(x);
        }
        else {
            min_stack_.push(min_stack_.top());
        }
        main_stack_.push(x);
    }

    void pop() {
        main_stack_.pop();
        min_stack_.pop();
    }

    int top() {
        if (main_stack_.empty()) return -1;
        return main_stack_.top();
    }

    int min() {
        return min_stack_.top();
    }
};

int main(int argc, char const* argv[]) {

    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    std::cout << minStack->min() << std::endl;
    minStack->pop();
    std::cout << minStack->top() << std::endl;
    std::cout << minStack->min() << std::endl;

    return 0;
}
