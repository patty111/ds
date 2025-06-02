class Solution {
public:
    void traverse(TreeNode* root, vector<int>& result) {
        if (!root)
            return;
        traverse(root->left, result);
        result.push_back(root->val);
        traverse(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;
        traverse(root, result);
        return result;
    }
};