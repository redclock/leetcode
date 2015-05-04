/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    vector<int> stack;
    vector<int> min;
    void push(int x) {
        stack.push_back(x);
        if (min.empty()) {
            min.push_back(x);
        }
        else {
            int m = min.back();
            if (m < x) min.push_back(m);
            else min.push_back(x);
        }
    }

    void pop() {
        min.pop_back();
        stack.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return min.back();
    }
};