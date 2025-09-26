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

function levelOrder(root: TreeNode | null): number[][] {
	let res: number[][] = [];
	const rec_search = (r: TreeNode | null, depth: number) => {
		if (r && r.val != null) {
			if (!res[depth]) {
				res.push([]);
			}
			res[depth].push(r.val);
			rec_search(r.left, depth + 1);
			rec_search(r.right, depth + 1);
		}
	};
	rec_search(root, 0);
	return res;
}
