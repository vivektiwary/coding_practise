/*
 * Parentheses matcher using stack.
 * Ex: ()()(()): true
 * )()( : false
 *
 * We will print the offending index
 */

#include <iostream>

using namespace std;

class Node {
    char data;
    int index;
public:
    Node *next;
    Node(char data, int index): data{data}, index{index}, next{nullptr} {}
    void assign_next(Node *nextObj) {
        this->next = nextObj;
    }
    pair<char, int> getData() {
        return make_pair(this->data, this->index);
    };
};

class List {
    Node *head = NULL;
public:
    void front_insertion(char data, int index) {
        Node *newNode = new Node(data, index);
        if (head == NULL) {
            head = newNode;
        }
        else {
            newNode->assign_next(head);
            head = newNode;
        }
    }
    pair<char, int> front_deletion() {
        if (head == NULL) {
            return make_pair('\0', -1);
        }
        Node *temp = head;
        pair<char, int> result = head->getData();
        this->head = this->head->next;
        free(temp);
        return result;
    }
    bool is_empty() {
        return head == NULL;
    }
    void print_data() {
        while(head != NULL) {
            cout << "The data is: " << head->getData().first << " " << head->getData().second << endl;
            head = head->next;
        }
    }
};

class Stack {
    int top;
    int size;
    List slist;
public:
    Stack(int size) {
        this -> top = -1;
        this -> size = size;
    }
    void push(char data, int index);
    pair<char, int> pop();
    bool is_empty();
};

bool Stack::is_empty() {
    return slist.is_empty();
}

void Stack::push(char data, int index) {
    if (this -> top >= this -> size) {
        cout << "Stack is full" << endl;
        return;
    }
    this -> top++;
    slist.front_insertion(data, index);
}
pair<char, int> Stack::pop() {
    pair<char,int> res = slist.front_deletion();
    if (res.first == '\0') {
        cout << "Stack is empty" << endl;
        return res;
    }
    return res;
}

void print_error(int pos) {
    cout << "false" << " at " << pos << endl;
}

void print_success() {
    cout << "yes" << endl;
}

int main() {
    string stream;
    cin >> stream;
    bool error = false;
    int size = stream.length();
    Stack stk {size};
    for (int i = 0; i < size; ++i) {
        if (stream[i] == '(') {
            stk.push(stream[i], i);
        }
        else if (stream[i] == ')') {
            pair<char, int> data = stk.pop();
            if (data.first != '(') {
                print_error(i);
                error = true;
                break;
            }
        }
    }
    if (!stk.is_empty()) {
        print_error(size);
    }
    else if (!error) {
        print_success();
    }
    return 0;
}