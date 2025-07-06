function compute(a: number[], b: number[]): number {
	let n = a.length;
	let memo: number[][] = new Array(n)
		.fill(undefined)
		.map(() => new Array(n).fill(undefined));
	let max: number = -Infinity;
	for (let i = 1; i < n; i++) {
		memo[i][n - 1] = a[i];
		max = a[i] > max ? a[i] : max;
	}
	for (let j = 0; j < n; j++) {
		memo[0][j] = b[j];
		max = b[j] > max ? b[j] : max;
	}
	for (let i = 1; i < n - 1; i++) {
		for (let j = n - 1; j > i; j--) {
			memo[i][j] = memo[i - 1][j - 1] * memo[i][j + 1];
			max = b[j] > max ? b[j] : max;
		}
	}
	return max;
}
