/*
 * Design a data structure to support the following operations:
 *  • insert(x,T) – Insert item x into the set T .
 *  • delete(k,T) – Delete the kth smallest element from T .
 *  • member(x,T) – Return true iff x ∈ T .
 *
 *  All operations must take O(log n) time on an n-element set
 *
 *
 *  Thinking:
 *  "Initial thinking" was to store the number of elements less than the
 *  node in the node itself, but I was not able to think of the code
 *  which will run in O(log n) time.
 *
 *  Later, I decided to store only the number of elements which are
 *  left to a node and if we find, while searching that the rank
 *  we are searching is greater than the left elements of that
 *  node, then we subtract the seen elements from the rank and
 *  search in the right sub tree.
 */

#include <iostream>

using namespace std;

struct Node {
    int data;
    int left_nodes;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        this->left_nodes = 0;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
    Node *root;
    void insert(Node **root, int data);
    void print_tree(Node *root);
    void print_tree_pre(Node *root);
    bool member(Node *root, int data);
//    void del_rank(Node **root, int rank);
    Node* del_rank(Node *root, int rank);
//    void delete_node(Node **root);
    Node* delete_node(Node *root);
    Node* find_left_node(Node *root);
public:
    BST(): root{NULL}{}
    void insert(int data);
    void del_rank(int rank);
    bool member(int data);
    void print_tree();
};

void BST::del_rank(int rank) {
    root = del_rank(root, rank);
}

Node* BST::find_left_node(Node *root) {
    Node *current = root;
    while(current->left != NULL) {
        current = current->left;
    }
    return current;
}

//Node* BST::delete_node(Node *root) {
//    if (root->left == NULL) {
//        Node *temp = root->right;
//        free(root);
//        return temp;
//    }
//    else if (root->right == NULL) {
//        Node *temp = root->left;
//        free(root);
//        return temp;
//    }
//    else if (root->left != NULL && root->right != NULL) {
//        Node *left_node = find_left_node(root->right);
//        if (left_node != NULL) {
//            root->data = left_node->data;
//            delete_node(root->right, )
//        }
//    }
//}

Node* BST::del_rank(Node *root, int rank) {
    if (root == NULL) {
        cout << "Rank not found" << endl;
        return root;
    }
    if (root->left_nodes + 1 == rank) {
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
        Node *left_node = find_left_node(root->right);
        if (left_node != NULL) {
            root->data = left_node->data;
            root->right = del_rank(root->right, left_node->left_nodes);
        }
    }
    if (rank > root->left_nodes + 1) {
        rank = rank - (root->left_nodes + 1);
        root->right = del_rank(root->right, rank);
    }
    else {
        root->left =  del_rank(root->left, rank);
    }
    return root;
}

bool BST::member(int data) {
    return member(root, data);
}

bool BST::member(Node *root, int data) {
    if (root == NULL) {
        return false;
    }
    if (root->data == data) {
        return true;
    }
    member(root->left, data);
    member(root->right, data);
}

void BST::insert(int data) {
    insert(&root, data);
}
void BST::insert(Node **root, int data) {
    if (*root == NULL) {
        Node *newNode = new Node(data);
        *root = newNode;
        return;
    }
    if (data < (*root)->data) {
        (*root)->left_nodes++;
        insert(&(*root)->left, data);
    }
    else {
        insert(&(*root)->right, data);
    }
}

void BST::print_tree() {
    Node *temp = root;
    print_tree_pre(temp);
}

void BST::print_tree_pre(Node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << endl;
    print_tree_pre(root->left);
    print_tree_pre(root->right);
}

void BST::print_tree(Node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    cout << root->data << endl;
    print_tree(root->right);
}

int main() {
    BST tree;
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    tree.insert(9);
    tree.insert(7);
    tree.insert(8);
    tree.insert(10);
    tree.print_tree();
    bool res = tree.member(9);
    cout << "The result is: " << res << endl;
    res = tree.member(11);
    cout << "The result is: " << res << endl;
    tree.del_rank(10);
    tree.print_tree();
    return 0;
}