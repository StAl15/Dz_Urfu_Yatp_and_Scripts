#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countMax(TreeNode *root, int maxVal, int count) {
    if (!root) {
        return count;
    }
    if (root->val > maxVal) {
        maxVal = root->val;
        count = 1;
    } else if (root->val == maxVal) {
        count++;
    }
    int leftCount = countMax(root->left, maxVal, count);
    int rightCount = countMax(root->right, maxVal, count);
    return leftCount + rightCount;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    int maxVal = root->val;
    int count = 1;
    int result = countMax(root, maxVal, count);
    cout << "The maximum value in the binary tree is " << maxVal << endl;
    cout << "The number of occurrences of the maximum value is " << result << endl;
    return 0;
}