class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return isValidBSTHelper(root, prev);
    }
    
    bool isValidBSTHelper(TreeNode* node, TreeNode*& prev) {
        if (node == nullptr)
            return true;
        
        if (!isValidBSTHelper(node->left, prev))
            return false;
        
        if (prev != nullptr && prev->val >= node->val)
            return false;
        
        prev = node;
        return isValidBSTHelper(node->right, prev);
    }
};