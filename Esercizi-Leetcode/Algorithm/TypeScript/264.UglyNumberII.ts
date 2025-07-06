//Trovare l'ennesimo elemento dell'array formato da i numeri con fattori primi 2,3,5
function nthUglyNumber(n: number): number {
	let primeFact: number[] = [2, 3, 5];
	let uglyArr: number[] = [1];
	let ind = 0;
	while (uglyArr.length <= n || uglyArr[n] > uglyArr[ind] * primeFact[0]) {
		if (uglyArr.findIndex((x) => x == uglyArr[ind] * primeFact[0]) == -1) {
			uglyArr.push(uglyArr[ind] * primeFact[0]);
		}
		if (uglyArr.findIndex((x) => x == uglyArr[ind] * primeFact[1]) == -1) {
			uglyArr.push(uglyArr[ind] * primeFact[1]);
		}
		if (uglyArr.findIndex((x) => x == uglyArr[ind] * primeFact[2]) == -1) {
			uglyArr.push(uglyArr[ind] * primeFact[2]);
		}
		ind++;
		uglyArr.sort((a, b) => a - b);
	}
	return uglyArr[n - 1];
}
