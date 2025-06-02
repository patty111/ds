/*
 * @lc app=leetcode id=61 lang=c
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (36.00%)
 * Likes:    7298
 * Dislikes: 1344
 * Total Accepted:    692.9K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, rotate the list to the right by k
 * places.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [4,5,1,2,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [0,1,2], k = 4
 * Output: [2,0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 500].
 * -100 <= Node.val <= 100
 * 0 <= k <= 2 * 10^9
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k){
    int length = 1;
    struct ListNode* ptr = head;
    if (!ptr) return NULL;
    while(ptr->next){
        ptr = ptr->next;
        length++;
    }

    /* key thought
    Don't need circular
    Change the rotate from right shift to left shift.
    (It is easier to shift to left in linked list)
    */
    int rotate = length - (k % length);

    for (int i=0;i<rotate;i++){
        ptr = head;
        int tmp = head->val;
        while(ptr->next){
            ptr->val = ptr->next->val;
            ptr = ptr->next;
        }
        ptr->val = tmp;
    }
    return head;
}
// @lc code=end

