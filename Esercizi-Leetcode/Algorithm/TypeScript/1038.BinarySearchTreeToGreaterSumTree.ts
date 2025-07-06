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

/*
Dato un BST ritorna lo stesso BST ma con i valori maggiori raggiungibili semplicemente sommando i valori al massimo una volta
es.        3                 
        2     5
      1     4   8 

Output:    20                 
        22    13
      23    17   8 
      
*/
function bstToGst(root: TreeNode | null): TreeNode | null {
	let som: number = 0;
	const rec_search = (r: TreeNode | null) => {
		if (r) {
			rec_search(r.right);

			som += r.val;

			r.val = som;

			rec_search(r.left);
		}
	};
	rec_search(root);
	return root;
}
