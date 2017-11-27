/*
 * Linked list reversal using recursion
 */

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int data): data{data} {this->next = NULL;}
};

class List {
    Node *head;
public:
    List(): head{NULL} {}
    void front_insertion(int data) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }
    void recursive_reverse(Node **head) {
        if (*head == NULL) {
            return;
        }
        Node *first = *head;
        Node *rest = first->next;
        if (rest == NULL) {
            return;
        }
        recursive_reverse(&rest);
        first->next->next = first;
        first->next = NULL;
//        rest->next = first;
        *head = rest;
    }
    void reverse_list() {
        recursive_reverse(&head);
    }
    void print_list() {
        Node *temp = this->head;
        while(temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    List slist;
    slist.front_insertion(1);
    slist.front_insertion(2);
    slist.front_insertion(3);
    slist.front_insertion(4);
    slist.front_insertion(5);
    slist.print_list();
    cout << "========================" << endl;
    slist.reverse_list();
    slist.print_list();
}

