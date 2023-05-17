#include <iostream>

using namespace std;

// Класс узла бинарного дерева
class Node {
public:
    int key;
    Node *left;
    Node *right;

    // Конструктор
    Node(int key) {
        this->key = key;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node *root;

    // Вспомогательная функция для вставки узла в дерево
    Node *insertHelper(Node *node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insertHelper(node->left, key);
        } else if (key > node->key) {
            node->right = insertHelper(node->right, key);
        }
        return node;
    }

public:

    Node *getRoot() {
        return root;
    }

    // Конструктор
    BinarySearchTree() {
        root = nullptr;
    }

    // Вставка узла в дерево
    void insert(int key) {
        root = insertHelper(root, key);
    }

    int height(Node *node) {
        if (node == nullptr) {
            return 0;
        } else {
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);
            return max(leftHeight, rightHeight) + 1;
        }
    }

// Функция для проверки сбалансированности бинарного дерева
    bool isBalanced(Node *node) {
        if (node == nullptr) {
            return true;
        } else {
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);
            if (abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right)) {
                return true;
            } else {
                return false;
            }
        }
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    if (bst.isBalanced(bst.getRoot())) {
        cout << "BALANCED" << endl;
    } else {
        cout << "NOOOOOOOOOO" << endl;
    }

    return 0;
}