function reverse(x: number): number {
	const reversed = parseInt(x.toString().split('').reverse().join(''));
	if (reversed < -Math.pow(2, 31) || reversed > Math.pow(2, 31) - 1) {
		return 0;
	}
	return x < 0 ? -reversed : reversed;
}
