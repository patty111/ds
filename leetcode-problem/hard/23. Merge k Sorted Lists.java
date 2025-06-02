class Solution {
	// recursive merge
	private ListNode mergeSortedLists(ListNode list1, ListNode list2) {
		if (list1 == null)
			return list2;
		if (list2 == null)
			return list1;

		if (list1.val < list2.val) {
			list1.next = mergeSortedLists(list1.next, list2);
			return list1;
		} else {
			list2.next = mergeSortedLists(list2.next, list1);
			return list2;
		}
	}

	public ListNode mergeKLists(ListNode[] lists, int start, int end) {
		if (start > end)
			return null;
		if (start == end)
			return lists[start];

		int middle = (end + start) / 2;
		ListNode leftList = mergeKLists(lists, start, middle);
		ListNode rightList = mergeKLists(lists, middle + 1, end);
		return mergeSortedLists(leftList, rightList);
	}

	public ListNode mergeKLists(ListNode[] lists) {
		return mergeKLists(lists, 0, lists.length - 1);
	}
}