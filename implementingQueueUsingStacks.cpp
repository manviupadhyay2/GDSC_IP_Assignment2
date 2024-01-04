class MyQueue {
private:
    stack<int> stk1;
    stack<int> stk2;

public:
    MyQueue() {
    }

    void push(int x) {
        stk1.push(x);
    }

    int pop() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }

        int frontElement = stk2.top();
        stk2.pop();
        return frontElement;
    }

    int peek() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }

        return stk2.top();
    }

    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};
