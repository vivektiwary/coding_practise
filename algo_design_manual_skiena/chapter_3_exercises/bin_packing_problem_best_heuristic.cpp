/*
 * 3-10. [5] In the bin-packing problem, we are given n metal objects, each weighing between
 * zero and one kilogram. Our goal is to find the smallest number of bins that will
 * hold the n objects, with each bin holding one kilogram at most.
 *
 *  • The best-fit heuristic for bin packing is as follows. Consider the objects in the
 *    order in which they are given. For each object, place it into the partially filled
 *    bin with the smallest amount of extra room after the object is inserted.. If
 *    no such bin exists, start a new bin. Design an algorithm that implements the
 *    best-fit heuristic (taking as input the n weights w 1 , w 2 , ..., w n and outputting
 *    the number of bins used) in O(n log n) time.
 *
 *  • Repeat the above using the worst-fit heuristic, where we put the next object in
 *    the partially filled bin with the largest amount of extra room after the object
 *    is inserted.
 *
 *
 * ==============Implementation of best-fit heuristic==========================
 */

#include <iostream>

using namespace std;

struct Node {
    double space;
    Node *left;
    Node *right;
    Node(float usedCap): space{1 - usedCap}, left{NULL}, right{NULL} {};
};

class BST {
    Node* insert(Node *root, Node *minNode);
    Node* del(Node *root, Node *minNode);
    void print_tree(Node *root);
    Node* find_minimum_node(Node *root);
public:
    Node *root;
    BST(): root{NULL}{};
    void insert(Node* minNode);
    Node* del(Node* minNode);
    void print_tree();
};

void BST::print_tree(Node *root) {
    if (root
        == NULL) {
        return;
    }
    cout << "The node is: " << root->space << endl;
    print_tree(root->left);
    print_tree(root->right);
}

void BST::print_tree() {
    print_tree(root);
}

Node* BST::insert(Node *root, Node *minNode) {
    if (root == NULL) {
        root = minNode;
        return root;
    }
    if (minNode->space < root->space) {
        root->left = insert(root->left, minNode);
    }
    else {
        root->right = insert(root->right, minNode);
    }
    return root;
}

void BST::insert(Node *minNode) {
    root = insert(root, minNode);
}

Node* BST::find_minimum_node(Node *root) {
    Node *current = root;
    while(current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* BST::del(Node *root, Node *minNode) {
    if (root->space == minNode->space) {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        } else {
            Node *current_node = find_minimum_node(root->right);
            if (current_node != NULL) {
                root->space = current_node->space;
                root->right = del(root->right, current_node);
            }
            return root;
        }
    }
    else if(minNode->space < root->space) {
        root->left =  del(root->left, minNode);
    }
    else {
        root->right = del(root->right, minNode);
    }
    return root;
}

Node* BST::del(Node *minNode) {
    root = del(root, minNode);
    return root;
}

int main() {
    BST tree;
    int n;
    cout << "Enter the number of objects" << endl;
    cin >> n;
    double weights[n];
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    int binCount = 0;
    for (int i = 0; i < n; ++i) {
        Node* minNode = NULL;
        double minSpace = 1;
        double weight = weights[i];
        Node *root = tree.root;
        while(root != NULL) {
            if (weight <= root->space) {
                float space = root->space - weight;
                if (space < minSpace) {
                    minSpace = space;
                    minNode = root;
                    root = root->left;
                }
            }
            else {
                root = root->right;
            }
        }
        if (minNode == NULL) {
            binCount++;
            tree.insert(new Node(weight));
        }
        else {
            minNode->space -= weight;
            float newSpace = minNode->space;
            root = tree.del(minNode);
            tree.insert(new Node(1 - newSpace));
        }
    }
    cout << "The min number of bin is: " << binCount << endl;
}