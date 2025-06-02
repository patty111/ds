// @lc app=leetcode id=2095 lang=c
// @lc code=start
int length(struct ListNode* head){
    int count=0;
    while(head){
        head = head->next;
        count++;
    }return count;
}

struct ListNode* deleteMiddle(struct ListNode* head){
    int find = (int)length(head)/2;
    struct ListNode* follow = NULL;
    struct ListNode* cursor = head;

    for (int i=0;i<find;i++){
        follow = cursor;
        cursor = cursor->next;
    }

    if (!follow) return NULL;
    if (!cursor->next){
        follow->next = NULL;
        return head;
    }
    follow->next = cursor->next;
    free(cursor);
    return head;
}
// @lc code=end

