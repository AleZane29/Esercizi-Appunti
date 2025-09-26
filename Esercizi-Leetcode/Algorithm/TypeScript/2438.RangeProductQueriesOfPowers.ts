function productQueries(n: number, queries: number[][]): number[] {
	let powers: number[] = [1];
	while (n != 0) {
		let i: number = 1;
		while (i <= n / 2) {
			i *= 2;
		}
		powers.push(i);
		n -= i;
	}
	powers.reverse();
	let answers: number[] = [];
	for (let i = 0; i < queries.length; i++) {
		answers.push(1);
		for (let n = 0; n < powers.length; n++) {
			if (n >= queries[i][0] && n <= queries[i][1]) {
				answers[i] *= powers[n];
			}
		}
	}

	return answers;
}
