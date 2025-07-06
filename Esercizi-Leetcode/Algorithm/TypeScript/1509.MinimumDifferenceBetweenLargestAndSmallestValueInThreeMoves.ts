/*
Dato un array è possibile rimpiazzare, al massimo 3 volte, un suo elemento con un altro preso a scelta dall'array stesso. Restituire la
differenza minima tra il valore massimo e il valore minimo dell'array.
es. [1,5,2,15,9,23] -> [1,5,2,5,2,5] Output: 4 (Sono stati rimpiazzati gli ultimi tre elementi o con 5 o con 2)
*/
function minDifference(nums: number[]): number {
	if (nums.length <= 4) {
		return 0;
	}
	let off = nums.length - 4;
	nums.sort((a, b) => a - b);
	let minDiff = nums[off] - nums[0];
	for (let i = 1; i < 4; i++) {
		if (nums[i + off] - nums[i] < minDiff) {
			minDiff = nums[i + off] - nums[i];
		}
	}
	return minDiff;
}
