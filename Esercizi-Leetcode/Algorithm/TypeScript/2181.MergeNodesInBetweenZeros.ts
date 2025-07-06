class ListNode {
	val: number;
	next: ListNode | null;
	constructor(val?: number, next?: ListNode | null) {
		this.val = val === undefined ? 0 : val;
		this.next = next === undefined ? null : next;
	}
}

/*
Data una lista che comincia e finisce con 0 e al suo interno sono presenti altri 0 che fungono da separatori resituire una lista formata
dalle somme dei valori contenuti tra i separatori
es. 0->1->5->0->4->0     Output: 6->4
*/
function mergeNodes(head: ListNode | null): ListNode | null {
	let res;
	let tmp = (res = head);
	let sum: number;
	while (head!.next != null) {
		sum = 0;
		head = head!.next;
		while (head!.val != 0) {
			sum += head!.val;
			head = head!.next;
		}
		res!.val = sum;
		if (head!.next != null) {
			res = res!.next;
		}
	}
	res!.next = null;
	return tmp;
}
