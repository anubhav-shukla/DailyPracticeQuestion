class CustomStack {
public:
    vector<int> stack;
    int top;

    CustomStack(int maxSize) {
        stack.resize(maxSize);
        top = -1;
    }

    void push(int x) {
        if (top+1 < stack.size()) {
            stack[++top] = x;
        }
    }

    int pop() {
        return top == -1 ? -1: stack[top--];

    }

    void increment(int k, int val) {
        for (int i = 0; i <min(k,top+1) ; i++) {
            stack[i]+=val;
        }
    }
};