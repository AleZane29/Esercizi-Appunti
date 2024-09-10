class ListNode {
	val: number;
	next: ListNode | null;
	constructor(val?: number, next?: ListNode | null) {
		this.val = val === undefined ? 0 : val;
		this.next = next === undefined ? null : next;
	}
}

function insertGreatestCommonDivisors(head: ListNode | null): ListNode | null {
	let tmp = head;
	while (tmp?.next != null) {
		let MCD = 1;
		if (tmp.val == tmp.next.val) {
			MCD = tmp.val;
		} else {
			let div = 2;
			let tmpVal = tmp.val;
			let tmpNextVal = tmp.next.val;
			let maxDiv = Math.max(tmp.val, tmp.next.val) / 2 + 2;
			while (div <= maxDiv && tmpVal != 1 && tmpNextVal != 1) {
				if (tmpVal % div == 0 && tmpNextVal % div == 0) {
					MCD *= div;
					tmpVal /= div;
					tmpNextVal /= div;
				} else {
					div++;
				}
			}
		}
		let newNode: ListNode = {
			val: MCD,
			next: tmp.next
		};
		tmp.next = newNode;
		tmp = newNode.next;
	}
	return head;
}
