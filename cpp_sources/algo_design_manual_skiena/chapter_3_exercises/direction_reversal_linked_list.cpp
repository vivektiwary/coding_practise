/*
 * Write a program to reverse the direction of a given singly-linked list. In other
 * words, after the reversal all pointers should now point backwards. Your algorithm
 * should take linear time.
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
    void reverse_list() {
        Node *prev = NULL;
        Node *right;
        Node *current = head;
        while (current != NULL) {
            right = current->next;
            current->next = prev;
            prev = current;
            current = right;
        }
        this->head = prev;
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
