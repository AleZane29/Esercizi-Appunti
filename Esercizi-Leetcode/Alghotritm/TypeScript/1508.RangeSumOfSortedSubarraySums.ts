/*Dato array di interi restituire la somme degli elementi tra left e right dell'array arr formato dalla somma delle somme di ogni
elemento di nums
Es. nums = [1,2,3,4], n = 4, left = 1, right = 5   ->    arr = [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]  Output: 13 = 1+2+3+3+4    */
function rangeSum(
	nums: number[],
	n: number,
	left: number,
	right: number
): number {
	let arr: number[] = [];
	for (let i = 0; i < n; i++) {
		arr.push(nums[i]);
		for (let x = i + 1; x < n; x++) {
			arr.push(nums[x] + arr[arr.length - 1]);
		}
	}
	arr.sort((a, b) => a - b);
	let res = 0;
	for (let i = left - 1; i < right; i++) {
		res += arr[i];
	}
	return res % (10 ** 9 + 7);
}
