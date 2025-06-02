// @lc app=leetcode id=203 lang=c
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    if (!head) return NULL;
    
    struct ListNode* cursor = head;
    struct ListNode* follow = (struct ListNode*)malloc(sizeof(struct ListNode));
    follow = NULL;
    while (cursor){
        // first
        if (cursor->val == val && !follow){
            head = head->next;
            free(cursor);
            cursor = head;
        }else if (cursor->val == val && cursor->next){  // mid
            follow->next = cursor->next;
            free(cursor);
            cursor = follow->next;
        }else if (cursor->val == val && !cursor->next){  //last
            follow->next = NULL;
            free(cursor);
            break;
        }else{
            follow = cursor;
            cursor = cursor->next;
        }
    }
    return head;
}
// @lc code=end

