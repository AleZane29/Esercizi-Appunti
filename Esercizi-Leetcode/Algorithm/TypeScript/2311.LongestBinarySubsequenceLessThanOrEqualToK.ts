function longestSubsequence(s: string, k: number): number {
	let res: number = 0;
	let count: number = 0;
	for (let i = s.length - 1; i >= 0; i--) {
		if (s[i] === '0') {
			res++;
		} else if (count + 2 ** (s.length - 1 - i) <= k) {
			res++;
			count += 2 ** (s.length - 1 - i);
		}
		console.log(count);
	}
	return res;
}
