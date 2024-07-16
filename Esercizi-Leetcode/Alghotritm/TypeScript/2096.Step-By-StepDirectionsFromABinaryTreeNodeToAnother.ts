class TreeNode {
	val: number;
	left: TreeNode | null;
	right: TreeNode | null;
	constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
		this.val = val === undefined ? 0 : val;
		this.left = left === undefined ? null : left;
		this.right = right === undefined ? null : right;
	}
}

//Trova il path più breve tra due nodi
function searchNode(
	root: TreeNode | null,
	startValue: number,
	a: string[]
): string[] {
	let prev: TreeNode[] = [];
	let watched: number[] = [];
	while (root!.val != startValue) {
		if (root!.left != null && !watched.includes(root!.left!.val)) {
			a.push('L');
			prev.push(root!);
			root = root!.left;
			continue;
		}
		if (root!.right != null && !watched.includes(root!.right!.val)) {
			a.push('R');
			prev.push(root!);
			root = root!.right;
			continue;
		}
		watched.push(root!.val);
		while (watched.includes(root!.val)) {
			a.pop();
			root! = prev!.pop()!;
		}
	}
	return a;
}

function getDirections(
	root: TreeNode | null,
	startValue: number,
	destValue: number
): string {
	let a: string[] = [];
	a = searchNode(root, startValue, a);
	let b: string[] = [];
	b = searchNode(root, destValue, b);
	for (let i = 0; i < a.length && i < b.length && a[i] == b[i]; i++) {
		a[i] = b[i] = '';
	}
	for (let i = 0; i < a.length; i++) {
		if (a[i] != '') {
			a[i] = 'U';
		}
	}
	return a.join('') + b.join('');
}
