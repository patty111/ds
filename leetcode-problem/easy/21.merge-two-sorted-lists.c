// @lc app=leetcode id=21 lang=c
// @lc code=start
struct ListNode *bubbleSort(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    int swapped;
    struct ListNode *tail = NULL;
    do {
        swapped = 0;
        struct ListNode *curr = head;
        struct ListNode *prev = NULL;
        while (curr->next != tail) {
            if (curr->val > curr->next->val) {
                struct ListNode *tmp = curr->next;
                curr->next = curr->next->next;
                tmp->next = curr;
                if (prev == NULL) {
                    head = tmp;
                } else {
                    prev->next = tmp;
                }
                prev = tmp;
                swapped = 1;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        tail = curr;
    } while (swapped);
    return head;
}
// @lc code=end