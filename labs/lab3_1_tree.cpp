
//------------------------------------------------------ #1 ------------------------------------------------------

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxSum = numeric_limits<int>::min();

        postOrder(root);

        return maxSum;
    }

private:
    int maxSum;

    int postOrder(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftSum = max(0, postOrder(root->left)); 
        int rightSum = max(0, postOrder(root->right)); 

        maxSum = max(maxSum, root->val + leftSum + rightSum);

        return root->val + max(leftSum, rightSum);
    }
};

int main() {
    // Пример 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    Solution solution;
    int result1 = solution.maxPathSum(root1);
    cout << "Пример 1: " << result1 << endl;

    // Пример 2
    TreeNode* root2 = new TreeNode(-10);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);

    int result2 = solution.maxPathSum(root2);
    cout << "Пример 2: " << result2 << endl;

    return 0;
}
