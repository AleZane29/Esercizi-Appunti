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

function balanceBST(root: TreeNode | null): TreeNode | null {
	let array: number[] = [];
	const save_val = (tree: TreeNode | null) => {
		if (tree) {
			save_val(tree.left);
			array.push(tree.val);
			save_val(tree.right);
		}
	};
	save_val(root);

	const get_middle = (arr: number[]): TreeNode | null => {
		if (arr.length > 0) {
			let ind = Math.round(arr.length / 2) - 1;
			let newRoot: TreeNode = {
				val: arr[ind],
				left: get_middle(arr.slice(0, ind)),
				right: get_middle(arr.slice(ind + 1, arr.length)),
			};
			return newRoot;
		}
		return null;
	};

	return get_middle(array);
}
