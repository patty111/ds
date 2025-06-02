/*
 * @lc app=leetcode id=19 lang=c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int LinkedLength(struct ListNode* head){
    int count = 0;
    struct ListNode* traverse = head;
    while(traverse){
        count++;
        traverse = traverse->next;
    }
    return count;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* ptr = head;
    struct ListNode* follow = NULL;
    int index = 0;
    if (!ptr) return NULL;
    if (!(ptr->next)) return NULL;
    while(ptr){
        if (index == LinkedLength(head) - n){
            if (ptr == head) return ptr->next;
            follow->next = ptr->next;
            free(ptr);
            return head;
        }
        index++;
        follow = ptr;
        ptr = ptr->next;
    }
    return head;
}
// @lc code=end

