#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    char data[1000];
    int top;

public:
    Stack() : top(-1) {}

    void push(char value) {
        if (top < 999) {
            data[++top] = value;
        }
    }

    char pop() {
        if (top >= 0) {
            return data[top--];
        }
        return '\0';
    }

    bool isEmpty() const {
        return top == -1;
    }
};

int main() {
    string s;
    cin >> s;

    Stack stack;

    for (char c : s) {
        stack.push(c);
    }

    while (!stack.isEmpty()) {
        cout << stack.pop();
    }
    cout << endl;

    return 0;
}
