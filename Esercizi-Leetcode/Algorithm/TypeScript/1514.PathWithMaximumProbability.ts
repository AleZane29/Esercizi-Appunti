//NOT FINISHED -> dato grafo con possibilità in percentuale di passare ogni arco, ritornare il percorso con possibilità maggiore
function maxProbability(
	n: number,
	edges: number[][],
	succProb: number[],
	start_node: number,
	end_node: number
): number {
	let prob = 1;
	let res = 0;
	let visited: number[] = [start_node];
	for (let i = 0; i < edges.length; i++) {
		if (edges[i][0] == start_node || edges[i][1] == start_node) {
			let b;
			if (edges[i][0] == start_node) {
				b = 1;
			} else {
				b = 0;
			}
			if (edges[i][b] == end_node) {
				if (prob * succProb[i] > res) {
					res = prob * succProb[i];
				}
			} else if (
				findProb(
					edges,
					succProb,
					edges[i][b],
					end_node,
					prob * succProb[i],
					visited
				) > res
			) {
				res = findProb(
					edges,
					succProb,
					edges[i][b],
					end_node,
					prob * succProb[i],
					visited
				);
			}
		}
	}
	return res;
}

function findProb(
	edges: number[][],
	succProb: number[],
	start_node: number,
	end_node: number,
	prob: number,
	visited: number[]
): number {
	let res = 0;
	visited.push(start_node);
	for (let i = 0; i < edges.length; i++) {
		if (edges[i][0] == start_node || edges[i][1] == start_node) {
			let b;
			if (edges[i][0] == start_node) {
				b = 1;
			} else {
				b = 0;
			}
			if (visited.includes(edges[i][b])) {
				continue;
			}
			if (edges[i][b] == end_node) {
				if (prob * succProb[i] > res) {
					res = prob * succProb[i];
				}
			} else if (
				findProb(
					edges,
					succProb,
					edges[i][b],
					end_node,
					prob * succProb[i],
					visited
				) > res
			) {
				res = findProb(
					edges,
					succProb,
					edges[i][b],
					end_node,
					prob * succProb[i],
					visited
				);
			}
		}
	}
	return res;
}
