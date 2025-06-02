/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
int max(int a, int b) {
    return a > b ? a : b;
}

int maxPathSumHelper(struct TreeNode* root, int* maxSum) {
    if (root == NULL) return 0;
    int leftSum = max(0, maxPathSumHelper(root->left, maxSum));
    int rightSum = max(0, maxPathSumHelper(root->right, maxSum));
    *maxSum = max(*maxSum, leftSum + rightSum + root->val);
    return max(leftSum, rightSum) + root->val;
}

int maxPathSum(struct TreeNode* root){
    int maxSum = INT_MIN;
    maxPathSumHelper(root, &maxSum);
    return maxSum;
}