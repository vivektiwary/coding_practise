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
 * ==============Implementation of worst-fit heuristic==========================
 */


#include <iostream>
using namespace std;

struct Node {
    float space;
    Node *left;
    Node *right;
    Node(float reqSpace): space{1 - reqSpace}, left{NULL}, right{NULL} {};
};

class BST {
    Node* insert(Node *root, Node *newNode);
    Node* del(Node *root, Node *newNode);
    Node* findMinimum(Node *node);
    void printTree(Node *root);
public:
    BST(): root{NULL} {};
    Node *root;
    void insert(Node *newNode);
    Node* del(Node *newNode);
    void printTree();
};

Node* BST::insert(Node *root, Node *newNode) {
    if (root == NULL) {
        root = newNode;
        return root;
    }
    if (newNode->space < root->space) {
        root->left = insert(root->left, newNode);
    }
    else {
        root->right = insert(root->right, newNode);
    }
    return root;
}

void BST::insert(Node *newNode) {
    root = insert(root, newNode);
}

Node* BST::findMinimum(Node *node) {
    Node *current = node;
    while(current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* BST::del(Node *root, Node *newNode) {
    if (newNode->space == root->space) {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else {
            Node *current = findMinimum(root->right);
            root->space = current->space;
            root->right = del(root->right, current);
        }
        return root;
    }
    else if (newNode->space < root->space) {
        root->left = del(root->left, newNode);
    }
    else {
        root->right = del(root->right, newNode);
    }
    return root;
}

Node* BST::del(Node *newNode) {
    root = del(root, newNode);
}

void BST::printTree(Node *root) {
    if (root == NULL) {
        return;
    }
    cout << "The space is: " << root->space << endl;
    printTree(root->left);
    printTree(root->right);
}

void BST::printTree() {
    printTree(root);
}

int main() {
    BST bst;
//    bst.insert(new Node(0.5));
//    bst.insert(new Node(0.3));
//    bst.insert(new Node(0.7));
//    bst.insert(new Node(0.4));
//    bst.insert(new Node(0.6));
//    bst.insert(new Node(0.8));
//    bst.insert(new Node(0.1));
//    bst.insert(new Node(0.2));
//    bst.printTree();
//    cout << "=========================" << endl;
//    bst.del(new Node(0.3));
//    bst.printTree();
    int n;
    cout << "Enter the number of metal balls" << endl;
    cin >> n;
    float weights[n];
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    int binCount = 0;
    for (int i = 0; i < n; ++i) {
        float maxDiff = 0;
        float weight = weights[i];
        Node* maxNode = NULL;
        Node* root = bst.root;
        while(root != NULL) {
            if (weight <= root->space) {
                float weightDiff = root->space - weight;
                if (weightDiff >= maxDiff) {
                    maxDiff = weightDiff;
                    maxNode = root;
                    root = root->right;
                }
            }
            else {
                root = root->right;
            }
        }
        if (maxNode == NULL) {
            binCount++;
            Node *newNode = new Node(weight);
            bst.insert(newNode);
        }
        else {
            float diffWeight = maxNode->space - weight;
            bst.del(maxNode);
            bst.insert(new Node(1 - diffWeight));
        }
    }
    cout << "The minimum number of bin required is: " << binCount << endl;
}
