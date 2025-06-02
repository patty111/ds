## 237. Delete Node in a Linked List
### 題目
**[link](https://leetcode.com/problems/delete-node-in-a-linked-list/description/)**
在不知道 linked list head 和 前一個節點的情況下刪除一個指定節點，指定節點不會是 Tail。
### Solution
把下一個值複製到當前節點，然後將 next 指向 next.next

> O(n)Runtime beats 73.39%, memory usage beats 27.5%
