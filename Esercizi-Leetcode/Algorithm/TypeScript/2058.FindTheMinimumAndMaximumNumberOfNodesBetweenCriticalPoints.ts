class ListNode {
	val: number;
	next: ListNode | null;
	constructor(val?: number, next?: ListNode | null) {
		this.val = val === undefined ? 0 : val;
		this.next = next === undefined ? null : next;
	}
}

//Trovati i nodi critici (Punti di massimo o di minimo) di una lista restituisce la distanza minima e massima tra due nodi critici
function nodesBetweenCriticalPoints(head: ListNode | null): number[] {
	let criticalPoints: number[] = [];
	let index: number = 0;
	if (head != null) {
		let prev = head.val;
		while (head.next != null) {
			if (
				(prev < head.val && head.val > head.next.val) ||
				(prev > head.val && head.val < head.next.val)
			) {
				criticalPoints.push(index);
			}
			prev = head.val;
			head = head?.next;
			index++;
		}
	}
	if (criticalPoints.length < 2) {
		return [-1, -1];
	}
	criticalPoints.sort((a, b) => a - b);
	let max = criticalPoints[0] - criticalPoints[criticalPoints.length - 1];
	let min = criticalPoints[1] - criticalPoints[0];
	for (let i = 1; i < criticalPoints.length - 1; i++) {
		if (criticalPoints[i + 1] - criticalPoints[i] < min) {
			min = criticalPoints[i + 1] - criticalPoints[i];
		}
	}
	return [min, max];
}
