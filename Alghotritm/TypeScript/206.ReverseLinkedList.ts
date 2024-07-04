class ListNode {
	val: number;
	next: ListNode | null;
	constructor(val?: number, next?: ListNode | null) {
		this.val = val === undefined ? 0 : val;
		this.next = next === undefined ? null : next;
	}
}
/*
Data una lista la restituisce rovesciata
*/
function reverseList(head: ListNode | null): ListNode | null {
	let prev: ListNode | null = null;

	while (head) {
		let next = head.next;
		head.next = prev;
		prev = head;
		head = next;
	}

	return prev;
}
