class Solution {
public:
    int maxh = 0;
    bool up = false;

    bool heightOfLeaf(TreeNode* t, int h){
        if(!t) {
            if(maxh == 0) maxh = h;
            else if(maxh < h) return false;
            else if(maxh == h + 1 && !up){
                up = true;
                maxh = h;
            }
            else if(maxh > h) return false;
            return true;
        }
        h++;
        return heightOfLeaf(t->left, h) && heightOfLeaf(t->right, h);
    }

    bool isCompleteTree(TreeNode* root) {
        return heightOfLeaf(root, 0);
    }
};