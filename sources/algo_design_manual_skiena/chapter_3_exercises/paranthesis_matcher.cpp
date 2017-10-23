/*
 * Parentheses matcher using stack.
 * Ex: ()()(()): true
 * )()( : false
 */

#include <iostream>

using namespace std;

class Stack {
    int top;
    int size;
    char arr[];
public:
    Stack(int size);
    void push(char data);
    char pop();
    bool isEmpty();
};
Stack::Stack(int size) {
    this->top = -1;
    this->size = size;
    this->arr[this->size];
}
void Stack::push(char data) {
    if (this-> top >= this -> size) {
        cout << "Stack is full" << endl;
        return;
    }
    this->top++;
    this->arr[this->top] = data;
}
char Stack::pop() {
    if (this->top == -1) {
        cout << "Stack is empty" << endl;
        return '\0';
    }
    char data = this->arr[this->top];
    this->top--;
    return data;
}

bool Stack::isEmpty() {
    return this->top == -1;
}

int main() {
    string stream;
    cin >> stream;
    int offendingIndex = 0;
    bool error = false;
    int size = stream.length();
    Stack stk{size};
    for (int i = 0; i < size; ++i) {
        if (stream[i] == '(') {
            stk.push(stream[i]);
        }
        else if (stream[i] == ')') {
            if (!stk.isEmpty()) {
                char data = stk.pop();
                if (data != '(') {
                    offendingIndex = i;
                    error = true;
                    break;
                }
            }
            else {
                offendingIndex = i;
                error = true;
                break;
            }
        }
    }
    if (!stk.isEmpty()) {
        cout << "false" << endl;
    }
    else {
        error ? cout << "false\n" << "And the offending index is " << offendingIndex << endl : cout << "true" << endl;
    }
}