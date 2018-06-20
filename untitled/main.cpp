#include <iostream>
using namespace std;

class AlgosTree {

    class Node {
    public:
        Node* left;
        Node* right;
        int value;

        Node() {}
        Node(int value) : value(value) {}
    };


    Node* root;
    int deep=0;
    void add(Node* node, int value);
    void print(Node* node);
    void clean();


public:

    AlgosTree() {}

    AlgosTree(int value){ root = new Node(value); }

    void add(int value) { add(root, value); }

    void print();

    virtual ~AlgosTree();
};

void AlgosTree::add(Node* node, int value) {
    Node* curent = new Node(value);

    if (!root) {
        root = curent;
        return;
    }

    Node* tmp = node;
    if (value <= node->value) {
        if (!node->left) { node->left = curent; return; }
        add(node->left, value);
    }
    if (value > node->value) {
        if (!node->right) { node->right = curent; return; }
        add(node->right, value);
    }
}

void AlgosTree::clean() {

}

AlgosTree::~AlgosTree() {

}

void AlgosTree::print() {
    print(root);
}

void AlgosTree::print(AlgosTree::Node *node) {
    if (!root) return;
    deep++;

    cout /*<< deep*/ << " -> " << node->value << endl;
    if (!node->left && !node->right) { return; }
    if (node->left) {
        print(node->left);
    }
    if (node->right) {
        print(node->right);
    }
}


int main() {
    AlgosTree algosTree;
    algosTree.add(5);
    algosTree.add(3);
    algosTree.add(8);
    algosTree.add(1);
    algosTree.add(2);
    algosTree.add(6);
    algosTree.add(9);
    algosTree.print();
    return 0;
}