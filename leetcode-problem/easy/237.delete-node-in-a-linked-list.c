//@lc app=leetcode id=237 lang=c
// @lc code=start
void deleteNode(struct ListNode* node) {
    struct ListNode* follow = NULL;
    while(node->next){
        node->val = node->next->val;
        follow = node;
        node = node->next;
    }
    follow->next = NULL;
}
// @lc code=end

