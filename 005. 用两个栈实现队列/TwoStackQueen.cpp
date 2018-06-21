#include<iostream>
#include<stack>
using namespace std;
class TwoStack {
public:
    //队列值依次压入stack1，stack1栈顶即为队列尾
    void push(int i) {
        stack1.push(i);
    }
    int pop() {
        if (isEmpty()){
            cout << "两个栈都为空" << endl;
            return -1;
        }
        if (stack2.empty()) {
            while(!stack1.empty()) {
                stack2.push(stack1.top()); //将stack1依次出栈压入stack2，stack2栈顶即为队列头
                stack1.pop();
            }
        }
        int result = stack2.top();
        stack2.pop();
        return result;
    }
    bool isEmpty() {
        return (stack1.empty() && stack2.empty());
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
int main() {
    TwoStack quene;
    quene.push(1);
    quene.push(2);
    quene.push(3);
    quene.push(4);
    while (!quene.isEmpty()) {
        cout << quene.pop() << " ";
    }
    return 0;
}
